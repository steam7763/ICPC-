#include<bits/stdc++.h>
#define rg register
#define Ls(x) x<<1
#define Rs(x) x<<1|1
#define int long long
using namespace std;
const int MAXN=200100;
int n,m,p,tot,num,root;
int Rank[MAXN],dep[MAXN],Size[MAXN]\
,dfn[MAXN],son[MAXN],fa[MAXN],\
top[MAXN],a[MAXN],head[MAXN];
struct Edge
{
	int u,v,w,nex;
}E[MAXN<<2];
struct Tree
{
	int l,r,len,val,add;
}t[MAXN<<2];
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
inline void Add(int u,int v)
{
	tot++;
	E[tot].u=u;
	E[tot].v=v;
	E[tot].nex=head[u];
	head[u]=tot;
}
inline void dfs1(int u)
{
	Size[u]=1;
	dep[u]=dep[fa[u]]+1;
	for(int i=head[u];i;i=E[i].nex)
	{
		int v=E[i].v;
		if(v==fa[u]) continue;
		fa[v]=u;
		dfs1(v);
		Size[u]+=Size[v];
		if(Size[son[u]]<Size[v]) son[u]=v;
	}
}
inline void dfs2(int u)
{
	dfn[u]=++num;
	Rank[num]=u;
	if(son[u])
	{
		top[son[u]]=top[u];
		dfs2(son[u]);
	}
	for(int i=head[u];i;i=E[i].nex)
	{
		int v=E[i].v;
		if(!top[v])
		{
			top[v]=v;
			dfs2(v);
		}
	}
}
inline void push_up(int x)
{
	t[x].val=(t[Ls(x)].val+t[Rs(x)].val)%p;
}
inline void push_down(int x)
{
	if(t[x].add==0)
		return ;
	t[Ls(x)].val=(t[x].add*t[Ls(x)].len+t[Ls(x)].val)%p;
	t[Rs(x)].val=(t[x].add*t[Rs(x)].len+t[Rs(x)].val)%p;

	t[Ls(x)].add=(t[x].add+t[Ls(x)].add)%p;
	t[Rs(x)].add=(t[x].add+t[Rs(x)].add)%p;

	t[x].add=0;
	return ;
}
inline void build(int x,int l,int r)
{
	t[x].l=l,t[x].r=r,t[x].len=r-l+1,t[x].add=0;
	if(l==r)
	{
		t[x].val = a[Rank[l]];
		return ;
	}
	int mid=(l+r)>>1;
	build(Ls(x),l,mid);
	build(Rs(x),mid+1,r);
	push_up(x);
}
inline void update(int x,int L,int R,int v)
{
	int l=t[x].l,r=t[x].r;
	if(R<l||r<L)
		return ;
	if(L<=l&&r<=R)
	{
		t[x].val = (t[x].val + t[x].len*v)%p;
		t[x].add = (t[x].add + v)%p;
		return ;
	}
	push_down(x);
	update(Ls(x),L,R,v);
	update(Rs(x),L,R,v);
	push_up(x);
}
inline int query(int x,int L,int R)
{
	int l=t[x].l,r=t[x].r;
	
	if(R<l||r<L)
		return 0;
	if(L<=l&&r<=R)
		return t[x].val%p;
	push_down(x);
	
	return (query(Ls(x),L,R)+query(Rs(x),L,R))%p;
}
inline void LCA_add(int x,int y,int v)
{
	while(top[x]!=top[y])
	{
		if(dep[top[x]]<dep[top[y]]) swap(x,y);
		update(1,dfn[top[x]],dfn[x],v);
		x=fa[top[x]];
	}
	if(dep[x]>dep[y]) swap(x,y);
	update(1,dfn[x],dfn[y],v);
}
inline void Son_add(int x,int v)
{
	update(1,dfn[x],dfn[x]+Size[x]-1,v);
}
inline int LCA_sum(int x,int y)
{
    int ans=0ll;
	while(top[x]!=top[y])
    {
        if(dep[top[x]]<dep[top[y]]) swap(x,y);
        ans+=query(1,dfn[top[x]],dfn[x]);
        x=fa[top[x]];
    }
    if(dep[x]>dep[y]) swap(x,y);
    ans+=query(1,dfn[x],dfn[y]);
    return ans%p;
}
inline int Son_sum(int x)
{
	return query(1,dfn[x],dfn[x]+Size[x]-1);
}
signed main()
{
//	freopen("testdata.in","r",stdin);
//	freopen("testdata.ans","w",stdout);
	read(n),read(m),read(root),read(p);
	for(int i=1;i<=n;i++)
		read(a[i]);
	for(int i=1,x,y;i<n;i++)
	{
		read(x),read(y);
		Add(x,y);
		Add(y,x);
	}
	dfs1(root);
	top[root]=root;
	dfs2(root);
	build(1,1,n);
	for(int i=1,opt,x,y,z;i<=m;i++)
	{
//		cerr<<"!";
		read(opt);
		if(opt==1)
		{
			read(x),read(y),read(z);
			LCA_add(x,y,z);
			continue;
		}
		if(opt==2)
		{
			read(x),read(y);
			print(LCA_sum(x,y));
			puts("");
			continue;
		}
		if(opt==3)
		{
			read(x),read(y);
			Son_add(x,y);
			continue;
		}
		if(opt==4)
		{
			read(x);
			print(Son_sum(x));
			puts("");
			continue;
		}
	}
	return 0;
}
