/*
pmaik
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb(a) push_back(a)
#define M 1000000007
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
