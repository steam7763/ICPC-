#include<bits/stdc++.h>
#define rg register
using namespace std;
const int MAXN=100100;
struct Edge
{
    int u,v,w,nex;
}E[MAXN<<4];
struct Node
{
    int num,val;
};
int n,m,tot,head[MAXN],dist[MAXN];
bool vis[MAXN];
void Add(int u,int v,int w)
{
    tot++;
    E[tot].u=u;
    E[tot].v=v;
    E[tot].nex=head[u];
    head[u]=tot;
}
bool operator < (Node a,Node b)
{
    return a.val>b.val;
}
priority_queue<Node>q;
void dijkstra(int s,int t)
{
    memset(dist,127/2,sizeof(dist));
    Node st;
    st.val=0;
    st.num=s;
    dist[s]=0;
    q.push(st);
    while(!q.empty())
    {
        Node u=q.top();
        q.pop();
        if(vis[u.num]) continue;
        vis[u.num] = 1;
        for(int i=head[u.num];i;i=E[i].nex)
        {
            int v=E[i].v;
            if(dist[v]>dist[u.num]+E[i].w)
            {
                dist[v]=dist[u.num]+E[i].w;
                if(vis[v]) continue;
                Node y;
                y.num=v;
                y.val=dist[v];
                q.push(y);
            }
        }
    }
}
signed main()
{
    int s,t;
    scanf("%d%d%d%d",&n,&m,&s,&t);
    for(int i=1,x,y,z;i<=m;i++)
    {
        scanf("%d%d%d",&x,&y,&z);
        Add(x,y,z);
    }
    dijkstra(s,t);
    printf("%d",dist[t]);
}
