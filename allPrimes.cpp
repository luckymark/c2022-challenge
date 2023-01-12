#include<stdio.h>
#include<time.h>
#include<math.h>

bool prime(int n);

int main()
{
	clock_t a=clock();
	for(int i=2;i<=1000;++i) {
		if(prime(i)) printf("%d ",i);
	}
	clock_t b=clock();
	printf("\n%lf",double(b-a) / CLOCKS_PER_SEC);
	return 0;
}

bool prime(int n)
{
	for(int i=2;i<=sqrt(n);++i) {
		if(n%i==0) return false;
	}
	return true;
}
