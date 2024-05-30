#include<bits/stdc++.h>
#define rg register
#define Ls(x) x<<1
#define Rs(x) x<<1|1
//#define int long long
using namespace std;
const int MAXN=1001001;
int n,m;
int a[MAXN];
template <typename T> inline void read(T &x)
{
    T ch=getchar(),f=1;
    for(x=0;!isdigit(ch);ch=getchar()) if(ch=='-') f=-1;
    for(;isdigit(ch);ch=getchar()) x=(x<<3)+(x<<1)+ch-'0';
    x*=f;
}
template <typename T> inline void print(T x)
{
    if(x<0) putchar('-'),x=-x;
    if(x>9) print(x/10);
    putchar(x%10+'0');
}
struct Tree
{
    int l,r,len,val,ma,mi,add;
}t[MAXN<<2];
inline void push_up(rg int x)
{
    t[x].ma=max(t[Rs(x)].val,t[Ls(x)].val);
    t[x].mi=min(t[Rs(x)].val,t[Ls(x)].val);
}
inline void push_down(rg int x)
{
    if(t[x].add==0)
        return ;
    t[Ls(x)].val = t[Ls(x)].len * t[x].add + t[Ls(x)].val;
    t[Rs(x)].val = t[Rs(x)].len * t[x].add + t[Rs(x)].val;

    t[Ls(x)].ma  = t[Ls(x)].ma + t[x].add;
    t[Rs(x)].ma  = t[Rs(x)].ma + t[x].add;

    t[Ls(x)].ma  = t[Ls(x)].mi + t[x].add;
    t[Rs(x)].ma  = t[Rs(x)].mi + t[x].add;

    t[Ls(x)].add = t[Ls(x)].add + t[x].add;
    t[Rs(x)].add = t[Rs(x)].add + t[x].add;

    t[x].add = 0;
}
inline void build(rg int x,rg int l,rg nt r)
{
    t[x].l=l,t[x].r=r,t[x].len=r-l+1;
    t[x].add=0;
    if(l==r)
    {
        t[x].val = a[l];
        t[x].ma  = a[l];
        t[x].mi  = a[l];
        return ;
    }
    int mid=(l+r)>>1;
    build(Ls(x),l,mid);
    build(Rs(x),mid+1,r);
    push_up(x);
}
inline void update(rg int x,rg int L,rg int R,rg int v)
{
    int l=t[x].l,r=t[x].r;
    if(R<l||r<L)
        return ;
    if(L<=l&&r<=R)
    {
        t[x].val += t[x].len * v;
        t[x].add += v;
        t[x].ma  += v;
        t[x].mi  += v;
    }
    push_down(x);
    update(Ls(x),L,R,v);
    update(Rs(x),L,R,v);
    push_up(x);
}
inline int query(rg int x,rg int L,rg int R,rg int w)
{
    int l=t[x].l,r=t[x].r;
    if(R < l || r < L || t[x].ma < w)
        return ;
    if(L <= l && r <= R && t[x].mi > w)
        return t[x].len;
    push_down(x);
    return query(Ls(x),L,R,w)+query(Rs(x),L,R,w);
}
signed main()
{
//看数据范围，看数组，long long，freopen
    read(n),read(m);
    for(int i=1;i<=n;i++)
        read(a[i]);
    char s;
    int l,r,w;
    for(int i=1;i<=m;i++)
    {
        scanf("%c%d%d%d",&s,&l,&r,&w);
        if(s=='M')
            update(l,r,w);
        if(s=='A')
            printf("%d\n",query(l,r,w));
    }
//看数据范围，看数组，long long，freopen
	return 0;
}
