/*
    maneesh(maik)
*/ 
// Floyd_warshall algorithm for Directed and Undirected graph

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


/*
struct data
{
    ll u,v,wt;
}; */
/*
// comperator function for priority queue 
struct comp
{
    bool operator()(data const& s1, data const& s2)
    {
        return s1.val > s2.val;
    }
}; */

// Floyd_warshall algorithm for Directed and Undirected graph

int main()
{
    fastio;

    ll n,m;
    cin>>n>>m;

    ll i,j,k,x,y,w;
    ll dist[n+1][n+1][n+1];

    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
        {
            dist[i][j][0]=10000000000000;
            if(i==j)
            {
                dist[i][j][0]=0;
            }
        }
    }

    for(i=0; i<m; i++)
    {
        cin>>x>>y>>w;
        dist[x][y][0]=w;
        //dist[y][x][0]=w;
    }

    for(k=1; k<=n; k++)
    {
        for(i=1; i<=n; i++)
        {
            for(j=1; j<=n; j++)
            {
                dist[i][j][k]=min(dist[i][j][k-1], dist[i][k][k-1]+dist[k][j][k-1]);
                //dist[j][i][k]=dist[i][j][k];
            }
        }
    }
    
    // Shortest distances each pair of nodes  
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
        {
            cout<<dist[i][j][n]<<"  ";
        }
        cout<<endl;
    }

    return 0;
} 
