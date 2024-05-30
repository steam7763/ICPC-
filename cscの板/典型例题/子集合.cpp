#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int MAXN=1000;
int n,m,a[MAXN],ans;
bool ll[MAXN];
void search(int k)
{
	if(k>n)
	{
		for(int i=1;i<=n;i++)
		{
			if(ll[i])
				printf("%d ",a[i]);
		}
//		ans++;
		printf("\n");
		return;
	}
	ll[k]=true;
	search(k+1);
	ll[k]=false;
	search(k+1);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	printf("\n");
	search(1);
//	printf("%d",ans-1);
}
