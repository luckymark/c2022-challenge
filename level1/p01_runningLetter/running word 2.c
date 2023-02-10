#include<stdio.h>
#include<stdlib.h>
#define N 118
int main()
{
	int word = 1, place = 0;
	while (1)
	{
		place += word;
		if (place == 0 || place == N)
		{
			word = -word;
		}
		system("cls");
		for (int i = 1; i <= place; ++i)
		{
			putchar(' ');
		}
		printf("3");
	}
	return 0;
}
