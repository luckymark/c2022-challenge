#pragma once
#include "Chess.h"
#include "ChessBoard.h"

class Player
{
private:
	Chess* chess;
	ChessBoard* board;
	bool blck_white = true;//判断玩家先后手，默认为先手
public:
	//玩家初始化
	void init(Chess* chess, ChessBoard* board);
	//玩家落子
	bool go();
	//black_white的set函数
	void setBlack_White(bool flag);
};
