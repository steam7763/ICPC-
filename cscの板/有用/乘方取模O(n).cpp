#include<iostream>
using namespace std;
int main()
{
	int a,b,k,mod;
	scanf("%d%d%d",&a,&b,&mod);
	k=a;
	for(int i=1;i<b;i++)
	{
		a+=(k-1)*a;
		while(a-mod>0)
			a-=mod;
	}
	printf("%d",a);
}
