#include "gobang.h"
int innerBoard[15][15] = { 0 };
HWND hwnd;   

void displayBoard(Point p);
void initBoard();
void regretButton(int x, int y, int w, int h, TCHAR* text)
{
	setbkmode(TRANSPARENT);
	setfillcolor(YELLOW);
	fillroundrect(x, y, x + w, y + h, 10, 10);
	TCHAR s1[] = "黑体";
	settextstyle(30, 0, s1);
	int tx = x + (w - textwidth(text)) / 2;
	int ty = y + (h - textheight(text)) / 2;
	outtextxy(tx, ty, text);
}

int main()
{
	initBoard();
	for (int a = 0; a < 15; a++) {
		for (int b = 0; b < 15; b++) {
			innerBoard[a][b] = 0;
		}
	}
	menu();
	system("pause");
	return 0;
}

void initBoard() 
{
	int i, j;
	Point p, lp;
	lp.x = lp.y = 0;
	IMAGE img;
	int BLACKcount;
	int m, n;
	MOUSEMSG Mouse;
	hwnd = GetHWnd();
	initgraph(600, 600, SHOWCONSOLE);
	setbkcolor(BROWN);
	cleardevice();
	setlinestyle(PS_SOLID, 3);
	setlinecolor(BLACK);
	settextcolor(BLACK);
	setbkmode(0);
	for (i = 2; i < 480; i += 2)
	{
		if (i % 30 == 0)
			line(30, i, 450, i);
	}
	for (j = 2; j < 480; j += 2)
	{
		if (j % 30 == 0)
			line(j, 30, j, 450);
	}
	outtextxy(485, 50, "First hand:");
	outtextxy(500, 70, "Black");
	outtextxy(485, 120, "Second hand:");
	outtextxy(500, 140, "White");
	TCHAR s1[60] = "悔棋";
	regretButton(470, 200, 100, 50, s1);
	Mouse = GetMouseMsg();
	short x = 0;
	short y = 0;
	hwnd = GetHWnd();
	
}

void mention(Point p)
{
	setfillcolor(GREEN);
	solidcircle(p.x*30, p.y*30, 3);
}

void displayBoard(Point p)
{
	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 15; j++) {
			if (innerBoard[i][j] == 1) {
				setfillcolor(BLACK);
				solidcircle(i * 30, j * 30, 10);
			}
			if (innerBoard[i][j] == 2) {
				setfillcolor(WHITE);
				solidcircle(i * 30, j * 30, 10);
			}
		}
	}
	mention(p);
}

void reinit(Point p)
{
	cleardevice();
	initBoard();
	displayBoard(p);
}
