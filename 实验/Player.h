#pragma once
#include "Chess.h"
#include "ChessBoard.h"

class Player
{
private:
	Chess* chess;
	ChessBoard* board;
	bool blck_white = true;//�ж�����Ⱥ��֣�Ĭ��Ϊ����
public:
	//��ҳ�ʼ��
	void init(Chess* chess, ChessBoard* board);
	//�������
	bool go();
	//black_white��set����
	void setBlack_White(bool flag);
};
