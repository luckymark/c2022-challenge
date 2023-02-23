#pragma once
#include <easyx.h>
#include <vector>
using namespace std;

struct ChessPos
{
	int row;
	int col;
	//构造函数
	ChessPos(int r = 0, int c = 0);
};

class ChessBoard
{
private:
	//上一步落子位置
	vector<ChessPos> lastPos;
	//存储当前游戏棋盘和棋子的情况,空白为0，黑子1，白子-1
	vector<vector<int>> chessMap;

public:
	//构造函数
	ChessBoard(int boardSize);

	//初始化棋盘——清空棋盘上的棋子
	void clearBoard();
	//落子完更新棋盘上的棋子信息
	void updateGameMap(ChessPos* pos, bool playerFlag);

	//用于获取棋盘某个位置的信息（白、黑、空）的接口  有两个重载函数
	int getChessData(ChessPos* pos);
	int getChessData(int row, int col);

	//lastPos的get、set函数
	ChessPos getLastPos();
	vector<ChessPos>* setLastPos();
	//ChessMap的get、set函数
	vector<vector<int>> getChessMap();
	vector<vector<int>>* setChessMap();
};



