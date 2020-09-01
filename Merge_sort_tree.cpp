/*
    Implemention of Merge_Sort_Tree....

    Find count of elements strictly less than num in range (l,r)
 
    Node: For kth smallest Go to 40_days_of_code repository Spoj problem: MKTHNUM(K-th Number) 
    Happy_Coding(^_^)
*/
 
 
/*          pmaik
    ░▒▓█►─═ Maneesh ═─◄█▓▒░


          ( •̪●)
        ███████]▄▄▄▄▄▄▄▄▃  ▃  ▃ 
    ▂▄▅█████████▅▄▃▂
   [███████████████████]
  ...◥⊙▲⊙▲⊙▲⊙▲⊙▲⊙▲⊙◤......  */

#include<bits/stdc++.h>
using namespace std;
#define inf() ifstream cin("in00.txt")
#define onf() ofstream cout("out00.txt")
#define ll long long int
#define pb push_back
#define pf push_front
#define lb lower_bound
#define up upper_bound
#define mkp make_pair
#define pii pair<ll,ll>
#define fi first
#define se second
#define M 1000000007
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
 
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
#define ordered_set  tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>
#define ordered_set1 tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update>
#define inff -1000000000000000

vector<ll>st[300000];
 
void build_tree(ll si, ll ss, ll se, ll a[])
{
    if(ss==se)
    {
        st[si].push_back(a[ss]);
        return;
    }
 
    ll mid=(ss+se)/2;
    build_tree(2*si, ss, mid, a);
    build_tree(2*si+1, mid+1, se, a);
 
    ll i=0,j=0;
    while(i<st[2*si].size() && j<st[2*si+1].size())
    {
        if(st[2*si][i]<st[2*si+1][j])
        {
            st[si].push_back(st[2*si][i]);
            i++;
        }
        else
        {
            st[si].push_back(st[2*si+1][j]);
            j++;
        }
    }
 
    while(i<st[2*si].size())
    {
        st[si].push_back(st[2*si][i]);
        i++;
    }
    while(j<st[2*si+1].size())
    {
        st[si].push_back(st[2*si+1][j]);
        j++;
    }
}
 
ll count_less_than_num(ll si, ll ss, ll se, ll l, ll r, ll num)
{
    if(r<ss || se<l)
        return 0;

    if(ss>=l && se<=r)
    {
        ll pos=lower_bound(st[si].begin(), st[si].end(), num)-st[si].begin();
        return pos;
    }

    ll mid=(ss+se)/2;
    ll s1=count_less_than_num(2*si, ss, mid, l, r, num);
    ll s2=count_less_than_num(2*si+1, mid+1, se, l, r, num);

    return (s1+s2); 
}
 
void solve(ll tc)
{
    ll n,q;
    cin>>n>>q;
 
    ll i,l,r,num,a[n+5];
    for(i=1; i<=n; i++)
        cin>>a[i];
     
    build_tree(1, 1, n, a);
        
    while(q--)
    {
        cin>>l>>r>>num;
        cout<<count_less_than_num(1, 1, n, l, r, num)<<endl;
    }
}
 
int main()
{
    fastio;
 
    ll t;
    cin>>t;
    for(ll tc=1; tc<=t; tc++)
    {
        solve(tc);
    }
    
    return 0;
}  
