#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
//#define int long long
#define ls(x)  x<<1
#define rs(x)  x<<1|1
#define Open(s) freopen(s".in","r",stdin),freopen(s".out","w",stdout)
using namespace std;
const int N;
const double eps;
struct Queue
{
	int aaa[N],hd,tl;
	Queue(){hd=1;tl=0;} 
	void push(int x){aaa[++tl]=x;}
	void pop(){hd++;}
	int front(){return aaa[hd];}
	bool empty(){return (hd>tl)?1:0;}
};
void tdivid()//          三分 
{
	int l=-N,r=N,mid1,mid2;
	while(r-l>=eps)
	{
		mid1=(l+r)/3;mid2=2*mid1;
		if(check(mid1,mid2))  l=mid1;
		else  r=mid2;
	}
}


const int base=10000;//                               高精！ 
char s[10000];
struct node
{
	int z[10000];
}c,ret;
void in(node &a)//                                高精の读入 
{
	scanf("%s",s);
	int len=strlen(s);
	for(int i=0;i<len;++i)
		a.z[i+3>>2]=a.z[i+3>>2]*10+s[i]-'0';
	a.z[0]=len+3>>2;
}
void out(node a)//                                高精の输出 
{
	printf("%d",a.z[a.z[0]]);
	for(int i=a.z[0]-1;i>=1;--i)
		for(int j=base/10;j;j/=10)
			printf("%d",a.z[i]/j%10);
}
bool operator <(node a,node b)//                  高精の比较 
{
	if(a.z[0]<b.z[0])  return 1;
	if(a.z[0]>b.z[0])  return 0;
	for(int i=1;i<=a.z[0];++i)
	{
		if(a.z[i]<b.z[i])  return 1;
		if(a.z[i]>b.z[i])  return 0;
	}
	return 0;
}
node operator +(node a,node b)//                  高精の加运算 
{
	memset(c.z,0,sizeof(c.z));
	int j=1,x=0;
	while(j<=a.z[0]||j<=b.z[0])
	{
		c.z[j]+=a.z[0]+b.z[0]+x;
		x=c.z[j]/base;
		c.z[j]%=base;
		j++;
		++c.z[0];
	}
	c.z[++c.z[0]]=x;
	while(c.z[c.z[0]]==0&&c.z[0])  --c.z[0];
	return c;
}
node operator -(node a,node b)//                  高精の减运算 
{
	if(a<b)
	{
		flag=1;
		return b-a;
	}
	for(int i=1;i<=a.z[0];i++)
	{
		a.z[i]-=b.z[i];
		if(a.z[i]<0)
		{
			a.z[i]+=base;
			--a.z[i+1];
		}
	}
	return a;
}
node operator *(node a,node b)//                  高精の乘运算 
{
	memset(c.z,0,sizeof(c.z))
	c.z[0]=a.z[0]+b.z[0];
	for(int i=1;i<=a.z[0];++i)
		for(int j=1;j<=b.z[0];++j)
		{
			c.z[i+j-1]+=a.z[i]*b.z[j];
			c.z[i+j]+=c.z[i+j-1]/base;
			c.z[i+j-1]%=base;
		}
	while(c.z[c.z[0]]==0&&c.z[0])  --c.z[0];
	return c;
}
node operator /(node a,int b)//                   高精の除运算 
{
	for(int i=a.z[0];i>=1;--i)
	{
		a.z[i-1]+=base*(a.z[i]%b);
		a.z[i]/=b;
	}
	while(a.z[0]==0&&a.z[0])  --a.z[0];
	return a;
}
node operator ^(node a,int b)//                   高精の快速幂 
{
	memset(ret.z,0,sizeof(ret.z));
	ret.z[0]=1;
	ret.z[1]=1;
	while(b)
	{
		if(b&1)  ret=ret*a;
		a=a*a;
		b>>=1;
	}
	return ret;
}


bool Hash_table(int x)//          哈希表 
{
	int h=x%MOD;
	for(int i=head[h];i;i=pre[i])
	  if(check(i))
	    return 1;
	stk[++top]=h;
	pre[++tot]=head[h];
	head[h]=tot;
	val[tot]=x;
	return 0;
}


