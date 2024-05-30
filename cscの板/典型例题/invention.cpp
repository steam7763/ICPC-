#include<stdio.h>
#include<iostream>
using namespace std;
int i,j=1,n,m,t[10001],s1[10001]={0},s2[10001]={0},s,z,y=1,dp[10001],mini;
int main()
{
//	freopen("invention.in","r",stdin);
//    freopen("invention.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)
	{
    	scanf("%d",&z);
		t[z]++;s=max(z,s);	
    }
    for(i=1;i<=s;i++)
    if(t[i]!=0)
    {
    	s1[i]=s1[i-1]+t[i];	
    	s2[i]=s2[i-1]+t[i]*i;
	}
    for(i=1;i<=s;i++)
    dp[i]=i*i-s2[i];	
	for(i=1;i<=s;i++)
	for(j=i-m;j<=i;j++)
		dp[i]=max(dp[i],dp[j]+i*(s1[i]-s1[j-1])-s2[i]+s2[j-1]); 
	mini=dp[s];
	for(i=s;i<=s+m;i++)
		mini=min(mini,dp[i]);
	printf("%d",mini);
	return 0;
}
