#ifndef _MINMAX_H_
#define _MINMAX_H_

#include<string.h>
#include<limits.h>

const int OTHER = 0;// 其他棋型
const int WIN = 1;
const int LOSE = 2;
const int FLEX4 = 3;
const int flex4 = 4;
const int BLOCK4 = 5;
const int block4 = 6;
const int FLEX3 = 7;
const int flex3 = 8;
const int BLOCK3 = 9;
const int block3 = 10;
const int FLEX2 = 11;
const int flex2 = 12;
const int BLOCK2 = 13;
const int block2 = 14;
const int FLEX1 = 15;
const int flex1 = 16;
//权重
const int weight[18] = { 0,100000000,-10000000,50000,-100000,400,-8000,400,-8000,20,-50,20,-50,1,-3,1,-3 };

typedef struct  {//前十个最高分
	int x[11];
	int y[11];
	int score[11];//此处落子的局势分数
}Points;
typedef struct  {//位置
	int x[11];
	int y[11];
	int eval[11];//分数评估
}Decision;

void init6type(void);
int evaluate(void);
void seekPoints(int blackORwhite);
int ifWin(void);
int analyse(int deep, int alpha, int beta, int Depth);

#endif