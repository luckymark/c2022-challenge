//�����ʼ��
#include"wuziqi.h"

int GameUI(void)
{
	initgraph(WIDTH, HIGH, EX_DBLCLKS);
	setfillcolor(RGB(255, 82, 178));
	solidrectangle(0, 0, WIDTH, HIGH);

	setfillcolor(RGB(255, 153, 00));
	solidrectangle(25, 25, 775, 775);//���̵�ͼ������

	setfillcolor(RGB(255, 255, 255));
	fillrectangle(950, 300, 1050, 380);//�����ͼ������
	
	setcolor(BLACK);
	
	for (int i = 50; i <= 775; i += 50){
		line(50, i, 750, i);//��15������
	}
	for (int i = 50; i <= 775; i += 50){
		line(i, 50, i, 750);//��15������
	}

	settextstyle(40, 20, L"����");
	setbkmode(TRANSPARENT);
	outtextxy(950, 50, L"������5.0");

	outtextxy(960, 320, L"����");
	
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

	settextstyle(80, 40, L"����");
	setbkmode(TRANSPARENT);
	outtextxy(250, 200, L"��ӭ�����˹�����������");

	settextstyle(100, 50, L"����");
	setbkmode(TRANSPARENT);
	setcolor(BLACK);
	outtextxy(255, 350, L"�˻�����");
	outtextxy(725, 350, L"˫�˶�ս");
	outtextxy(255, 500, L"�˻�����");
	outtextxy(725, 500, L"��������");

	ButtonClick1();

	getchar();

	return 0;
}

