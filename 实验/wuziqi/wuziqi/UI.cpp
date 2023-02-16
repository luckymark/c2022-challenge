//界面初始化
#include"wuziqi.h"

int GameUI(void)
{
	initgraph(WIDTH, HIGH, EX_DBLCLKS);
	setfillcolor(RGB(255, 82, 178));
	solidrectangle(0, 0, WIDTH, HIGH);

	setfillcolor(RGB(255, 153, 00));
	solidrectangle(25, 25, 775, 775);//棋盘的图形区块

	setfillcolor(RGB(255, 255, 255));
	fillrectangle(950, 300, 1050, 380);//悔棋的图形区块
	
	setcolor(BLACK);
	
	for (int i = 50; i <= 775; i += 50){
		line(50, i, 750, i);//画15根横线
	}
	for (int i = 50; i <= 775; i += 50){
		line(i, 50, i, 750);//画15根竖线
	}

	settextstyle(40, 20, L"楷体");
	setbkmode(TRANSPARENT);
	outtextxy(950, 50, L"五子棋5.0");

	outtextxy(960, 320, L"悔棋");
	
	return 0;
}


int InitUI(void) {
	initgraph(WIDTH, HIGH, EX_DBLCLKS);
	setfillcolor(RGB(33, 82, 178));
	solidrectangle(0, 0, WIDTH, HIGH);

	setfillcolor(RGB(255, 255, 255));
	fillrectangle(250, 350, 650, 450);
	fillrectangle(720, 350, 1120, 450);
	fillrectangle(250, 500, 650, 600);
	fillrectangle(720, 500, 1120, 600);

	settextstyle(80, 40, L"楷体");
	setbkmode(TRANSPARENT);
	outtextxy(250, 200, L"欢迎来到人工智能五子棋");

	settextstyle(100, 50, L"楷体");
	setbkmode(TRANSPARENT);
	setcolor(BLACK);
	outtextxy(255, 350, L"人机黑子");
	outtextxy(725, 350, L"双人对战");
	outtextxy(255, 500, L"人机白子");
	outtextxy(725, 500, L"机器对下");

	ButtonClick1();

	getchar();

	return 0;
}

