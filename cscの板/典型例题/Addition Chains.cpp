#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<queue>
#include<algorithm>
#define rg register
using namespace std;
int n,cnt,a[1000];
bool flag=true,f=true;
void dfs(int l)
{
	if(a[l]>n)
		return;
	if(l>=cnt)
	{
		if(a[l]==n)
		{
			if(f==true)
			{
				for(rg int i=1;i<=l;i++)
					printf("%d ",a[i]);
				printf("\n");
				f=false;
			}
			flag=false;
		}
		return;
	}
	for(rg int i=1;i<=l;i++)
	for(rg int j=1;j<=i;j++)
	{
		if(a[i]+a[j]>a[l])
		{
			a[l+1]=a[i]+a[j];
			dfs(l+1);
		}
	}
}
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	scanf("%d",&n);
	while(n!=0)
	{
		memset(a,0,sizeof(a));
		a[1]=1;
		cnt=1;
		while(flag==true)
		{
			dfs(1);
			cnt++;
		}
		f=true;
		flag=true;
		scanf("%d",&n);
	}
	return 0;
}
