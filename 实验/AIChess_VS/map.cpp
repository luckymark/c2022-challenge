#include "AIChess_VS.h"
using namespace std;

int inx, iny;
Chess Map[17][17];
void chessboard()
{
	initgraph(510,510,EX_SHOWCONSOLE);
	setbkcolor(YELLOW);
	setlinestyle(PS_SOLID, 2);
	setlinecolor(BLACK);
	settextcolor(BLACK);
	cleardevice();
	int step = 30;
	for (int i = 1; i <= 15; i++)
	{
		line(i * step, 1 * step, i * step, 15 * step);
		
		line(1 * step, i * step, 15 * step, i * step);
	}
	for (int i = 1; i <= 15; i++)
	{
		TCHAR s[5];
		swprintf_s(s,_T(" %d"), i);
		outtextxy(i * step-10, 16 * step-15, s);
		outtextxy(16 * step-15, i * step-10, s);
	}
	for (int i = 1; i <= 15; i++)
	{
		for (int j = 1; j <= 15; j++)
		{
			Map[i][j].x = i;
			Map[i][j].y = j;
			Map[i][j].color = Map[i][j].atkV = Map[i][j].defV = 0;
			if (i == 0 || i == 16 || j == 0 || j == 16)
			{
				Map[i][j].isBoundry = 1;
			}
		}
	}
}

void putChess(Chess it)
{
	int x = it.x, y = it.y, color = it.color;
	int step = 30;
	if (color == 1)//╨звс
	{
		setfillcolor(BLACK);
	}
	else if (color == 2)
	{
		setfillcolor(WHITE);
	}
	fillcircle(y*step, x*step, 12);
}



int Map_num()
{
	int cnt = 0;
	for (int i = 1; i <= 15; i++)
		for (int j = 1; j <= 15; j++)
			if (Map[i][j].color != 0)
				cnt++;
	return cnt;
}