void kmp_pre(char *s)//         KMPのnex数组預處理 
{
	int j=0,len=strlen(s+1);
	nex[1]=0;
	for(int i=1;i<=len;++i)
	{
		while(j>0&&s[j+1]!=s[i+1])  j=nex[j];
		if(s[j+1]==s[i+1])  j++;
		nex[i+1]=j;
	}
}
void kmp(char *s1,char *s2)//   KMPの正体     s1：目标の字符串  s2：匹配用の字符串 
{
	int l1=strlen(s1+1),l2=strlen(s2+1),j=0;
	for(int i=0;i<=l1;++i)
	{
		while(j>0&&s2[j+1]!=s1[i+1])  j=nex[j];
		if(s1[i+1]==s2[j+1])  j++;
		if(j==l2)  print();
	}
}


void trie_insert(char *s)//               Trieの插♂入 
{
	int len=strlen(s),u=0;
	for(int i=0;i<len;++i)
	{
		int c=s[i]-'a';
		if(!to[u][c])  to[u][c]=++tot;
		u=to[u][c];
	}
	ed[u]=1;
}
bool trie_find(char *s)//                 Trieの查询 
{
	int len=strlen(s),u=0;
	for(int i=0;i<len;++i)
	{
		int c=s[i]-'a';
		if(!to[u][c])  return 0;
		u=to[u][c];
	}
	return 1;
}


void AC_insert(char *s)//                AC自动机 
{
	int len=strlen(s),u=0;
	for(int i=0;i<len;++i)
	{
		int c=s[i]-'a';
		if(!to[u][c])  to[u][c]=++tot;
		u=to[u][c];
	}
	ed[u]++;
}
void AC_bfs()
{
	for(int i=0;i<=25;++i)  to[0][i]=1;
	q[1]=1;nex[1]=0;
	for(int q1=1,q2=1;q1<=q2;++q1)
	{
		int u=q[q1];
		for(int i=0;i<=25;++i)
		{
			if(!to[u][i])  to[u][i]=to[nex[u]][i];
			else
			{
				q[++q2]=to[u][c];
				int v=nex[u];
				while(v>0&&!to[v][i])  v=nex[v];
				nex[to[u][i]]=to[v][i];
			}
		}
	}
}
int AC_find(char *s)
{
	int u=1,len=strlen(s);
	for(int i=0;i<len;++i)
	{
		int c=s[i]-'a';
		int k=to[u][c];
		while(k>1)
		{
			ans+=ed[k];
			ed[k]=0;
			k=nex[k];
		}
		u=to[u][c];
	}
	return ans;
}


void tarjan(int u,int f)//            Tarjan求割点和桥 
{
	vis[u]=1;
	dfn[u]=low[u]=++tol;
	int cnt=0;
	for(int i=head[u];i;i=pre[i])
	{
		int v=to[i];
		if(v!=f)
		{
			cnt++;
			if(!dfn[v])
			{
				tarjan(v,u);
				low[u]=min(low[v],low[u]);
				if((u==root&&cnt>1)||(u!=root&&dfn[u]<=low[v]))  cut[u]=1;
				if(dfn[u]<low[v])  bridge[i]=bridge[(i&1)?i+1:i-1]=1;
			}
			else  low[u]=min(dfn[v],low[u]);
		}
	}
}


void tarjan(int x)//                Tarjan缩点 
{
	dfn[x]=low[x]=++tol;
	stk[++top]=x;
	for(int i=head[x];i;i=pre[i])
	{
		int y=to[i];
		if(!dfn[y])
		{
			tarjan(y);
			low[x]=min(low[y],low[x]);
		}
		else if(!group[y])  low[x]=min(dfn[y],low[x]);
	}
	if(dfn[x]==low[x])
	{
		knd++;
		group[x]=knd;
        while(stk[top]!=x)
        {
        	group[stk[top]]=knd;
        	top--;
		}
		top--;
	}
}


void euler_dfs(int u)//                   dfs找euler回路（单向边） 
{
	for(int &i=head[u];i;i=pre[i])
	{
		int v=to[i];
		if(!vis[i])
		{
			vis[i]=1;//     vis[i]=vis[(i&1)?i+1:i-1]=1;(双向兄弟边） 
			euler_dfs(v);
			stk1[++top1]=i;//stk1[++top1]=num[i];（双向兄弟边の编号） 
			stk2[++top2]=u;
		}
	}
}
void print()
{
	for(int i=top1;i>=1;--i)  printf("%d ",stk1[i]);//  euler边の遍历 
	for(int i=top2;i>=1;--i)  printf("%d ",stk2[i]);//  euler点の遍历 
}


