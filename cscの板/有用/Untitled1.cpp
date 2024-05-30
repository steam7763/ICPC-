#include<bits/stdc++.h>
#define rg register
//#define int long long
using namespace std;
const int MAXN=100100;
struct trie
{
    int nex[MAXN][27],cnt=0;
    bool ex[MAXN];
    void ins(char *s,int l)
    {
        int p=0;
        for(int i=1;i<=l;i++)
        {
            int c=s[i]-'a'+1;
            if(!nex[p][c]) nex[p][c] =++cnt;
            p=nex[p][c];
        }
        ex[p]=1;
    }
};
signed main()
{


}
