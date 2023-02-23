#pragma once
#include "Chess.h"
#include "ChessBoard.h"
#include "Node.h"
class Al
{
private:
	bool black_white = false;//判断al先后手 默认为后手
	Chess* chess;
	//棋盘，用于存储棋局情况
	ChessBoard* board;
	Node* node;

	// 存储各个点位的评分情况，作为AI下棋依据
	vector<vector<int>> scoreMap;
public:
	void init(Chess* chess, ChessBoard* board, Node* node);
	void go();
	void setBlack_White(bool flag);
};

