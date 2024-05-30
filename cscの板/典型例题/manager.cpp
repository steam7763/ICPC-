#include<iostream>
#include<cstdio>
#include<cstring>
#define Ls(x) x<<1
#define Rs(x) x<<1|1
using namespace std;
const int MAXN =120010;
struct Edge
{
	int from,val,to,nxt;
} E[MAXN*2];
struct Tre
{
	int l,r,len;long long val,vis;
}tree[MAXN*4];
int head[MAXN],tot;
void Edge_add(int x,int y)
{
	++tot;
	E[tot].from=x;
	E[tot].to=y;
	E[tot].nxt=head[x];
	head[x]=tot;
}
int a[MAXN];
int top[MAXN],dep[MAXN],rank[MAXN],cnt\
,fa[MAXN],dfn[MAXN],size[MAXN],son[MAXN],use[MAXN];
void dfs1(int u)
{
	dep[u]=dep[fa[u]]+1;
	size[u]=1;
	for(int i=head[u];i;i=E[i].nxt)
	{
		int v=E[i].to;
		if(v==fa[u])continue;
		fa[v]=u;
		dfs1(v);
		size[u]+=size[v];
		if(size[son[u]]<size[v])son[u]=v;
	}
}
void dfs2(int u,int pos)
{
	dfn[u]=++cnt;
	top[u]=pos;
	rank[dfn[u]]=u;
	if(!son[u])return ;
	dfs2(son[u],pos);
	for(int i=head[u];i;i=E[i].nxt)
	{
		int v=E[i].to;
		if(v==fa[u]||v==son[u])continue;
		dfs2(v,v);
	}
}
void push_up(int x)
{
	tree[x].val=tree[Rs(x)].val + tree[Ls(x)].val;
}
void push_down(long long x)
{
	if(tree[x].vis>0)
	{
		tree[x*2].val=tree[x*2].r-tree[x*2].l+1;
		tree[x*2+1].val=tree[x*2+1].r-tree[x*2+1].l+1;
		tree[x*2].vis=tree[x].vis;
		tree[x*2+1].vis=tree[x].vis;
	}
	else if(tree[x].vis<0){
		tree[x*2].val=0;
		tree[x*2+1].val=0;
		tree[x*2].vis=tree[x].vis;
		tree[x*2+1].vis=tree[x].vis;
	}
	tree[x].vis=0;
}
void build(long long x,long long l,long long r)
{
	tree[x].l=l;
	tree[x].r=r;
	tree[x].len=r-l+1;
	if(l==r)
	{
		tree[x].val=0;
		return ;
	}
	long long mid=(l+r)>>1;
	build (Ls(x),l,mid);
	build (Rs(x),mid+1,r);
	push_up(x);
}
void update(int x,int l,int r,int val)
{
	if(l<=tree[x].l&&tree[x].r<=r)
	{
		if(val>0)
		{
			tree[x].val=tree[x].len;
		}
		if(val<0)
		{
			tree[x].val=0;
		}
		tree[x].vis=val;
		return ;
	}
	push_down(x);
	long long mid=(tree[x].l+tree[x].r)>>1;
	if(l<=mid)update(Ls(x),l,r,val);
	if(r>mid)update(Rs(x),l,r,val);
	push_up(x);
}
long long querry(int x,int l,int r)
{

	if(l<=tree[x].l&&tree[x].r<=r)
	{
		return tree[x].val;
	}
	push_down(x);
	long long re=0;
	int mid=(tree[x].l+tree[x].r)>>1;
	if(l<=mid)re=re+querry(Ls(x),l,r);
	if(r>mid)re=re+querry(Rs(x),l,r);
	return re;
}
int n,m;
int main()
{
	#ifndef DEBUG
	freopen("manager.in","r",stdin);
	freopen("manager.out","w",stdout);
	#endif
	scanf("%d",&n);
	for(int i=2;i<=n;i++)
	{
		int x,y,k;
		scanf("%d",&x);
		Edge_add(x+1,i);
	}	
	dfs1(1);
	dfs2(1,1);	
	build(1,1,n);
		scanf("%d",&m);
	for(int i=1;i<=m;i++)
	{
		char s[11];
		int ans=0,x;
		cin>>s;
		if(s[0]=='i')
		{
			scanf("%d",&x);++x;
			int now=x;
			while(x)
			{
				ans+=querry(1,dfn[top[x]],dfn[x]);
        	  	update(1,dfn[top[x]],dfn[x],1);
        	  	x=fa[top[x]];	
			}
			cout<<dep[now]-ans<<endl;
		}
		else 
		{
			scanf("%d",&x);
			x++;
			ans=querry(1,dfn[x],size[x]+dfn[x]-1);
			update(1,dfn[x],size[x]+dfn[x]-1,-1);
			cout<<ans<<endl;
		}
	}
	return 0;
}
/*
7
0 0 0 1 1 5
5
i 5
i 6
u 1
i 4
u 0
*/
