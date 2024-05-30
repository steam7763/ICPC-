#include<bits/stdc++.h>
#define rg register
//#define int long long
using namespace std;
const int MAXN=100100;
int n,m,s,t,k,tot,tot1;
int dist[MAXN],head[MAXN],head1[MAXN],cnt[MAXN];
bool vis[MAXN];
struct Edge
{
	int u,v,w,nex;
}E[MAXN<<1];
struct Edge1
{
	int u,v,w,nex;
}E1[MAXN<<1];
void Add(int u,int v,double w)
{
	tot++;
	E[tot].u=u;
	E[tot].v=v;
	E[tot].w=w;
	E[tot].nex=head[u];
	head[u]=tot;
}
void Add1(int u,int v,double w)
{
	tot1++;
	E1[tot1].u=u;
	E1[tot1].v=v;
	E1[tot1].w=w;
	E1[tot1].nex=head1[u];
	head1[u]=tot1;
}
struct Node
{
	int x,val;
	bool operator < (Node a) const
	{
		return val+dist[x]>a.val+dist[a.x];
	}
};
priority_queue<Node>q;
struct Node1
{
	int x,val;
	bool operator < (Node1 a) const
	{
		return val>a.val;
	}
}u;
priority_queue<Node1>Q;
void Dijkstra()
{
	memset(dist,127,sizeof(dist));
	Node1 st;
	st.x=t,st.val=0;
	Q.push(st);
	while(!Q.empty())
	{
		u=Q.top();
		Q.pop();
		if(vis[u.x]) continue;
		vis[u.x]=1;
		for(int i=head1[u.x];i;i=E1[i].nex)
		{
			int v=E1[i].v;
			if(dist[v]>dist[u.x]+E1[i].w)
            {
				dist[v]=dist[u.x]+E1[i].w;
				if(!vis[v])
                {
					Node1 za;
					za.x=v,za.val=dist[v];
					Q.push(za);
				}
			}
		}
	}
}
void k_Dijkstra()
{
	Node ss;
	ss.x=s;
	ss.val=0;
	q.push(ss);
	while(!q.empty())
	{
		Node u=q.top();
		q.pop();
		cnt[u.x]++;
		if(u.x==t&&cnt[u.x]==k)
		{
			printf("%d\n",u.val);
			exit(0);
		}
		for(int i=head[u.x];i;i=E[i].nex)
		{
			Node v;
			v.x=E[i].v;
			v.val=u.val+E[i].w;
			q.push(v);
		}
	}
}
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	scanf("%d%d%d%d%d",&n,&m,&s,&t,&k);
	for(int i=1,x,y,z;i<=m;i++)
	{
		scanf("%d%d%d",&x,&y,&z);
		Add(x,y,z);
		Add1(y,x,z);
	}
	Dijkstra();
	k_Dijkstra();
	printf("-1\n");
}
