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
void init();//初始化
bool clickBoard(int x, int y, ChessPos* pos);//检查是否为有效点击
void chessDown(ChessPos* pos);//下棋
int getChessData(ChessPos* pos);
int getChessData(int x, int y);
bool checkOver();//检查棋局是否结束
bool checkWin();
void updateGameMap(ChessPos* pos);
void dispose();
void regretStep();
void deleteStep(ChessPos* pos);
void updateMap(ChessPos* pos);
extern ChessPos lastPos,chessPos[226];
extern int chessMap[20][20];//存储当前棋盘数据。0：空白 1：黑子 -1：白子
extern int gradeSize, margin_x, margin_y, chessSize,stepNum;