#include<iostream>
#include<cstdlib>
#include<ctime>
#define random(a,b) (rand()%(b-a+1)+a)
using namespace std;
int main()
{
    srand((unsigned)time(NULL));
    for(int i=0;i<10;i++)
    cout<<random(-1,0)<<' ';
    return 0;
}
/*
通式
 
产生一定范围随机数的通用表示公式是：
 取得[0,x)的随机整数：rand()%x；
 取得[a,b)的随机整数：rand()%(b-a)+a；
 取得[a,b]的随机整数：rand()%(b-a+1)+a；
 取得(a,b]的随机整数：rand()%(b-a)+a+1；
 取得0-1之间的浮点数：rand()/double(RAND_MAX)。

*/
