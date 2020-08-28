/*
    lps function used in KMP algorithm
*/


/*           pmaik
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

vector<ll> LPS_function(string s) 
{
    int n = s.size();
    vector<ll> lps(n);

    for (int i = 1; i < n; i++) 
    {
        int j = lps[i-1];

        while (j > 0 && s[i] != s[j])
            j = lps[j-1];

        if (s[i] == s[j])
            j++;

        lps[i] = j;
    }
    return lps;
}

 
int main()
{
    fastio;

    string s;
    cin>>s;

    vector<ll>lps=LPS_function(s);
    for(int i=0; i<s.size(); i++)
    {
        cout<<lps[i]<<" ";
    }

    return 0;
}
