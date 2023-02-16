#include"wuziqi.h"
void set(int row ,int col) {
	int color = -1, t = 0;
	if (step % 2 == 1) {
		color = 255;
		t = -1;
	}
	else if (step % 2 == 0) {
		color = 0;
		t = 1;
	}
	board[row][col] = t;
	Neighbor_Location(row, col, 1);

	setfillcolor(RGB(color, color, color));
	solidcircle((col + 1) * 50, (row + 1) * 50, 25);
	
	count_step(row, col, t);//记录步数
	Judge(row, col);//判断胜负
}


