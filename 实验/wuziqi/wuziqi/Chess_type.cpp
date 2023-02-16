#include"wuziqi.h"
int Chess_type(int row,int col,int direction) {//只实现棋型判断的功能
	int num = 1;//用于记录连续的棋子数
	int empty = 0;//用于记录空格数
	int x, y;//记录坐标
	int remote[2] = { 0 };//实现空格棋型判断
	
	if (direction == 1) {
		// 方向1 行分级
		x = row; y = col;
		while (true) {//往上
			if (x == 0) {
				break;
			}
			if (board[x - 1][y] == board[x][y]) {
				num++;
				x--;
			}
			else if (board[x - 1][y] == 0) {
				empty++;
				remote[0] = Opposite_shore(x - 2, y, 1, board[row][col]);
				break;
			}
			else {
				break;
			}
		}
		x = row; y = col;
		while (true) {//往下
			if (x == 14) {
				break;
			}

			if (board[x + 1][y] == board[x][y]){
				num++;
				x++;
			}
			else if (board[x + 1][y] == 0){
				empty++;
				remote[1] = Opposite_shore(x + 2, y, 2, board[row][col]);
				break;
			}
			else{
				break;
			}
		}
	}
	else if (direction == 2) {
		//列分级
		x = row; y = col;
		while (true) {//往左
			if (y == 0) {
				break;
			}

			if (board[x][y - 1] == board[x][y]) {
				num++;
				y--;
			}
			else if (board[x][y - 1] == 0) {
				empty++;
				remote[0] = Opposite_shore(x, y - 2, 3, board[row][col]);
				break;
			}
			else{
				break;
			}
		}
		x = row; y = col;
		while (true) {//往右
			if (y == 14) {
				break;
			}

			if (board[x][y + 1] == board[x][y]) {
				num++;
				y++;
			}
			else if (board[x][y + 1] == 0) {
				empty++;
				remote[1] = Opposite_shore(x, y + 2, 4, board[row][col]);
				break;
			}
			else{
				break;
			}
		}
	}
	else if (direction == 3) {
		//左斜线分级
		x = row; y = col;
		while (true) {//左上
			if (x == 0 || y == 0) {
				break;
			}

			if (board[x - 1][y - 1] == board[x][y]) {
				num++;
				x--;
				y--;
			}
			else if (board[x - 1][y - 1] == 0) {
				empty++;
				remote[0] = Opposite_shore(x - 2, y - 2, 5, board[row][col]);
				break;
			}
			else{
				break;
			}
		}

		x = row; y = col;
		while (true) {//右下
			if (x == 14 || y == 14) {
				break;
			}

			if (board[x + 1][y + 1] == board[x][y]) {
				num++;
				x++;
				y++;
			}
			else if (board[x + 1][y + 1] == 0) {
				empty++;
				remote[1] = Opposite_shore(x + 2, y + 2, 6, board[row][col]);
				break;
			}
			else{
				break;
			}
		}
	}
	else if (direction == 4) {
		//右斜线分级
		x = row; y = col;
		while (true) {//右上
			if (x == 0 || y == 14) {
				break;
			}

			if (board[x - 1][y + 1] == board[x][y]) {
				num++;
				x--;
				y++;
			}
			else if (board[x - 1][y + 1] == 0) {
				empty++;
				remote[0] = Opposite_shore(x - 2, y + 2, 7, board[row][col]);
				break;
			}
			else {
				break;
			}
		}

		x = row; y = col;
		while (true) {//左下
			if (x == 14 || y == 0) {
				break;
			}

			if (board[x + 1][y - 1] == board[x][y]) {
				num++;
				x++;
				y--;
			}
			else if (board[x + 1][y - 1] == 0) {
				empty++;
				remote[1] = Opposite_shore(x + 2, y - 2, 8, board[row][col]);
				break;
			}
			else {
				break;
			}
		}

	}
	//棋型 //remote数组里每个位置上 1表示同色棋子 2表示空格 0表示异色棋子
	if (empty == 0 && num == 1) {//死一
		return 1;
	}
	if (num == 1 && empty == 1 && (remote[0] == 222 || remote[1] == 222)) {
		return 2;
	}//眠一
	if (num == 1 && empty == 2 && (remote[0] / 10 == 22 || remote[1] / 10 == 22)) {
		return 3;
	}//活一	

	if (empty == 0 && num == 2) {
		return 4;
	}//死二
	if (empty == 1 && num == 2 && (remote[0] == 0 || remote[1] == 0)) {
		return 4;
	}//一型死二变种 ★ ■ ■ □ ★
	if (empty == 1 && num == 2 && (remote[0] == 20 || remote[1] == 20)) {
		return 4;
	}//二型死二变种 ★ ■ ■ □ □ ★
	if (empty == 1 && num == 2 && (remote[0] / 10 == 22 || remote[1] / 10 == 22)) {
		return 5;
	}//眠二 ★ ■ ■ □ □ □ 左图左右子
	if (empty == 1 && num == 1 && (remote[0] == 122 || remote[1] == 122)) {
		return 5;
	}//一型眠二变种 ★ ■ □ ■ □ □ 左图左子
	if (empty == 2 && num == 1 && ((remote[0] / 10 == 10 && remote[1] / 100 == 2) || (remote[1] / 10 == 10 && remote[0] / 100 == 2))) {
		return 5;
	}//一型眠二变种 ★ ■ □ ■ □ □ 左图右子
	if (empty == 1 && num == 1 && ((remote[0] / 100 == 0 && remote[1] / 10 == 212) || (remote[0] / 10 == 10 && remote[1] / 10 == 22))) {
		return 5;
	}//二型眠二变种 ★ ■ □ □ ■ □  左图左子
	if (empty == 2 && num == 1 && (remote[0] == 210 || remote[1] == 210)) {
		return 5;
	}//二型眠二变种 ★ ■ □ □ ■ □  左图右子
	if (empty != 0 && num == 1 && (remote[0] == 221 || remote[1] == 221)) {
		return 5;
	}//三型眠二变种  ■ □ □ □ ■   左图左右子皆可

	if (empty == 2 && num == 2 && (remote[0] / 100 == 2 && remote[1] / 100 == 2)) {
		return 6;
	}//活二 □ □ ■ ■ □ □ 左右子
	if (empty == 2 && num == 1 && (remote[0] / 10 == 12 && remote[1] / 10 == 12)) {
		return 6;
	}//一型活二变种 □ ■ □ ■ □ 左右子
	if (empty == 2 && num == 1 && (remote[0] == 212 || remote[1] == 212)) {
		return 6;
	}//二型活二变种 □ ■ □  □ ■ □ 左右子
	
	if (empty == 0 && num == 3 ) {
		return 7;
	}//死三
	if (empty == 1 && num == 3 && (remote[0] == 0 || remote[1] == 0)) {
		return 7;
	}//一型死三变种

	if (empty == 1 && num == 3 && (remote[0] / 100 == 2 || remote[1] / 100 == 2)) {
		return 8;
	}//眠三 ★ ■ ■ ■ □ □ 左图左右子
	if (empty == 1 && num == 2 && (remote[0] / 10 == 12 || remote[1] / 10== 12)) {
		return 8;
	}//一型眠三变种 ★ ■ ■ □ ■ □ 左图左子域
	if (empty == 2 && num == 1 && (remote[0] == 110 || remote[1] == 110)) {
		return 8;
	}//一型眠三变种 ★ ■ ■ □ ■ □ 左图右子
	if (empty == 1 && num == 1 && (remote[0] == 110 || remote[1] == 110)) {
		return 8;
	}//二型眠三变种 ★ ■ □ ■ ■ □ 左图左子
	if (empty == 2 && num == 2 && (remote[0] / 10 == 10 || remote[1] / 10== 10)) {
		return 8;
	}//二型眠三变种 ★ ■ □ ■ ■ □ 左图右子域
	if (empty != 0 && num == 2 && (remote[0] / 10 == 21 || remote[1] / 10== 21)) {
		return 8;
	}//三型眠三变种 ■ ■ □ □ ■ 左图左子域
	if (empty != 0 && num == 2 && (remote[0] == 211 || remote[1] == 211)) {
		return 8;
	}//三型眠三变种 ■ ■ □ □ ■ 左图右子
	if (empty != 0 && num == 1 && (remote[0] == 121 || remote[1] == 121)) {
		return 8;
	}//四型眠三变种 ■ □ ■ □ ■ 左图左右子
	if (empty == 2 && num == 1 && (remote[0] / 100 == 1 || remote[1] / 100== 1)) {
		return 8;
	}//四型眠三变种 ■ □ ■ □ ■ 左图中子
	if (empty == 2 && num == 3 && (remote[0] / 100 == 0 || remote[1] / 100 == 0)) {
		return 8;
	}//五型眠三变种  ★ □ ■ ■ ■ □  左图中子
	if (empty == 1 && num == 3 && (remote[0] / 10 == 20 || remote[1] / 10== 20)) {
		return 8;
	}//六型眠三变种  ★ ■ ■ ■ □ □ ★左图中子

	if (empty == 2 && num == 3) {
		return 9;
	}//活三
	if (empty == 2 && num == 2 && (remote[0]/10 == 12 || remote[1]/10 == 12)) {
		return 9;
	}//一型嵌四（活三）双子处 □ ■ ■ □ ■ □
	if (empty == 2 && num == 1 && (remote[0] == 112 || remote[1] == 112)) {
		return 9;
	}//一型嵌四（活三）单子处 

	if (empty == 0 && num == 4) {
		return 10;
	}//死四

	if (empty == 1 &&num == 4 ) {
		return 11;
	}//冲四
	if (empty != 0 && num == 3 && (remote[0] / 100 == 1 || remote[1] / 100 == 1)) {
		return 11;
	}//一型冲四变种  ■ ■ ■ □ ■ 三子处
	if (empty != 0 && num == 1 && (remote[0] == 111 || remote[1] == 111)) {
		return 11;
	}//一型冲四变种 ■ ■ ■ □ ■ 一子处
	if (empty != 0 && num == 2 && (remote[0]/ 10 == 11 || remote[1] / 10 == 11)) {
		return 11;
	}//二型冲四变种 ■ ■  □ ■ ■ 左右二子处

	if (empty == 2 && num == 4) {
		return 12;
	}//活四
	
	if (num == 5) {
		return 13;
	}//成五

	//其他必胜棋型
	if (empty == 2 && num == 2 && remote[0] / 10 == 11 && remote[1] / 10 == 11) {
		return 13;//■ ■ □ ■ ■ □ ■ ■ 型
	}
	if (empty == 2 && num == 3 && remote[0] / 100 == 1 && remote[1] / 100 == 1) {
		return 13;//■ □ ■ ■ ■ □ ■  型
	}
	if (num > 5) {
		return 14;//长连
	}
	return 1;
}