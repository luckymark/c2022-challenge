#pragma once
#include<stdio.h>
#include"chess.h"

int gradeSize = 15, margin_x = 20, margin_y = 20, chessSize = 40,stepNum;//num��ʾ�µ��ڼ�����
int chessMap[20][20],scoreMap[20][20];
bool playerFlag, playType;
int AInum, ManNum, blankNum;
ChessPos maxPoint[20];
ChessPos chessPos[226];