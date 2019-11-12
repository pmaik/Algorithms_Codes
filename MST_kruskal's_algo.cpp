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

ll root(ll A[], ll i)
{
	while(A[i]!=i)
	{
		A[i]=A[A[i]];
		i=A[i];
	}
	return i;
}

void unionn(ll A[], ll size[], ll a, ll b)
{
	ll root_a=root(A,a);
	ll root_b=root(A,b);

	if(size[root_a]<size[root_b]) // make root as b
	{
		A[root_a]=A[root_b];
		size[root_b]+=size[root_a];
	}
	else
	{
		A[root_b]=A[root_a];
		size[root_a]+=size[root_b];
	}
}

bool find(ll A[], ll a, ll b)
{
	if(root(A,a)==root(A,b))
		return true;
	else
		return false;
}

int main()
{
	fastio;

	ll n,m;
	cin>>n>>m;

	ll i,j,k,x,y,w;
	ll A[n+1],vis[n+1],size[n+1];
	for(i=1; i<=n; i++)
	{
		A[i]=i; vis[i]=0; size[i]=1;
	}

	vector<data>MST;
	data z;
	priority_queue<data, vector<data>, comp>pq;

	for(i=0; i<m; i++)
	{
		cin>>x>>y>>w;
		z.s=x; z.d=y; z.val=w;
		pq.push(z);
	}

	while(MST.size()<n-1)
	{
		z=pq.top();
		x=z.s; y=z.d;
		pq.pop();

		if(!find(A,x,y))
		{
			unionn(A, size, x, y);
			MST.pb(z);
		}
	}
	//cout<<MST.size()<<endl;
	// MST edges 
	for(i=0; i<MST.size(); i++)
	{
		cout<<MST[i].s<<" "<<MST[i].d<<" "<<MST[i].val<<"\n";
	}
	return 0;
}
