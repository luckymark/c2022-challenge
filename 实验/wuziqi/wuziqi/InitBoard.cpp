//��ʼ������
#include"wuziqi.h"
void InitBoard() {
	int i, j;
	for (i = 0; i < ROW; i++) {
		for (j = 0; j < ROW; j++) {
			board[i][j] = 0;//0��������� 1������� -1�������
			vision[i][j] = 0;
		}
	}
}