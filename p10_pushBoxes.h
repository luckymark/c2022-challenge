#pragma once
#include <stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>

const int ROW = 7, QUEUE = 10;//include'\n' and NULL
extern char ar[ROW][QUEUE];
void map(char MAP[100]);
int play(void);
void savegoal(int Goal);
