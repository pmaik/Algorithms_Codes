/*
    maneesh(maik)
*/ 
// Prim's Algorithm 

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
    ll s;
    ll d;
    ll val;
};

// comperator function for priority queue 
struct comp
{
    bool operator()(data const& a, data const& b)
    {
        return a.val > b.val;
    }
}; 

// Prim's Algorithm

int main()
{
    fastio;

    ll n,m;
    cin>>n>>m;

    ll i,j,k,x,y,w,mx=0;
    vector<data>v[n+1];
    vector<data>MST;
    data z1,z2;

    for(i=0; i<m; i++)
    {
        cin>>x>>y>>w;
        mx=mx+w;

        z1.s=x; z1.d=y; z1.val=w;
        v[x].pb(z1);

        z2.s=y; z2.d=x; z2.val=w;
        v[y].pb(z2); 
    }
    mx=mx+100;

  /*  for(i=1; i<=n; i++)
    {
        cout<<i<<" ";
        for(j=0; j<v[i].size(); j++)
        {
            cout<<"("<<v[i][j].d<<", "<<v[i][j].val<<")   ";
        }
        cout<<endl;
    } */
    
    ll vis[n+1],dist[n+1];
    for(i=1; i<=n; i++)
    {
        vis[i]=0;
        dist[i]=mx;
    }
    vis[1]=1; dist[1]=0;

    priority_queue<data, vector<data>, comp>pq;

    for(i=0; i<v[1].size(); i++)
    {
        z1.s=v[1][i].s; z1.d=v[1][i].d; z1.val=v[1][i].val;
        dist[v[1][i].d]=v[1][i].val;
        pq.push(z1);
    }

    while(!pq.empty())
    {
        z1=pq.top();
        pq.pop();

        ll p=z1.d;
        if(vis[p]==0)
        {
            MST.pb(z1);
            vis[p]=1;
        }
        else
            continue;

        for(i=0; i<v[p].size(); i++)
        {
            if(vis[v[p][i].d]==0 )
            {
                z2.s=v[p][i].s; z2.d=v[p][i].d; z2.val=v[p][i].val;
                pq.push(z2);

                if(dist[v[p][i].d]>v[p][i].val)
                {
                    dist[v[p][i].d]=v[p][i].val;
                }
            }
        }
    }

    // print edges of MST 
    for(i=0; i<MST.size(); i++)
    {
        cout<<MST[i].s<<" "<<MST[i].d<<" "<<MST[i].val<<"\n";
    }

    return 0;
} 
