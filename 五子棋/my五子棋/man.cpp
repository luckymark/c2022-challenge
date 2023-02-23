#include "man.h"

void goMan()
{
	MOUSEMSG msg;//获取鼠标点击消息
	ChessPos pos;

	while (1)
	{
		msg = GetMouseMsg();
		if (msg.uMsg == WM_LBUTTONDOWN && clickBoard(msg.x, msg.y, &pos)) {
			chessDown(&pos);
			break;
		}
		else if (msg.uMsg == WM_LBUTTONDOWN && msg.x >= 400 && msg.x <= 650 && msg.y >= 700 && msg.y <= 750) {
			gameStart();
			break;
		}
		else if (msg.uMsg == WM_LBUTTONDOWN && msg.x >= 240 && msg.x <= 375 && msg.y >= 700 && msg.y <= 750) {
			regretStep();
			break;
		}
	}
}
