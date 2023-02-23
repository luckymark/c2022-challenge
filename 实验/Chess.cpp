#include "Chess.h"
#include <conio.h>
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")

//Chess的初始化，创建窗口
bool Chess::init(ChessBoard* board)
{
	board->clearBoard();
	this->board = board;

	initgraph(windowWidth, windowHigth);
	loadimage(NULL, "res/init.png", windowWidth, windowHigth);
	return chooseHand();
}
//加载棋盘的图片资源，初始化棋盘的相关数据
void Chess::loadChessBoard()
{
	loadimage(NULL, "res/chessboard.png", windowWidth, windowHigth);

	loadimage(&chessBlackImg, "res/black.png", chessSize * 0.95, chessSize * 0.95, true);
	loadimage(&chessWhiteImg, "res/white.png", chessSize * 0.95, chessSize * 0.95, true);
	this->board->clearBoard();
	playerFlag = true;//将下棋方还原为黑棋
}
//判断玩家的先后手选择
bool Chess::chooseHand()
{
	ExMessage msg;
	while (1)
	{
		msg = getmessage(EX_MOUSE);
		//玩家先手
		if (msg.lbutton == 1 && msg.x > 577 && msg.x < 635 && msg.y >459 && msg.y < 520)
		{
			return true;
		}
		//玩家后手
		if (msg.lbutton == 1 && msg.x > 753.7 && msg.x < 823.8 && msg.y >459 && msg.y < 520)
		{
			return false;
		}
	}
}

bool Chess::clickBoard(int x, int y, ChessPos* pos)
{
	int col = (x - margin_x) / chessSize;
	int row = (y - margin_y) / chessSize;

	int leftTopPosX = margin_x + chessSize * col;
	int leftTopPosY = margin_y + chessSize * row;
	int offset = chessSize * 0.5; // 20 鼠标点击的模糊距离上限

	int len;
	int selectPos = false;

	do {
		// 距离左上角的距离
		len = sqrt((x - leftTopPosX) * (x - leftTopPosX) + (y - leftTopPosY) * (y - leftTopPosY));
		if (len < offset)
		{
			pos->row = row;
			pos->col = col;
			if (board->getChessData(pos->row, pos->col) == 0)
			{
				selectPos = true;
			}
			break;
		}

		// 距离右上角的距离
		len = sqrt((x - leftTopPosX - chessSize) * (x - leftTopPosX - chessSize) + (y - leftTopPosY) * (y - leftTopPosY));
		if (len < offset)
		{
			pos->row = row;
			pos->col = col + 1;
			if (board->getChessData(pos->row, pos->col) == 0)
			{
				selectPos = true;
			}
			break;
		}

		// 距离左下角的距离
		len = sqrt((x - leftTopPosX) * (x - leftTopPosX) + (y - leftTopPosY - chessSize) * (y - leftTopPosY - chessSize));
		if (len < offset)
		{
			pos->row = row + 1;
			pos->col = col;
			if (board->getChessData(pos->row, pos->col) == 0)
			{
				selectPos = true;
			}
			break;
		}

		// 距离右下角的距离
		len = sqrt((x - leftTopPosX - chessSize) * (x - leftTopPosX - chessSize) + (y - leftTopPosY - chessSize) * (y - leftTopPosY - chessSize));
		if (len < offset)
		{
			pos->row = row + 1;
			pos->col = col + 1;

			if (board->getChessData(pos->row, pos->col) == 0)
			{
				selectPos = true;
			}
			break;
		}
	} while (0);

	return selectPos;
}

