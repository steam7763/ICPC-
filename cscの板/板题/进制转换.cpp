#include<cstdio>
using namespace std;
int pp(int,int);
int a[10000],top=0,dd,n;
int main()
{
	scanf("%d%d",&n,&dd);
	pp(n,dd);
	printf("\n");
	return main();
}
int pp(int N,int d)
{
	do
	{
		top++;
		a[top]=N%d;
		N/=d;
	}while(N!=0); 
	do
	{
		printf("%d",a[top]);
		top--;
	}while(top>0);
}
