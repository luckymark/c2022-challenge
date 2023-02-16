#include"wuziqi.h"

int Compete_Chess_Repentance() {
	int x, y;
	if (step == 0) {
		return 0;
	}
	setfillcolor(RGB(255, 153, 00));
	setcolor(BLACK);

	y = stackpop(stack);
	x = stackpop(stack);
	board[x][y] = 0;
	Neighbor_Location(x, y, -1);
	solidcircle((y + 1) * 50, (x + 1) * 50, 25);
	line((y + 1) * 50 - 25, (x + 1) * 50, (y + 1) * 50 + 25, (x + 1) * 50);
	line((y + 1) * 50, (x + 1) * 50 - 25, (y + 1) * 50, (x + 1) * 50 + 25);
	step--;

	return 0;
}
