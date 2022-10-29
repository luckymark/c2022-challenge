#include<stdio.h>
#include<stdlib.h>
int main()
{
	printf("请输入水仙花数的位数\n");
	int n = 0;
	scanf_s("%d", &n);
	int num = 1;
	for (int i = 1; i < n; i++)
	{
		num *= 10;
	}
	
	
	for (int i = num;i < num * 10; i++)
	{
		int num1 = num;
		int jug = i;
		int a = 0;
		int sum = 0;
		int num2 = 1;
		for (int j = 0; j < n; j++)
		{
			a = jug / num1;
			for (int k = 0; k < n; k++)
			{
				num2 *= a;
			}
			sum += num2;
			a = 0;
			jug %= num1;
			num1 /= 10;
			num2 = 1;
		}
		if (sum == i)
		{
			printf("%d\n", sum);
		}
	}
	system("pause");
	return 0;
}