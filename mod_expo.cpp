/*
  pmaik (Maneesh)
*/

#include<iostream>
#include<algorithm>
#include<string.h>
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
ll P[10000000];

ll mod(ll x, ll n)
{
	if(n==0)
		return 1;
	if(n%2==0)
	{
		ll y=mod(x, n/2);
		return ((y%M)*(y%M))%M;
	}
	else
	{
		return ((x%M)*(mod(x, (n-1))%M))%M;
	}
}

void Sieve() 
{  
	ll n=9999999;
    memset(P, 1, sizeof(P));
    for (ll p=2; p*p<=n; p++) 
    { 
        if (P[p] == 1) 
        {  
            for (ll i=p*p; i<=n; i += p) 
                P[i] = 0; 
        } 
    } 
}

ll modInverse(ll a, ll m) 
{ 
    ll m0 = m; 
    ll y = 0, x = 1; 
    if (m == 1) 
      return 0; 
    while (a > 1) 
    {  
        ll q = a / m; 
        ll t = m;  
        m = a % m; a = t; 
        t = y; 
        y = x - q * y; 
        x = t; 
    }  
    if(x<0) 
       x+=m0; 
    return x; 
}

int main()
{
	fastio;
	
	int t;
	cin>>t;
	while(t--)
	{
		
	}
	return 0;
}
