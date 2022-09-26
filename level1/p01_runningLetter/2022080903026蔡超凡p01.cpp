#include<stdio.h>
#include<Windows.h>
void main()
{
	while (1)
	{
		for (int i = 0; i < 50; i++)
		{
			printf(" a\b");
			Sleep(20);
		}
		printf("\b");
		for (int i = 50; i >= 0; i--)
		{
			printf("a \b\b\b");
			Sleep(20);
		}
	}
}
