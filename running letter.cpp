#include <stdio.h>
#include<windows.h>
const int l = 0;
const int r=120;
int main()
{   int a = 0, b = 1;
	while (1) {
		a += b;
		if (a == l || a == r) { b = -b; }
		for (int i = 1; i <= a; ++i) { putchar(' '); }
		putchar('o');
		Sleep(50);
		system("cls");
	}
	return 0;
}