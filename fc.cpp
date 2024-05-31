#include<bits/stdc++.h>
using namespace std;
#define ll long long 
int main()
{
	ll t=0;
	while(1){
		cout<<"test "<<(++t)<<endl;
		system("data.exe > data.in");
		system("solve.exe < data.in > solve.out");
		system("std.exe < data.in > std.out");
		if(system("fc std.out solve.out > diff.log")){
			cout<<"WA"<<endl;
			getchar();
			break;
		}
		cout<<"AC"<<endl;
	}
	return 0;
 } 
