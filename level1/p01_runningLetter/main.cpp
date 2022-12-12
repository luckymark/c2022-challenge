#include<iostream>
#include<windows.h>
using namespace std;

const int L = 0, R = 20;
int main() 
{
	int flag = 1, cur = 0;
	while (true)
	{
		for (int i = 0; i <= cur; i++)
			putchar(' ');
		putchar('%');
		cur += flag;
		if (cur == L || cur == R)
			flag = -flag;
		Sleep(100);
		system("cls");
	}
	return 0;
}