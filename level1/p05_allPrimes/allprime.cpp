#include<stdio.h>
#include<time.h>
int main()
{
	clock_t start, end;
	double time;
	start = clock();
	int prime[100];
	prime[0] = 3;
	int head = 0;
	printf("%d ", 3);
	for (int i = 3; i <= 997; i += 2)
	{
		int flag = 1;
		for (int j = 0; j <= head; j++)
		{
			if (i % prime[j] == 0)
			{
				flag = 0;
			}
		}
		if (flag)
		{
			printf("%d ", i);
			head++;
			prime[head] = i;
		}
	}
	end = clock();
	time = (double)(end - start);
	printf("\n时间为%f", time);//时间输出不了
	return 0;
}