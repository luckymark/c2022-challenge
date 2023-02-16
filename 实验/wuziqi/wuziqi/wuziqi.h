//包含的头文件库
#include <graphics.h>
#include <conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//宏定义与全局变量声明
#define HIGH 800//UI界面的高度
#define WIDTH 1400//UI界面的宽度
#define ROW 15//棋盘行数
#define COL 15//棋盘列数
#define DEPTH 4
#define THEBLACK 1
#define THEWHITE -1

extern int board[ROW][COL] ;//棋盘数组 0代表空棋盘 1代表黑子 -1代表白子
extern int vision[ROW][COL];
extern int step;//记录步数

typedef struct {
    int sp;
    int* data;
} Stack;

extern Stack* stack;

//函数声明
int InitUI(void);//开始界面的UI
int GameUI(void);//游戏主界面的UI

void Game(int t);//选择游戏模式
void InitBoard();//初始化棋盘

int ButtonClick1();//进入游戏主界面
int ButtonClick2();//再来一局或者退出游戏
void count_step(int x, int y, int color);//记录对战步数

void AI(int color);//AI落子
int Move(void);//玩家对下
int PlayerMove(int color);//人机对战时的人类玩家
void set(int row, int col);//落子功能的集成模块

void Judge(int row, int col);//判断胜利与平局（平局判定）
int Kill(int depth, int player, int color);//算杀
int check(int row, int col);//检查部分棋型
int thedefend(int row, int col, int color);//防御
int fobidden(int row, int col);//禁手

int Chess_type(int row, int col, int direction);//棋型判断 辅助估值
int Opposite_shore(int row, int col, int direction, int color);//辅助判断变种棋型

int SituationValuation(int row, int col, int color);//将棋型判断与估值分割成两个模块
int Settled_Situation(int color);//辅助全局估值 
int min_max_dfs(int depth, int player, int color, int a, int b);//dfs

void Neighbor_Location(int row, int col, int t);//位置减枝

int Compete_Chess_Repentance();//悔棋

Stack* creatRepentanceStack(int size);
void stackpush(Stack* pStack, int data);
int stackpop(Stack* pStack);


