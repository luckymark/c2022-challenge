#pragma once
#include<graphics.h>
#include<math.h>
#include<stdio.h>
#include"start.h"

struct ChessPos {
	int x;
	int y;
};

extern bool playerFlag,playType;
void init();//��ʼ��
bool clickBoard(int x, int y, ChessPos* pos);//����Ƿ�Ϊ��Ч���
void chessDown(ChessPos* pos);//����
int getChessData(ChessPos* pos);
int getChessData(int x, int y);
bool checkOver();//�������Ƿ����
bool checkWin();
void updateGameMap(ChessPos* pos);
void dispose();
void regretStep();
void deleteStep(ChessPos* pos);
void updateMap(ChessPos* pos);
extern ChessPos lastPos,chessPos[226];
extern int chessMap[20][20];//�洢��ǰ�������ݡ�0���հ� 1������ -1������
extern int gradeSize, margin_x, margin_y, chessSize,stepNum;