#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <graphics.h>
#include <conio.h>

#define SIZEE 15
#define TOTALMIN -999999999999999
#define TOTALMAX 100000000000000

#define KILLDEPTH 12 //算杀深度
#define DEPTH 4 //深度


typedef long long LL;
typedef struct Point {
    int x;
    int y;
}Point;
typedef struct Type {
    int more;
    int win5;
    int alive4;
    int sleepy4;
    int dead4;
    int alive3;
    int sleepy3;
    int dead3;
    int alive2; 
    int sleepy2; 
    int dead2; 
    int alive1; 
    int sleepy1; 
    int dead1;
}Type;
typedef struct Move {
    Point p;
    int score;
}Move;


extern int innerBoard[SIZEE][SIZEE];
extern int id;
extern int num;
extern int aix, aiy;
extern int Cancel;

int regret(Point p, int x, int y);
void displayBoard();
void menu(void);
void reinit();

void put(Point p, int player);
void unPut(Point p);
int opp(int player);
void Player(void);
void Computer(void);
int JudgeFive(int x, int y);
int JudgeDisplay(void);

Point nextPoint(Point p, int d, int dr);
int inSide(Point p);
void getBoundary(Point p, int d, int* s, int way, int player);
int Length(Point p, int d, int* left, int* right, int player);
int singleScore(Point p, int player);
int singleScoreOppo(Point p, int player);
LL wholeScore(int player);
Type typeAnalysis(int length, int* left, int* right, int player);
Type getType(Point p, int player);

LL minmax(int depth, LL alpha, LL beta, int player);
LL alphaBeta(int depth, LL alpha, LL beta, int player, Point p);
int inspireFind(Move* s, int player);
void shellSort(Move* s, int len);
int killSearch(void);
int maxKill(int depth, Point p);
int minKill(int depth, Point p);
int findComKill(Move* move);
int findHumKill(Move* move);
