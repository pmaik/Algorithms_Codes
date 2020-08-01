 
// Connected components in Directed Graph using TOPOLOGICAL Order 

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

void DFS(ll s, ll vis[], vector<ll>v[] )
{
    vis[s]=1;
    for(ll i=0; i<v[s].size(); i++)
    {
        ll it=v[s][i];
        if(vis[it]==0)
        {
            DFS(it, vis, v);
        }
    }
}
// Connected components in Directed Graph using TOPOLOGICAL Order  

int main()
{
    fastio;

    ll n,m;
    cin>>n>>m;
    ll i,x,y;
    vector<ll>Topo;
    vector<ll>v[n+1];

    ll indg[n+1];
    for(i=1; i<=n; i++)
        indg[i]=0;

    for(i=0; i<m; i++)
    {
        cin>>x>>y;
        v[x].pb(y);
        indg[y]++;
    }

/*    for(i=1; i<=n; i++)
    {
        cout<<i<<" ";
        for(int j=0; j<v[i].size(); j++)
        {
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }*/ 

    ll vis[n+1];
    for(i=1; i<=n; i++)
        vis[i]=0;

    queue<ll>q;
    for(i=1; i<=n; i++)
    {
        if(indg[i]==0)
        {
            q.push(i);
            Topo.pb(i);
            vis[i]=1;
            // cout<<i<<" jjj\n";
        }
    }

    while(!q.empty())
    {
        ll p=q.front();

        for(i=0; i<v[p].size(); i++)
        {
            ll it=v[p][i];
            vis[it]=1;
            indg[it]--;
            if(indg[it]==0)
            {
                q.push(it);
                Topo.pb(it);
            }
        }
        q.pop();
    }

    for(i=1; i<=n; ++i)
        if(vis[i]==0)
            Topo.pb(i);


    ll conn_comp=0;
    for(i=1; i<=n; i++)
        vis[i]=0;


    for(i=0; i<Topo.size(); i++)
    {
        ll it=Topo[i];
        // cout<<it<<" ";
        if(vis[it]==0)
        {
            conn_comp++;
            DFS(it, vis, v);
        }
    }

    if(conn_comp==0)
        conn_comp=1;

    cout<<"\nno. of connected components are --> "<<conn_comp<<endl;

    return 0;
} 
