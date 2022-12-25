#include"p02_isPrime.h"
int isPrime(int num) {
	int i;
	if (num == 2) { return 1; }
	else if (num % 2 == 0||num==1) { return 0; }
	else {
		for (i = 3; i * i <= num; i += 2) {
			if (num % i == 0) { break; }
		}if (i * i > num) { return 1; }
		else return 0;
	}
}