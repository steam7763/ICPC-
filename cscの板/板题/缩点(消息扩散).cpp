#include<bits/stdc++.h>
#define rg register
//#define int long long
using namespace std;
const int MAXN=500100;
int n,m,tot,num,col,top,ans;
int head[MAXN],co[MAXN]\
,low[MAXN],dfn[MAXN],\
st[MAXN],in[MAXN];
struct Edge
{
    int u,v,nex;
}E[MAXN<<3];
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
inline void Tarjan(int u)
{
    dfn[u]=low[u]=++num;
    st[++top]=u;
    for(int i=head[u];i;i=E[i].nex)
    {
        int v=E[i].v;
        if(!dfn[v])
        {
            Tarjan(v);
            low[u]=min(low[u],low[v]);
        }
        else if(!co[v])
            low[u]=min(dfn[v],low[u]);
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
signed main()
{
	srand((unsigned)time(NULL));
//看数据范围，看数组，long long，freopen
    read(n),read(m);
    for(int i=1,x,y;i<=m;i++)
    {
        read(x),read(y);
        Add(x,y);
    }
    for(int i=1;i<=n;i++)
        if(!dfn[i])
            Tarjan(i);
    for(int i=1;i<=n;i++)
        for(int j=head[i];j;j=E[j].nex)
            if(co[i]!=co[E[j].v])
                in[co[E[j].v]]++;
    for(int i=1;i<=col;i++)
        if(!in[i])
            ans++;
    print(ans);
//看数据范围，看数组，long long，freopen
	return 0;
}
