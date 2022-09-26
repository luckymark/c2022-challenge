#include<stdio.h>
#include<math.h>
#include<time.h>
void main()
{
	clock_t t1 = clock(), t2;//开始计时
	printf("2 ");
	for (int i = 3; i < 1000; i++)
	{
		for (int j = 3; j < sqrt((float)i); j += 2)
		{
			if (i % j == 0)
			{
				goto next;
			}
		}
		printf("%d ", i);
		next : i++;
	}
	t2 = clock();//结束计时
	printf("\n\033[40;32m程序运行的时间为%dms", t2 - t1);
}