void lowbit(int x){return x&(-x);}//           树状数组 
void update(int x,int w){for(;x<=n;x+=lowbit(x)) c[x]+=w;}//    一维 
int sum(int x)
{
	int ans=0;
	for(;x;x-=lowbit(x))  ans+=c[x];
	return ans;
}


void update(int x,int y,int w)//      二维 
{
	int i=x;
	while(i<=n)
	{
		int j=y;
		while(j<=m)
		{
			c[i][j]+=w;
			j+=lowbit(j);
		}
		i+=lowbit(i);
	}
}
int sum(int x,int y)
{
	int ans=0,i=x;
	while(i>0)
	{
		int j=y;
		while(j>0)
		{
			ans+=c[i][j];
			j-=lowbit(j);
		}
		i-=lowbit(i);
	}
}


void ST_pre(int n)//                       ST表求最大值の預處理 
{
	for(int i=1;i<=n;++i)  scanf("%d",&st[i][0]);
	for(int i=2;i<=n;++i)  ci[i]=ci[i>>1]+1;
	for(int j=1;j<=ci[n];++j)
	  for(int i=1;i+(1<<j-1)<=n;++i)
	    st[i][j]=max(st[i][j-1],st[i+(1<<j-1)][j-1]);
}
int ST(int l,int r)//                      ST表求最大值の正体 
{
	int z=r-l+1;
	return max(st[l][ci[z]],st[r-(1<<ci[z])+1][ci[z]]);
}


void pushup(int x)//                      线段树其の壹    区间加 
{
	mio[x].val=mio[ls(x)].val+mio[rs(x)].val;
}
void pushdown(int x)
{
	int mid=mio[x].le+mio[x].ri>>1;
	mio[ls(x)].val+=mio[x].tag*(mid-mio[x].le+1);
	mio[rs(x)].val+=mio[x].tag*(mio[x].ri-mid);
	mio[ls(x)].tag+=mio[x].tag;
	mio[rs(x)].tag+=mio[x].tag;
	mio[x].tag=0;
}
void build(int x,int l,int r)
{
	mio[x].le=l;mio[x].ri=r;
	int mid=l+r>>1;
	if(l==r)
	{
		mio[x].val=a[l];
		return;
	}
	build(ls(x),l,mid);
	build(rs(x),mid+1,r);
	pushup(x);
}
void update(int x,int L,int R,int v)
{
	int l=mio[x].le,r=mio[x].ri;
	if(L<=l&&R>=r)
	{
		mio[x].val+=(r-l+1)*v;
		mio[x].tag+=v;
		return;
	}
	if(l>R||r<L)  return;
	if(mio[x].tag)  pushdown(x);
	update(ls(x),L,R,v);
	update(rs(x),L,R,v);
	pushup(x);
}
int query(int x,int L,int R)
{
	int l=mio[x].le,r=mio[x].ri;
	if(L<=l&&R>=r)  return mio[x].val;
	if(l>R||r<L)  return 0;
	if(mio[x].tag)  pushdown(x);
	return query(ls(x),L,R)+query(rs(x),L,R);
}


