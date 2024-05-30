#include<bits/stdc++.h>
#define rg register
//#define int long long
using namespace std;
const int MAXN=100100;
int n,m,ans;
int fa[MAXN];
struct Edge
{
    int u,v,w,nex;
}E[MAXN<<2];
int find_fa(int x)
{
    return fa[x]==x ? x : fa[x]=find_fa(fa[x]);
}
bool cmp(Edge a,Edge b)
{
    return a.w<b.w;
}
void Kruscal()
{
    for(int i=1;i<=n;i++)
        fa[i]=i;
    sort(E+1,E+m+1,cmp);
    for(int i=1;i<=m;i++)
    {
        int u=E[i].u,v=E[i].v;
        int fx=find_fa(u),fy=find_fa(v);
        if(fx!=fy)
        {
            fa[fx]=fy;
            ans+=E[i].w;
        }
    }
}
signed main()
{
	#ifndef DEBUG
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif //DEBUG
    scanf("%d%d",&n,&m);
	for(int i=1,u,v,w;i<=m;i++)
    {
        scanf("%d%d%d",&u,&v,&w);
        E[i].u=u;
        E[i].v=v;
        E[i].w=w;
    }
    Kruscal();
    printf("%d",ans);
	return 0;
}
