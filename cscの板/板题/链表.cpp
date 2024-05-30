#include<iostream>
using namespace std;
struct Node
{
	int data;
	Node *next;
};
Node *p,*head,*r;
int x;
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	scanf("%d",&x);
	head=new Node;
	r=head;
	while(x!=-1)
	{
		p=new Node;
		p->data=x;
		p->next=NULL;
		r->next=p;
		r=p;
		scanf("%d",&x);
	}
	p=head->next;
	while(p->next!=NULL)
	{
		printf("%d ",p->data);
		p=p->next;
	}
	printf("%d\n",p->data);
	system("pause");
}
