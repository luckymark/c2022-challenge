#pragma once
#include"chess.h"

extern int scoreMap[20][20];

extern ChessPos maxPoint[20];

extern int AInum, ManNum, blankNum;

extern bool playerFlag;

void calculateScore();

ChessPos think();

void goAI();

void attackScore();

void defenseScore();