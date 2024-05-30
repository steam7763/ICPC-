#include<bits/stdc++.>
#define rg register
//#define int long long
using namespace std;
const int MAXN=100100;
int n,m,num;
int head[MAXN],son[MAXN],siz[MAXN],\
fa[MAXN],dep[MAXN],dfn[MAXN],top[MAXN];
struct Edge
{
    int v,w,nex;
}E[MAXN<<1];
void dfs1(int u)
{
    siz[u]=1;
    dep[u]=dep[fa[u]]+1;
    for(int i=head[u];i;i=E[i].nex)
    {
        int v=E[i].v;
        if(v==fa[u]) continue;
        fa[v]=u;
        dfs1(v);
        siz[u]+=siz[v];
        if(siz[son[u]]<siz[v]) son[u]=v;
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
int LCA(int x,int y)
{

}
signed main()
{




}
