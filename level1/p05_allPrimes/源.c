#include<stdio.h>
#include<time.h>
#include<math.h>
int main()
{
	int i,j,count=0;
	double sum;
	clock_t start_t, end_t;
	start_t = clock();
	for (i = 2; i <= 1000; i++)
	{
		for (j = 2; j <= sqrt(i); j++)
		{
			if (i % j == 0)
			{
				count++; break;
			}
		}
		if (count == 0)
		{
			printf("%d\n", i);
		}
		count = 0;
	}
	end_t = clock();
	sum = (double)(end_t - start_t) / CLOCKS_PER_SEC;
	printf("%f", sum);
	return 0;
}