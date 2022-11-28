#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<ctime>
#include<cstdbool>
#include<cstring>
#include<windows.h>
#include <conio.h>
#include <Windows.h>
#include<time.h>

using namespace std;
const int Maxnum = 2;
const int MaxStep = 10;
const int Length = 25, Width = 25;

extern char maze[Length][Width];
extern bool RoadCreate;


void CreateMaze();
void PrintMaze();
void StartGame();
void CreateRoad(int x, int y, int nun, int way);
int Random();
void Move();
