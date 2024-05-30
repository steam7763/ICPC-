#include<bits/stdc++.h>
#define rg register
#define Ls(x) x<<1
#define Rs(x) x<<1|1
#define int long long
using namespace std;
const int MAXN=1001000;
int n,m,p;
int a[MAXN];
struct Tree
{
    int l,r,len,val,add,mul;
}t[MAXN<<2];
void push_up(int x)
{
    t[x].val=(t[Ls(x)].val+t[Rs(x)].val)%p;
    return;
}
void push_down(int x)
{
    if(t[x].add==0&&t[x].mul==1)
        return ;
    t[Ls(x)].val=(t[Ls(x)].val*t[x].mul+t[Ls(x)].len*t[x].add)%p;
    t[Rs(x)].val=(t[Rs(x)].val*t[x].mul+t[Rs(x)].len*t[x].add)%p;

    t[Ls(x)].add=(t[Ls(x)].add*t[x].mul+t[x].add)%p;
    t[Rs(x)].add=(t[Rs(x)].add*t[x].mul+t[x].add)%p;

    t[Ls(x)].mul=(t[Ls(x)].mul*t[x].mul)%p;
    t[Rs(x)].mul=(t[Rs(x)].mul*t[x].mul)%p;

    t[x].add=0;
    t[x].mul=1;
}
void build(int x,int l,int r)
{
    t[x].l=l,t[x].r=r,t[x].len=r-l+1;
    t[x].add=0;t[x].mul=1;
    if(l==r)
    {
        t[x].val=a[l];
        return;
    }
    int mid=(l+r)>>1;
    build(Ls(x),l,mid);
    build(Rs(x),mid+1,r);
    push_up(x);
}
void update_add(int x,int L,int R,int v)
{
    int l=t[x].l,r=t[x].r;
    if(R<l||r<L)
        return;
    if(L<=l&&r<=R)
    {
        t[x].val=(t[x].val+t[x].len*v)%p;
        t[x].add=(t[x].add+v)%p;
        return ;
    }
    push_down(x);
    update_add(Ls(x),L,R,v);
    update_add(Rs(x),L,R,v);
    push_up(x);
}
void update_mul(int x,int L,int R,int v)
{
    int l=t[x].l,r=t[x].r;
    if(R<l||r<L)
        return ;
    if(L<=l&&r<=R)
    {
        t[x].val=(t[x].val*v)%p;
        t[x].add=(t[x].add*v)%p;
        t[x].mul=(t[x].mul*v)%p;
        return ;
    }
    push_down(x);
    update_mul(Ls(x),L,R,v);
    update_mul(Rs(x),L,R,v);
    push_up(x);
}
int query(int x,int L,int R)
{
    int l=t[x].l,r=t[x].r;
    if(R<l||r<L)
        return 0;
    if(L<=l&&r<=R)
        return t[x].val;
    push_down(x);
    return (query(Ls(x),L,R)+query(Rs(x),L,R))%p;
}
signed main()
{
//	#ifndef DEBUG
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	#endif //DEBUG
    scanf("%lld%lld%lld",&n,&m,&p);
    for(int i=1;i<=n;++i)
        scanf("%lld",&a[i]);
    build(1,1,n);
    int opt,l,r,v;
    while(m--)
    {
        scanf("%lld",&opt);
        if(opt==1)
        {
            scanf("%lld%lld%lld",&l,&r,&v);
            update_mul(1,l,r,v);
            continue;
        }
        if(opt==2)
        {
            scanf("%lld%lld%lld",&l,&r,&v);
            update_add(1,l,r,v);
            continue;
        }
        if(opt==3)
        {
            scanf("%lld%lld",&l,&r);
            printf("%lld\n",query(1,l,r));
        }
    }
	return 0;
}

