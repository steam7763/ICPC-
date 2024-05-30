#include<iostream>
#include<cstdio>
#define ll long long
using namespace std;
inline int slowmul(int a,int b,int mod)
{
	ll ans=0;
	while(b)
	{
		if(b&1)
			ans+=a%mod;
		a<<=1%mod;
		b>>=1;
	}
	return ans;
}
int main()
{
	int a,b,n;//a*b%n
	scanf("%d%d%d",&a,&b,&n);
	printf("%d",slowmul(a,b,n));
}
