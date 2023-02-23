#pragma once
#include <easyx.h>
#include <vector>
using namespace std;

struct ChessPos
{
	int row;
	int col;
	//���캯��
	ChessPos(int r = 0, int c = 0);
};

class ChessBoard
{
private:
	//��һ������λ��
	vector<ChessPos> lastPos;
	//�洢��ǰ��Ϸ���̺����ӵ����,�հ�Ϊ0������1������-1
	vector<vector<int>> chessMap;

public:
	//���캯��
	ChessBoard(int boardSize);

	//��ʼ�����̡�����������ϵ�����
	void clearBoard();
	//��������������ϵ�������Ϣ
	void updateGameMap(ChessPos* pos, bool playerFlag);

	//���ڻ�ȡ����ĳ��λ�õ���Ϣ���ס��ڡ��գ��Ľӿ�  ���������غ���
	int getChessData(ChessPos* pos);
	int getChessData(int row, int col);

	//lastPos��get��set����
	ChessPos getLastPos();
	vector<ChessPos>* setLastPos();
	//ChessMap��get��set����
	vector<vector<int>> getChessMap();
	vector<vector<int>>* setChessMap();
};



