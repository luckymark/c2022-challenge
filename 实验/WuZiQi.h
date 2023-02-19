#ifndef NEWWUZIQI_WUZIQI_H
#define NEWWUZIQI_WUZIQI_H

#pragma GCC optimize(3,"Ofast","inline")
//#pragma comment(lib,"Winmm.lib")

#include <graphics.h>
#include <conio.h>
#include <math.h>
#include <stdio.h>
#include <limits.h>
#include <mmsystem.h>

#define DEPTH 8//4
#define WIDTH 8//54

const int Broad_SizeNum=18;
const float BlockSize = 43.3 ;
const int rW = GetSystemMetrics(SM_CXSCREEN),rH = GetSystemMetrics(SM_CYSCREEN);//UI 获取大小(1536,864);
const int margin_X = rW/2 -rH/2 +1+BlockSize;//UI 从左到右 直到地图 第一个格子前的距离
const int margin_Y = BlockSize;

typedef long long LL;
typedef enum{//棋子类型判断
    Chess_Black = -1,
    Chess_White = 1,
}chess_kind_j;

typedef enum{
    PVP_ = 0,
    PVE_1 = 1,
    PVE_2 = 2,
}Game_Mode;
struct ChessData{//棋子数据
    int Chess_Map[Broad_SizeNum][Broad_SizeNum];//1是白棋，-1是黑棋，0是空
    int Score_Map[Broad_SizeNum][Broad_SizeNum];

    int Player_Flag;//表示当前下棋方 玩家先手 1 是白棋玩家， -1 是黑棋AI  ； 电脑先手情况相反

};

typedef struct Info{//参考山东师范大学董红安在2005年的硕士毕业论文中使用的的评分表
    int alive1; //活1 20
    int dalive1; //眠1 10
    int dead1; //死1 1

    int alive2; //活2 120
    int dalive2; //眠2 20
    int dead2; //死2 5

    int alive3;//活3 720
    int dalive3;//眠3 120
    int dead3;//死3 10

    int alive4;//活4 4320
    int dalive4;//冲4 720
    int dead4;//死4 60

    int more;//长连
    int win5;//连5
}Info;

//点的坐标
typedef struct Point{
    int x;
    int y;
}Point;


typedef struct point_Data{
    Point p;
    int score;
}point_Data;

extern int num;//总棋子数
extern int id;
extern ChessData Game;
extern int AI_x,AI_y;

//Game_Start.cpp
void test();
void AI_go();
void Player_go(MOUSEMSG msg);
bool Judge_Player_Down(MOUSEMSG msg); //判断子落的位置是否成功，返回落点坐标 0 or 1
void chess_Down(int row, int col,chess_kind_j kind);//执行落子
bool CheckOver(int GameMode);
void EndGame();
void init();
int Is_inBoard(struct Point p);
void unmock_chess_Down(struct Point p);
void mock_chess_Down(struct Point p,int player);

//myscore
Point nextPoint(Point p,int d,int di);
void extend_info(struct Point p,int d,int way,int player,int *side);
int get_ChessLength(Point p,int d,int *left,int *right,int player);
Info get_ChessInfo(struct Point p,int player);
int count_singleScore(Point p,int player);
Info type_Analysis(int length,int *left, int *right,int player);
int forbidden_Hand(Point p,int player);

//min_max.cpp
void initChess_Data(ChessData *data);//初始化棋盘数据
void update_ChessDate(ChessData *data, int row, int col);

void shellSort(point_Data *s,int len);
int JudgeFive(Point p,int player);
LL minmaxSearch(int depth,LL alpha,LL beta,int player);
LL alphaBeta(int depth,LL alpha,LL beta,int player,Point p);
LL count_wholeScore(int player);

//GoPng.cpp
void drawAlpha(IMAGE* picture, int  picture_x, int picture_y);// 画PNG图用

//main.cpp
void PVP();
void PVE1();
void PVE2();
#endif //NEWWUZIQI_WUZIQI_H