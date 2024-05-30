#include<bits/stdc++.h>
#define rg register
//#define int long long
using namespace std;
const int MAXN=100100;
int n,m,k;
int dist[MAXN],cnt[MAXN];
bool vis[MAXN];
struct Twice
{
    int tot,head[MAXN];
    struct Edge
    {
        int u,v,nex,w;
    }E[MAXN];
    inline void Add(int u,int v,int w)
    {
        tot++;
        E[tot].u=u;
        E[tot].v=v;
        E[tot].w=w;
        E[tot].nex=head[u];
        head[u]=tot;
    }
}a,b;
queue<int>q;
priority_queue< pair<int,int> >Q;
inline void bfs()
{
    memset(dist,127,sizeof(dist));
    q.push(n);
    dist[n]=0;
    vis[n]=1;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        vis[u]=0;
        for(int i=a.head[u];i;i=a.E[i].nex)
        {
            int v=a.E[i].v;
            if(dist[v]>dist[u]+a.E[i].w)
            {
                dist[v]=dist[u]+a.E[i].w;
                if(vis[v]) continue;
                vis[v]=1;
                q.push(v);
            }
        }
    }
}
inline void SPFA()
{
    cnt[1]=1;
    Q.push(make_pair(-dist[1],1));
    while(!Q.empty())
    {
        int u=Q.top().second;
        int dis=-Q.top().first-dist[u];
        Q.pop();
        if(cnt[n]==k)
        {
            printf("%d",dis);
            exit(0);
        }
        for(int i=b.head[u];i;i=b.E[i].nex)
        {
            int v=b.E[i].v;
            cnt[v]++;
            Q.push(make_pair(-dis-b.E[i].w-dist[v],v));
        }
    }
}
signed main()
{
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1,x,y,z;i<=m;i++)
    {
        scanf("%d%d%d",&x,&y,&z);
        a.Add(x,y,z),b.Add(x,y,z);
    }
    bfs();
    SPFA();
    return 0;
}
