//��Ϸ������
#include"wuziqi.h"
void Game(int t) {//��ʼ����Ϸ������
	InitBoard();
	GameUI();
	while (1) {
		if (t == 1) {
			PlayerMove(1);
			AI(THEWHITE);
		}
		else if (t == 2) {
			Move();//��Ҷ�ս
		}
		else if (t == 3) {
			AI(THEBLACK);
			PlayerMove(-1);
		}
		else {//���Զ�ս
			AI(THEBLACK);
			AI(THEWHITE);
		}
	}
	getchar();
}