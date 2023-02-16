//游戏主界面
#include"wuziqi.h"
void Game(int t) {//初始化游戏主界面
	InitBoard();
	GameUI();
	while (1) {
		if (t == 1) {
			PlayerMove(1);
			AI(THEWHITE);
		}
		else if (t == 2) {
			Move();//玩家对战
		}
		else if (t == 3) {
			AI(THEBLACK);
			PlayerMove(-1);
		}
		else {//电脑对战
			AI(THEBLACK);
			AI(THEWHITE);
		}
	}
	getchar();
}