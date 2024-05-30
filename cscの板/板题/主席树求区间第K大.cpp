#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#define blank putchar(' ')
#define line putchar('\n')
using namespace std;
const int maxn=200001;
struct Segment_Tree
{
	int l,r,v;
}tree[maxn*4];
int n,m,a[maxn],ls[10*maxn],rs[10*maxn],cnt=1,tree_head[maxn],maxa;
void push_up(int);
void build(int,int,int);
void ins(int &,int,int);
int query(int,int,int,int);
void read(int &);
void print(int);
signed main()
{
//	freopen("tree.in","r",stdin);
//	freopen("tree.out","w",stdout);
	read(n);read(m);
	for(int i=1;i<=n;++i) read(a[i]),maxa=max(maxa,a[i]);
	build(1,1,maxa);
	tree_head[0]=1;
	for(int i=1;i<=n;++i)
	{
		tree_head[i]=cnt+1;
		int t=tree_head[i-1];
		ins(t,a[i],1);
	}
	while(m--)
	{
		int l,r,k;
		scanf("%d%d%d",&l,&r,&k);
		printf("%d\n",query(tree_head[l-1],tree_head[r],k,0));
	}
	return 0;
}
void push_up(int id)
{
	tree[id].v=tree[ls[id]].v+tree[rs[id]].v;
}
void build(int id,int l,int r)
{
	tree[id].l=l,tree[id].r=r;
	cnt++;
	if(l==r)
	{
		tree[id].v=0;
		return ;
	}
	int mid=(l+r)>>1;
	ls[id]=id<<1;
	rs[id]=id<<1|1;
	build(ls[id],l,mid);
	build(rs[id],mid+1,r);
	push_up(id);
}
void ins(int &id,int pos,int val)
{
	int l=tree[id].l,r=tree[id].r;
	tree[++cnt].v=tree[id].v,ls[cnt]=ls[id],rs[cnt]=rs[id],tree[cnt].l=tree[id].l,tree[cnt].r=tree[id].r;
	id=cnt;
	if(l==r)
	{
		tree[id].v+=val;
		return ; 
	}
	int mid=(l+r)>>1;
	if(pos<=mid) ins(ls[id],pos,val);
	else ins(rs[id],pos,val);
	push_up(id);
}
int query(int x,int y,int k,int sum)
{
	int l=tree[y].l,r=tree[y].r;
	if(l==r) return tree[x].l;
	if(sum+tree[ls[y]].v-tree[ls[x]].v>=k&&ls[x]&&ls[y]) return query(ls[x],ls[y],k,sum);
	if(sum+tree[ls[y]].v-tree[ls[x]].v<k) return query(rs[x],rs[y],k,sum+tree[ls[y]].v-tree[ls[x]].v);
}
void read(int &rd)
{
	int re=0,fu=1;char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-') fu=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		re=(re<<3)+(re<<1)+ch-'0';
		ch=getchar();
	}
	rd=re*fu;
}
void print(int pt)
{
	if(pt<0) putchar('-'),pt=-pt;
	if(pt>=10) print(pt/10);
	putchar(pt%10+'0');
}
