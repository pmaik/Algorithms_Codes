/*
    maneesh(maik)
*/
// Connected components in Directed Graph using TOPOLOGICAL Order 

#include<iostream>
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
#include<unordered_map>
#include<unordered_set>
#include<vector>
using namespace std;
#define ll long long int
#define pb push_back
#define pf push_front
#define M 1000000007
#define fastio ios_base::sync_with_stdio(false);

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
    } */

    queue<ll>q;
    for(i=1; i<=n; i++)
    {
        if(indg[i]==0)
        {
            q.push(i);
            Topo.pb(i);
            //cout<<i<<" ";
        }
    }

    while(!q.empty())
    {
        ll p=q.front();

        for(i=0; i<v[p].size(); i++)
        {
            indg[v[p][i]]--;
            if(indg[v[p][i]]==0)
            {
                q.push(v[p][i]);
                Topo.pb(v[p][i]);
                //cout<<v[p][i]<<" ";
            }
        }
        q.pop();
    }

    ll conn_comp=0,vis[n+1];
    for(i=1; i<=n; i++)
    {
        vis[i]=0;
    }

    for(i=0; i<n; i++)
    {
        ll it=Topo[i];
        if(vis[it]==0)
        {
            conn_comp++;
            DFS(it, vis, v);
        }
    }

    cout<<"no. of connected components are --> "<<conn_comp<<endl;

    return 0;
} 
