#include<stdio.h>
#include<stdlib.h>
int main()
{
	int input = 0;
	int n = 0;
	printf("������һ������\n");
	scanf_s("%d", &input);
	if (input == 1)
	{
		printf("�ⲻ��һ������\n");
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
			printf("����һ������\n");
		}
		else
		{
			printf("�ⲻ��һ������\n");
		}
	}
	system("pause");
	return 0;
}