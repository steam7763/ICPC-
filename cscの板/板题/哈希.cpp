#include<bits/stdc++.h>
#define rg register
#define ull unsigned long long
using namespace std;
const int MAXN=1001001;
const int prime=233317;
const ull mod=212370440130137957ll;
ull base=131;
ull a[MAXN];
int n,m,ans;
char s[MAXN];
inline ull Hash(char s[])
{
    int len=strlen(s+1);
    ull ans=0;
    for(int i=1;i<=len;i++)
        ans = (ans * base + (ull)s[i])%mod+prime;
    return ans;
}
signed main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%s",s);
        a[i] = Hash(s);
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++)
        if(a[i]!=a[i+1])
            ans++;
    printf("%d",ans);
	return 0;
}
