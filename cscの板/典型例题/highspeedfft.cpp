#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
int map[51][51],i,j,i1,j1,j2,i2,m,n,dp[51][51][51][51];
int main()
{
	bool a[51][51]={true};
	//freopen("LCS.in","r",stdin);
	//freopen("LCS.out","w",stdout);
    scanf("%d%d",&m,&n);
	for(i=1;i<=m;i++)
	   for(j=1;j<=n;j++)
	   	scanf("%d",&map[i][j]);
	for(i1=1;i1<=n;i1++)
	for(j1=1;j1<=m;j1++)
	for(i2=n;i2>=1;i2--)
	for(j2=m;j2>=1;j2--)
	{
	    dp[i1][j1][i2][j2]=max(dp[i1-1][j1][i2][j2],dp[i1][j1-1][i2][j2])+max(dp[i1][j1][i2-1][j2],dp[i1][j1][i2][j2-1])+map[i1][j1]+map[i2][j2];
	    if(i1==i2&&j1==j2)
	        dp[i1][j1][i2][j2]=map[i1][j1]+map[i2][j2];
	}
	printf("%d ",dp[m][n][1][1]);
	return 0;
}
