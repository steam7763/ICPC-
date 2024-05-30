#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int MAXN=300010;
int tot=0,heap[MAXN];
void push(int a)
{
	tot++;
	heap[tot]=a;
	int x=tot;
	while(x!=1&&heap[x/2]>heap[x])
	{
		swap(heap[x/2],heap[x]);
		x/=2;
	}
	return;
}
void pop()
{
	swap(heap[1],heap[tot]);
	tot--;
	int x=1;
	while(2*x<=tot)
	{	
		if(2*x+1<=tot)
		{
			if(heap[x]<heap[2*x]&&heap[x]<heap[2*x+1])
				break;
			if(heap[2*x+1]<heap[2*x])
			{
				swap(heap[2*x+1],heap[x]);
				x=2*x+1;
			}
			else
			{
				swap(heap[2*x],heap[x]);
				x=2*x;
			}
		}
		else
			if(heap[2*x]<heap[x])
			{
				swap(heap[2*x],heap[x]);
				x=x*2;
			}
			else
				break;
	}
}
int main()
{
//	freopen("fruit.out","r",stdin);
//	freopen("fruit.in","w",stdin);
	int n,a[MAXN];
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int a;
		scanf("%d",&a);
		push(a);
	}
	for(int i=1;i<=n;i++)
	{
		a[i]=heap[1];
		printf("%d ",heap[1]);
		pop();
	}
}
//Ð¡¸ù¶Ñ 
