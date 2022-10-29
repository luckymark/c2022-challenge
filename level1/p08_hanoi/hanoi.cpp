#include<stdio.h>
#include<stdlib.h>

void hanoi(int n, char a, char b, char c) {
	if (n == 1)
	{
		printf("%c->%c\n", a, c);
	}
	else
	{
		hanoi(n - 1, a, c, b);//��n-1�ᵽb
		printf("%c->%c\n", a, c);//��n�ᵽc
		hanoi(n - 1, b, a, c);//��n-1�ᵽc
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
