/*
    maneesh(maik)
*/ 
// Dijkstra algo 
// The shortest path for undirected
// you can make this directed  

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
#define pii pair<ll,ll>
#define mp make_pair 
#define M 1000000007
#define fastio ios_base::sync_with_stdio(false);

struct comp
{
    bool operator()(const pair<int , int> &a , const pair<int , int> &b)
    {
        return a.first > b.first;
    }
};

 int main()
 {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    
    ll n,m;
    cin>>n>>m;
    vector<ll>G[n+2];
    vector<ll>cost[n+2];
    ll i,x,y,w,mx=0;
    for(i=0; i<m; i++)
    {
        cin>>x>>y>>w;
        
        G[x].pb(y);
        cost[x].pb(w);
        G[y].pb(x);
        cost[y].pb(w);
    }
 /*   for(i=1; i<=n; i++)
    {
    	cout<<i<<" ";
    	for(int j=0; j<G[i].size(); j++)
    	{
    		cout<<"("<<G[i][j]<<", "<<cost[i][j]<<")   ";
    	}
    	cout<<endl;
    } cout<<endl; */
	 
    ll dist[n+2];
    for(i=1; i<=n; i++)
    {
        dist[i]=1000000000;
    }
    priority_queue<pii, vector<pii>, comp>pq;

    ll source;
    cin>>source;

    dist[source]=0;
    pq.push(mp(0, source));
    
    while(!pq.empty())
    {
        ll node=pq.top().second;
        pq.pop();
        
        for(i=0; i<G[node].size(); i++)
        {
            ll it=G[node][i];
            if(dist[it]>dist[node]+cost[node][i])
            {
               dist[it]=dist[node]+cost[node][i];
               pq.push(mp(dist[it], it));
            }
        }
    }
    
    // distance from source to other
    for(i=1; i<=n; i++)
    {
        cout<<dist[i]<<" ";
    }
     return 0;
 }




// other method of Dijkstra 
/*
struct data
{
    ll nod;
    ll val;
};
// comperator function for priority queue 
struct comp
{
    bool operator()(data const& s1, data const& s2)
    {
        return s1.val > s2.val;
    }
};

int main()
{
    fastio;

    ll n,m;
    cin>>n>>m;

    ll i,x,y,w,mx=0;
    vector<data>v[n+1];
    data z1,z2;
    
    for(i=0; i<m; i++)
    {
    	cin>>x>>y>>w;
        mx=mx+w;

        z1.nod=y; z1.val=w;
    	v[x].pb(z1);
        z2.nod=x; z2.val=w;
        v[y].pb(z2);
    }
    mx=mx+100;

    ll vis[n+1],dist[n+1];
    for(i=1; i<=n; i++)
    {
        vis[i]=0;
        dist[i]=mx;
    }

//  for(i=1; i<=n; i++)
//    {
//    	cout<<i<<" ";
//    	for(int j=0; j<v[i].size(); j++)
//    	{
//    		cout<<v[i][j].nod<<" ";
//    	}
//    	cout<<endl;
//    } 
// source node 
    ll s;
    cin>>s;
    
    // define priority queue of structure 
    priority_queue<data, vector<data>, comp>pq;
    
    z1.nod=s; z1.val=0;
    pq.push(z1);
    
    vis[s]=1;
    dist[s]=0;

    while(!pq.empty())
    {
    	z1=pq.top();
        ll p=z1.nod;   //cout<<p<<" ";
        vis[p]=1;
        pq.pop();
        
        // traverse in the adjacency list of p 
        for(i=0; i<v[p].size(); i++)
        {
            if(dist[v[p][i].nod] > dist[p]+v[p][i].val )
            {
                dist[v[p][i].nod]=dist[p]+v[p][i].val;
            }
            
            // if not visited push it in to priority_queue 
            if(vis[v[p][i].nod]==0)
            {
                z2.nod=v[p][i].nod; z2.val=v[p][i].val;
                pq.push(z2);
            }
        }
    }
    //cout<<endl;
    // Shortest distance from source to all other nodes  
    for(i=1; i<=n; i++)
    {
        cout<<dist[i]<<" ";
    }

    return 0;
} 
*/
