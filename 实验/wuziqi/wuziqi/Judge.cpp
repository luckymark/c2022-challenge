#include"wuziqi.h"

void Judge(int row, int col) {//判断胜利与平局（平局判定）
	int flag = 0;
	flag = check(row, col);
	settextstyle(40, 20, L"楷体");
	settextcolor(BLACK);
	if (step == 255) {
		flag = 1;
		outtextxy(950, 250, L"双方平局");
	}
	if (flag == 1 && board[row][col] == THEBLACK) {
		outtextxy(950, 250, L"黑子获胜");
	}
	else if (flag == 1 && board[row][col] == THEWHITE) {
		outtextxy(950, 250, L"白子获胜");
	}
	if (flag == 1) {
		step = 0;
		for (int i = 0; i < ROW; i++) {
			for (int j = 0; j < COL; j++) {
				vision[i][j] = 0;
			}
		}
		ButtonClick2();
		return;
	}
	return;
}
