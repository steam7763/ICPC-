#include<iostream>
#include<cstdio>
using namespace std;
const int MAXN=1000;
int tot=1,a[MAXN];
struct aaa
{
	int val;//�ڵ��ֵ 
	int num;//�ڵ���� 
	int lch;//����ӱ�� 
	int rch;//�Ҷ��ӱ�� 
	bool use;
}rt[MAXN];
void Insert(int x)//���Ĳ��� 
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
bool qq(int x)//���� 
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
int midd(int x)//���� 
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
