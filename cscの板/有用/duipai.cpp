#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <fstream>
#include <cstdlib>

using namespace std;

string name;

inline bool cmp()
{
  
  ifstream fin1(name+"1.in");
  ifstream fin2(name+".in");
  char c1='\0',c2='\0';
  int i=1,j=0;
  while(fin1.eof()||fin2.eof())
  {
    
    j++;
    fin1>>c1;
    fin2>>c2;
    if(c1!=c2)
    {
      
      cout<<"��"<<i<<"��"<<j<<"�г��ִ���"<<endl;
      cout<<"���б�׼���Ϊ��"<<c1<<",�������Ϊ:"<<c2<<endl;
      return 0;
      
    }
    if(c1=='\n')
    {
      
      i++;
      j=0;
      
    }
    
  }
  return 1;
  
}

int main()
{
  
  cin>>name;
  
  string name0=".exe";
  string name1=name+name0;
  int ans=0;
  do
  {
    
    ans++;
    system("make.exe");
    int t=0;
    char nname1[10]={};
    while(name1[t]!='\0') nname1[t]=name1[t],t++;
    system(nname1);
    system("baoli.exe");
    cout<<ans<<endl;
    
  }while(cmp());
  
  return 0;
  
}
