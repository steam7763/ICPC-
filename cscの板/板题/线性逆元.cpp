#include<bits/stdc++.h>
using namespace std;
int inv[1000005],p,n;
int main()
{
    inv[1]=1;
    scanf("%d%d",&n,&p);
    for(int i=2;i<=n;i++)
        inv[i]=(p-p/i)*inv[p%i]%p,printf("%d\n",inv[i]);
    return 0;
}
