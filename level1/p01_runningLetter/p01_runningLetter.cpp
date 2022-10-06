#include <stdio.h>
#include <iostream>
using namespace std;
int main()
{
	int L=0,R=118;
	int move=1,now=0;
	while(1)
	{
		now+=move;
		if(now==L||now==R)
		{
			move=-move;
		}
		#ifdef _WIN32	
			system("cls");//windowsϵͳ 
		#else
			system("clear");//Linuxϵͳ 
		#endif
		for(int i=1;i<=now;i++)
		{
			cout<<' ';
		}	
		cout<<'A';
	}
	return 0;
}
