/*
    --------> LCA <---------
    LOWEST COMMON ANCESTOR in grneral tree in log(N) with O(N) preprocessing(for making segment tree)
    by EULER TOUR on TREE

            pmaik
    ░▒▓█►─═ Maneesh ═─◄█▓▒░


          ( •̪●)
        ███████]▄▄▄▄▄▄▄▄▃  ▃  ▃ 
    ▂▄▅█████████▅▄▃▂
   [███████████████████]
  ...◥⊙▲⊙▲⊙▲⊙▲⊙▲⊙▲⊙◤......

███╗░░░███╗░█████╗░███╗░░██╗███████╗███████╗░██████╗██╗░░██╗
████╗░████║██╔══██╗████╗░██║██╔════╝██╔════╝██╔════╝██║░░██║
██╔████╔██║███████║██╔██╗██║█████╗░░█████╗░░╚█████╗░███████║
██║╚██╔╝██║██╔══██║██║╚████║██╔══╝░░██╔══╝░░░╚═══██╗██╔══██║
██║░╚═╝░██║██║░░██║██║░╚███║███████╗███████╗██████╔╝██║░░██║
╚═╝░░░░░╚═╝╚═╝░░╚═╝╚═╝░░╚══╝╚══════╝╚══════╝╚═════╝░╚═╝░░╚═╝
*/

#include<iostream>
#include<math.h>
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
#include<cstdio>
#include<memory.h>
#include<cassert>
#include<cstdlib>
#include<cmath>
#include<unordered_map>
#include<unordered_set>
#include<vector>
using namespace std;
#define ll long long int
#define pb push_back
#define pf push_front
#define mp make_pair
#define M 1000000007
#define maxval 100000000000
#define fastio ios_base::sync_with_stdio(false);

ll n;                // number of nodes in the tree 
vector<ll>G[300000]; // adajency list of graph(tree)
vector<ll>euler;     // euler tour list of trer
ll st[600050];       // segment tree for Min Height in given range

// DFS for euler tour in tree
void DFS(ll s, ll vis[], ll H[])
{
    ll i;
    for(i=0; i<G[s].size(); i++)
    {
        ll it=G[s][i];
        if(vis[it]==0)
        {
            vis[it]=1;
            euler.pb(it);
            H[it]=H[s]+1;
            if(G[it].size()>1)
            {
                DFS(it, vis, H);
            }
            euler.pb(s);
        }
    }
}
// building segment tree of euler tour list 
void build_EULER_Tree(ll H[], ll si, ll ss, ll se)
{
    if(ss==se)
    {
        st[si]=euler[ss];
        return;
    }

    ll mid=(ss+se)/2;
    build_EULER_Tree(H, 2*si+1, ss, mid);
    build_EULER_Tree(H, 2*si+2, mid+1, se);

    if(H[st[2*si+1]]<=H[st[2*si+2]])
        st[si]=st[2*si+1];
    else
        st[si]=st[2*si+2];
}

// finding LCA of given nodes in range (l, r)  
ll find_LCA(ll H[], ll si, ll ss, ll se, ll l, ll r, ll in)
{
    if(se<l || r<ss)
        return in;
    if(l<=ss && r>=se)
        return st[si];

    ll mid=(ss+se)/2;
    ll z1=find_LCA(H, 2*si+1, ss, mid, l, r, in);
    ll z2=find_LCA(H, 2*si+2, mid+1, se, l, r, in);

    if(H[z1]<=H[z2])
        return z1;
    else
        return z2;
}

int main()
{
    fastio;

    cin>>n;
    ll vis[n+1]={0};
    ll i,u,v;
    for(i=1; i<=n-1; i++)
    {
        cin>>u>>v;
        G[u].pb(v);
        G[v].pb(u);
    }

    // Height array of all nodes with root node 1 
    ll H[n+2];
    H[n+1]=maxval;

    ll root=1;
    H[root]=0; vis[root]=1;
    euler.pb(root);
    DFS(root, vis, H);

    ll first[n+2];
    for(i=0; i<=n; i++)  
        first[i]=-1;

    // finding first occurance of any node in euler tour list 
    for(i=0; i<euler.size(); i++)  
    {
        if(first[euler[i]]==-1)
        {
            first[euler[i]]=i;
        }
    }

    ll n1=euler.size();
    build_EULER_Tree(H, 0, 0, n1-1);

    ll q,l,r;
    cin>>q;
    while(q--)
    {
        cin>>u>>v;
        l=min(first[u], first[v]);
        r=max(first[u], first[v]);
        // querying for u and v 
        ll lca=find_LCA(H, 0, 0, n1-1, l, r, n+1);
        cout<<lca<<endl;
    }

    return 0;
}
