#include<stdio.h>
#include<stdlib.h>
int main()
{
	int input = 0;
	int n = 0;
	printf("请输入一个数字\n");
	scanf_s("%d", &input);
	if (input == 1)
	{
		printf("这不是一个素数\n");
	}
	else
	{
		for (int i = 2; i < input; i++)
		{
			if (input % i == 0)
			{
				n = 1;
				break;
			}
		}
		if (n == 0)
		{
			printf("这是一个素数\n");
		}
		else
		{
			printf("这不是一个素数\n");
		}
	}
	system("pause");
	return 0;
}