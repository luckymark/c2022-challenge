#include "Chess.h"
#include <conio.h>
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")

//Chess�ĳ�ʼ������������
bool Chess::init(ChessBoard* board)
{
	board->clearBoard();
	this->board = board;

	initgraph(windowWidth, windowHigth);
	loadimage(NULL, "res/init.png", windowWidth, windowHigth);
	return chooseHand();
}
//�������̵�ͼƬ��Դ����ʼ�����̵��������
void Chess::loadChessBoard()
{
	loadimage(NULL, "res/chessboard.png", windowWidth, windowHigth);

	loadimage(&chessBlackImg, "res/black.png", chessSize * 0.95, chessSize * 0.95, true);
	loadimage(&chessWhiteImg, "res/white.png", chessSize * 0.95, chessSize * 0.95, true);
	this->board->clearBoard();
	playerFlag = true;//�����巽��ԭΪ����
}
//�ж���ҵ��Ⱥ���ѡ��
bool Chess::chooseHand()
{
	ExMessage msg;
	while (1)
	{
		msg = getmessage(EX_MOUSE);
		//�������
		if (msg.lbutton == 1 && msg.x > 577 && msg.x < 635 && msg.y >459 && msg.y < 520)
		{
			return true;
		}
		//��Һ���
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
	int offset = chessSize * 0.5; // 20 �������ģ����������

	int len;
	int selectPos = false;

	do {
		// �������Ͻǵľ���
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

		// �������Ͻǵľ���
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

		// �������½ǵľ���
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

		// �������½ǵľ���
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

//����������������й�ͼƬ����͸����
void drawAlpha(IMAGE* image, int x, int y, int width, int height, int pic_x, int pic_y, double AA = 1)
{
	// ������ʼ��
	DWORD* dst = GetImageBuffer();			// GetImageBuffer() ���������ڻ�ȡ��ͼ�豸���Դ�ָ�룬 EasyX �Դ�
	DWORD* draw = GetImageBuffer();
	DWORD* src = GetImageBuffer(image);		// ��ȡ picture ���Դ�ָ��
	int imageWidth = image->getwidth();		// ��ȡͼƬ���
	int imageHeight = image->getheight();	// ��ȡͼƬ���
	int dstX = 0;							// �� ��ͼ���� �Դ������صĽǱ�
	int srcX = 0;							// �� image �Դ������صĽǱ�

	// ʵ��͸����ͼ ��ʽ�� Cp=��p*FP+(1-��p)*BP �� ��Ҷ˹���������е���ɫ�ĸ��ʼ���
	for (int iy = 0; iy < height; iy++)
	{
		for (int ix = 0; ix < width; ix++)
		{
			// ��ֹԽ��
			if (ix + pic_x >= 0 && ix + pic_x < imageWidth && iy + pic_y >= 0 && iy + pic_y < imageHeight &&
				ix + x >= 0 && ix + x < 1400 && iy + y >= 0 && iy + y < 700)
			{
				// ��ȡ���ؽǱ�
				int srcX = (ix + pic_x) + (iy + pic_y) * imageWidth;
				dstX = (ix + x) + (iy + y) * 1400;

				int sa = ((src[srcX] & 0xff000000) >> 24) * AA;			// 0xAArrggbb; AA ��͸����
				int sr = ((src[srcX] & 0xff0000) >> 16);				// ��ȡ RGB ��� R
				int sg = ((src[srcX] & 0xff00) >> 8);					// G
				int sb = src[srcX] & 0xff;								// B

				// ���ö�Ӧ�Ļ�ͼ����������Ϣ
				int dr = ((dst[dstX] & 0xff0000) >> 16);
				int dg = ((dst[dstX] & 0xff00) >> 8);
				int db = dst[dstX] & 0xff;
				draw[dstX] = ((sr * sa / 255 + dr * (255 - sa) / 255) << 16)  //��ʽ�� Cp=��p*FP+(1-��p)*BP  �� ��p=sa/255 , FP=sr , BP=dr
					| ((sg * sa / 255 + dg * (255 - sa) / 255) << 8)         //��p=sa/255 , FP=sg , BP=dg
					| (sb * sa / 255 + db * (255 - sa) / 255);              //��p=sa/255 , FP=sb , BP=db
			}
		}
	}
}
void putimagePNG(int x, int y, IMAGE* picture) //xΪ����ͼƬ��X���꣬yΪY����
{
	// ������ʼ��
	DWORD* dst = GetImageBuffer();    // GetImageBuffer()���������ڻ�ȡ��ͼ�豸���Դ�ָ�룬EASYX�Դ�
	DWORD* draw = GetImageBuffer();
	DWORD* src = GetImageBuffer(picture); //��ȡpicture���Դ�ָ��
	int picture_width = picture->getwidth(); //��ȡpicture�Ŀ�ȣ�EASYX�Դ�
	int picture_height = picture->getheight(); //��ȡpicture�ĸ߶ȣ�EASYX�Դ�
	int graphWidth = getwidth();       //��ȡ��ͼ���Ŀ�ȣ�EASYX�Դ�
	int graphHeight = getheight();     //��ȡ��ͼ���ĸ߶ȣ�EASYX�Դ�
	int dstX = 0;    //���Դ������صĽǱ�

	// ʵ��͸����ͼ ��ʽ�� Cp=��p*FP+(1-��p)*BP �� ��Ҷ˹���������е���ɫ�ĸ��ʼ���
	for (int iy = 0; iy < picture_height; iy++)
	{
		for (int ix = 0; ix < picture_width; ix++)
		{
			int srcX = ix + iy * picture_width; //���Դ������صĽǱ�
			int sa = ((src[srcX] & 0xff000000) >> 24); //0xAArrggbb;AA��͸����
			int sr = ((src[srcX] & 0xff0000) >> 16); //��ȡRGB���R
			int sg = ((src[srcX] & 0xff00) >> 8);   //G
			int sb = src[srcX] & 0xff;              //B
			if (ix >= 0 && ix <= graphWidth && iy >= 0 && iy <= graphHeight && dstX <= graphWidth * graphHeight)
			{
				dstX = (ix + x) + (iy + y) * graphWidth; //���Դ������صĽǱ�
				int dr = ((dst[dstX] & 0xff0000) >> 16);
				int dg = ((dst[dstX] & 0xff00) >> 8);
				int db = dst[dstX] & 0xff;
				draw[dstX] = ((sr * sa / 255 + dr * (255 - sa) / 255) << 16)  //��ʽ�� Cp=��p*FP+(1-��p)*BP  �� ��p=sa/255 , FP=sr , BP=dr
					| ((sg * sa / 255 + dg * (255 - sa) / 255) << 8)         //��p=sa/255 , FP=sg , BP=dg
					| (sb * sa / 255 + db * (255 - sa) / 255);              //��p=sa/255 , FP=sb , BP=db
			}
		}
	}
}
//����
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

//���庯��
void Chess::turnBack(bool black_white)
{
	if ((*(this->board->setLastPos())).size() == 1)//Al���֣�������ֻ��һ������
	{
		return;
	}
	if (!black_white)
	{
		playerFlag = !playerFlag;
	}
	if (!(*(this->board->setLastPos())).size())//����û�����ӵ�ʱ��
	{
		return;
	}
	else//���������������>=2
	{
		ChessPos p1 = this->board->getLastPos();
		(*(this->board->setLastPos())).pop_back();
		ChessPos p2 = this->board->getLastPos();
		(*(this->board->setLastPos())).pop_back();

		(*(this->board->setChessMap()))[p1.row][p1.col] = 0;
		(*(this->board->setChessMap()))[p2.row][p2.col] = 0;
	}
	//����easyXû��ɾ��ͼƬ�ĺ�����ֻ�������̸���
	loadimage(NULL, "res/chessboard.png", windowWidth, windowHigth);
	int maxSize = (*(this->board->setLastPos())).size();
	for (int i = 0; i < maxSize; i++)
	{
		chessDown(&(*this->board->setLastPos())[i], playerFlag);
	}
}

//���ֺ���
void Chess::changeHand(ChessPos* pos)
{
	playerFlag = !playerFlag; // ����
}

//�����ж�����Ƿ����
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
			//����
			if (msg.lbutton == 1 && msg.x > 885 && msg.x < 1050 && msg.y >530 && msg.y < 575)
			{
				turnBack(flag);
				return false;
			}
			//�ؿ�
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
//�����ж����ʤ��
bool Chess::checkWin()
{
	// ����б���ִ������ÿ����������ݵ�ǰ�����������5�����ӣ���һ�ַ��Ͼ���Ӯ
	int row = (board->getLastPos()).row;
	int col = (board->getLastPos()).col;
	// ˮƽ����
	for (int i = 0; i < 5; i++)
	{
		if ((col - i) >= 0 && (col - i + 4) < boardSize &&
			board->getChessData(row, col - i) == board->getChessData(row, col - i + 1) &&
			board->getChessData(row, col - i) == board->getChessData(row, col - i + 2) &&
			board->getChessData(row, col - i) == board->getChessData(row, col - i + 3) &&
			board->getChessData(row, col - i) == board->getChessData(row, col - i + 4))
			return true;
	}
	// ��ֱ����
	for (int i = 0; i < 5; i++)
	{
		if ((row - i) >= 0 && (row - i + 4) < boardSize &&
			board->getChessData(row - i, col) == board->getChessData(row - i + 1, col) &&
			board->getChessData(row - i, col) == board->getChessData(row - i + 2, col) &&
			board->getChessData(row - i, col) == board->getChessData(row - i + 3, col) &&
			board->getChessData(row - i, col) == board->getChessData(row - i + 4, col))
			return true;
	}

	// ��/"����
	for (int i = 0; i < 5; i++)
	{
		if ((row + i < boardSize) && (row + i - 4) >= 0 && (col - i) >= 0 && (col - i + 4) < boardSize &&
			board->getChessData(row + i, col - i) == board->getChessData(row + i - 1, col - i + 1) &&
			board->getChessData(row + i, col - i) == board->getChessData(row + i - 2, col - i + 2) &&
			board->getChessData(row + i, col - i) == board->getChessData(row + i - 3, col - i + 3) &&
			board->getChessData(row + i, col - i) == board->getChessData(row + i - 4, col - i + 4))
			return true;
	}

	// ��\�� ����
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
//�����ж�
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
//���ڻ�ȡ���̴�С��15*15���Ľӿ�
int Chess::getBoardSize()
{
	return boardSize;
}
//���캯��
Chess::Chess(int boardSize, int marginX, int marginY, float chessSize)
{
	this->boardSize = boardSize;
	this->margin_x = marginX;
	this->margin_y = marginY;
	this->chessSize = chessSize;
	playerFlag = true;
}


