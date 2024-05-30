#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
#include<cmath>
#define rg register
using namespace std;
struct BT{
	int data;
	BT *left;
	BT *right;
};

void Insert(BT *&bst,int item)
{
	if(bst==NULL)
	{
		BT *p=new BT;
		p->data=item;
		p->left=NULL;
		p->right=NULL;
		bst=p;
	}
	else if(item<bst->data)
		Insert(bst->left,item);
	else
		Insert(bst->right,item);
}
void Inoder(BT *&bst)
{
	if(bst!=NULL)
	{
		Inoder(bst->left);
		printf("%d ",bst->data);
		Inoder(bst->right);
	}
}
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	BT *bst=NULL;
	for(int i=1000;i>=1;i-=7)
	Insert(bst,i);
	Inoder(bst);
	return 0;
}
