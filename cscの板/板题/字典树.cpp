#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int MAXN=10000;
struct kkk
{
	int ch[27];
	bool end;
}rt[MAXN];
int tot=1;
void Insert(string a)
{
	int p=1;
	for(int i=1;i<=a.size();i++)
	{
		if(rt[p].ch[a[i]-'a'+1]==0)
		{
			tot++;
			rt[p].ch[a[i]-'a'+1]=tot;
		}
		p=rt[p].ch[a[i]-'a'+1];
	}
	rt[p].end=1;
}
bool q(string a)
{
	int p=1;
	for(int i=1;i<=a.size();i++)
	{
		if(rt[p].ch[a[i]-'a'+1]==0)
			return false;
		p=rt[p].ch[a[i]-'a'+1];
	}
	if(rt[p].end)
		return true;
	else
		return false;
	
}
int main()
{
	string a;
	a="sona";
	Insert(a);
	a="sonb";
	Insert(a);
	a="sona";
	if(q(a))
		printf("YES");
	else
		printf("NO");
	return 0;
}
