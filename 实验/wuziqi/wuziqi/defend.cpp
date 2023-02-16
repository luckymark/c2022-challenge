#include"wuziqi.h"

int thedefend(int row, int col, int color) {
	int rank = 0, flag = 0;
	int ko = 0, ko1 = 0;;

	board[row][col] = color;

	for (int i = 0; i < 4; i++) {
		rank = Chess_type(row, col, i + 1);
		if (rank >= 13) {//成五
			ko = 1;
			break;
		}
		else if (rank == 12) {//活四 
			ko1 = 1;
		}
	}

	if (ko == 1) {
		flag = 1;
	}
	else if (ko1 == 1) {
		flag = 2;
	}

	board[row][col] = 0;

	return flag;//在对手下一步成五返回1 在对手下一步活四返回2 下一步无成五活四返回0
}
