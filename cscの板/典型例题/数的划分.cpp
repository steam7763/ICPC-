#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<queue>
#include<algorithm>
#define MAXN 100000
#define rg register
using namespace std;
int n,k,ans,a[MAXN];
void dfs(int x)
{
	if(n==0)
		return;
	if(x==k)
	{
		ans++;
		return;
	}
	for(int i=a[x-1];i<=n/(k-x+1);i++)
	{
		a[x]=i;
		n-=i;
		dfs(x+1);
		n+=i;
	}
}
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	scanf("%d%d",&n,&k);
	a[0]=1;
	dfs(1);
	printf("%d",ans);
	return 0;
}
