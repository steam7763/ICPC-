#include<bits/stdc++.h>
#define rg register
using namespace std;
const int MAXN=100100;
const int power=4;
const int base=10000;
char A[MAXN],B[MAXN];
struct num
{
    int a[MAXN];
    num(){ memset(a,0,sizeof(a));}
    num(char *s)
    {
        memset(a,0,sizeof(a));
        int len = strlen(s);
        a[0]=(len + power - 1) / power;
        for(int i = 0,t = 0, w; i < len; i++, w *= 10)
        {
            if(i % power == 0) { w = 1, t++;}
            a[t] += w*(s[i]-'0');
        }
    }
    void print()
    {
        printf("%d",a[a[0]]);
        for(int i = a[0] - 1;i > 0; i--)
            printf("%0*d",power,a[i]);
        puts("");
    }
}p,q,ans;
num operator + (const num &p,const num &q)
{
    num c;
    c.a[0] = max(p.a[0],q.a[0]);
    for(int i=1;i<=c.a[0];i++)
    {
        c.a[i  ] += p.a[i] + q.a[i];
        c.a[i+1] += c.a[i]  /  base;
        c.a[i  ]  = c.a[i]  %  base;
    }
    if(c.a[ c.a[0] +1 ]) c.a[0]++;
    return c;
}
num operator - (const num &p,const num &q)
{
    num c = p;
    for(int i=1;i<=c.a[0];i++)
    {
        c.a[i] -= q.a[i];
        if(c.a[i] < 0)
        {
            c.a[i  ] += base;
            c.a[i+1]--;
        }
    }
    while(c.a[0] > 0 && !c.a[ c.a[0] ]) c.a[0]--;
    return c;
}
num operator * (const num &p,const num &q)
{
    num c;
    c.a[0] = p.a[0] + q.a[0] - 1;
    for(int i=1;i<=p.a[0];i++)
    for(int j=1;j<=q.a[0];j++)
    {
        c.a[i+j-1] += p.a[i] *  q.a[j];
        c.a[i+j  ] += c.a[i+j-1] /base;
        c.a[i+j-1]  = c.a[i+j-1] %base;
    }
    if(c.a[ c.a[0] + 1]) c.a[0]++;
    return c;
}
signed main()
{
    scanf("%s%s",&A,&B);
    reverse(A,A+strlen(A));
    reverse(B,B+strlen(B));
    p = num(A), q = num(B);
    ans = p + q;
    printf("p+q:");
    ans.print();
    ans = p * q;
    printf("\np*q:");
    ans.print();
    ans = p - q;
    printf("\np-q:");
    ans.print();
    return 0;
}
