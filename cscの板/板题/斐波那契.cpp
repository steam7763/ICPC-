#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	int a[10000];
	a[1]=1,a[2]=1;
	int n;
	scanf("%d",&n);
	for(int i=3;i<=n;i++)
		a[i]=a[i-1]+a[i-2];
	printf("%d",a[n]);
}
