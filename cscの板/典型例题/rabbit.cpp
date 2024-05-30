#include<stdio.h>
#include<iostream>
using namespace std;
int i,j,n,s[204]={0},y,dpmin[202][202],dpmax[202][202],w;
int main()
{
	freopen("rabbit.in","r",stdin);
//	freopen("rabbit.out","w",stdout);
    scanf("%d",&n);
    for(i=1;i<=n;i++)
	{
    scanf("%d",&s[i]);
    s[i]=s[i-1]+s[i];
    }
    for(i=1;i<=n;i++)
//    for(j=1;j<=n;j++)
//    dpmin[i][j]=99999;
    for(i=n+1;i<=2*n;i++)
    s[i]=s[i-n+1];
    for( i=1;i<=n;i++)dpmax[i][i]=0;
    for( i=1;i<=n;i++)dpmin[i][i]=0;
    for(i=n;i>=1;i--)
    for(j=i+1;j<=i+n-1;j++)
		for(y=i;y<=j-1;y++)
		{
			if(s[j]-s[i-1]>=0) w=s[j]-s[i-1];else w=s[i-1]-s[j];
		dpmin[i][j]=min(dpmin[i][j],dpmin[i][y]+dpmin[y+1][j]+w);
		dpmax[i][j]=max(dpmax[i][j],dpmax[i][y]+dpmax[y+1][j]+w);	
		}
    printf("%d\n%d",dpmin[1][n-],dpmax[1][n+1]);
	return 0;
}
