#include"wuziqi.h"

void Judge(int row, int col) {//�ж�ʤ����ƽ�֣�ƽ���ж���
	int flag = 0;
	flag = check(row, col);
	settextstyle(40, 20, L"����");
	settextcolor(BLACK);
	if (step == 255) {
		flag = 1;
		outtextxy(950, 250, L"˫��ƽ��");
	}
	if (flag == 1 && board[row][col] == THEBLACK) {
		outtextxy(950, 250, L"���ӻ�ʤ");
	}
	else if (flag == 1 && board[row][col] == THEWHITE) {
		outtextxy(950, 250, L"���ӻ�ʤ");
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
