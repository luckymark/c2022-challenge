#include"wuziqi.h"

void AI(int color) {
	int score = -200, Max = -1e9;//��ʼ�����������ֵ
	int x = 7, y = 7;//��ʼ������λ��
	int flag1 = 0, flag2 = 0, flag3 = 0, flag4 = 0, flag5 = 0;
	int attack = 0, defend = 0,kill = 0;

	if (step == 0 && color== THEBLACK) {//���ֵ�һ��������Ԫ
		board[x][y] = THEBLACK;
		Neighbor_Location(x, y, 1);
		setfillcolor(RGB(00, 00, 00));
		solidcircle((y + 1) * 50, (x + 1) * 50, 25);
		//��¼����
		count_step(x, y, THEBLACK);
	}
	else {
		for (int i = 0; i < ROW; i++) {
			for (int j = 0; j < COL; j++) {
				if (board[i][j] == 0 && vision[i][j] != 0 && flag1 == 0 
					&& ( (color==THEBLACK && fobidden(i, j) == 0 ) || color == THEWHITE) ) {
					defend = thedefend(i, j, -color);

					board[i][j] = color;
					Neighbor_Location(i, j, 1);

					attack = check(i, j);
					kill = Kill(2, 1, color);

					if (attack == 1) {
						x = i;
						y = j;
						flag1 = 1;
					}//�ȿ��ҷ�����
					if (flag1 == 0 && flag2 == 0 && defend == 1) {
						x = i;
						y = j;
						flag2 = 1;
					}//�ٿ��з���һ������ ���� �����

					if (flag1 == 0 && flag2 == 0 && flag3 == 0) {
						if (attack == 7) {
							x = i;
							y = j;
							flag3 = 1;
						}//�ҷ�����
					}
					if (flag1 == 0 && flag2 == 0 && flag3 == 0 && flag4 == 0) {
						if (attack == 5 || attack == 6 || (attack == 4 && kill == 1) || defend == 2) {
							x = i;
							y = j;
							flag4 = 1;
						}//Ȼ�����ҷ���������ɱ�ĵ�͵з���һ���ɻ��ĵĵ�
					}
					if (flag1 == 0 && flag2 == 0 && flag3 == 0 && flag4 == 0 && flag5==0) {
						if ((kill == 1 && attack == 2) || attack == 3) {
							x = i;
							y = j;
							flag5 = 1;
						}//Ȼ�����ҷ�������ɱ�ĵ�
						else {
							score = min_max_dfs(2, 1, color, Max, 1e9);
							if (score > Max) {
								Max = score;
								x = i;
								y = j;
							}
						}//���϶�����ִ������ Ѱ��4��֮�����ŵ�
					}

					board[i][j] = 0;
					Neighbor_Location(i, j, -1);
				}
			}
		}
		set(x, y);
		
	}
}