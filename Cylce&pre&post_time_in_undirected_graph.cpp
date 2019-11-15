/*
    maneesh(maik)
*/
// Cycles in Undirected graph by DFS
// Pre and Post time of all nodes 

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
ll flag=0,cnt=0;

void DFS(ll p, ll s, ll vis[], ll start[], ll end[])
{
	vis[s]=1;

	for(ll i=0; i<G[s].size(); i++)
	{
		ll it=G[s][i];

		if(vis[it]==0)
		{
			start[it]=cnt; cnt++;
			DFS(s, it, vis, start, end);
		}
		else if(vis[it]==1 && it!=p )
		{
			flag=1;
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
	for(i=0; i<m; i++)
	{
		cin>>x>>y;
		G[x].pb(y);
		G[y].pb(x);
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

	flag=0; cnt=0;
	for(i=1; i<=n;  i++)
	{
		if(vis[i]==0)
		{
			start[i]=cnt; cnt++;
			DFS(i, i, vis, start, end);
		}
	}
    
    // pre(start) and post(end) time of DFS 

	for(i=1; i<=n; i++)
		cout<<start[i]<<" ";
	cout<<endl;
	for(i=1; i<=n; i++)
		cout<<end[i]<<" ";
	cout<<endl;

	if(flag==0)
		cout<<"NO cycle in the graph"<<endl;
	else
		cout<<"Cycle exist in the graph"<<endl;

	return 0;
}
