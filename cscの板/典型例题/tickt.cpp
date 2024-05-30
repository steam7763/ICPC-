#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
#define mod 1000007
#define MAXN 10010
#define rg register
using namespace std;
template <typename T> inline void in(T &a)
{
	T ch=getchar(),f=1;
	for(a=0;!isdigit(ch);ch=getchar())if(ch=='-')f=-1;
	for(;isdigit(ch);ch=getchar())a=(a<<3)+(a<<1)+ch-'0';
	a*=f;
}
template <typename T> inline void print(T x)
{
	if(x<0) putchar('-'),x=-x;
	if(x>9) print(x/10);
	putchar(x%10+'0');
}
int goal[MAXN],head[mod],nex[MAXN],a,now;
inline bool Judge(int x)
{
	int z=x%mod;
	for(rg int i=head[z];i;i=nex[i])
	{
		if(goal[z]==x) return 1;
	}
	goal[++now]=x;
    nex[now]=head[z];
	head[z]=now;
	return 0;
}
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	while(1)
	{
		in(a);
		if(Judge(a))
		{
			printf("Yes\n");
		}
		else
		{
			printf("No\n");
		}
	}
	return 0;
}

