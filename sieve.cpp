/*
pmaik
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
/**************************************Sieve for prime********************************/
int isprime[1000001];
void sieve()
{
	int i,j,k;
	isprime[0]=isprime[1]=1;
	for(i=2;i<=sqrt(1000000);i++)
	{
		if(!isprime[i])
		{
			for(j=2*i;j<=1000000;j+=i)
			{
				isprime[j]=1;
			}
		}
	}
}
int checkprime(int x)
{
	return (!isprime[x]);
}
/************************************************************************************/
int main()
{
  sieve();
  cout<<checkprime(199)<<endl;
  
	return 0;
}
