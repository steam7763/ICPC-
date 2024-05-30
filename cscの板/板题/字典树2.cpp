#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int T,n,ch[1000][1000],tot;
bool bo[1000];
char s[1000];
bool Insert(char *s)
{
	int len=strlen(s);
	int u=1;
	bool flag=false;
	for(int i=0;i<len;i++)
	{
		int c=s[i]-'0';
		if(!ch[u][c])
			ch[u][c]=++tot;
		else
			if(i==len-1)
				flag=true;
		u=ch[u][c];
		if(bo[u])
			flag=true;
	}
	bo[u]=true;
	return flag;
}
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		tot=0;
		bool ans=false;
		scanf("%d",&n);
		memset(ch,0,sizeof(ch));
		memset(s,0,sizeof(s));
		memset(bo,0,sizeof(bo));
		for(int i=1;i<=n;i++)
		{
			scanf("%s",s);
			if(Insert(s))
				ans=true;
		}
		if(ans)
			printf("NO\n");
		else
			printf("YES\n");
	}
	return 0;
}
/*
2
3
911
97625999
91125426
5
113
12340
123440
12345
98346
*/
