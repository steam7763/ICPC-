#include<bits/stdc++.h>
#define re register
#define int long long
using namespace std;
const int MAXN=1001000ll;
int c[MAXN];
int n,m,last,now,opt;
inline int lowbit(int x)
{
    return x&(-x);
}
inline void update(int x,int v)
{
    for(;x<=n;x+=lowbit(x))
        c[x]+=v;
    return ;
}
inline int query(int x)
{
    int ans=0ll;
    for(;x;x-=lowbit(x))
        ans+=c[x];
    return ans;
}
signed main()
{
    scanf("%lld%lld", &n, &m);
    for (int i = 1ll; i <= n; i++)
    {
        scanf("%lld", &now);
        update(i, now - last);
        last = now;
    }
    while (m--)
    {
        scanf("%lld", &opt);
        int x, y, k;
        if (opt == 1ll)
        {
            scanf("%lld%lld%lld", &x, &y, &k);
            update(x, k);
            update(y + 1ll, -k);
        }
        if (opt == 2ll)
        {
            scanf("%lld", &x);
            printf("%lld\n", query(x));
        }
    }
    return 0;
}
