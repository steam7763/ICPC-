///*
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define INF 0x3f3f3f3f
#define int long long
using namespace std;
const int MAXN=1000010;
struct Queue{
	int q[MAXN*10];
	int head,tail;
	void clear()
	{
		memset(q,-0x3f,sizeof(q));
		head=0,tail=0;
	}
	int front(){return q[head];}
	void pop(){head++;}
	bool empty(){return head>=tail ? 1 : 0 ;}
	void push(int x){q[tail]=x,tail++;}
}q1,q2,q3;
int a[MAXN],num[MAXN],pre[MAXN],nex[MAXN];
int n,m,u,q,v,t;
signed main()
{
	#ifndef DEBUG
	freopen("earthworm.in","r",stdin);
	freopen("earthworm.out","w",stdout);
	#endif
	q1.clear();
	q2.clear();
	q3.clear();
	scanf("%lld%lld%lld%lld%lld%lld",&n,&m,&q,&u,&v,&t);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	for(int i=n;i>=1;i--)
		q3.push(a[i]);
	int dlt=0;
	for(int i=1;i<=m;i++)
	{
		int x1=-INF,x2=-INF,x3=-INF;
		if(!q1.empty()) x1=q1.front();
		if(!q2.empty()) x2=q2.front();
		if(!q3.empty()) x3=q3.front();
		int xx=max(max(x1,x2),x3);
		if(xx==x1) q1.pop();
		else if(xx==x2) q2.pop();
		else q3.pop();
		xx+=dlt;
		if(i%t==0)
			printf("%lld ",xx);
		dlt+=q;
		int d1=(int)(double(xx)*(double)u/(double)v);
		int d2=xx-d1;
		q1.push(d1);
		q2.push(d2);
	}
	puts("");
	for(int i=1;i<=(n+m)&&(!q1.empty()||!q2.empty())||!q3.empty();i++)
	{
		int x1=-INF,x2=-INF,x3=-INF;
		if(!q1.empty()) x1=q1.front();
		if(!q2.empty()) x2=q2.front();
		if(!q3.empty()) x3=q3.front();
		int xx=max(max(x1,x2),x3);
		if(xx==x1) q1.pop();
		else if(xx==x2) q2.pop();
		else q3.pop();
		if(i%t==0)
			printf("%lld ",xx+dlt);
	}
}
/*
in:
3 7 1 1 3 2
3 3 2

ans:
4 4 5
6 5 4 3 2 



//*/
/*
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<cmath>
#include<map>
#define MAXN 1000010
#define ll long long int
#define max(x,y) ((x)>(y)?(x):(y))
using namespace std;
struct Queue
{
	int q[MAXN*10];
	int head,tail;
	inline int clear()
	{
		memset(q,-0x3f,sizeof(q));
		head=0,tail=0;
	}
	inline int front(){return q[head];}
	inline int pop(){head++;}
	inline bool empty(){return head>=tail;}
	inline int push(int x){q[tail]=x;tail++;}
}q1,q2,q3;
int a[MAXN];
int num[MAXN];
int pre[MAXN];
int nxt[MAXN];
int main()
{
	#ifndef DEBUG
	freopen("earthworm.in","r",stdin);
	freopen("earthworm.out","w",stdout);
	#endif
	int n,m,q,u,v,t;
	q1.clear();
	q2.clear();
	q3.clear();
	scanf("%d%d%d%d%d%d",&n,&m,&q,&u,&v,&t);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	for(int i=n;i>=1;i--)
		q3.push(a[i]);
	int dlt=0;
	for(int i=1;i<=m;i++)
	{
		int x1=-0x3f3f3f3f,x2=-0x3f3f3f3f,x3=-0x3f3f3f3f;
		if(!q1.empty())x1=q1.front();
		if(!q2.empty())x2=q2.front();
		if(!q3.empty())x3=q3.front();
		int xx=max(max(x1,x2),x3);
		if(xx==x1)q1.pop();
		else if(xx==x2)q2.pop();
		else q3.pop();
//		cout<<xx<<" "<<q1.front()<<" "<<q2.front()<<endl;
		xx+=dlt;
		if(i%t==0)
			printf("%d ",xx);
		dlt+=q;
		int d1=int((double)xx*(double)u/(double)v);
		int d2=xx-d1;
		q1.push(d1-dlt);
		q2.push(d2-dlt);
	}
	puts("");
	for(int i=1;i<=n+m&&(!q1.empty()||!q2.empty()||!q3.empty());i++)
	{
		int x1=-0x3f3f3f3f,x2=-0x3f3f3f3f,x3=-0x3f3f3f3f;
		if(!q1.empty())x1=q1.front();
		if(!q2.empty())x2=q2.front();
		if(!q3.empty())x3=q3.front();
		int xx=max(x1,max(x2,x3));
		if(xx==x1)q1.pop();
		else if(xx==x2)q2.pop();
		else q3.pop();
		if(i%t==0)
			printf("%d ",xx+dlt);
	}
	return 0;
}
/*
3 5 0 1 2 2
5 6 8




1 10 10 1 2 1
20
*/
