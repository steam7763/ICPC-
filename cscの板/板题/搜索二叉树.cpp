#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
struct Node
{
	int data;
	Node *l,*r;
};
void initb(Node *& bt)
{
	bt=NULL;
}
void Insert(int data,Node *& bat)
{
	if(bat==NULL)
	{
		Node*p=new Node;
		p->data=data;
		p->l=p->r=NULL;
		bat=p;
	}
	else if(data<bat->data)
		Insert(data,bat->l);
	else	
		Insert(data,bat->r);
}
void Inorder(Node * bt)
{
	if(bt!=NULL)
	{
		Inorder(bt->l);
		printf("%d ",bt->data);
		Inorder(bt->r);	
	}
}
int main()
{
	Node*bst;
	initb(bst);
	Insert(4,bst);
	Insert(12,bst);
	Insert(9,bst);
	Insert(5,bst);
	Inorder(bst);,
	return 0;
} 
