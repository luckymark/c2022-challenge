//�����ֵ
#include"wuziqi.h"

int SituationValuation(int row, int col, int color) {//ע�� ���������������������board[col][row]���Ѿ�����
	int Valuation = 0;//���ڹ�ֵ

	int Val_White[13] = { 0,2,5,2,5,20,5,15,200,20,200,1000000 , 9999999};
	int Val_BLACK[13] = { 0,2,5,2,5,20,5,15,200,20,200,1000000 , 9999999};

	int flag = 0;

	if (board[row][col] == color) {
		flag = 1;
	}
	else {
		flag = -1;
	}

	if (color == THEWHITE) {
		for (int i = 0; i < 4; i++) {
			Valuation += flag * Val_White[Chess_type(row, col, i + 1) - 1];
		}
	}
	else if (color== THEBLACK) {
		for (int i = 0; i < 4; i++) {
			Valuation += flag * Val_BLACK[Chess_type(row, col, i + 1) - 1];
		}
	}
	
	return Valuation;
}
