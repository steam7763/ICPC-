#include <bits/stdc++.h>
#define rg  register
#define LL long long
using namespace std;
const int MAXN=2222222LL;
const int INF=0x3f3f3f3fLL;
const LL mod=1e9+7LL;
LL N,tot,Ans=1LL;
LL prime[MAXN],num[MAXN];
bool vis[MAXN];

inline void Prime(){
	vis[1]=1LL;
	for(rg int i=2LL;i<=1000101LL;i++)
	{
		if(!vis[i]) vis[i]=true,prime[++tot]=i;
		for(rg int j=1LL;j<=tot;j++)
		{
			if(i*prime[j]>1000101LL) break;
			vis[i*prime[j]]=true;
			if(!(i%prime[j])) break;
		}
	}
	return ;
}

signed main()
{
	#ifndef DEBUG
	freopen("Cherry.in","r",stdin);
	freopen("Cherry.out","w",stdout);
    #endif
    Prime();
	scanf("%lld",&N);
	for(rg int j=1;j<=tot&&prime[j]<=N;j++)
	{
		int x=N;
		while(x)
		{
			num[j]+=x/prime[j];
			x/=prime[j];
		}
	}
	for(rg int i=1;i<=tot&&prime[i]<=N;i++)
		if(num[i]>=1) Ans=Ans*(2*num[i]+1)%mod;
	
	printf("%lld\n",Ans);
	
	return 0;
}
/*

*/









