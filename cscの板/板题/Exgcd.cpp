#include<bits/stdc++.h>
#define rg register
using namespace std;
void Exgcd(int a,int b,int &x,int &y)
{
	if(b==0)
	{
		x=1;
		y=0;
	}
	else
	{
		Exgcd(b,a%b,x,y);
		int x1=x,y1=y;
		x=y1;
		y=(x1-(a/b)*y1);
	}
}
signed main()
{
	int a,b,x,y;
	scanf("%d%d",&a,&b);
	Exgcd(a,b,x,y);
	printf("%d %d",x,y);
	return 0;
}
