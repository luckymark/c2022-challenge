#include"wuziqi.h"

int Settled_Situation(int color){//color表示是对黑子还是白子估值
	int total = 0,pointscore = 0;

	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COL; j++) {
			if (board[i][j] != 0) {
				pointscore = SituationValuation(i, j, color);
				total = total + pointscore;
				pointscore = 0;
			}
		}
	}

	return total;
}
