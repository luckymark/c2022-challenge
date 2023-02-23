#include"chess.h"

void init()//画出游戏窗口及功能。
{
	initgraph(700, 800);//创建游戏窗口。
	setbkcolor(RGB(170, 243, 255));
	cleardevice();
	setlinecolor(RGB(0, 0, 0));
	for (int i = 20; i <= 660; i += 40) {
		line(i, 20, i, 660);
	}
	for (int i = 20; i <= 660; i += 40) {
		line(20, i, 660, i);
	}
	settextstyle(50, 30, "楷体");
	settextcolor(RGB(0, 0, 0));
	outtextxy(400, 700, TEXT("重新开始"));
	rectangle(400, 700, 650, 750);
	rectangle(240, 695, 375, 750);
	outtextxy(250, 700, TEXT("悔棋"));
	//初始化棋盘。
	for (int i = 0; i <= gradeSize; ++i) {
		for (int j = 0; j <= gradeSize; ++j) {
			chessMap[i][j] = 0;
		}
	}
	//初始化走的步。
	for (int i = 0; i < 226; ++i) {
		chessPos[i].x = 0;
		chessPos[i].y = 0;
	}
	playerFlag = true;//黑棋先行
	stepNum = 0;
}

//函数功能：检查是否为有效点击，是则控制下棋
bool clickBoard(int x, int y, ChessPos* pos)
{
	int col = (x - margin_x) / chessSize;//列
	int row = (y - margin_y) / chessSize;//行
	//计算离鼠标点击位置最近的左上方点的位置
	int leftTopPosX = margin_x + col * chessSize;
	int leftTopPosY = margin_y + row * chessSize;
	int offset = chessSize / 2;
	int len;
	bool ret = false;//bool变量判断是否为有效点击，有效则退出函数
	do {
		if (x <= 35 || x >= 640 || y <= 35 || y >= 640) {
			break;
		}
		//左上角的判断
		len = sqrt((x - leftTopPosX) * (x - leftTopPosX) + (y - leftTopPosY) * (y - leftTopPosY));
		if (len <= offset) {
			pos->x = col;
			pos->y = row;
			if (chessMap[pos->y][pos->x] == 0) {
				ret = true;
			}
			break;
		}
		//右上角判断
		int x2 = leftTopPosX + chessSize;
		int y2 = leftTopPosY;
		len = sqrt((x - x2) * (x - x2) + (y - y2) * (y - y2));
		if (len <= offset) {
			pos->x = col + 1;
			pos->y = row;
			if (chessMap[pos->y][pos->x] == 0) {
				ret = true;
			}
			break;
		}
		//左下角判断
		int x3 = leftTopPosX;
		int y3 = leftTopPosY + chessSize;
		len = sqrt((x - x3) * (x - x3) + (y - y3) * (y - y3));
		if (len <= offset) {
			pos->x = col;
			pos->y = row + 1;
			if (chessMap[pos->y][pos->x] == 0) {
				ret = true;
			}
			break;
		}
		//右下角判断
		int x4 = leftTopPosX + chessSize;
		int y4 = leftTopPosY + chessSize;
		len = sqrt((x - x4) * (x - x4) + (y - y4) * (y - y4));
		if (len <= offset) {
			pos->x = col + 1;
			pos->y = row + 1;
			if (chessMap[pos->y][pos->x] == 0) {
				ret = true;
			}
			break;
		}
	} while (0);
	return ret;
}

//函数功能：实现落子
void chessDown(ChessPos* pos)
{
	int x = margin_x + chessSize * pos->x;
	int y = margin_y + chessSize * pos->y;

	if (playerFlag == true) {
		setfillcolor(BLACK);
	}
	else {
		setfillcolor(WHITE);
	}
	fillcircle(x, y, chessSize / 2);

	//更新图
	updateMap(pos);
}

//函数功能：处理结束之后的文字输出
bool checkOver()
{
	if (checkWin()) {
		settextstyle(50, 25, _T("楷体"));
		if (playType == true) {
			if (playerFlag == false) {
				outtextxy(20, 700, TEXT("黑子赢了"));
			}
			else {
				outtextxy(20, 700, TEXT("白子赢了"));
			}
		}
		else {
			if (playerFlag == true) {
				outtextxy(50, 700, TEXT("你输了"));
			}
			else {
				outtextxy(50, 700, TEXT("你赢了"));
			}
		}
		return true;
	}
	return false;
}

