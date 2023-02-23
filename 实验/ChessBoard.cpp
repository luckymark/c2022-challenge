#include "ChessBoard.h"

//构造函数
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

//清空棋盘上的棋子
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

//更新棋盘上的棋子信息
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


//用于获取棋盘某个位置的信息（白、黑、空）的接口  有两个重载函数
int ChessBoard::getChessData(ChessPos* pos)
{
	return chessMap[pos->row][pos->col];
}
int ChessBoard::getChessData(int row, int col)
{
	return chessMap[row][col];
}


//用于获取上一步的棋子坐标
ChessPos ChessBoard::getLastPos()
{
	return lastPos.back();
}
//lastPos的set函数
vector<ChessPos>* ChessBoard::setLastPos()
{
	return &lastPos;
}

//ChessMap的get、set函数
vector<vector<int>> ChessBoard::getChessMap()
{
	return chessMap;
}
vector<vector<int>>* ChessBoard::setChessMap()
{
	return &chessMap;
}
