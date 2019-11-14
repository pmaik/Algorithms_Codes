 /*
    maneesh(maik)
*/
// Connected component in Undirected graph using DSU  

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

ll root(ll A[], ll i)
{
	while(A[i]!=i)
	{
		A[i]=A[A[i]];
		i=A[i];
	}
	return i;
}

void unoinn(ll A[], ll size[], ll x, ll y)
{
	ll root_x=root(A, x);
	ll root_y=root(A, y);

	if(size[root_x]<size[root_y])
	{
		A[root_x]=A[root_y];
		size[root_y]+=size[root_x];
	}
	else
	{
		A[root_y]=A[root_x];
		size[root_x]+=size[root_y];
	}
}

int main()
{
	fastio;

	ll n,m;
	cin>>n>>m;
	ll i,A[n+1],size[n+1];
	for(i=1; i<=n; i++)
	{
		A[i]=i;
		size[i]=1;
	}

	ll x,y;
	for(i=0; i<m; i++)
	{
		cin>>x>>y;
		ll root_x=root(A, x);
		ll root_y=root(A, y);

		if(root_x!=root_y)
		{
			unoinn(A, size, x, y);
		}
	}

	ll connected_comp=0;
	for(i=1; i<=n; i++)
	{
		//cout<<i<<" "<<A[i]<<endl;
		if(A[i]==i)
			connected_comp++;
	}

	cout<<connected_comp<<endl;
	return 0;
}