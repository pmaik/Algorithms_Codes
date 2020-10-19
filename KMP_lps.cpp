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
    int i, j, n = s.size();
    vector<int>lps(n);
    lps[0] = 0;
    
    i = 1, j = 0;
    while(i < n){
        if(s[i] == s[j]){
            lps[i] = j + 1;
            i++; j++;
        }
        else{
            if(j == 0){
                lps[i] = 0;
                i++;
            }
            else{
                j = lps[j-1];
            }
        }
    }
    
    retunr lps;
}

int find_Pat(string text, string pat){
    
    int n = text.size();
    int m = pat.size();
    
    vector<ll>lps = LPS_function(pat);
    
    // LPS ARRAY....
    for(int i=0; i<m; i++){
        cout<<lps[i]<<" ";
    }cout<<endl;
    
    int idx = -1;
    i = 0; j = 0;
    
    while( i < n && j < m ){
        
        if(text[i] == pat[j]){
            i++; j++;
            if(j == m){
                idx = i-m;
                break;
            }
        }
        else{
            if(j == 0){
                i++;
            }
            else{
                j = lps[j-1];
            }
        }
    }
    
    return idx;
}

 
int main()
{
    fastio;

    string text, pat;
    cin>>text;
    cin>>pat;
    
    int idx = find_Pat(text, pat);
    
    if( idx != -1 ){
        cout<<"Pattern found at index: "<<idx<<endl;
    }
    else{
        cout<<"Pattern does not found "<<endl;
    }

    return 0;
}
