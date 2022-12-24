#include <stdio.h>
#include<windows.h>
const int LEFT = 0;
const int RIGHT = 120;
int main(){
	int curPoint = 0, move = 1;
	while (1) {
		curPoint += move;
		if (curPoint == LEFT || curPoint == RIGHT) { move = -move; }
		for (int i = 1; i <= curPoint; ++i) { putchar(' '); }
		putchar('o');
		Sleep(50);
		system("cls");
	}
	return 0;
}