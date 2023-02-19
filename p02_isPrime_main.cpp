#include"p02_isPrime.h"
#include<stdio.h>
int main() {
	int Num;
	scanf_s("%d",&Num);
	if (isPrime(Num) == 1) { printf("yes"); }
	else { printf("no"); }
	return 0;
}