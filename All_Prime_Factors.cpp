#include<bits/stdc++.h>
using namespace std;
#define ll long long int


vector<ll> all_Prime_Factors(ll num)
{
  
    vector<ll>primeFact;
    ll n = num;
    for(ll i = 2; i*i<=num && n>1; i++)
    {
        if(n % i == 0)
        {
            primeFact.push_back(i);
            while(n%i == 0)
            {
                n /= i;
            }
        }
    }
    if(n > 1){
        primeFact.push_back(n);
    }

    return primeFact;
}

int main() {

    ll num;
    cin>>num;

    vector<ll>primeFact = all_Prime_Factors(num);

    for(ll i=0; i<primeFact.size(); i++)
    {
        cout<<primeFact[i]<<" ";
    }
    cout<<endl;
    return 0;
}
