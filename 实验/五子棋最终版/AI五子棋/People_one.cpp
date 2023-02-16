#include "People_one.h"

void People_one::init(Chess* chess)
{
	this->chess = chess;
}
void People_one::go()
{
	MOUSEMSG msg;//获取鼠标信息
	ChessPos pos;
	
	while (1)
	{
		msg = GetMouseMsg();
		if (msg.uMsg == WM_LBUTTONDOWN && chess->clickBoard(msg.x, msg.y, &pos))
		{
			break;
		}
	}
	printf("%d,%d\n", msg.x, msg.y);
	printf("%d,%d\n", pos.row+1, pos.col+1);
	chess->chessDown(&pos, CHESS_BLACK);

}