//函数功能：判断棋局是否结束
bool checkWin()
{
	//每下一步就判断一次，故只需考虑最后一次落子其八个方向是否有连成五子
	int x = chessPos[stepNum].x;
	int y = chessPos[stepNum].y;

	int chessNum = 1;

	if (chessMap[y][x] == 0) return false;

	//行判断
	for (int i = 1; i <= 4; ++i) {
		if (x <= 0 || x >= 16 || y <= 0 || y >= 16) {
			break;
		}
		if (chessMap[y][x - i] == chessMap[y][x]) {
			chessNum++;
		}
		else break;
	}
	for (int i = 1; i <= 4; ++i) {
		if (x <= 0 || x >= 16 || y <= 0 || y >= 16) {
			break;
		}
		if (chessMap[y][x + i] == chessMap[y][x]) {
			chessNum++;
		}
		else break;
	}
	if (chessNum >= 5) {
		return true;
	}
	else chessNum = 1;

	//列判断
	for (int i = 1; i <= 4; ++i) {
		if (x <= 0 || x >= 16 || y <= 0 || y >= 16) {
			break;
		}
		if (chessMap[y - i][x] == chessMap[y][x]) {
			chessNum++;
		}
		else break;
	}
	for (int i = 1; i <= 4; ++i) {
		if (x <= 0 || x >= 16 || y <= 0 || y >= 16) {
			break;
		}
		if (chessMap[y + i][x] == chessMap[y][x]) {
			chessNum++;
		}
		else break;
	}
	if (chessNum >= 5) {
		return true;
	}
	else chessNum = 1;

	//对角判断
	for (int i = 1; i <= 4; ++i) {
		if (x <= 0 || x >= 16 || y <= 0 || y >= 16) {
			break;
		}
		if (chessMap[y - i][x - i] == chessMap[y][x]) {
			chessNum++;
		}
		else break;
	}
	for (int i = 1; i <= 4; ++i) {
		if (x <= 0 || x >= 16 || y <= 0 || y >= 16) {
			break;
		}
		if (chessMap[y + i][x + i] == chessMap[y][x]) {
			chessNum++;
		}
		else break;
	}
	if (chessNum >= 5) {
		return true;
	}
	else {
		chessNum = 1;
	}
	for (int i = 1; i <= 4; ++i) {
		if (x <= 0 || x >= 16 || y <= 0 || y >= 16) {
			break;
		}
		if (chessMap[y + i][x - i] == chessMap[y][x]) {
			chessNum++;
		}
		else break;
	}
	for (int i = 1; i <= 4; ++i) {
		if (x <= 0 || x >= 16 || y <= 0 || y >= 16) {
			break;
		}
		if (chessMap[y - i][x + i] == chessMap[y][x]) {
			chessNum++;
		}
		else break;
	}
	if (chessNum >= 5) {
		return true;
	}
	else {
		chessNum = 1;
		return false;
	}
}

//函数功能：控制重新开始新的棋局功能
void dispose()
{
	MOUSEMSG msg;
	while (1) {
		msg = GetMouseMsg();
		if (msg.uMsg == WM_LBUTTONDOWN && msg.x >= 400 && msg.x <= 650 && msg.y >= 700 && msg.y <= 750) {
			gameStart();
			break;
		}
		else continue;
	}
}

//函数功能：悔棋功能
void regretStep()
{
	//棋盘变空且人换回来
	chessMap[chessPos[stepNum].y][chessPos[stepNum].x] = 0;
	playerFlag = -playerFlag;

	//处理画面上棋子的删除
	deleteStep(&chessPos[stepNum]);
	stepNum--;

	//如果人机对战，直接退两步
	if (playType == false && stepNum) {
		chessMap[chessPos[stepNum].y][chessPos[stepNum].x] = 0;
		playerFlag = -playerFlag;
		deleteStep(&chessPos[stepNum]);
		stepNum--;
	}
}

//函数功能：辅助悔棋功能（删除画面上的棋子）
void deleteStep(ChessPos* pos)
{
	int x = margin_x + chessSize * pos->x;
	int y = margin_y + chessSize * pos->y;
	setfillcolor(RGB(170, 243, 255));
	solidrectangle(x - chessSize / 2, y - chessSize / 2, x + chessSize / 2, y + chessSize / 2);
	playerFlag = -playerFlag;
	line(x - chessSize / 2, y, x + chessSize / 2, y);
	line(x, y - chessSize / 2, x, y + chessSize / 2);
	return;
}

//函数功能：记录落子及更改下棋方
void updateMap(ChessPos* pos)
{
	chessMap[pos->y][pos->x] = playerFlag ? 1 : -1;
	playerFlag = !playerFlag;//交换下棋方
	chessPos[++stepNum] = *pos;
}
