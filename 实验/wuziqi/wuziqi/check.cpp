#include"wuziqi.h"

int check(int row, int col) {
	int rank = 0,flag = 0;
	int ko = 0, ko1 = 0, ko2 = 0, ko3 = 0;

	for (int i = 0; i < 4; i++) {
		rank = Chess_type(row, col, i + 1);
		if (rank >= 13) {
			ko = 1;
			break;
		}
		else if (rank == 9) {//活三 
			ko1++;
		}
		else if (rank == 11) {//冲四
			ko2++;
		}
		else if (rank == 12) {//活四
			ko3 = 1;
		}
	}

	if (ko1 == 1 && ko2 == 0) {
		flag = 2;//单活三
	}
	else if (ko1 >= 2 && ko2 == 0) {
		flag = 3;//双活三
	}
	else if (ko1 == 0 && ko2 == 1) {
		flag = 4;//单冲四
	}
	else if (ko1 == 0 && ko2 >= 2) {
		flag = 5;//双冲四
	}
	else if (ko1 >= 1 && ko2 >= 1) {
		flag = 6;//一活三，一冲四
	}
	if (ko3 == 1) {
		flag = 7;//活四
	}
	if (ko == 1) {
		flag = 1;//成五返回1
	}

	return flag;
}