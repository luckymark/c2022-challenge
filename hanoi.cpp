#include<stdio.h>
#include<time.h>
void hano(int n,char A,char B,char C) {
	if (n == 1) {
		printf("%c->%c\n",A,C);
	}
	else {
		hano(n - 1, A, C, B);
		printf("%c->%c\n",A,C);
		hano(n - 1, B, A, C);
	}
}
int main() {
	int n;
	clock_t time,start,end;
	char A='A', B='B' ,C='C';
	scanf_s("%d",&n);
	start = clock();
	hano(n, A, B, C);
	end = clock();
	time = end - start;
	printf("%ld", time);
	return 0;
}