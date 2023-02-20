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

extern int inx, iny;//�������x��y
extern void chessboard();//��������
extern void putChess(Chess);//��������
extern Chess AI();//
extern void AI_put(Chess);//AI����
extern void Person_put(Chess);//�������
extern int Map_num();//������������
extern Chess Map[17][17];//
extern bool line_same(Line,vector <int>);
extern bool check_win(Chess);
extern Line getline_lay(Chess, int, int);
extern Line getline_stand(Chess, int, int);
extern Line getline_main(Chess, int, int);
extern Line getline_vice(Chess, int, int);
extern int Map_num();
//����
extern void giveAllValue();
extern long long getatkV(Chess);
extern long long getdefV(Chess);

#endif