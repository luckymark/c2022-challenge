#pragma once
#include "Chess.h"
#include "ChessBoard.h"
#include "Node.h"
class Al
{
private:
	bool black_white = false;//�ж�al�Ⱥ��� Ĭ��Ϊ����
	Chess* chess;
	//���̣����ڴ洢������
	ChessBoard* board;
	Node* node;

	// �洢������λ�������������ΪAI��������
	vector<vector<int>> scoreMap;
public:
	void init(Chess* chess, ChessBoard* board, Node* node);
	void go();
	void setBlack_White(bool flag);
};

