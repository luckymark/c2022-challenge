#include"wuziqi.h"

int Kill(int depth ,int player,int color) {
	//player=1表示接下来是对手下棋来进入下一层 player=-1表示自己下棋来进入下一层 
	int key = 0; //返回值
	int v = 0;
	if (depth == DEPTH + 7) {
		return 0;
	}//算杀失败返回0
	
	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COL; j++) {
			if (board[i][j] == 0 && vision[i][j] != 0) {
				if (player == -1 && key == 0) {
					board[i][j] = color;
					Neighbor_Location(i, j, 1);
					v = check(i, j);
					if (v == 2 || v==4 ) {
						key = Kill(depth + 1, 1, color);
					}//算杀半成功
					else if (v == 1 || v == 3 || v == 5 || v == 6) {
						key = 1;
					}//算杀成功;

					board[i][j] = 0;
					Neighbor_Location(i, j, -1);
				}
				else if(player == 1 && thedefend(i, j, color) != 0){
					board[i][j] = -color;
					Neighbor_Location(i, j, 1);

					key = Kill(depth + 1, -1, color);

					board[i][j] = 0;
					Neighbor_Location(i, j, -1);
				}
			}
		}
	}
	return key;
}