//这个函数看不懂，有关图片背景透明化
void drawAlpha(IMAGE* image, int x, int y, int width, int height, int pic_x, int pic_y, double AA = 1)
{
	// 变量初始化
	DWORD* dst = GetImageBuffer();			// GetImageBuffer() 函数，用于获取绘图设备的显存指针， EasyX 自带
	DWORD* draw = GetImageBuffer();
	DWORD* src = GetImageBuffer(image);		// 获取 picture 的显存指针
	int imageWidth = image->getwidth();		// 获取图片宽度
	int imageHeight = image->getheight();	// 获取图片宽度
	int dstX = 0;							// 在 绘图区域 显存里像素的角标
	int srcX = 0;							// 在 image 显存里像素的角标

	// 实现透明贴图 公式： Cp=αp*FP+(1-αp)*BP ， 贝叶斯定理来进行点颜色的概率计算
	for (int iy = 0; iy < height; iy++)
	{
		for (int ix = 0; ix < width; ix++)
		{
			// 防止越界
			if (ix + pic_x >= 0 && ix + pic_x < imageWidth && iy + pic_y >= 0 && iy + pic_y < imageHeight &&
				ix + x >= 0 && ix + x < 1400 && iy + y >= 0 && iy + y < 700)
			{
				// 获取像素角标
				int srcX = (ix + pic_x) + (iy + pic_y) * imageWidth;
				dstX = (ix + x) + (iy + y) * 1400;

				int sa = ((src[srcX] & 0xff000000) >> 24) * AA;			// 0xAArrggbb; AA 是透明度
				int sr = ((src[srcX] & 0xff0000) >> 16);				// 获取 RGB 里的 R
				int sg = ((src[srcX] & 0xff00) >> 8);					// G
				int sb = src[srcX] & 0xff;								// B

				// 设置对应的绘图区域像素信息
				int dr = ((dst[dstX] & 0xff0000) >> 16);
				int dg = ((dst[dstX] & 0xff00) >> 8);
				int db = dst[dstX] & 0xff;
				draw[dstX] = ((sr * sa / 255 + dr * (255 - sa) / 255) << 16)  //公式： Cp=αp*FP+(1-αp)*BP  ； αp=sa/255 , FP=sr , BP=dr
					| ((sg * sa / 255 + dg * (255 - sa) / 255) << 8)         //αp=sa/255 , FP=sg , BP=dg
					| (sb * sa / 255 + db * (255 - sa) / 255);              //αp=sa/255 , FP=sb , BP=db
			}
		}
	}
}
void putimagePNG(int x, int y, IMAGE* picture) //x为载入图片的X坐标，y为Y坐标
{
	// 变量初始化
	DWORD* dst = GetImageBuffer();    // GetImageBuffer()函数，用于获取绘图设备的显存指针，EASYX自带
	DWORD* draw = GetImageBuffer();
	DWORD* src = GetImageBuffer(picture); //获取picture的显存指针
	int picture_width = picture->getwidth(); //获取picture的宽度，EASYX自带
	int picture_height = picture->getheight(); //获取picture的高度，EASYX自带
	int graphWidth = getwidth();       //获取绘图区的宽度，EASYX自带
	int graphHeight = getheight();     //获取绘图区的高度，EASYX自带
	int dstX = 0;    //在显存里像素的角标

	// 实现透明贴图 公式： Cp=αp*FP+(1-αp)*BP ， 贝叶斯定理来进行点颜色的概率计算
	for (int iy = 0; iy < picture_height; iy++)
	{
		for (int ix = 0; ix < picture_width; ix++)
		{
			int srcX = ix + iy * picture_width; //在显存里像素的角标
			int sa = ((src[srcX] & 0xff000000) >> 24); //0xAArrggbb;AA是透明度
			int sr = ((src[srcX] & 0xff0000) >> 16); //获取RGB里的R
			int sg = ((src[srcX] & 0xff00) >> 8);   //G
			int sb = src[srcX] & 0xff;              //B
			if (ix >= 0 && ix <= graphWidth && iy >= 0 && iy <= graphHeight && dstX <= graphWidth * graphHeight)
			{
				dstX = (ix + x) + (iy + y) * graphWidth; //在显存里像素的角标
				int dr = ((dst[dstX] & 0xff0000) >> 16);
				int dg = ((dst[dstX] & 0xff00) >> 8);
				int db = dst[dstX] & 0xff;
				draw[dstX] = ((sr * sa / 255 + dr * (255 - sa) / 255) << 16)  //公式： Cp=αp*FP+(1-αp)*BP  ； αp=sa/255 , FP=sr , BP=dr
					| ((sg * sa / 255 + dg * (255 - sa) / 255) << 8)         //αp=sa/255 , FP=sg , BP=dg
					| (sb * sa / 255 + db * (255 - sa) / 255);              //αp=sa/255 , FP=sb , BP=db
			}
		}
	}
}
//落子
void Chess::chessDown(ChessPos* pos, bool playerFlag)
{
	mciSendString("play res/down.mp3", 0, 0, 0);
	int x = margin_x + pos->col * chessSize - 0.5 * chessSize;
	int y = margin_y + pos->row * chessSize - 0.5 * chessSize;

	if (playerFlag == false)
	{
		drawAlpha(&chessWhiteImg, x, y, chessSize, chessSize, 0, 0, 1);
	}
	else
	{
		drawAlpha(&chessBlackImg, x, y, chessSize, chessSize, 0, 0, 1);
	}
	changeHand(pos);
}

//悔棋函数
void Chess::turnBack(bool black_white)
{
	if ((*(this->board->setLastPos())).size() == 1)//Al先手，棋盘上只有一颗棋子
	{
		return;
	}
	if (!black_white)
	{
		playerFlag = !playerFlag;
	}
	if (!(*(this->board->setLastPos())).size())//棋盘没有棋子的时候
	{
		return;
	}
	else//正常情况，棋子数>=2
	{
		ChessPos p1 = this->board->getLastPos();
		(*(this->board->setLastPos())).pop_back();
		ChessPos p2 = this->board->getLastPos();
		(*(this->board->setLastPos())).pop_back();

		(*(this->board->setChessMap()))[p1.row][p1.col] = 0;
		(*(this->board->setChessMap()))[p2.row][p2.col] = 0;
	}
	//由于easyX没有删除图片的函数，只能用棋盘覆盖
	loadimage(NULL, "res/chessboard.png", windowWidth, windowHigth);
	int maxSize = (*(this->board->setLastPos())).size();
	for (int i = 0; i < maxSize; i++)
	{
		chessDown(&(*this->board->setLastPos())[i], playerFlag);
	}
}

