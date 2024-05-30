#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<stack>
using namespace std;
int n,m;
stack<int>s;
const int N = 200000;
int C[600][600];
int ind[N];
int head[N],tot;
void dfs(int x)
{
    for(int v=1; v<=n; v++)
        if(C[x][v])
        {
            C[x][v]--;
            C[v][x]--;
            dfs(v);
        }
    s.push(x);
}
int main()
{
    scanf("%d",&m);
    for(int i=1; i<=m; i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        n=max(max(a,b),n);
        C[a][b]++;
        C[b][a]++;
        ind[a]++;
        ind[b]++; 
    }
    int root=1;
    for(int i=1; i<=n; i++)
        if(ind[i]%2==1)
        {
            root=i;
            break;
        }
    dfs(root);
    while(!s.empty())
    {
        printf("%d\n",s.top());
        s.pop();
    }
}
