#include<iostream>
#include<cstdio>
using namespace std;
const int MAXN=1000;
int tot=1,a[MAXN];
struct aaa
{
	int val;//节点的值 
	int num;//节点个数 
	int lch;//左儿子编号 
	int rch;//右儿子编号 
	bool use;
}rt[MAXN];
void Insert(int x)//树的插入 
{
	int p=1;
	while(rt[p].use)
	{
		if(rt[p].val==x)
		{
			rt[p].num++;
			return;
		}
		if(x<rt[p].val)
		{
			if(rt[p].lch==0)
			{
				tot++;
				rt[p].lch=tot;
			}
			p=rt[p].lch;
		}
		else
		{
			if(rt[p].rch==0)
			{
				tot++;
				rt[p].rch=tot;
			}	
			p=rt[p].rch;
		}
	}
	rt[p].val=x;
	rt[p].num=1;
	rt[p].use=1;
}
bool qq(int x)//访问 
{
	int p=1;
	while(rt[p].use==true)
	{
		if(rt[p].val==x)
			return true;
		if(x<rt[p].val)
		{
			if(!rt[p].lch)
				return false;
			p=rt[p].lch;
		}
		else
		{
			if(!rt[p].rch)
				return false;
			p=rt[p].rch;
		}
	}
	return false;
}
int midd(int x)//中序 
{
	if(rt[x].use==false)
		return 0;
	else
	{
		midd(rt[x].lch);
		printf("%d",rt[x].val);
		midd(rt[x].rch);
	}
}
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		Insert(a[i]);
	}
/*	int kk;
	scanf("%d",&kk);
		if(qq(kk))
			printf("YES");
		else
			printf("NO");
	*/
	midd(1);
	return 0;
}
