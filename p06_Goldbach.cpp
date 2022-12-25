#include<stdio.h>
#include<time.h>
#include"p02_isPrime.h"
int main() {
	clock_t time;
	for (int num = 6; num <= 100; ++num) {
		int flag = 0;
		for (int a = 2; a < num; ++a) {
			if (isPrime(a) == 1) {
				for (int b = 2; b <= a; ++b) {
					if (isPrime(b) == 1) {
						for (int c = 2; c <= b; ++c) {
							if (isPrime(c) == 1) {
								if (a + b + c == num)
								{
									printf("%d=%d+%d+%d\n", num, c, b, a);
									flag = 1; break;
								}
							}

						}
					}
					if (flag == 1) {
						break;
					}
				}
			}
			if (flag == 1) {
				break;
			}
		}
	}
	printf("%ld", time = clock());
	return 0;
}