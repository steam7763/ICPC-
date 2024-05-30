#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n;
bool v[1000000];
int main()
{
	scanf("%d",&n);
	for(int i=2;i<=n;i++)
	{
		if(v[i])
			continue;
		printf("%d ",i);
		for(int j=i;j<=n/i;j++)
			v[i*j]=1;
	}
	return 0;
}

