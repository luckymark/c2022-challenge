#include"start.h"

void gameStart()
{
	MOUSEMSG msg;
	IMAGE img;
	initgraph(1000, 700);
	setbkcolor(RGB(255, 244, 126));
	cleardevice();
	settextcolor(RGB(0, 0, 0));
	settextstyle(50, 30, "����");
	outtextxy(200, 50, TEXT("��ӭ������������Ϸ"));
	settextstyle(100, 50, "����");
	outtextxy(75, 500, TEXT("˫�˶Ծ�"));
	outtextxy(525, 500, TEXT("�˻��Ծ�"));
	setlinecolor(RGB(0, 0, 0));
	rectangle(75, 500, 475, 600);
	rectangle(525, 500, 925, 600);
	loadimage(&img, "C:\\Users\\̷����\\c2022-challenge\\������\\sta.png",320,320);
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
