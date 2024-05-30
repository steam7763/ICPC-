#include<bits/stdc++.h>
#define rg register
//#define int long long
using namespace std;
const int MAXN=600100;
int n,m,tot,ans,num;
int head[MAXN],dfn[MAXN],\
low[MAXN],st[MAXN],fa[MAXN];
bool vis[MAXN];
struct Edge
{
    int u,v,nex;
    bool cut;
}E[MAXN<<1];
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
    vis[u]=1;
    for(int i=head[u];i;i=E[i].nex)
    {
        int v=E[i].v;
        if(v==fa[u])
            continue;
        fa[v]=u;
        if(!dfn[v])
        {
            Tarjan(v);
            low[u]=min(low[u],low[v]);
            if(dfn[u]<low[v])
                ans++,E[i].cut=1;
        }
        else
            low[u]=min(dfn[v],low[u]);
    }
}
void init()
{
    tot=ans=num=0;
    memset(E,0,sizeof(E));
    memset(head,0,sizeof(head));
    memset(dfn,0,sizeof(dfn));
    memset(fa,0,sizeof(fa));
    memset(low,0,sizeof(low));
    memset(vis,0,sizeof(vis));
}
signed main()
{
//	#ifndef DEBUG
	freopen("route.in","r",stdin);
	freopen("route.out","w",stdout);
//	#endif //DEBUG
	scanf("%d%d",&n,&m);
	while(n!=0&&m!=0)
    {
        init();
        for(int i=1,x,y;i<=m;i++)
        {
            scanf("%d%d",&x,&y);
            Add(x,y);
            Add(y,x);
        }
        for(int i=1;i<=n;i++)
            if(!dfn[i])
            {
            	fa[i]=i;
            	Tarjan(i);
			}
        printf("%d\n",ans);
        scanf("%d%d",&n,&m);
    }
	return 0;
}
