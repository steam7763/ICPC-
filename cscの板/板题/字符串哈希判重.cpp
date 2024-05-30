#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
typedef unsigned long long ULL ;
char s1[1000001],s2[1000001];
ULL T,power[1000001],sum[1000001];
int main()
{
    #ifndef DEBUG
	freopen("Oulipo.in","r",stdin);
	freopen("Oulipo.out","w",stdout);
	#endif // DEBUG
	scanf("%d",&T);
	power[0]=1;
	for(int i=1;i<=1000000;i++)
	power[i]=power[i-1]*31;
	while(T--)
	{
		scanf("%s%s",s1+1,s2+1);
		int n=strlen(s1+1),m=strlen(s2+1);
		sum[0]=0;
		for(int i=1;i<=m;i++)
			sum[i]=sum[i-1]*31+(ULL)(s2[i]-'A'+1);
		ULL s=0;
		for(int i=1;i<=n;i++)
			s=s*31+(ULL)(s1[i]-'A'+1);
		int ans=0;
		for(int i=0;i<=m-n;i++)
			if(s==sum[i+n]-sum[i]*power[n])
				ans++;
		printf("%d\n",ans);
	}
}
