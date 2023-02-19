#include"gui.h"

extern struct Decision {
	int x[11];
	int y[11];
	int eval[11];
};
extern Decision decision;
extern int analyse(int depth, int alpha, int beta, int Depth);
extern int Board[17][17];
extern int ifWin(void);

void playChess(void)
{
	int i, j;
	initgraph(480, 480, SHOWCONSOLE);
	setbkcolor(BROWN);
	cleardevice();
	setlinestyle(PS_SOLID, 1);//直线宽度
	setlinecolor(BLACK);
	for (i = 30; i <= 480; i += 30)				//横线
	{
		line(30, i, 450, i);
	}
	for (j = 30; j <= 480; j += 30)				//竖线
	{
		line(j, 30, j, 450);
	}

	MOUSEMSG Mouse;
	int flag;
	while (1)
	{
		Mouse = GetMouseMsg();

		flag = 0;
		for (int i = 1; i <= 15; ++i)
		{
			for (int j = 1; j <= 15; ++j)
			{
				if (abs(Mouse.x - i * 30) < 10 && abs(Mouse.y - j * 30) < 10)  //将点击的范围内的值取整
				{
					Mouse.x = i * 30;
					Mouse.y = j * 30;
					flag = 1;
				}
			}
		}


		if (Mouse.uMsg == WM_LBUTTONDOWN) //判断当前鼠标左键是否按下
		{
			if (!Board[Mouse.x / 30][Mouse.y / 30]&&flag==1) {
				setfillcolor(BLACK);

				solidcircle(Mouse.x, Mouse.y, 12);
				Board[Mouse.x / 30][Mouse.y / 30] = 1;

				int val = -INT_MAX, X, Y;
				analyse(4, -INT_MAX, INT_MAX, 4);
				for (int i = 1; i <= 10; ++i) {
					if (val < decision.eval[i]) {
						X = decision.x[i];
						Y = decision.y[i];
						val = decision.eval[i];
					}
				}
				Board[X][Y] = 2;
				setfillcolor(WHITE);
				solidcircle(X * 30, Y * 30, 12);
				if (ifWin() != 0)
				{
					system("pause"); break;
				}
			}
		}

	}
}