#include <bits/stdc++.h>
#define rg register
//#define int long long
using namespace std;
const int MAXN=100100;
int n,m,num,root,col,tot;
int low[MAXN],dfn[MAXN],\
head[MAXN];
bool cut[MAXN];
struct Edge
{
    int u,v,nex;
}E[MAXN<<2];
template <typename T> inline void read(T &x)
{
    T f=1,ch=getchar();
    for(x=0;!isdigit(ch);ch=getchar()) if(ch=='-') f=-1;
    for(;isdigit(ch);ch=getchar()) x=(x<<3)+(x<<1)+ch-'0';
    x*=f;
}
template <typename T>inline void print(T x)
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
inline void dfs(int u)
{
    dfn[u]=low[u]=++num;
    int cnt=0;
    for(int i=head[u];i;i=E[i].nex)
    {
        int v=E[i].v;
        if(!dfn[v])
        {
            cnt++;
            dfs(v);
            low[u]=min(low[u],low[v]);
            if(((u==root&&cnt>1)||u!=root)&&(low[v]>=dfn[u])&&!cut[u])
                col++,cut[u]=1;
        }
        else
            low[u]=min(low[u],dfn[v]);
    }
}
signed main()
{
    read(n),read(m);
    for(int i=1,x,y;i<=m;i++)
    {
        read(x),read(y);
        Add(x,y);
        Add(y,x);
    }
    for(int i=1;i<=n;++i)
    	if(!dfn[i])
    		dfs(root=i);
    printf("%d\n",col);
    for(int i=1;i<=n;i++)
        if(cut[i])
            printf("%d ",i);
    return 0;
}
