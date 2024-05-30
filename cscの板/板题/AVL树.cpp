#include<bits/stdc++.h>
using namespace std;
struct Node{
	Node *lchild,*rchild;
	int data;
};
int GetHight(Node *root)
{
	if(root == NULL)
		return 0;
	return max(GetHight(root->lchild),GetHight(root->rchild)) + 1; 
}
int GetBalence(Node *root)
{
	return GetHight(root->lchild) - GetHight(root->rchild);
}
void L(Node* &root)
{
	Node *tmp=root->rchild;
	root->rchild=tmp->lchild;
	tmp->lchild=root;
	root=tmp;
}
void R(Node* &root)
{
	Node *tmp=root->lchild;
	root->lchild=tmp->rchild;
	tmp->rchild=root;
	root=tmp;
}
void Insert(Node* &root,int x)
{
	if(root==NULL)
	{
		root=new Node;
		root->data=x;
		root->lchild=NULL;
		root->rchild=NULL;
		return ;
	}
	if(x < root->data)
	{
		Insert(root->lchild,x);
		if(GetBalence(root)==2)
		{
			if(GetBalence(root->lchild)==1)
				R(root);
			if(GetBalence(root->lchild)==-1)
			{
				L(root->lchild);
				R(root);
			}
		}
	}
	else
	{
		Insert(root->rchild,x);
		if(GetBalence(root)==-2)
		{
			if(GetBalence(root->rchild)==-1)
				L(root);
			if(GetBalence(root->rchild)==1)
			{
				R(root->rchild);
				L(root);
			}
		}
	}
}
void PreOrder(Node *root)
{
	if(root==NULL)
		return ;
	printf("%d ",root->data);
	PreOrder(root->lchild);
	PreOrder(root->rchild);
}
void InOrder(Node *root)
{
	if(root==NULL)
		return ;
	InOrder(root->lchild);
	printf("%d ",root->data);
	InOrder(root->rchild);
}
signed main()
{
	int x;
	Node *root=NULL;
	while(scanf("%d",&x))
	{
		if(x==-1)
			break;
		Insert(root,x);
	}
	PreOrder(root);
	puts("");
	InOrder(root);
	return 0;
}