void pushup(int x)//                      线段树其の貳    区间加乘    tag1为乘   tag2为加 
{
	mio[x].val=(mio[ls(x)].val+mio[rs(x)].val)%p;
}
void pushdown(int x)
{
	int l=mio[x].le,r=mio[x].ri,mid;
	mid=l+r>>1;
	mio[ls(x)].val=mio[ls(x)].val*mio[x].tag1%p;
	mio[rs(x)].val=mio[rs(x)].val*mio[x].tag1%p;
	mio[ls(x)].tag1=mio[ls(x)].tag1*mio[x].tag1%p;
	mio[ls(x)].tag2=mio[ls(x)].tag2*mio[x].tag1%p;
	mio[rs(x)].tag1=mio[rs(x)].tag1*mio[x].tag1%p;
	mio[rs(x)].tag2=mio[rs(x)].tag2*mio[x].tag1%p;
	mio[ls(x)].val=(mio[ls(x)].val+(mid-l+1)*mio[x].tag2%p)%p;
	mio[rs(x)].val=(mio[rs(x)].val+(r-mid)*mio[x].tag2%p)%p;
	mio[ls(x)].tag2=(mio[ls(x)].tag2+mio[x].tag2)%p;
	mio[rs(x)].tag2=(mio[rs(x)].tag2+mio[x].tag2)%p;
	mio[x].tag1=1;mio[x].tag2=0;
}
void build(int x,int l,int r)
{
	mio[x].le=l;mio[x].ri=r;
	int mid=l+r>>1;
	if(l==r)
	{
		mio[x].val=a[l];
		return;
	}
	build(ls(x),l,mid);
	build(rs(x),mid+1,r);
	pushup(x);
}
void update1(int x,int L,int R,int v)
{
	int l=mio[x].le,r=mio[x].ri;
	if(L<=l&&R>=r)
	{
		mio[x].val=mio[x].val*v%p;
		mio[x].tag1=mio[x].tag1*v%p;
		mio[x].tag2=mio[x].tag2*v%p;
		return;
	}
	if(L>r||R<l)  return;
	if(mio[x].tag1!=1||mio[x].tag2!=0)  pushdown(x);
	update1(ls(x),L,R,v);
	update1(rs(x),L,R,v);
	pushup(x);
}
void update2(int x,int L,int R,int v)
{
	int l=mio[x].le,r=mio[x].ri;
	if(L<=l&&R>=r)
	{
		mio[x].val=(mio[x].val+(r-l+1)*v%p)%p;
		mio[x].tag2=(mio[x].tag2+v%p)%p;
		return;
	}
	if(L>r||R<l)  return;
	if(mio[x].tag1!=1||mio[x].tag2!=0)  pushdown(x);
	update2(ls(x),L,R,v);
	update2(rs(x),L,R,v);
	pushup(x);
}
int query(int x,int L,int R)
{
	int l=mio[x].le,r=mio[x].ri;
	if(L<=l&&R>=r)  return mio[x].val;
	if(L>r||R<l)  return 0;
	if(mio[x].tag1!=1||mio[x].tag2!=0)  pushdown(x);
	return  (query(ls(x),L,R)+query(rs(x),L,R))%p;
}


void pushdown(int x,int &ls,int &rs)//     线段树其の叁    动态开点区间加 
{
	if(!ls)  ls=++cnt;
	if(!rs)  rs=++cnt;
	int l=mio[x].le,r=mio[x].ri,mid;
	mid=l+r>>1;
	mio[ls].val+=(mid-l+1)*mio[x].tag;
	mio[rs].val+=(r-mid)*mio[x].tag;
	mio[ls].tag+=mio[x].tag;
	mio[rs].tag+=mio[x].tag;
	mio[x].tag=0;
}
void update(int &x,int l,int r,int L,int R,int v)
{
	if(!x)  x=++cnt;
	if(L<=l&&R>=r)
	{
		mio[x].tag+=v;
		mio[x].val+=(r-l+1)*v;
		return;
	}
	if(L>r||R<l)  return;
	int mid=l+r>>1;
	if(mio[x].tag)  pushdown(x,mio[x].ls,mio[x].rs);
	update(mio[x].ls,l,mid,L,R,v);
	update(mio[x].rs,mid+1,r,L,R,v);
	mio[x].val+=mio[mio[x].ls].val+mio[mio[x].rs].val;
}
int query(int x,int l,int r,int L,int R)
{
	if(!x)  return 0;
	if(L<=l&&R>=r)  return mio[x].val;
	if(l>R||r<L)  return 0;
	if(mio[x].tag)  pushdown(x,mio[x].ls,mio[x].rs);
	int mid=l+r>>1;
	return query(mio[x].ls,l,mid,L,R)+query(mio[x].rs,mid+1,r,L,R);
}


void build(int &x,int l,int r)//           线段树其の肆    主席樹單點修改 
{
	x=++cnt;
	int mid=l+r>>1;
	if(l==r)
	{
		mio[x].val=a[l];
		return;
	}
	build(mio[x].ls,l,mid);
	build(mio[x].rs,mid+1,r);
	mio[x].val=mio[mio[x].ls].val+mio[mio[x].rs].val;
}
void update(int &x,int now,int l,int r,int pos,int v)
{
	++cnt;
	mio[cnt].val=mio[x].val;
	mio[cnt].ls=mio[x].ls;
	mio[cnt].rs=mio[x].rs;
	x=cnt;
	if(l==r&&l==pos)
	{
		mio[x].val=v;
		return;
	}
	int mid=l+r>>1;
	if(pos<=mid)  update(mio[x].ls,l,mid,pos,v);
	else  update(mio[x].rs,mid+1,r,pos,v);
	mio[x].val=mio[mio[x].ls].val+mio[mio[x].rs].val;
}


