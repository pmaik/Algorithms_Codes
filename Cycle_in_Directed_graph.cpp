/*
    maneesh(maik)
*/
// Cycles in Directed graph using DFS
// Four types of edges in DFS tree 
// 1. Tree edges, 2. Forward edges, 3. Backward edges, 4. Cross edges

//**** If any back edges exist then it must form a cycle****

// in Back edges for any edge (u-->v)  
// Interval [Pre(v),Post(v)] contains [Pre(u),Post(u)].

// in Forward and tree edges for any edge (u-->v)  
// Interval [Pre(u),Post(u)] contains [Pre(v),Post(v)]

// in Cross edges for any edge (u-->v)  
// Interval [Pre(u),Post(u)] and [Pre(v),Post(v)] are Disjoint 

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

vector<ll>G[1000000];
ll cnt=0;

struct data
{
     ll u,v;
};

void DFS(ll s, ll vis[], ll start[], ll end[])
{
	vis[s]=1;

	for(ll i=0; i<G[s].size(); i++)
	{
		ll it=G[s][i];

		if(vis[it]==0)
		{
			start[it]=cnt; cnt++;
			DFS(it, vis, start, end);
		}
	}
	end[s]=cnt; cnt++;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll n,m;
	cin>>n>>m;

	ll start[n+1],end[n+1];
	ll i,x,y;
	vector<data>edge;
	data z;
	for(i=0; i<m; i++)
	{
		cin>>x>>y;
		z.u=x; z.v=y;
		edge.pb(z);
		G[x].pb(y);
	}

/*	for(i=1; i<=n; i++)
	{
		cout<<i<<"-->";
		for(ll j=0; j<G[i].size(); j++)
		{
			cout<<G[i][j]<<" ";
		}
		cout<<endl;
	} */

	ll vis[n+1];
	for(i=1; i<=n; i++)
	{
		vis[i]=0;
	}

	cnt=0;
	for(i=1; i<=n;  i++)
	{
		if(vis[i]==0)
		{
			start[i]=cnt; cnt++;
			DFS(i, vis, start, end);
		}
	}
    
    // pre(start) and post(end) time of DFS 
	for(i=1; i<=n; i++)
		cout<<start[i]<<" ";
	cout<<endl;
	for(i=1; i<=n; i++)
		cout<<end[i]<<" ";
	cout<<"\n\n";

	ll flag=0,tx1,tx2,ty1,ty2;
	for(i=0; i<m; i++)
	{
		x=edge[i].u;  y=edge[i].v;
		tx1=start[x]; ty1=start[y];
		tx2=end[x];   ty2=end[y];
		// check back edges
		if(ty1<tx1 && ty2>tx2)
		{
			flag=1;
			break;
		}
	}
    
	if(flag==0)
		cout<<"NO cycle in the graph"<<endl;
	else
		cout<<"Cycle exist in the graph"<<endl;

	return 0;
}
