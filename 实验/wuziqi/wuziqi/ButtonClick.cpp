#include"wuziqi.h"

////������Ϸ������
int ButtonClick1() {
	while (true) {
		ExMessage msg = { 0 };
		if (peekmessage(&msg, EM_MOUSE));//��������Ϣ
		{
			switch (msg.message)//ɸѡ�����Ϣ����
			{
			case WM_LBUTTONDOWN://�����Ϣ
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

int ButtonClick2() {//����һ�ֻ����˳���Ϸ
	settextstyle(40, 20, L"����");
	setbkmode(TRANSPARENT);
	setfillcolor(RGB(255, 255, 255));
	setcolor(BLACK);
	fillrectangle(950, 300, 1130, 380);
	outtextxy(960, 320, L"�˻�����");

	fillrectangle(950, 400, 1130, 480);
	outtextxy(960, 420, L"�˻�����");

	fillrectangle(950, 500, 1130, 580);
	outtextxy(960, 520, L"˫�˶�ս");

	fillrectangle(950, 600, 1130, 680);
	outtextxy(955, 620, L"��������");

	fillrectangle(950, 700, 1155, 780);
	outtextxy(955, 720, L"����������");

	while(true){
		ExMessage msg = { 0 };
		if (peekmessage(&msg, EM_MOUSE));//��������Ϣ
		{
			switch (msg.message)//ɸѡ�����Ϣ����
			{
			case WM_LBUTTONDOWN://�����Ϣ
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



