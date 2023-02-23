#pragma once
#include <graphics.h>
#include "ChessBoard.h"

class Chess
{
private:
	int boardSize;// ���̳ߴ磨15�ߣ�
	float margin_x;//ˮƽ�߽����;
	int margin_y;//��ֱ�߽����;
	float chessSize; //���Ӵ�С�����̷����С��
	int windowWidth = 1400;//���ڿ��
	int windowHigth = 700;//���ڸ߶�

	IMAGE lostImg;
	IMAGE winImg;
	IMAGE chessBlackImg;
	IMAGE chessWhiteImg;

	//��ʾ���巽, true:���巽  false:���巽
	bool playerFlag;

	//���̣����ڴ洢������
	ChessBoard* board;
public:
	//���캯��
	Chess(int boardSize, int marginX, int marginY, float chessSize);

	//Chess�ĳ�ʼ������������
	//����ֿ�ʼʱ��ִ��һ�Σ���ÿһ��ֻ��ִ��һ��
	bool init(ChessBoard* board);
	//�������̵�ͼƬ��Դ����ʼ�����̵��������
	void loadChessBoard();
	//�ж���ҵ��Ⱥ���ѡ��
	bool chooseHand();

	//�ж���ָ������(x,y)λ�ã��Ƿ�����Ч���
	//�������Ч���������Ч�����λ��(�У��У������ڲ���pos��
	bool clickBoard(int x, int y, ChessPos* pos);
	//�����̵�ָ��λ������,true �� ��false ��
	void chessDown(ChessPos* pos, bool payerFlag/*chess_kind_t kind*/);

	//���庯��
	void turnBack(bool black_white);
	//���ֺ���
	void changeHand(ChessPos* pos);
	// �ж�����Ƿ����
	bool checkOver(bool flag);
	bool checkWin();
	bool heqi();

	//���ڻ�ȡ���̴�С��15�ߣ��Ľӿ�
	int getBoardSize();
	//���ڻ�ȡplayerFlag�Ľӿ�
	bool getPlayerFlag();
};
