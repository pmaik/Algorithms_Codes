 /*
    Policy based data structures (PBDS) supports two additional operations
    1. st.order_of_key(num) 
    It returns count of elements which is strictly less than num. means index of num in sorted 
    array.(0 based indexing)

    2. st.order_of_key(k)
    It returns iterator pointing to (k+1)th elements (coz 0 based indexing).  
    

    There are two types of policy based data structures(pbds)
    1. Which can not contain duplicates =>(below)  ordered_set 
    2. which can contain duplicates => (below)  ordered_set1 
    
    Note: ordered_set1  does not support .find(num) operation directly but 
    for removing any element we have to use this for deleting num-> 
    (Here i'm assuming that num is present in set)
    
    st.erase(st.find_by_order(st.order_of_key(num)));

    Here in erase function we have to send the iterator pointing to the number
    which we want to delete.

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
#define mp make_pair
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
// ordered_set1 can also contains duplicates 
// ordered_set can not contains duplicates 



void defining_ordered_set()
{
    // ordered_set declared with name with name st.
    // It supports all property of set with two additional operation..
    ordered_set st;
    o_set.insert(5); 
    o_set.insert(1); 
    o_set.insert(2); 

    // 1. find_by_order(k). it returns an iterator of (k+1)th element of set.
    cout << *(st.find_by_order(1)) <<endl;

    // 2. st.order_of_key(num). it returns count of elements strictly less than num.
    // means returns the index of num (0 based indexing). 
    cout<< st.order_of_key(5) <<endl;

    // Deleting 2 from the set if it exists 
    if (st.find(2) != st.end()) 
        st.erase(st.find(2)); 
}

void defining_ordered_set1()
{
    // ordered_set1 declaration
    // It also supports property of set with two additional operation..
    ll num=1,k=1;
    ordered_set1 st1;

    cout << *(st.find_by_order(k)) <<endl;
    cout<< st.order_of_key(num) <<endl;
    // 1. find_by_order(k). it returns an iterator of (k+1)th element of set.
    // 2. st.order_of_key(num). it returns count of elements strictly less than num.
    // means returns the index of num (0 based indexing). 
    

    // Major difference is => ordered_set1 : is not support .find(num) directly.
    // We have to send iterator of number which we want to delete->  st1.erase(iterator) 

    // For deleting/removing element from ordered_set1 we have to do the following:
    // Here i'm checking if it is present ... 
    if( st.order_of_key(num)!=st.size() && ( st.order_of_key(num)==0 && num==(*st.begin())) )
    {
        st.erase(st.find_by_order(st.order_of_key(num)));
    }


    // Checking presence of any element
    if(st.order_of_key(num)==st.size())
    {
        cout<<num<<" is not present\n";
    }
    else if( st.order_of_key(num)==0 && num!=(*st.begin()) )  
    {
        cout<<num<<" is not present\n";
    }
    else
    {
        cout<<"present at index "<<st.order_of_key(num)<<endl;
    }

}

void solve(ll tc)
{
    ll n;
    cin>>n;
    ll a[n],i;

    for(i=0; i<n; i++)
    {
        cin>>a[i];
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
