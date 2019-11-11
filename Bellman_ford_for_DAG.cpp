/*
    maneesh(maik)
*/ 
// Bellman_Ford algorithm for Directed acylic graph(DAG)

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

struct data
{
    ll u,v,wt;
};

/*
// comperator function for priority queue 
struct comp
{
    bool operator()(data const& s1, data const& s2)
    {
        return s1.val > s2.val;
    }
}; */

// Bellman_Ford algorithm for Directed graph

int main()
{
    fastio;

    ll n,m;
    cin>>n>>m;

    ll i,x,y,w,mx=0;

    vector<data>Edge;
    data z1;
    
    for(i=0; i<m; i++)
    {
        cin>>x>>y>>w;
        mx=mx+w;

        z1.u=x; z1.v=y; z1.wt=w;
        Edge.pb(z1);
    }
    mx=mx+100;

    ll dist[n+1];
    for(i=1; i<=n; i++)
    {
        dist[i]=mx;
    }

/*  for(i=1; i<=n; i++)
    {
        cout<<i<<" ";
        for(int j=0; j<v[i].size(); j++)
        {
            cout<<v[i][j].nod<<" ";
        }
        cout<<endl;
    } */
    // source node 
    ll s;
    cin>>s;
    dist[s]=0;

    ll c=n-1;
    while(c>0)
    { 
        // traverse to all edges  
        for(i=0; i<Edge.size(); i++)
        {
            x=Edge[i].u; y=Edge[i].v; w=Edge[i].wt;

            if(dist[y] > dist[x]+w )
            {
                dist[y]=dist[x]+w;
            }
        }
        c--;
    }
    // Shortest distance from source s to all other nodes  
    for(i=1; i<=n; i++)
    {
        cout<<dist[i]<<" ";
    }

    return 0;
} 
