#include<stdio.h>
#include<math.h>
void proveGoldbach(int *p);
int* find_primenumber();


void main()
{
	int* p = find_primenumber();
	proveGoldbach(p);
}




int* find_primenumber()
{
	int prime_number[25] = { 2,3 }, count = 1;
	for (int i = 4; i < 100; i++)
	{
		int f = 1;
		for (int j = 2; j <= (double)sqrt(i); j++)
		{
			if (i % j == 0)
			{
				f = 0;
				break;
			}
		}
		if (f)
		{
			count++;
			prime_number[count] = i;
		}
	}
	return prime_number;
}

void proveGoldbach(int *p)
{
	for (int i = 6; i <= 100; i++)
	{
		int f = 0;
		for (int j = 0; j < 25; j++)
		{
			for (int k = 0; k < 25; k++)
			{
				if (i % 2 == 0 && i == p[j] + p[k] + 2)
				{
					printf("%d = %d + %d + 2\n", i, p[j], p[k]);
					f = 1;
					break;
				}
				if (i % 2 == 1 && i == p[j] + p[k] + 3)
				{
					printf("%d = %d + %d + 3\n", i, p[j], p[k]);
					f = 1;
					break;
				}
				if (f) break;
			}
			if (f) break;
		}
	}
	printf("\033[40;31m100以内哥德巴赫猜想得证\n");
}