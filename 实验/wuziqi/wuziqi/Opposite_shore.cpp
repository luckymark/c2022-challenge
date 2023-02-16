#include"wuziqi.h"

//为了实现棋型的判断 比如中间空一个的冲四 活三之类的棋型
//所以在一个方向上找到空位置之后不是停止搜索而是进一步往前找
//往这个方向搜索2步
int Opposite_shore(int row,int col,int direction,int color) {
	int go = 0;//空格对面的步数
	int num = 0;//记录空格对面棋型 
	const int Maxgo=3;
	//用1表示同色棋子 2表示空 0表示异色棋子或者是棋盘壁
	switch (direction) {
	case 1://往上
		while (row >= 0  && go < Maxgo) {
			if (board[row][col] == color) {
				num = num * 10 + 1;
				row--;
			}
			else if (board[row][col] == 0) {
				num = num * 10 + 2;
				row--;
			}
			else {
				break;
			}
			go++;
		}
		break;
	case 2://往下
		while (row <=14 && go < Maxgo) {
			if (board[row][col] == color) {
				num = num * 10 + 1;
				row++;
			}
			else if (board[row][col] == 0) {
				num = num * 10 + 2;
				row++;
			}
			else {
				break;
			}
			go++;
		}
		break;
	case 3://往左
		while (col >= 0 && go < Maxgo) {
			if (board[row][col] == color) {
				num = num * 10 + 1;
				col--;
			}
			else if (board[row][col] == 0) {
				num = num * 10 + 2;
				col--;
			}
			else {
				break;
			}
			go++;
		}
		break;
	case 4://往右
		while (col <=14 && go < Maxgo) {
			if (board[row][col] == color) {
				num = num * 10 + 1;
				col++;
			}
			else if (board[row][col] == 0) {
				num = num * 10 + 2;
				col++;
			}
			else {
				break;
			}
			go++;
		}
		break;
	case 5://左上
		while (row >= 0 && col >= 0 && go < Maxgo) {
			if (board[row][col] == color) {
				num = num * 10 + 1;
				row--;
				col--;
			}
			else if (board[row][col] == 0) {
				num = num * 10 + 2;
				row--;
				col--;
			}
			else {
				break;
			}
			go++;
		}
		break;
	case 6://右下
		while (row <= 14 && col <= 14 && go < Maxgo) {
			if (board[row][col] == color) {
				num = num * 10 + 1;
				row++;
				col++;
			}
			else if (board[row][col] == 0) {
				num = num * 10 + 2;
				row++;
				col++;
			}
			else {
				break;
			}
			go++;
		}
		break;
	case 7://右上
		while (row >= 0 && col <= 14 && go < Maxgo) {
			if (board[row][col] == color) {
				num = num * 10 + 1;
				row--;
				col++;
			}
			else if (board[row][col] == 0) {
				num = num * 10 + 2;
				row--;
				col++;
			}
			else {
				break;
			}
			go++;
		}
		break;
	case 8://左下
		while (row <= 14 && col >= 0 && go < Maxgo) {
			if (board[row][col] == color) {
				num = num * 10 + 1;
				row++;
				col--;
			}
			else if (board[row][col] == 0) {
				num = num * 10 + 2;
				row++;
				col--;
			}
			else {
				break;
			}
			go++;
		}
		break;
	}
	if (num < 100 && num > 0) {
		num = num * 10;
	}
	return num;
}