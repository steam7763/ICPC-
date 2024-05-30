#include<iostream>
#include<cstdio>
#define ll long long
using namespace std;
inline int quickPow(int a,int b,int mod)
{
	ll ans=1;
	for(;b;b>>=1)
	{
		if(b&1)
			ans=(ll)((ll)ans*(ll)a)%mod;
		a=(ll)((ll)a*a)%mod;
	}
	return ans;
}
int main()
{
	int a,b,n;//a^b%n
	scanf("%d%d%d",&a,&b,&n);
	printf("%d",quickPow(a,b,n));
}
