#include <stdio.h>
#include<time.h>
int main()
{
	clock_t start, end, time;
	start = clock();
	int count = 0;
	int prime[168] = {};
	int i, j;
	int amount = 0;
	prime[0] = 2;
	prime[++amount] = 3;
	for (i = 5; i < 1000; i += 2) {
		for (j = 0; prime[j] * prime[j] <= i; ++j) {
			++count;
			if (i % prime[j] == 0)
			{
				break;
			}
		}
		if (i < prime[j] * prime[j]) {  prime[++amount] = i; }
	}
	for (i = 0; i < amount; ++i) {
		printf("%d ", prime[i]);
	}
	end = clock();
	time = end - start;
	printf("time=%ldms ", time);
	printf("%d", count);
	return 0;
}