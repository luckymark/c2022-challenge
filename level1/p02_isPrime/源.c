#include<stdio.h>
int main()
{
	int a, i,count=0;
	scanf_s("%d", &a);
	for (i = 2; i < a; i++)
	{
		if (a % i == 0)
		{
			count++;
		}
	}
	if (count >= 1)
	{
		printf("%d������", a);
	}
	else
	{
		printf("%d��������", a);
	}
	return 0;
}