void lca_pre(int u,int f)//                 倍增求LCAの预处理 
{
	dep[u]=dep[f]+1;
	fa[u][0]=f;
	for(int i=1;i<=20;++i)
	  fa[u][i]=fa[fa[u][i-1]][i-1];
	for(int i=head[u];i;i=pre[i])
	{
		int v=to[i];
		if(f==v)  continue;
		lca_pre(v,u);
	}
}
int get_lca(int x,int y)//					LCA 獲得 
{
	if(dep[x]<dep[y])  swap(x,y);
	for(int i=20;i>=0;--i)
	{
		if(dep[fa[x][i]]>=dep[y])  x=fa[x][i];
		if(x==y)  return x;
	}
	for(int i=20;i>=0;--i)
	  if(fa[x][i]!=fa[y][i])  x=fa[x][i],y=fa[y][i];
	return fa[x][0];
}


void dfs1(int u,int f)//      				树剖DFSの一回目 
{
	dep[u]=dep[f]+1;
	size[u]=1;
	fa[u]=f;
	for(int i=head[u];i;i=pre[i])
	{
		int v=to[i];
		if(f==v)  continue;
		dfs1(v,u);
		size[u]+=size[v];
		if(size[son[u]]<size[v]||!son[u])  son[u]=v;
	}
}
void dfs2(int u)//						树剖DFSの二回目 
{
	if(son[u])
	{
		top[son[u]]=top[u];
		seg[son[u]]=++cnt;
		res[cnt]=son[u];
		dfs2(son[u]);
	}
	for(int i=head[u];i;i=pre[i])
	{
		int v=to[i];
		if(f==v||v==son[u])  continue;
		top[v]=v;
		seg[v]=++cnt;
		res[cnt]=v;
		dfs2(v);
	}
}


int lca(int l,int r)//                   树剖求LCA 
{
	while(top[l]!=top[r])
	{
		if(dep[top[l]]<dep[top[r]])  swap(l,r);
		l=fa[top[l]];
	}
	return dep[l]<dep[r]?l:r;
}


int Find(int x)//                        并查集路径压缩 
{
	if(x==fa[x])  return x;
	return fa[x]=Find(fa[x]);
}
void Kruscal()//                         Kruscal求最小生成树 
{
	sort(a+1,a+1+m,cmp);
	for(int i=1,k=0;i<=m;++i)
	{
		int f1=Find(a.le),f2=Find(a.ri);
		if(f1!=f2)
		{
			ans+=a.val;
			k++;
			fa[f1]=f2;
		}
		if(k==n-1)  break;
	}
}


void prim()//                            prim求最小生成树 
{
	memset(dis,127,sizeof(dis));
	dis[1]=0;
	for(int i=1;i<=n;++i)
	{
		int minn=dis[0],pos=0;
		for(int j=1;j<=n;++j)
		if(!vis[j]&&dis[j]<minn) minn=dis[j],pos=j;
        ans+=dis[pos],vis[pos]=1;
        for(int i=head[pos];i;i=pre[i])
            dis[to[i]]=min(dis[to[i]],edge[i]);
	}
}


bool cmp(node a,node b)//                  莫队玄学优化 
{
	return (group[a.le]^group[b.le])?group[a.le]<group[b.le]:((group[a.le]&1)?a.ri<b.ri:a.ri>b.ri);
}
void mo(int pos,int x)
{
	if(x>0)  ans[pos]++;
	else  ans[pos]--;
}
void modify()
{
	for(int i=1,m=ceil(sqrt(n));i<=n;++i)
		group[a[i].le]=a[i].le/m;
	sort(a+1,a+1+n,cmp);
	for(int i=1,l=0,r=0;i<=n;++i)
	{
		//函数调用直接改写在主函数内卡时间 
		while(a[i].ri>r)  mo(++r,1);
		while(a[i].ri<r)  mo(--r,-1);
		while(a[i].le<l)  mo(--l,1);
		while(a[i].le>l)  mo(++l,-1);
		printf("%d\n",ans[r]-ans[l-1]);
	}
}


