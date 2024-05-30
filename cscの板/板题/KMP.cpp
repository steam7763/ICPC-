#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
const int MAXN=1100000;
int n,m,nex[MAXN],j;
char a[MAXN],b[MAXN];

using namespace std;

void pre()
{
	nex[1]=0;
	j=0;
	for(int i=1;i<m;i++)
	{
		while(j>0&&b[j+1]!=b[i+1]) j=nex[j];
		if(b[j+1]==b[i+1]) j++;
		nex[i+1]=j;
	}
}

int main()
{
	scanf("%s",a+1);
	scanf("%s",b+1);
	n=strlen(a+1);
	m=strlen(b+1);
	pre();
	j=0;
	for(int i=0;i<n;i++)
	{
		while(j>0&&b[j+1]!=a[i+1]) j=nex[j];
		if(b[j+1]==a[i+1]) j++;
		if(j==m)
		{
			printf("%d\n",i+1-m+1);
			j=nex[j];
		}
	}
	for(int i=1;i<=m;i++)
		printf("%d ",nex[i]);
	return 0;
}
