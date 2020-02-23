/*
    LCA via BINARY LIFTING & 
    Kth node in the path from u to v ***
    SUM of edge weight b/w given pair of nodes *** 
    ( spoj problem-> QTREE2 - Query on a tree II )

            pmaik
    ░▒▓█►─═ Maneesh ═─◄█▓▒░


          ( •̪●)
        ███████]▄▄▄▄▄▄▄▄▃  ▃  ▃ 
    ▂▄▅█████████▅▄▃▂
   [███████████████████]
  ...◥⊙▲⊙▲⊙▲⊙▲⊙▲⊙▲⊙◤......

*/

#include<bits/stdc++.h>
#include<iostream>
#include<math.h>
#include<algorithm>
#include<string>
#include<bitset>
#include<deque>
#include<iterator>
#include<list>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<cstdio>
#include<memory.h>
#include<cassert>
#include<cstdlib>
#include<cmath>
#include<unordered_map>
#include<unordered_set>
#include<vector>
using namespace std;
#define ll long long int
#define pb push_back
#define pf push_front
#define mp make_pair
#define fi first
#define se second
#define M 1000000007
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); 

vector<pair<ll, ll>>G[100005];
ll S[100005];
ll level[100005];
ll parent[100005];
ll anc[100005][20];
bool vis[100005]={0};

void DFS(ll node)
{
	ll i;
	for(i=0; i<G[node].size(); i++)
	{
		ll it=G[node][i].first;
		if(vis[it]==0)
		{
			vis[it]=1;
			level[it]=level[node]+1;
			S[it]=S[node]+G[node][i].second;
			parent[it]=node;
			DFS(it);
		}
	}
}

ll LCA(ll u, ll v)
{
    ll lg,i,temp;
    if(level[u]<level[v])
    {
        temp=u;
        u=v;
        v=temp;
    }

    for(lg=0; (1<<lg)<=level[u]; lg++);
        lg--;

    for(i=lg; i>=0; i--)
    {
        if(level[u]-(1<<i)>=level[v])
        {
            u=anc[u][i];
        }
    }

    if(u==v)
        return u;

    for(i=lg; i>=0; i--)
    {
        if(anc[u][i]!=-1 && anc[u][i]!=anc[v][i])
        {
            u=anc[u][i]; v=anc[v][i];
        }
    }
    return parent[u];
}

int main()
{
    fastio;

    ll t;
    cin>>t;
    while(t--)
    {
        ll i,j,n;
        cin>>n;
        for(i=0; i<=n; i++)
        {
        	G[i].clear();
        	vis[i]=0;
        	S[i]=0;
        }

        ll a,b,c;
        for(i=0; i<n-1; i++)
        {
        	cin>>a>>b>>c;
        	G[a].push_back(make_pair(b, c));
        	G[b].push_back(make_pair(a, c));
        }

        for(j=0; j<20; j++)
            for(i=1; i<=n; i++)
                anc[i][j]=-1;

        ll root=1;
        parent[root]=-1; S[0]=0;
        vis[root]=1; S[root]=0; level[root]=0;
        DFS(root);

        for(i=1; i<=n; i++)
            anc[i][0]=parent[i];

        for(j=1; j<20; j++)
        {
            for(i=1; i<=n; i++)
            {
                if(anc[i][j-1]!=-1)
                {
                    anc[i][j]=anc[anc[i][j-1]][j-1];
                }
            }
        }

        ll lca,ans;
        string s,s1="DONE";
        while(1)
        {
            cin>>s;
            if(s==s1)
                break;

            if(s=="DIST")
            {
                cin>>a>>b;
                lca=LCA(a, b);
                // cout<<lca<<" =lca \n";
                ans=S[a]+S[b]-2*S[lca];
                cout<<ans<<endl;
            }
            else if(s=="KTH")
            {
                ll k,at;
                cin>>a>>b>>c;
                lca=LCA(a, b);

                if(c==1)
                    ans=a;
                else if((level[a]-level[lca]+1)==c)
                    ans=lca;
                else if(lca==a && (level[b]-level[a]+1==c) )
                    ans=b;
                else
                {
                    if((level[a]-level[lca]+1)>=c)
                    {
                        at=a; k=c-1;
                    }
                    else
                    {
                        at=b; 
                        k=level[a]-level[lca];
                        k=c-k;
                        k=(level[b]-level[lca])-k+1;
                        // cout<<k<<endl;
                    }

                    /*ll lg;
                    for(lg=0; (1<<lg) <= level[at]; lg++); 
                        lg--;

                    k=level[at]-k;
                    for(i=lg; i>=0; i--)
                    {
                        if (level[at]-(1<<i)>=k)
                        {
                            // cout<<at<<" "<<i<<endl;
                            at = anc[at][i];
                        }
                    } //cout<<endl; */

                    for(i=0; i<15; i++)
                    {
                        if( k&(1<<i))
                        {
                            at=anc[at][i];
                        }
                    }
                    ans=at;
                }
                cout<<ans<<endl;
            }
        }
        cout<<endl;
    }
    return 0;
}