//换手函数
void Chess::changeHand(ChessPos* pos)
{
	playerFlag = !playerFlag; // 换手
}

//用于判断棋局是否结束
bool Chess::checkOver(bool flag)
{
	if (checkWin())
	{
		if (playerFlag != flag)
		{
			loadimage(&winImg, "res/win.png", 200, 100, true);
			putimagePNG(50, 0, &winImg);
			flag = !flag;
		}
		else
		{
			loadimage(&lostImg, "res/lost.png", 200, 100, true);
			putimagePNG(50, 0, &lostImg);
		}
		while (1)
		{
			ExMessage msg;
			msg = getmessage(EX_MOUSE);
			//悔棋
			if (msg.lbutton == 1 && msg.x > 885 && msg.x < 1050 && msg.y >530 && msg.y < 575)
			{
				turnBack(flag);
				return false;
			}
			//重开
			if (msg.lbutton == 1 && msg.x > 885 && msg.x < 1050 && msg.y >600 && msg.y < 645)
			{
				break;
			}
		}
		return true;
	}
	else if (heqi())
	{
		while (1)
		{
			ExMessage msg;
			msg = getmessage(EX_MOUSE);
			if (msg.lbutton == 1 && msg.x > 885 && msg.x < 1050 && msg.y >530 && msg.y < 575)
			{
				turnBack(flag);
				break;
			}
			if (msg.lbutton == 1 && msg.x > 885 && msg.x < 1050 && msg.y >600 && msg.y < 645)
			{
				break;
			}
		}
		return true;
	}

	return false;
}
//用于判断棋局胜负
bool Chess::checkWin()
{
	// 横竖斜四种大情况，每种情况都根据当前落子往后遍历5个棋子，有一种符合就算赢
	int row = (board->getLastPos()).row;
	int col = (board->getLastPos()).col;
	// 水平方向
	for (int i = 0; i < 5; i++)
	{
		if ((col - i) >= 0 && (col - i + 4) < boardSize &&
			board->getChessData(row, col - i) == board->getChessData(row, col - i + 1) &&
			board->getChessData(row, col - i) == board->getChessData(row, col - i + 2) &&
			board->getChessData(row, col - i) == board->getChessData(row, col - i + 3) &&
			board->getChessData(row, col - i) == board->getChessData(row, col - i + 4))
			return true;
	}
	// 竖直方向
	for (int i = 0; i < 5; i++)
	{
		if ((row - i) >= 0 && (row - i + 4) < boardSize &&
			board->getChessData(row - i, col) == board->getChessData(row - i + 1, col) &&
			board->getChessData(row - i, col) == board->getChessData(row - i + 2, col) &&
			board->getChessData(row - i, col) == board->getChessData(row - i + 3, col) &&
			board->getChessData(row - i, col) == board->getChessData(row - i + 4, col))
			return true;
	}

	// “/"方向
	for (int i = 0; i < 5; i++)
	{
		if ((row + i < boardSize) && (row + i - 4) >= 0 && (col - i) >= 0 && (col - i + 4) < boardSize &&
			board->getChessData(row + i, col - i) == board->getChessData(row + i - 1, col - i + 1) &&
			board->getChessData(row + i, col - i) == board->getChessData(row + i - 2, col - i + 2) &&
			board->getChessData(row + i, col - i) == board->getChessData(row + i - 3, col - i + 3) &&
			board->getChessData(row + i, col - i) == board->getChessData(row + i - 4, col - i + 4))
			return true;
	}

	// “\“ 方向
	for (int i = 0; i < 5; i++)
	{
		if ((row - i) >= 0 && (row - i + 4) < boardSize && (col - i) >= 0 && (col - i + 4) < boardSize &&
			board->getChessData(row - i, col - i) == board->getChessData(row - i + 1, col - i + 1) &&
			board->getChessData(row - i, col - i) == board->getChessData(row - i + 2, col - i + 2) &&
			board->getChessData(row - i, col - i) == board->getChessData(row - i + 3, col - i + 3) &&
			board->getChessData(row - i, col - i) == board->getChessData(row - i + 4, col - i + 4))
			return true;
	}
	return false;
}
//和棋判断
bool Chess::heqi()
{
	if ((board->setLastPos())->size() == 225)
	{
		loadimage(&lostImg, "res/heqi.png", 200, 100, true);
		putimagePNG(50, 0, &lostImg);
		return true;
	}
	return false;
}
bool Chess::getPlayerFlag()
{
	return playerFlag;
}
//用于获取棋盘大小（15*15）的接口
int Chess::getBoardSize()
{
	return boardSize;
}
//构造函数
Chess::Chess(int boardSize, int marginX, int marginY, float chessSize)
{
	this->boardSize = boardSize;
	this->margin_x = marginX;
	this->margin_y = marginY;
	this->chessSize = chessSize;
	playerFlag = true;
}


