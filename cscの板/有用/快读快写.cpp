#include<bits/stdc++.h>
using namespace std;
/*
template <typename T> inline void read(T &a)
{
	T ch = getchar(), f = 1;
	for(a = 0; !isdigit(ch); ch = getchar()) if(ch == '-') f = -1;
	for( ; isdigit(ch); ch = getchar()) a = (a << 3) + (a << 1) + ch - '0';
	a *= f;
}
*/
/*
inline int read()
{
	int num = 0, f = 1, ch;
	for(; !isdigit(ch); ch = getchar()) if(ch == '-') f = -1;
	for(; isdigit(ch); ch = getchar()) num = (num << 3) + (num << 1) + ch - '0';
	return num * f;
}

inline void print(int x)
{

	if(x < 0) putchar('-'), x = -x;
	if(x > 9) print(x / 10);
	putchar(x % 10 + '0');
}
*/
/*
template <typename T> inline void read(T &x)
{
	char c = getchar();
	bool f = false;
	for(x = 0; !isdigit(c); c = getchar())
		if(c == '-')
			f = true;
	for(; isdigit(c); c = getchar())
		x =( (x << 3) + (x << 1) + c - '0');
	if(f)
		x = -x;
}

template <typename T> inline void print(T x)
{
	if(x < 0) putchar('-'), x = -x;
	if(x > 9) print(x / 10);
	putchar(x % 10 + '0');
}
*/

template <typename T>inline void read(T &a)
{
	T ch=getchar(),f=1;
	for(a=0;!isdigit(ch);ch=getchar()) if(ch=='-') f=-1;
	for(;isdigit(ch);ch=getchar()) a=(a<<3)+(a<<1)+ch-'0';
	a*=f;
}
template <typename T>inline void print(T x)
{
	if(x<0) putchar('-'),x=-x;
	if(x>9) print(x/10);
	putchar(x%10+'0');
}

int main()
{
	long long n;
	read(n);
//	n=read();
	print(n);
}
/*
#include<cctype>
inline int read()
{
    int X=0,w=0; char ch=0;
    while(!isdigit(ch)) {w|=ch=='-';ch=getchar();}
    while(isdigit(ch)) X=(X<<3)+(X<<1)+(ch^48),ch=getchar();
    return w?-X:X;
}
*/
