#include<bits/stdc++.h>
#define rg register
//#define int long long
using namespace std;
const int MAXN=11001;
bool flag=0;
int n,it,cnt;
int a[MAXN];
char s[MAXN];
struct Node
{
	int i;
	int w;
	int pa;
	int Ls,Rs;
	char data;
}t[MAXN];
bool operator < (Node a,Node b)
{
	if(a.w > b.w||(a.w == b.w && a.i > b.i)) return true;
	return false;
}
bool operator > (Node a,Node b)
{
	return b < a;
}
priority_queue<Node>q;
void search(char ch,int root,int nums)
{
	if(root==-1) return;
	if(flag==1) return;
	if(t[root].data==ch)
	{
		a[++cnt]=nums;
		flag=1;
		return;
	}
	search(ch,t[root].Ls,0);
	search(ch,t[root].Rs,1);
	if(root!=it&&flag)
		a[++cnt]=nums;
	return;
}
void print(int root)
{
	if(t[root].data!='#')
	{
		cout<<t[root].data;
		print(it);
		return;
	}
	char x;
	scanf("%c",&x);
	if(x=='0')
		print(t[root].Ls);
	if(x=='1')
		print(t[root].Rs);
	return;
}
signed main()
{
	int T,Q;
	scanf("%d",&Q);
	while(Q--)
	{
		scanf("%d",&T);
		if(T==0)
		{
			scanf("%d",&n);
			for(int i=1;i<=n;i++)
			{
				cin>>t[i].data;
				t[i].pa=-1;
				t[i].Ls=-1;
				t[i].Rs=-1;
				t[i].i=i;
			}
			for(int i=1;i<=n;i++)
			{
				scanf("%d",&t[i].w);
				q.push(t[i]);
			}
			it=n;
			for(int i=1;i<n;i++)
			{
				it++;
				Node a,b;
				a=q.top(),q.pop();
				b=q.top(),q.pop();
				a.pa=it;
				b.pa=it;
				t[it].i=it;
				t[it].w=a.w+b.w;
				t[it].Ls=a.i;
				t[it].Rs=b.i;
				t[it].data='#';
				q.push(t[it]);
			}
		}
		if(T==1)
		{
			getchar();
			gets(s);
			int l=strlen(s);
			for(int i=0;i<l;i++)
			{
				search(s[i],it,0);
				while(cnt)
				{
					cout<<a[cnt];
					cnt--;
				}
				flag=0;
			}
			puts("");
		}
		if(T==2)
		{
			getchar();
			print(it);
			puts("");
		}
		cnt=0;
		memset(s,0,sizeof(s));
		memset(a,0,sizeof(s));
	}
	return 0;
}
