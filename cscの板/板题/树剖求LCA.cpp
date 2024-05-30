#include <bits/stdc++.h>
#define rg register
//#define int long long
using namespace std;
const int MAXN=1001000;
int tot,n,m,num,q,s;
int head[MAXN],son[MAXN],fa[MAXN],\
Size[MAXN],dfn[MAXN],top[MAXN],dep[MAXN],\
Rank[MAXN];
struct Edge
{
    int u,v,nex;
}E[MAXN];
void Add(int u,int v)
{
    tot++;
    E[tot].u=u;
    E[tot].v=v;
    E[tot].nex=head[u];
    head[u]=tot;
}
void dfs1(int u)
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
void dfs2(int u)
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
inline int LCA(int x,int y)
{
	int fx=top[x],fy=top[y];
	while(fx!=fy)
    {
        if(dep[fx]<dep[fy]) swap(fx,fy),swap(x,y);
        x=fa[fx],fx=top[x];
    }
    if(dep[x]>dep[y]) return y;
    return x;
}
signed main()
{
    scanf("%d%d%d",&n,&q,&s);
    for(int i=1,x,y;i<n;i++)
    {
        scanf("%d%d",&x,&y);
        Add(x,y);
        Add(y,x);
    }
    dfs1(s);
    top[s]=s;
    dfs2(s);
    for(int i=1,x,y;i<=q;i++)
    {
        scanf("%d%d",&x,&y);
        printf("%d\n",LCA(x,y));
    }
}
