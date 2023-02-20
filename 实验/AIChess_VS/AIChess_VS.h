#pragma once
#ifndef AIChess_VS
#define AIChess_VS

#include<bits/stdc++.h>
#include<easyx.h>
using namespace std;

typedef struct Chess {
	int color, x, y;
	long long  atkV, defV;
	bool isBoundry;
}Chess;//
typedef struct Line {
	vector<int> f;
	int p;
}Line;

extern int inx, iny;//玩家输入x，y
extern void chessboard();//绘制棋盘
extern void putChess(Chess);//绘制棋子
extern Chess AI();//
extern void AI_put(Chess);//AI下棋
extern void Person_put(Chess);//玩家下棋
extern int Map_num();//计算棋子数量
extern Chess Map[17][17];//
extern bool line_same(Line,vector <int>);
extern bool check_win(Chess);
extern Line getline_lay(Chess, int, int);
extern Line getline_stand(Chess, int, int);
extern Line getline_main(Chess, int, int);
extern Line getline_vice(Chess, int, int);
extern int Map_num();
//调试
extern void giveAllValue();
extern long long getatkV(Chess);
extern long long getdefV(Chess);

#endif