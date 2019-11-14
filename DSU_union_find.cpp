/*
    maneesh(maik)
*/
// DSU union_find perations 

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

// find_root of any vertex 
ll root(ll A[], ll i)
{
	while(A[i]!=i)
	{
		A[i]=A[A[i]];
		i=A[i];
	}
	return i;
}

// take union of two sets 
void unionn(ll A[], ll size[], ll a, ll b)
{
	ll root_a=root(A,a);
	ll root_b=root(A,b);

	if(size[root_a]<size[root_b]) // make root as b
	{
		A[root_a]=A[root_b];
		size[root_b]+=size[root_a];
	}
	else (size[root_a]>size[root_b]) // make root as a 
	{
		A[root_b]=A[root_a];
		size[root_a]+=size[root_b];
	}
}

// check whether a and b are in the same set or not 
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

	ll A[n+1],size[n+1];
	ll i,x,y,op;

	for(i=1; i<=n; i++)
	{
		A[i]=i;
		size[i]=1;
	}

	for(i=0; i<m; i++)
	{
		cin>>op;
		if(op==0)
		{
			cin>>x>>y;
		    unionn(A,size,x,y);
		}
		else if(op==1)
		{
			cin>>x>>y;
			if(find(A,x,y))
				cout<<x<<" and "<<y<<" are in same set "<<endl;
			else
				cout<<x<<" and "<<y<<" are in different sets "<<endl;
		}
	}
	return 0;
}
