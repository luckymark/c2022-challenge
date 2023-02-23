#include "Player.h"

//构造函数
void Player::init(Chess* chess, ChessBoard* board)
{
	this->chess = chess;
	this->board = board;

}
//落子
bool Player::go()
{
	ExMessage msg;
	ChessPos pos;
	while (1)
	{
		msg = getmessage(EX_MOUSE);
		//悔棋判断
		if (msg.lbutton == 1 && msg.x > 885 && msg.x < 1050 && msg.y >530 && msg.y < 575)
		{
			chess->turnBack(blck_white);
		}
		//重开判断
		if (msg.lbutton == 1 && msg.x > 885 && msg.x < 1050 && msg.y >600 && msg.y < 645)
		{
			return false;
		}
		//落子判断
		if (msg.lbutton == 1 && msg.x > 290 && msg.x < 862 && msg.y < 640 && msg.y >64 && chess->clickBoard(msg.x, msg.y, &pos))
		{
			break;
		}
	}
	board->updateGameMap(&pos, chess->getPlayerFlag());
	// 落子
	chess->chessDown(&pos, chess->getPlayerFlag());
	return true;
}
//black_white的set函数
void Player::setBlack_White(bool flag)
{
	blck_white = flag;
}
