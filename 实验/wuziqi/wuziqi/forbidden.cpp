#include"wuziqi.h"

int fobidden(int row, int col) {
	int rank = 0,flag = 0;
	int ko1 = 0,ko2 = 0,ko3 = 0;

	board[row][col] = THEBLACK;

	for (int i = 0; i < 4; i++) {
		rank =Chess_type(row, col, i + 1);
		if (rank == 14) {
			flag = 1;
		}
		else if (rank == 9) {
			ko1++;//���ڼ�¼��������
		}
		else if (rank == 11) {
			ko2++;//���ڼ�¼��������
		}
		else if (rank == 12) {
			ko3++;//���ڼ�¼��������
		}
	}
	if (ko1 == 2 || ko2 == 2 || ko3 == 2) {
		flag = 1;
	}

	board[row][col] = 0;
	return flag;//�������ַ���1 ���򷵻�0
}