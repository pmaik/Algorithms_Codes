/*
    maneesh(maik)
*/ 
// dijikstra algorithm(Shortest path) for undirected graph 

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
    ll nod;
    ll val;
};

// comperator function for priority queue 
struct comp
{
    bool operator()(data const& s1, data const& s2)
    {
        return s1.val > s2.val;
        // here sorting according to decreasing val 
    }
};

int main()
{
    fastio;
    
    // define priority queue of structure 
    priority_queue<data, vector<data>, comp>pq;
    
    
    return 0;
} 
