#include "ChessGame.h"

ChessGame::ChessGame(People_one* people_one, People_two* people_two, AI* ai, Chess* chess)
{
	this->people_one = people_one;
	this->people_two = people_two;
	this->ai = ai;
	this->chess = chess;
	people_one->init(chess);
	people_two->init(chess);
	ai->init(chess);
}

void ChessGame::play()
{
	
	initgraph(650, 650, EW_SHOWCONSOLE);
	loadimage(&backgroundImg, "../img/background.jpg", 650, 650);
	putimage(0, 0, &backgroundImg);
	MOUSEMSG msg;//获取鼠标信息
	ChessPos pos;
	while (1)//游戏开始页面
	{
		msg = GetMouseMsg();
		if (msg.uMsg == WM_LBUTTONDOWN && msg.x>=190 && msg.x<=480 && msg.y>=280 && msg.y<=360)
		{
			chess->mode = 1;
			mciSendString("play ../audio/begin.mp3", 0, 0, 0);
			break;
		}
		if (msg.uMsg == WM_LBUTTONDOWN && msg.x >= 190 && msg.x <= 480 && msg.y >= 390 && msg.y <= 470)
		{
			chess->mode = 2;
			mciSendString("play ../audio/begin.mp3", 0, 0, 0);
			break;
		}
	}
	chess->init();
	if (chess->mode == 1)
	{
		while (1)
		{
			people_one->go();

			if (chess->checkOver())
			{
				chess->init();
				continue;
			}

			ai->go();

			if (chess->checkOver())
			{
				chess->init();
				continue;
			}
		}
	}
	if (chess->mode == 2)
	{
		while (1)
		{
			people_one->go();

			if (chess->checkOver())
			{
				chess->init();
				continue;
			}

			people_two->go();

			if (chess->checkOver())
			{
				chess->init();
				continue;
			}
		}
	}

}