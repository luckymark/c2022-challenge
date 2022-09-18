#include<stdio.h>
void func(int n);
int number_cycle(int a);
static int count = 0;
void main()
{
	int n;
	scanf_s("%d", &n);
	func(n);
}

void func(int n)
{
	char pillar[3] = { 'A','B','C' };

	if (n == 1)
	{
		
		printf("%c -> %c\n", pillar[count], pillar[number_cycle(count + 1)]);
		count++;
		if (count > 2) count = 0;
	}
	if (n == 2)
	{
		func(1);
		printf("%c -> %c\n", pillar[number_cycle(count - 1)], pillar[number_cycle(count + 1)]);
		func(1);
	}
	if (n > 2)
	{
		//递归
		func(n - 1);
		if (n % 2 == 1)
		{
			printf("%c -> %c\n", pillar[number_cycle(count - 2)], pillar[number_cycle(count - 1)]);
		}
		else
		{
			printf("%c -> %c\n", pillar[number_cycle(count - 1)], pillar[number_cycle(count - 2)]);
		}
		//递归
		func(n - 1);
	}
}

int number_cycle(int a)
{
	if (a == -2) return 1;
	else if (a == -1) return 2;
	else if (a == 3) return 0;
	else if (a == 4) return 1;
	else return a;
}

