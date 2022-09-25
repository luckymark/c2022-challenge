#include<stdio.h>
#include<time.h>
void fun(int n, char start, char aim, char empty)
{
	if (n == 1)
	{
		printf("%c->%c\t", start, aim);
	}
	else
	{
		fun(n - 1, start, empty, aim);
		printf("%c->%c\t", start, aim);
		fun(n - 1, empty,aim,start);
	}
}
int main()
{
	char start = 'A';
	char aim = 'B';
	char end = 'C';
	time_t start_t, end_t;
	double sum;
	start_t = clock();
	fun(64,start,aim,end);
	end_t = clock();
	sum = (double)(end_t - start_t) / CLOCKS_PER_SEC;
	printf("%f", sum);
	return 0;
}