#include<stdio.h>
#include<stdlib.h>
#include<math.h>
void main()
{
	int x;
	scanf_s("%d", &x);
	if (x < 2)
	{
		printf("error");
		exit(0);
	}
	if (x == 2 || x == 3)
	{
		printf("yes");
		exit(0);
	}
	for (int i = 2; i <=sqrt((double)x)+2; i ++)
	{
		if (x % i == 0)
		{
			printf("no");
			exit(0);
		}
	}
	printf("yes");
}