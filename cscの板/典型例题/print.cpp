#include <cstdlib>
#include <cstdio>
#include <string>
#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
	freopen("1.txt","w",stdout);
	int n=100,m=100;
	for(double i=0;i<=n;i+=0.2)
	{
	  for(double j=0; j<=n;j+=0.1)
	  {
	  	if(i>=60&&abs((i-42)*(i-42)+(j-50)*(j-50)-1225)<=10||i>=60&&abs((i-20)*(i-20)+(j-50)*(j-50)-2500)<=10||abs((i-35)*(i-35)+(j-30)*(j-30)-9)<=1||abs((i-35)*(i-35)+(j-70)*(j-70)-9)<=1||abs((i-50)*(i-50)+(j-50)*(j-50)-2000)<=10)
	  //	if(abs((j*j)/9-(i*i)/4-1)<=1)
	  //	if(abs((i*i)+(j*j)-80*j)<=10)
	 // if(abs(i-10*sin(j+1)-50)<=1||i>=40&&abs((i-40)*(i-40)+(j-40)*(j-40)-900)<=10)
	  	{
	  		putchar('@');
		  }
		  else
		  putchar(' ');
	  }
	  putchar('\n');
	}
}
