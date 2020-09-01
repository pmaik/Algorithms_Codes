/*
    Implemention of Segment_tree_find_max with point update

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
#define inff 100000000000000000

ll st[300000];

ll maxx(ll a, ll b)
{
    if(a>b)
        return a;
    else
        return b;
}

void build_tree(ll si, ll ss, ll se, ll a[])
{
    if(ss==se)
    {
        st[si]=a[ss];
        return;
    }

    ll mid=(ss+se)/2;
    build_tree(2*si, ss, mid, a);
    build_tree(2*si+1, mid+1, se, a);

    st[si]=max(st[2*si], st[2*si+1]);
}

ll find_max(ll si, ll ss, ll se, ll l, ll r)
{
    if(r<ss || se<l)
        return -inff;

    if(ss>=l && se<=r)
        return st[si];

    ll mid=(ss+se)/2;

    return maxx(find_max(2*si, ss, mid, l, r), find_max(2*si+1, mid+1, se, l, r));

   /* ll num1=find_max(2*si, ss, mid, l, r);
    ll num2=find_max(2*si+1, mid+1, se, l, r);
    return maxx(num1, num2);*/
}

void update1(ll si, ll ss, ll se, ll idx, ll val)
{
    if(idx<ss || idx>se)
        return;

    if(ss==se && idx==ss)
    {
        st[si]=val;
        return;
    }

    ll mid=(ss+se)/2;
    if(idx>=ss && idx<=mid)
        update1(2*si, ss, mid, idx, val);
    else
        update1(2*si+1, mid+1, se, idx, val);

    st[si]=maxx(st[2*si], st[2*si+1]);
}

void solve(ll tc)
{
    ll n,q;
    cin>>n>>q;
 
    ll i,l,r,val,idx,a[n+5];
    for(i=1; i<=n; i++)
        cin>>a[i];
     
    build_tree(1, 1, n, a);
        
    while(q--)
    {
        char op;
        cin>>op;
        if(op=='Q')
        {
            cin>>l>>r;
            cout<< find_max(1, 1, n, l, r) <<endl;
        }
        else if(op=='U')
        {
            cin>>idx>>val;
            a[idx]=val;
            update1(1, 1, n, idx, val);
        }
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
