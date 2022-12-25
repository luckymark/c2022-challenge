#include<time.h>
#include"p08_hanoi.h"
int main() {
	int Num;
	clock_t time, start, end;
	char A = 'A', B = 'B', C = 'C';
	scanf_s("%d", &Num);
	start = clock();
	hanoi(Num, A, B, C);
	end = clock();
	time = end - start;
	printf("%ld", time);
	return 0;
}