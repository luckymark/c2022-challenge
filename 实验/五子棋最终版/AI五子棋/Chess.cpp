#include "Chess.h"
#include <math.h>
#include <mmsystem.h>
#pragma comment(lib,"winmm.lib")
#include <conio.h>
Chess::Chess(int chessboard_Size, int margin_X, int margin_Y, float chessSize)
{
	this->chessboard_Size = chessboard_Size;
	this->margin_x = margin_X;
	this->margin_y = margin_Y;
	this->chessSize = chessSize;
	playerFlag = CHESS_BLACK;

	for (int i = 0; i < chessboard_Size; i++)
	{
		vector<int> row;
		for (int j = 0; j < chessboard_Size; j++)
		{
			row.push_back(0);
		}
		chessMap.push_back(row);
	}
}

void Chess::init()
{
	initgraph(650, 650,EW_SHOWCONSOLE);
	loadimage(&chessBoardImg, "../img/chessboard.jpg", 650, 650);
	loadimage(&chessWhiteImg, "../img/white.jpg",chessSize,chessSize);
	loadimage(&chessBlackImg, "../img/black.jpg",chessSize,chessSize);
	putimage(0, 0, &chessBoardImg);

	for (int i = 0; i < chessboard_Size; i++)
	{
		for (int j = 0; j < chessboard_Size; j++)
		{
			chessMap[i][j] = 0;
		}
	}

	playerFlag = true;
}
bool Chess::clickBoard(int x, int y, ChessPos* pos)
{
	int col = (x - margin_x) / chessSize;
	int row = (y - margin_y) / chessSize;
	int leftTopPosX = margin_x + chessSize * col;
	int leftTopPosY = margin_y + chessSize * row;
	int offset = chessSize * 0.4;//�������Χ

	int len;
	bool flag = false;

	//���Ͻ��ж�
	len = sqrt((x - leftTopPosX) * (x - leftTopPosX) + (y - leftTopPosY) * (y - leftTopPosY));
	if (len < offset)
	{
		pos->row = row;
		pos->col = col;
		if (chessMap[pos->row][pos->col] == 0)
		{
			flag = true;
		}
	}

	//���Ͻ��ж�
	int x2 = leftTopPosX + chessSize;
	int y2 = leftTopPosY;
	len = sqrt((x - x2) * (x - x2) + (y - y2) * (y - y2));
	if (len < offset)
	{
		pos->row = row;
		pos->col = col+1;
		if (chessMap[pos->row][pos->col] == 0)
		{
			flag = true;
		}
	}

	//���½��ж�
	x2 = leftTopPosX;
	y2 = leftTopPosY + chessSize;
	len = sqrt((x - x2) * (x - x2) + (y - y2) * (y - y2));
	if (len < offset)
	{
		pos->row = row+1;
		pos->col = col;
		if (chessMap[pos->row][pos->col] == 0)
		{
			flag = true;
		}
	}

	//���½��ж�
	x2 = leftTopPosX + chessSize;
	y2 = leftTopPosY + chessSize;
	len = sqrt((x - x2) * (x - x2) + (y - y2) * (y - y2));
	if (len < offset)
	{
		pos->row = row+1;
		pos->col = col+1;
		if (chessMap[pos->row][pos->col] == 0)
		{
			flag = true;
		}
	}
	return flag;
}
void Chess::chessDown(ChessPos* pos, chess_kind_t kind)
{
	int x = margin_x + chessSize * pos->col-0.5 * chessSize;
	int y = margin_y + chessSize * pos->row-0.5 * chessSize;
	if (kind == CHESS_WHITE)
	{
		putimage(x, y, &chessWhiteImg);
		if (this->mode == 2)
		{
			mciSendString("play ../audio/click.mp3", 0, 0, 0);
		}
	}
	else
	{
		putimage(x, y, &chessBlackImg);
		mciSendString("play ../audio/click.mp3", 0, 0, 0);
	}
	updateGameMap(pos);
}
int Chess::getChessBoard_Size()
{
	return chessboard_Size;
}
int Chess::getChessData(ChessPos* pos)
{
	return chessMap[pos->row][pos->col];
}
int Chess::getChessData(int row, int col)
{
	return chessMap[row][col];
}
bool Chess::checkOver()
{
	if (checkWin())
	{
		Sleep(1500);
		if (playerFlag == false)
		{
			//�ղ�������Ǻڷ������ַ���������ʤ��
			loadimage(&black_winImg, "../img/black_win.jpg",50,100);
			putimage(590, 250, &black_winImg);
			mciSendString("play ../audio/victory.mp3", 0, 0, 0);
		}
		else
		{
			loadimage(&white_winImg, "../img/white_win.jpg",50,100);
			putimage(590, 250, &white_winImg);
			if (this->mode == 1)
			{
				mciSendString("play ../audio/fail.mp3", 0, 0, 0);
			}
			if (this->mode == 2)
			{
				mciSendString("play ../audio/victory.mp3", 0, 0, 0);
			}
			
		}
		_getch();//��ͣ
		return true;
	}
	return false;
}

void Chess::updateGameMap(ChessPos* pos)
{
	lastPos = *pos;
	//�ڰ׷���������
	if (playerFlag)
	{
		chessMap[pos->row][pos->col] = CHESS_BLACK;
	}
	else
	{
		chessMap[pos->row][pos->col] = CHESS_WHITE;
	}
	playerFlag = !playerFlag;
}

bool Chess::checkWin()
{
	//������ӵ��λ��
	int row = lastPos.row;
	int col = lastPos.col;

	for (int i = 0; i < 5; i++)
	{
		//���ӵ��ˮƽ����
		if (col - i >= 0 && col - i + 4 < chessboard_Size &&
			chessMap[row][col - i] == chessMap[row][col - i + 1] &&
			chessMap[row][col - i] == chessMap[row][col - i + 2] &&
			chessMap[row][col - i] == chessMap[row][col - i + 3] &&
			chessMap[row][col - i] == chessMap[row][col - i + 4])
		{
			return true;
		}
		//��ֱ����
		if (row - i >= 0 && row - i + 4 < chessboard_Size &&
			chessMap[row-i][col] == chessMap[row-i+1][col] &&
			chessMap[row-i][col] == chessMap[row-i+2][col] &&
			chessMap[row-i][col] == chessMap[row-i+3][col] &&
			chessMap[row-i][col] == chessMap[row-i+4][col])
		{
			return true;
		}
		//   ��/���������ϵ����£�
		if (row + i < chessboard_Size && row + i - 4 >= 0 &&
			col - i >= 0 && col - i + 4 < chessboard_Size &&
			chessMap[row + i][col-i] == chessMap[row + i - 1][col-i+1] &&
			chessMap[row + i][col-i] == chessMap[row + i - 2][col-i+2] &&
			chessMap[row + i][col-i] == chessMap[row + i - 3][col-i+3] &&
			chessMap[row + i][col-i] == chessMap[row + i - 4][col-i+4])
		{
			return true;
		}
		//   ��\���������µ����ϣ�
		if (row - i >= 0 && row - i + 4 < chessboard_Size &&
			col - i >= 0 && col - i + 4 < chessboard_Size &&
			chessMap[row - i][col - i] == chessMap[row - i + 1][col - i + 1] &&
			chessMap[row - i][col - i] == chessMap[row - i + 2][col - i + 2] &&
			chessMap[row - i][col - i] == chessMap[row - i + 3][col - i + 3] &&
			chessMap[row - i][col - i] == chessMap[row - i + 4][col - i + 4])
		{
			return true;
		}
	}
	return false;
}
