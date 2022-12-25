#include <stdio.h>
#include<time.h>
int main()
{
	int num, i = 0, c = 0;
	clock_t time, s, e;
	scanf_s("%d", &num);
	s = clock();
	if (num == 2) { ++c; printf("y "); }
	else if (num % 2 == 0 || num == 1) { c += 2;; printf("n "); }
	else {
		c += 2;
		for (i = 3; i * i <= num; i += 2) {
			++c;
			if (num % i == 0) {
				break;
			}
		}

		if (i * i > num) { printf("y "); }
		else { printf("n "); }
	}
	e = clock();
	time = e - s;
	printf("%ld %d", time, c);
	return 0;
}