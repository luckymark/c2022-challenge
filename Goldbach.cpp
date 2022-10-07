#include<stdio.h>
#include<time.h>
int prime(int n) {
	int i ;
	if (n == 2) { return 1; }
	else if (n % 2 == 0) { return 0; }
	else {
		for (i = 3; i * i <= n; i += 2) {
			if (n % i == 0) { break; }
		}if (i * i > n) { return 1; }
		else return 0;
	}
}
int main() {
	clock_t time;
	for (int num = 6; num <= 100; ++num) {
		int flag = 0;
		for (int a = 2; a < num; ++a) {
			if (prime(a) == 1) {
				for (int b = 2; b <= a; ++b) {
					if (prime(b) == 1) {
						for (int c = 2; c <= b; ++c) {
							if (prime(c) == 1) {
								if (a + b + c == num)
								{
									printf("%d=%d+%d+%d\n", num, c, b, a);
									flag = 1;
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