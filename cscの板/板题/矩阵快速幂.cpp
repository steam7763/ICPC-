#include<bits/stdc++.h>
#define rg register
//#define int long long
using namespace std;
const int MAXN=101;
const long long mod=1000000007;
int n;
long long k;
struct matrix
{
    long long s[MAXN][MAXN];
    matrix()
    {
        memset(s,0,sizeof(s));
    }
        
}id;
matrix operator * (const matrix &a,const matrix &b)
{
    matrix res;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            for(int k=1;k<=n;k++)
                res.s[i][j] = (res.s[i][j] + (a.s[i][k] * b.s[k][j])%mod)%mod;
    return res;
}
matrix operator ^ (matrix a,long long b)
{
    matrix res;
	for(int i=1;i<=n;i++)
    	res.s[i][i]=1;
    while(b)
    {
        if(b&1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}
signed main()
{
//看数据范围，看数组，long long，freopen
    scanf("%d%lld",&n,&k);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            scanf("%lld",&id.s[i][j]);
    matrix ass = id ^ k;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
            printf("%lld ",ass.s[i][j]);
        puts("");
    }
//看数据范围，看数组，long long，freopen
	return 0;
}
