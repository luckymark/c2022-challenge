#include<cstdio>
#include<windows.h>
using namespace std;
const int L=0,R=118;
int main()
{
	int cur=0,flag=1;
	while (1)
	{
		cur+=flag;
		if (cur==L||cur==R) flag=-flag;
		#ifdef _WIN32
			system("cls");
		#else
			system("clear");
		#endif
		for (int i=1;i<=cur;++i)
		{
			putchar(' ');
		}
		putchar('%');
	}
	return 0;
}