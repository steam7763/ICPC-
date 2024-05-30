#include<bits/stdc++.h>
#define rg register
#define int long long
using namespace std;
const int MAXN=100010;
long long n,a0,a1,b0,b1;
long long prime[MAXN];
int  top;
bool vis[MAXN];
void pre()
{
	vis[1]=1;
	for(int i=2;i<=54722ll;i++)
	{
		if(!vis[i]) prime[++top] = i;
		for(int j=1;j<=top;++j)
		{
			if( i * prime[j] >= MAXN ) break;
			vis[i * prime[j]] = 1;
		}
//		if(vis[i]) continue;
//		prime[++top]=i;
//		for(int j=i;j<=n/i;j++)
//			vis[i*j]=1;
	}
}
signed main()
{
	#ifndef DEBUG
	freopen("son.in","r",stdin);
	freopen("son.out","w",stdout);
	#endif
	scanf("%lld",&n);
	pre();
	while(n--)
	{
		scanf("%lld%lld%lld%lld",&a0,&a1,&b0,&b1);
		int ans=1ll;
		for(int i=1;i<=top;i++)
		{
			int A0=0,A1=0,B0=0,B1=0;
			while(!(a0%prime[i])) A0++,a0/=prime[i];
			while(!(a1%prime[i])) A1++,a1/=prime[i];
			while(!(b0%prime[i])) B0++,b0/=prime[i];
			while(!(b1%prime[i])) B1++,b1/=prime[i];
			if(A0==A1)
			{
				if(B0==B1)
				{
					if(B1<A1)
					{
						ans=0ll;
						break;
					}
					ans*=(B1-A1+1ll);
//					cerr<<"!";
				}
			}
			else
			{
				if(B0 != B1)
				if(A1 != B1)
				{
					ans = 0ll;
					break;
				}
				if(B0 == B1)
				if(B0 <  A1)
				{
					ans = 0ll;
					break;
				}
			}
		}
		if(b1 > 1ll)
		{
			int A0=0ll,A1=0ll,B0=0ll,B1=0ll;
			while(a0 % b1 == 0ll) { ++A0; a0 /= b1; };
			while(a1 % b1 == 0ll) { ++A1; a1 /= b1; };
			while(b0 % b1 == 0ll) { ++B0; b0 /= b1; };
			++B1;
			if(A0 == A1)
			{
				if(B0 == B1)
				{
					if(B0 < A0)
					{
						ans = 0ll;
						break;
					}
					ans*=(B1-A1+1ll);
				}
				
			}
			else
			{
				if(B0 != B1)
				if(A1 != B1)
				{
					ans = 0ll;
					break;
				}
				if(B0 == B1)
				if(B0 <  A1)
				{
					ans = 0ll;
					break;
				}
				
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
/*
2
41 1 96 288
95 1 37 1776
 
*/
