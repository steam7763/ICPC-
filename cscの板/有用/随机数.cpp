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
ͨʽ
 
����һ����Χ�������ͨ�ñ�ʾ��ʽ�ǣ�
 ȡ��[0,x)�����������rand()%x��
 ȡ��[a,b)�����������rand()%(b-a)+a��
 ȡ��[a,b]�����������rand()%(b-a+1)+a��
 ȡ��(a,b]�����������rand()%(b-a)+a+1��
 ȡ��0-1֮��ĸ�������rand()/double(RAND_MAX)��

*/
