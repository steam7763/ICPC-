#include<bits/stdc++.h>
#define rg register
//#define int long long
using namespace std;
const int MAXN=101010;
int n,m,T,tot;
int head[MAXN],dist[MAXN],cnt[MAXN];
bool vis[MAXN];
struct Edge
{
    int u,v,w,nex;
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
inline void init()
{
    memset(head,0,sizeof(head));
    memset(vis,0,sizeof(vis));
    tot=0;
}
inline void Add(int u,int v,int w)
{
    tot++;
    E[tot].u=u;
    E[tot].v=v;
    E[tot].w=w;
    E[tot].nex=head[u];
    head[u]=tot;
}
inline bool SPFA(int st)
{
    memset(dist,127/2,sizeof(dist));
    memset(cnt,0,sizeof(cnt));
    queue<int> q;
    q.push(st);
    vis[st]=1;
    dist[st]=0;
    while(!q.empty())
    {
        int u=q.front(); q.pop();
        vis[u]=0;
        ++cnt[u];
        if(cnt[u]>n) return 1;
        for(int i=head[u];i;i=E[i].nex)
        {
            int v=E[i].v;

            if(dist[v]>dist[u]+E[i].w)
            {
                dist[v]=dist[u]+E[i].w;
                if(vis[v]) continue;
                vis[v]=1;
                q.push(v);
            }
        }
    }
    return 0;
}
signed main()
{
	srand((unsigned)time(NULL));
//看数据范围，看数组，long long，freopen
    scanf("%d",&T);
    while(T--)
    {
        init();
        scanf("%d%d",&n,&m);
        for(int i=1,x,y,z;i<=m;i++)
        {
            scanf("%d%d%d",&x,&y,&z);
            Add(x,y,z);
            if(z>=0)
                Add(y,x,z);
        }
        SPFA(1) ? printf("YE5") : printf("N0");
        putchar('\n');

    }
//看数据范围，看数组，long long，freopen
	return 0;
}
