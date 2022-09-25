#include<stdlib.h>
#include<stdio.h>
#include<windows.h>
const int L = 0, R = 118;
int main()
{
	int flag = 1, cur = 0;
	while (1)
	{
		cur += flag;
		if (cur == L || cur == R)
		{
			flag = -flag;
		}
		system("cls");
		for (int i = 1; i <= cur; i++)
		{
			putchar(' ');
		}
		putchar('%');
		sleep(111);
	}
	return 0;
}