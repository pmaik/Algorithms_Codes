/*
  pmaik (Maneesh)
*/

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

// for (1/a)%M 

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
	
	modInverse(a);
	return 0;
}
