#include<bits/stdc++.h>
#define rg register
//#define int long long
using namespace std;
const int MAXN=100100;
int tot,n,q;
int Root[MAXN],b[MAXN];
struct Node
{
    int num,val;
    inline bool operator < (const Node &x)const {return val < x.val;}
}A[MAXN];
struct Tree
{
    int tim,l,r;
    Tree(){tim=0,l=r=NULL;}
}D[MAXN<<5];
inline void update(int &x,int now,int l,int r,int pos,int G)
{
    x = ++tot;
    D[x] = D[now];
    D[now].tim += G;
    if(l==r) return ;
    int mid = (l+r)>>1;
    if(pos<=mid) update(D[x].l,D[now].l,l,mid,pos,G);
    else          update(D[x].r,D[now].r,r,mid+1,pos,G);
    return ;
}
inline int Search(int x,int now,int l,int r,int K)
{
    if(l==r) return l;
    int G=D[D[x].l].tim-D[D[now].l].tim;
    int mid=(l+r)>>1;
    if(G>=K)return Search(D[x].l,D[now].l,l,mid,K);
    return Search(D[x].r,D[now].r,mid+1,r,K-G);
}
signed main()
{
    scanf("%d",&n);
    scanf("%d",&q);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&A[i].val);
        A[i].num=i;
    }
    sort(A+1,A+1+n);
    for(int i=1;i<=n;i++) b[A[i].num]= i;
    for(int i=1;i<=n;i++) update(Root[i],Root[i-1],1,200000,b[i],1);
    for(int i=1,l,r,k;i<=q;i++)
    {
        scanf("%d%d%d",&l,&r,&k);
        printf("%d\n",A[Search(Root[r],Root[l-1],1,200000,k)].val);
    }
    return 0;
}
