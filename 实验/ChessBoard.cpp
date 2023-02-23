#include "ChessBoard.h"

//���캯��
ChessPos::ChessPos(int r, int c)
{
	this->row = r;
	this->col = c;
}

ChessBoard::ChessBoard(int boardSize)
{
	for (int i = 0; i < boardSize; i++)
	{
		vector<int>row;
		for (int j = 0; j < boardSize; j++)
		{
			row.push_back(0);
		}
		chessMap.push_back(row);
	}

}

//��������ϵ�����
void ChessBoard::clearBoard()
{
	lastPos.clear();
	chessMap.clear();
	for (int i = 0; i < 15; i++)
	{
		vector<int>row;
		for (int j = 0; j < 15; j++)
		{
			row.push_back(0);
		}
		chessMap.push_back(row);
	}
}

//���������ϵ�������Ϣ
void ChessBoard::updateGameMap(ChessPos* pos, bool playerFlag)
{
	lastPos.push_back(*pos);
	if (playerFlag == true)
	{
		chessMap[pos->row][pos->col] = 1;
	}
	else
	{
		chessMap[pos->row][pos->col] = -1;
	}
}


//���ڻ�ȡ����ĳ��λ�õ���Ϣ���ס��ڡ��գ��Ľӿ�  ���������غ���
int ChessBoard::getChessData(ChessPos* pos)
{
	return chessMap[pos->row][pos->col];
}
int ChessBoard::getChessData(int row, int col)
{
	return chessMap[row][col];
}


//���ڻ�ȡ��һ������������
ChessPos ChessBoard::getLastPos()
{
	return lastPos.back();
}
//lastPos��set����
vector<ChessPos>* ChessBoard::setLastPos()
{
	return &lastPos;
}

//ChessMap��get��set����
vector<vector<int>> ChessBoard::getChessMap()
{
	return chessMap;
}
vector<vector<int>>* ChessBoard::setChessMap()
{
	return &chessMap;
}
