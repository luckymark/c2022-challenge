#include"start.h"

void gameStart()
{
	MOUSEMSG msg;
	IMAGE img;
	initgraph(1000, 700);
	setbkcolor(RGB(255, 244, 126));
	cleardevice();
	settextcolor(RGB(0, 0, 0));
	settextstyle(50, 30, "楷体");
	outtextxy(200, 50, TEXT("欢迎来到五子棋游戏"));
	settextstyle(100, 50, "楷体");
	outtextxy(75, 500, TEXT("双人对决"));
	outtextxy(525, 500, TEXT("人机对决"));
	setlinecolor(RGB(0, 0, 0));
	rectangle(75, 500, 475, 600);
	rectangle(525, 500, 925, 600);
	loadimage(&img, "C:\\Users\\谭浩翔\\Desktop\\visual studio\\my五子棋\\sta.png",320,320);
	putimage(300, 150, &img);
	//setfillcolor(BLUE);
	//cleardevice();
	while (1) {
		msg = GetMouseMsg();
		playType = false;
		if (msg.uMsg == WM_LBUTTONDOWN && msg.x > 100 && msg.x < 450 && msg.y>500 && msg.y < 600) {
			playType = true;
			closegraph();
			break;
		}
		if (msg.uMsg == WM_LBUTTONDOWN && msg.x > 550 && msg.x < 900 && msg.y>500 && msg.y < 600) {
			closegraph();
			break;
		}
	}
	if (playType) Man_ManPlay();
	else Man_AIplay();
}
