#include<stdio.h>
int sum[1001][2],i,j,n,m,sun;
double mapl[101][101]= {0},mapr[101][101]= {0},dp[101][101];
int main()
{
	freopen("glass.in","r",stdin);
	freopen("glass.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(i=0; i<=n+1; i++)
	for(j=0; j<=m+1; j++)
	{
		dp[i][j]=0;
	}
	dp[1][1]=1;
	for(i=1; i<=n; i++)
	for(j=1; j<=m; j++)
	{
		scanf("%lf",&mapl[i][j]);
		mapr[i][j]=1.0-mapl[i][j];
	}
	scanf("%d",&sun);
	for(i=1; i<=sun; i++)
		scanf("%d%d",&sum[i][1],&sum[i][2]);
	for(i=1; i<=n; i++)
	for(j=1; j<=m; j++)
	{
		if(i!=1||j!=1)
			dp[i][j]=dp[i-1][j]*mapl[i-1][j]+dp[i][j-1]*mapr[i][j-1];
	}
	for(i=1; i<=sun; i++)
		printf("%0.2lf\n",dp[sum[i][1]][sum[i][2]]);
	return 0;
}

