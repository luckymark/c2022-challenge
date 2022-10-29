//打印2 - 1000以内的所有素数
//打印出总的计算时间(我不会啊
//尽可能优化算法的效率
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
	clock_t start, end;
	start = clock();
	for (int i = 2; i <= 1000; i++)
	{
		int count = 0;
		for (int j = 2; j < i; j++)
		{
			if (i % j == 0)
			{
				count = 1;
				break;
			}
		}
		if (count == 0)
		{
			printf("%d\n", i);
		}
	}
	end = clock();
	printf("运行时间为%fms\n", (double)(end - start) / CLOCKS_PER_SEC);
	system("pause");
	return 0;
}