void SPFA(int x)//                         SPFAの双端队列优化 
{
	deque <int> q;
	memset(dis,127,sizeof(dis));
	dis[x]=0;vis[x]=1;q.push_front(x);
	while(!q.empty())
	{
		int u=q.front();q.pop_front();vis[u]=0;
		for(int i=head[u];i;i=pre[i])
		{
			int v=to[i];
			if(dis[v]>dis[u]+edge[i])
			{
				dis[v]=dis[u]+edge[i];
				if(!vis[v])
				{
					if(q.empty())  q.push_front(v);
					else
					{
						if(dis[v]<=dis[q.front()])  q.push_front(v);
						else  q.push_back(v);
					}
					vis[v]=1;
				}
			}
		}
	}
	for(int i=1;i<=n;++i)  printf("%d\n",dis[i]);
}


struct node
{
	int num,d;
};
void dijkstra(int x)//                  Dijkstraの堆优化   存负值当小根堆 
{
	priority_queue<node> q;
	memset(dis,127,sizeof(dis));
	memset(vis,0,sizeof(vis));
	dis[x]=0;
	node y;y.num=x;y.d=0;
	q.push(y);
	while(!q.empty())
	{
		int u=q.top().num;q.pop();
		if(vis[u])  continue;
		vis[u]=1;
		for(int i=head[u];i;i=pre[i])
		{
			int v=to[i];
			if(dis[v]>dis[u]+edge[i])
			{
				dis[v]=dis[u]+edge[i];
				node z;z.num=v;z.d=-dis[v];
				q.push(z);
			}
		}
	}
}


void floyd()//                          Floyd多源最短路 
{
	memset(dis,127,sizeof(dis));
	for(int k=1;k<=n;++k)
	  for(int i=1;i<=n;++i)
	    for(int j=1;j<=n;++j)
	      if(dis[i][k]!=dis[0][0]&&dis[k][j]!=dis[0][0]&&dis[i][k]+dis[k][j]<dis[i][j])
	        dis[i][j]=dis[i][k]+dis[k][j];
}


void DP_01()//                          01背包 
{
	for(int i=1;i<=n;++i)
		for(int j=c;j>=v[i];--j)
			dp[j]=max(dp[j],dp[j-v[i]]+w[i]);
}


void DP_com()//                           完全背包 
{
	for(int i=1;i<=n;++i)
		for(int j=v[i];j<=c;++j)
			dp[j]=max(dp[j],dp[j-v[i]]+w[i]);
}


void DP_01_plus()//                       多次背包 
{
	for(int i=1;i<=n;++i)
	{
		int m=1;
		while(k[i]>0)
		{
			if(m>k[i])  m=k[i];
			k[i]-=m;
			for(int j=c;j>=v[i]*m;--j)
				dp[j]=max(dp[j],dp[j-v[i]*m]+w[i]*m);
			m*=2;
		}
	}
}


int gcd(int a,int b)//                   辗转相除求GCD 
{
	return a%b==0?b:gcd(b,a%b);
}


void exgcd(ll a,ll b,ll &d,ll &x,ll &y)//     拓展Euclid
{
	if(b==0)
	{
		x=1;y=0;d=a;
		return;
	}
	else
	{
		exgcd(b,a%b,d,x,y);
		ll t=x;
		x=y;y=t-a/b*y;
	}
}


int quickpow(int a,int b,int MOD)//            快速幂 
{
	int ret=1;
	while(b)
	{
		if(b%2==1)  ret=ret*a%MOD;
		a=a*a%MOD;
		b>>=1;
	}
	return ret;
}


void prime(int n)//                            Eratosthenes筛素数 
{
	memset(v,0,sizeof(v));
	for(int i=2;i<=n;++i)
	{
		if(v[i])  continue;
		printf("%d ",i);
		for(int j=i;j<=n/i;++j)  v[i*j]=1;
	}
}


void prime(int n)//                           线性筛 
{
	memset(v,0,sizeof(v));
	int m=0;
	for(int i=2;i<=n;++i)
	{
		if(v[i]==0)
		{
			v[i]=i;
			p[++m]=i;
		}
		for(int j=1;j<=m;++j)
		{
			if(i*p[j]>n)  break;
			v[i*p[j]]=p[j];
		}
	}
	for(int i=1;i<=m;++i)  printf("%d ",p[j]);
}


void square mul()//                           矩阵乘法 
{
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			for(int k=1;k<=m;++k)
				c[i][j]+=a[i][k]*b[k][j];
}


int main()
{
//	Open("");
	
	return 0;
}
