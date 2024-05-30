#include<bits/stdc++.h>
#include<iostream>
#define rg register
#define int long long
using namespace std;
const int MAXN=100100;
int p,T,n,m;
int a[MAXN];
template <typename T> inline void read(T &x)
{
	T f=1,ch=getchar();
	for(x=0;!isdigit(ch);ch=getchar()) if(ch == '-') f=-1;
	for(;isdigit(ch);ch=getchar()) x = (x<<3) + (x<<1) + ch - '0';
	x*=f;
}
template <typename T> inline void print(T x)
{
	if(x<0) putchar('-'),x=-x;
	if(x>9) print(x/10);
	putchar(x%10+'0');
}
inline void init()
{
	memset(a,0,sizeof(0));
}
inline int power(int y,int z,int p)
{
	int ans=1;y%=p;
    for(int i = z; i ; i >>= 1,y = y * y % p)
		if(i&1)ans=ans*y%p;
    return ans;
}
inline int C(int n,int m)
{
    if(m>n)
		return 0;
    return ((a[n] * power(a[m],p - 2, p)) % p * power(a[ n - m ], p - 2 , p) % p);
}
inline int Lucas(int n,int m)
{
    if(!m)
		return 1;
    return C(n  % p ,m % p) * Lucas(n / p,m / p)% p;
}
signed main()
{
	read(T);
    while(T--)
	{
		init();
        read(n),read(m),read(p);
        a[0]=1;
        for(int i = 1; i <= p; i++)
			a[i] = (a[i - 1] * i) % p;
        print(Lucas(n+m,n));
        puts("");
    }
}
//Â¬¿¨Ë¹¶¨Àí£ºC(n,m)%p=C(n/p,m/p)*C(n%p,m%p)
