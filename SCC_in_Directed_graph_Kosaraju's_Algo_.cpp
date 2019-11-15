/*
    maneesh(maik)
*/
// Kosaraju's Algorithm
// Strongly connected components in Directed Graph

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
#define mp make_pair 
#define M 1000000007

vector<ll>G1[1000000],G2[1000000];
ll cnt=0;

struct data
{
	ll u,v;
};

void DFS1(stack<ll> &S, ll s, ll vis[], ll start[], ll end[])
{
	vis[s]=1;

	for(ll i=0; i<G1[s].size(); i++)
	{
		ll it=G1[s][i];

		if(vis[it]==0)
		{
			start[it]=cnt; cnt++;
			DFS1(S, it, vis, start, end);
		}
	}
	end[s]=cnt; cnt++;
	S.push(s);
}

void DFS2(ll s, ll vis[] )
{
	vis[s]=1;
	cout<<s<<" ";
	for(ll i=0; i<G2[s].size(); i++)
	{
		ll it=G2[s][i];
		if(vis[it]==0)
		{
			DFS2(it, vis);
		}
	}
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
		G1[x].pb(y);
		G2[y].pb(x);
	}

/*	for(i=1; i<=n; i++)
	{
		cout<<i<<"-->";
		for(ll j=0; j<G1[i].size(); j++)
		{
			cout<<G1[i][j]<<" ";
		}
		cout<<endl;
	} */

	ll vis[n+1];
	for(i=1; i<=n; i++)
	{
		vis[i]=0;
	}

	cnt=0;
	stack<ll>S;
	for(i=1; i<=n;  i++)
	{
		if(vis[i]==0)
		{
			start[i]=cnt; cnt++;
			DFS1(S, i, vis, start, end);
		}
	}

	for(i=1; i<=n; i++)
		vis[i]=0;

	ll count_SCC=0,c=1;
	while(!S.empty())
	{
		x=S.top();
		if(vis[x]==0)
		{
			count_SCC++; 
			cout<<"component no. "<<c<<"--> ";
			c++;
			DFS2(x, vis); cout<<endl;
		}

		S.pop();
	}
	// Print number of SCC's in graph 
	cout<<"\nTotal components are :: ";
	cout<<count_SCC<<endl;

	if(count_SCC==1)
	{
		cout<<"\nOver all Graph is Strongly connected.\n";
	}
    
    // pre(start) and post(end) time of DFS 
/*	for(i=1; i<=n; i++)
		cout<<start[i]<<" ";
	cout<<endl;
	for(i=1; i<=n; i++)
		cout<<end[i]<<" ";
	cout<<"\n\n";
*/

	return 0;
} 
