#include"wuziqi.h"

////进入游戏主界面
int ButtonClick1() {
	while (true) {
		ExMessage msg = { 0 };
		if (peekmessage(&msg, EM_MOUSE));//检测鼠标信息
		{
			switch (msg.message)//筛选鼠标信息类型
			{
			case WM_LBUTTONDOWN://左键信息
				closegraph();
				if (msg.x >= 250 && msg.x <= 650 && msg.y >= 350 && msg.y <= 450) {
					Game(1);
				}
				if (msg.x >= 720 && msg.x <= 1120 && msg.y >= 350 && msg.y <= 450) {
					Game(2);
				}
				if (msg.x >= 250 && msg.x <= 650 && msg.y >= 500 && msg.y <= 600) {
					Game(3);
				}
				if (msg.x >= 720 && msg.x <= 1120 && msg.y >= 500 && msg.y <= 600) {
					Game(4);
				}
				break;
			default:
				break;
			}
		}
	}
	return 0;
}

int ButtonClick2() {//再来一局或者退出游戏
	settextstyle(40, 20, L"楷体");
	setbkmode(TRANSPARENT);
	setfillcolor(RGB(255, 255, 255));
	setcolor(BLACK);
	fillrectangle(950, 300, 1130, 380);
	outtextxy(960, 320, L"人机黑子");

	fillrectangle(950, 400, 1130, 480);
	outtextxy(960, 420, L"人机白子");

	fillrectangle(950, 500, 1130, 580);
	outtextxy(960, 520, L"双人对战");

	fillrectangle(950, 600, 1130, 680);
	outtextxy(955, 620, L"机器对下");

	fillrectangle(950, 700, 1155, 780);
	outtextxy(955, 720, L"返回主界面");

	while(true){
		ExMessage msg = { 0 };
		if (peekmessage(&msg, EM_MOUSE));//检测鼠标信息
		{
			switch (msg.message)//筛选鼠标信息类型
			{
			case WM_LBUTTONDOWN://左键信息
				closegraph();
				if (msg.x >= 950 && msg.x <= 1130 && msg.y >= 300 && msg.y <= 380) {
					Game(1);
				}
				else if (msg.x >= 950 && msg.x <= 1130 && msg.y >= 400 && msg.y <= 480) {
					Game(3);
				}
				else if (msg.x >= 950 && msg.x <= 1130 && msg.y >= 500 && msg.y <= 580) {
					Game(2);
				}
				else if (msg.x >= 950 && msg.x <= 1130 && msg.y >= 600 && msg.y <= 680) {
					Game(4);
				}
				else if (msg.x >= 950 && msg.x <= 1155 && msg.y >= 700 && msg.y <= 780) {		
					InitUI();
				}	
				break;
			default:
				break;
			}
		}
	}
	return 0;
}



