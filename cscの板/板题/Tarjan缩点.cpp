#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=800100;
struct Edge{
	int u,v,nex;
}E[MAXN];
int n,m,tot,top,root,num,col;
int head[MAXN],dfn[MAXN],low[MAXN]\
,st[MAXN],co[MAXN];
void Add(int u,int v)
{
	tot++;
	E[tot].u=u;
	E[tot].v=v;
	E[tot].nex=head[u];
	head[u]=tot;
}
void Tarjan(int u)
{
	dfn[u]=low[u]=++num;
	st[++top]=u;
	for(int i=head[u];i;i=E[i].nex)
	{
		int v=E[i].v;
		if(!dfn[v])
		{
			Tarjan(v);
			low[u]=min(low[v],low[u]);
		}
		else if(!co[v])
			low[u]=min(low[u],dfn[v]);
	}
	if(low[u]==dfn[u])
	{
		co[u]=++col;
		while(st[top]!=u)
		{
			co[st[top]]=col;
			top--;
		}
		top--;
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1,x,y;i<=m;i++)
	{
		scanf("%d%d",&x,&y);
		Add(x,y);
	}
	for(int i=1;i<=n;i++)
		if(!dfn[i])
			Tarjan(i);
	
	return 0;
}
