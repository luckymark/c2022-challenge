#include "Player.h"

//���캯��
void Player::init(Chess* chess, ChessBoard* board)
{
	this->chess = chess;
	this->board = board;

}
//����
bool Player::go()
{
	ExMessage msg;
	ChessPos pos;
	while (1)
	{
		msg = getmessage(EX_MOUSE);
		//�����ж�
		if (msg.lbutton == 1 && msg.x > 885 && msg.x < 1050 && msg.y >530 && msg.y < 575)
		{
			chess->turnBack(blck_white);
		}
		//�ؿ��ж�
		if (msg.lbutton == 1 && msg.x > 885 && msg.x < 1050 && msg.y >600 && msg.y < 645)
		{
			return false;
		}
		//�����ж�
		if (msg.lbutton == 1 && msg.x > 290 && msg.x < 862 && msg.y < 640 && msg.y >64 && chess->clickBoard(msg.x, msg.y, &pos))
		{
			break;
		}
	}
	board->updateGameMap(&pos, chess->getPlayerFlag());
	// ����
	chess->chessDown(&pos, chess->getPlayerFlag());
	return true;
}
//black_white��set����
void Player::setBlack_White(bool flag)
{
	blck_white = flag;
}
