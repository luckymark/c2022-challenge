//初始化棋盘
#include"wuziqi.h"
void InitBoard() {
	int i, j;
	for (i = 0; i < ROW; i++) {
		for (j = 0; j < ROW; j++) {
			board[i][j] = 0;//0代表空棋盘 1代表黑子 -1代表白子
			vision[i][j] = 0;
		}
	}
}