
#ifndef GOBANG_HEAD_H
#define GOBANG_HEAD_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include<time.h>

#include "raylib.h"

#define RADIUS 12
#define LINE_WID 1
#define INTERVAL 30
#define SIZE 23

#define L5 10000000
#define L4 500000
#define L3 4000
#define L2 200
#define L1 10
#define D4 4000
#define D3 200
#define D2 10

#define DEP 3
#define INF INT32_MAX
#define AI 1
#define BORDER 4
#define BORDER_NUM 3

#define FACTOR 3 //增加玩家L5，L4，D4,L3的权重
#define MAP_VALUE 2

#define TABLE_SIZE 33554432 //2的25次方

typedef struct {
    int x;
    int y;
}Coord;
typedef struct {
    Coord pos;
    int value;
}Piece;
typedef struct { //再往后搜depth层己方所能获得的最好分数value
    int value;
    int depth;
    uint64_t lock;
}Hash;

extern int humAddVal[4][4][4][4][4][4][4][4];
extern int comAddVal[4][4][4][4][4][4][4][4];
extern int humDeVal[4][4][4][4][4][4][4][4];
extern int comDeVal[4][4][4][4][4][4][4][4];
extern int humNum,comNum;
extern int score;
extern int valueMap[SIZE][SIZE];

extern uint64_t humTable[SIZE][SIZE];
extern uint64_t comTable[SIZE][SIZE];
extern uint64_t key;
//extern uint64_t keyLock;
extern Hash zobristCache[TABLE_SIZE]; //zobristCache[i]：当局面键值为i时对应的Hash

extern void drawChessboard(int (*gobang)[SIZE],int humNum,int comNum,Color humColor,Color comColor);
extern void chessPlay(int (*gobang)[SIZE],int humNum,int comNum,Color humColor,Color comColor);
extern Coord convertPosition(int (*gobang)[SIZE]); //获取玩家左键的物理坐标并返回转换后的在扩展数组上的棋盘坐标

extern void setAddVal(int playerNum,int oppoNum,int humNum,int comNum); //给棋型数组赋值
extern void setDeleteVal(int playerNum,int oppoNum,int humNum,int comNum);
extern int evaluate(int (*gobang)[SIZE],int x, int y, int playerNum,int humNum,int comNum); //返回该落子产生的己方得分增量
extern Piece makeMove(int (*gobang)[SIZE], int spaceCount); //电脑找到最佳落子点并返回该落子坐标和落子分值
extern void initZobrist(void); //初始化当前键值、玩家和AI键值以及zobristCache数组

void testCase(int (*gobang)[SIZE],int humNum,int comNum,Color humColor,Color comColor);

#endif //GOBANG_HEAD_H