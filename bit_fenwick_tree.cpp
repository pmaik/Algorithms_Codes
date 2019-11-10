/*
  pmaik (Maneesh)
*/
// mega_inversion spoj_prob.

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
 
ll N;
vector<ll> B1(100005, 0), B2(100005, 0);
 
void update(vector<ll> &t, int x, ll v)
{
    while(x>0)
    {
        t[x] += v;
        x -= x&-x;
    }
}
 
ll query(vector<ll> &t, int x)
{
    ll ret = 0;
    while(x <= N)
    {
        ret += t[x];
        x += x&-x;
    }
    return ret;
}

int main()
{
    scanf("%lld", &N);
    ll ans = 0;
    for(ll i=1; i<=N; i++)
    {
        ll x;
        scanf("%lld", &x);
        
        update(B1, x, 1);
        
        ll q = query(B1, x+1);
        
        update(B2, x, q);
        
        ans += query(B2, x+1);
    }
    cout << ans<<endl;
    
 /*   for(int z=1; z<=6; z++)
    cout<<B1[z]<<" ";
    cout<<endl;
    for(int z=1; z<=6; z++)
    cout<<B2[z]<<" "; */
    
    /*int mm,nn;
    mm=2;
    mm=mm+(mm&(-mm));
    cout<<mm<<"  hh";*/
} 
