#include"chess.h"

void init()
{
	initgraph(700, 800,EW_SHOWCONSOLE);//创建游戏窗口。
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
	for (int i = 0; i <= gradeSize; ++i) {
		for (int j = 0; j <= gradeSize; ++j) {
			chessMap[i][j] = 0;
		}
	}
	for (int i = 0; i < 226; ++i) {
		chessPos[i].x = 0;
		chessPos[i].y = 0;
	}
	playerFlag = false;
	stepNum = 0;
}

bool clickBoard(int x, int y, ChessPos* pos)
{
	int col = (x - margin_x) / chessSize;//列
	int row = (y - margin_y) / chessSize;//行
	int leftTopPosX = margin_x + col * chessSize;
	int leftTopPosY = margin_y + row * chessSize;
	int offset = chessSize / 2;
	int len;
	bool ret = false;
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
				//printf("%d   %d\n", pos->y, pos->x);
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
				//printf("%d   %d\n", pos->y, pos->x);
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
				//printf("%d   %d\n", pos->y, pos->x);
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
				//printf("%d   %d\n", pos->y, pos->x);
			}
			break;
		}
	} while (0);
	return ret;
}

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
	updateMap(pos);
	updateGameMap(pos);
	printf("%d  %d\n", chessPos[stepNum].x, chessPos[stepNum].y);
}

int getChessData(ChessPos* pos)
{
	return chessMap[pos->y][pos->x];
}

int getChessData(int x, int y)
{
	return chessMap[y][x];
}

bool checkOver()
{
	if (checkWin()) {
		settextstyle(50, 30, _T("楷体"));
		if (playType == true) {
			if (playerFlag == false) {
				outtextxy(50, 700, TEXT("黑子赢了"));
			}
			else {
				outtextxy(50, 700, TEXT("白子赢了"));
			}
		}
		else {
			if (playerFlag == false) {
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

bool checkWin()
{
	int x = chessPos[stepNum].x;
	int y = chessPos[stepNum].y;
	int chessNum = 1;
	if (chessMap[y][x] == 0) return false;
	//printf("%d   %d\n", x, y);
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
	//printf("行有%d\n", num);
	if (chessNum >= 5) {
		return true;
	}
	else chessNum = 1;
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
	//printf("列有%d\n", num);
	if (chessNum >= 5) {
		return true;
	}
	else chessNum = 1;
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
	//printf("斜线有%d\n", num);
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

void updateGameMap(ChessPos* pos)
{
	chessPos[++stepNum] = *pos;
}

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

void regretStep()
{
		chessMap[chessPos[stepNum].y][chessPos[stepNum].x] = 0;
		playerFlag = -playerFlag;	
		deleteStep(&chessPos[stepNum]);
		stepNum--;
		if (playType == false && stepNum) {
			chessMap[chessPos[stepNum].y][chessPos[stepNum].x] = 0;
			playerFlag = -playerFlag;
			deleteStep(&chessPos[stepNum]);
			stepNum--;
		}
}

void deleteStep(ChessPos* pos)
{
	int x = margin_x + chessSize * pos->x;
	int y = margin_y + chessSize * pos->y;
	setfillcolor(RGB(170, 243, 255));
	solidrectangle(x-chessSize/2,y-chessSize/2,x+chessSize/2,y+chessSize/2);
	playerFlag = -playerFlag;
	line(x - chessSize / 2, y, x + chessSize / 2, y);
	line(x, y - chessSize / 2, x, y + chessSize / 2);
	return;
}

void updateMap(ChessPos* pos)
{
	chessMap[pos->y][pos->x] = playerFlag ? 1 : -1;
	playerFlag = !playerFlag;//交换下棋方
}
