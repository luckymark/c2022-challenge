#include<stdio.h>
#include<stdlib.h>

void hanoi(int n, char a, char b, char c) {
	if (n == 1)
	{
		printf("%c->%c\n", a, c);
	}
	else
	{
		hanoi(n - 1, a, c, b);//把n-1搬到b
		printf("%c->%c\n", a, c);//把n搬到c
		hanoi(n - 1, b, a, c);//把n-1搬到c
	}

}

int main()
{
	int n = 0;
	char a = 'a', b = 'b', c = 'c';
	scanf_s("%d", &n);

	hanoi(n, a, b, c);
	system("pause");
	return 0;
}
