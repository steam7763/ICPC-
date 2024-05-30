#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
int T;
typedef unsigned long long ULL;
ULL power[1001224];
ULL sum[1001224];
int main()
{
   // freopen("test.in","r",stdin);
   // freopen("1.out","w",stdout);
    scanf("%d",&T);
    power[0]=1;
    for (int i=1;i<=1000000;++i)
        power[i]=power[i-1]*31;
    while(T--)
    {
        long long ans=0;
        char a[10120],b[1020340];
        scanf("%s%s",a+1,b+1);
        int l1=strlen(a+1),l2=strlen(b+1);
        sum[0]=0;
        ULL s=0;
        for (int i=1;i<=l2;++i)
          sum[i]=sum[i-1]*31+(ULL)(b[i]-'A'+1);
        for (int i=1;i<=l1;++i)
          s=s*31+(ULL)(a[i]-'A'+1);
        for (int i=0;i<=l2-l1;++i)
            if(s==sum[i+l1]-sum[i]*power[l1])
              ++ans;
        printf("%lld\n",ans);
    }
    return 0;
}
/*
3
BAPC
BAPC
AZA
AZAZAZA
VERDI
AVERDXIVYERDIAN
*/
