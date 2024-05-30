#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
int i,j,l1,l2,dp[4001][4001],maxture;
int main()
{
//	freopen("LCS.in","r",stdin);
//	freopen("LCS.out","w",stdout);
	char a[4001],b[4001];
	gets(a);
	gets(b);
	l1=strlen(a);
	l2=strlen(b);
	for(i=1;i<=l1;i++)
	for(j=1;j<=l2;j++)
	{
		dp[i][j]=max(dp[i-1][j]+1,dp[i][j-1]+1);
		if(a[i-1]==b[j-1]) dp[i][j]=max(dp[i-1][j-1]+1,dp[i][j]);  
	}
	printf("%d",dp[l1][l2]);
	return 0;
}
