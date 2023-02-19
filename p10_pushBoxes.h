#pragma once
#include <stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
const int ROW = 7, QUEUE = 10;//include'\n' and NULL
const char MAP1[100] = "C:\\Users\\86134\\source\\repos\\p10_pushBoxes\\p10_pushBoxes_map1.txt";
const char MAP2[100] = "C:\\Users\\86134\\source\\repos\\p10_pushBoxes\\p10_pushBoxes_map2.txt";
void map(const char MAP[100]);
int play(void);
void savegoal(int Goal);
