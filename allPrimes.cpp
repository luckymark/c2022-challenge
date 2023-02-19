#include <stdio.h>
#include<time.h>
int main()
{   
	clock_t start, end,time;
	start = clock();
	int count=0,j;
	int p[200]={};
	int pr = 0,i;
	p[pr] = 2;
	p[++pr] = 3;
	for ( i = 5; i <1000; i+=2) {
		for( j=0;p[j] * p[j] <= i; ++j) {
			++count;
			if (i%p[j] == 0)
			{
				break;
			}
		}
		if (i < p[j] * p[j]) { ++pr; p[pr] = i; }
	}
	for (i = 0; i < pr; ++i) {
		printf("%d ", p[i]);
	}
	end = clock();
	time =end-start;
	printf("time=%ldms ",time);
	printf("%d", count);
	return 0;
}