/*
    LCA by Binary Lifting 
    Try Codeforces Problem -- Minimum spanning tree for each edge
    link--> https://codeforces.com/contest/609/problem/E 
*/

/*
           pmaik
    ░▒▓█►─═ Maneesh ═─◄█▓▒░
 
 
          ( •̪●)
        ███████]▄▄▄▄▄▄▄▄▃  ▃  ▃ 
    ▂▄▅█████████▅▄▃▂
   [███████████████████]
  ...◥⊙▲⊙▲⊙▲⊙▲⊙▲⊙▲⊙◤......  */
 
#include<bits/stdc++.h>
using namespace std;
#define inf() ifstream cin("in00.txt")
#define onf() ofstream cout("out00.txt")
#define ll long long int
#define pb push_back
#define pf push_front
#define mp make_pair
#define pii pair<ll,ll>
#define fi first
#define se second
#define M 1000000007
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
 
ll n,m;
vector<pair<ll,ll>>G[200005];
ll vis[200005],par[200005],lev[200005],anc[200005][20];
 
void DFS(ll node, ll p, ll cost)
{
    anc[node][0]=p;
    lev[node]=lev[p]+1;
    par[node]=p;

    for(int i=1; i<20; i++)
    {
        anc[node][i]=anc[anc[node][i-1]][i-1];
    }

    for(ll i=0; i<G[node].size(); i++)
    {
        ll it=G[node][i].first;
        if(it!=p)
        {
            DFS(it, node, G[node][i].second);
        }
    }
}

ll lca(ll u, ll v)
{
    if(lev[u]<lev[v])
        swap(u,v);

    // Here i'm assuming that level(u) >= level(v) 
    // First make level of u & v equal 
    // we have to lift u up 

    ll diff=lev[u]-lev[v];  // difference in levels 
    ll temp=u;
    for(ll i=0; i<20; i++)
    {
        if( diff >> i & 1 )
        {
            temp=anc[temp][i];
        }
    }
    u=temp;
    
    // if they are at same level return 
    if(u==v)
        return u;
 
    for(ll i=19; i>=0; i--)
    {
        if(anc[u][i]!=anc[v][i])
        {
            u=anc[u][i]; v=anc[v][i];
        }
    }
    
    return par[u];
}
 
int main() 
{
    cin>>n>>m;
    ll u,v,w,j;
    
    // Here This is Unweighted Graph hence we used weight w=0
    for(ll i=0; i<m; i++)
    {
        cin>>u>>v;
        w=0;
        G[u].pb(make_pair(v, w));
        G[v].pb(make_pair(u, w));
    }
 
    ll i;
    vis[1]=1; lev[1]=0;
    DFS(1, 1, 0);
    
    // query 
    ll q;
    cin>>q;
    while(q--)
    {
        cin>>u>>v;
        cout<<lca(u,v)<<endl;
    }
 
    return 0;
}
