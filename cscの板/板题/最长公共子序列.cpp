#include <bits/stdc++.h>
using namespace std;
const int MAXN=100001;
int n,len;
int a[MAXN],b[MAXN],mp[MAXN],f[MAXN];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        mp[a[i]]=i;
    }
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&b[i]);
        f[i]=0x7fffffff;
    }
    for(int i=1;i<=n;i++)
    {
        int l=0,r=len,mid;
        if(mp[b[i]]>f[len])
            f[++len]=mp[b[i]];
        else
        {
            while(l<r)
            {
                mid=(l+r)>>1;
                if(f[mid]>mp[b[i]])r=mid;
                else l=mid+1;
            }
            f[l]=min(mp[b[i]],f[l]);
        }
    }
    printf("%d",len);
    return 0;
}
