#define _CRT_SECURE_NO_DEPRECATE 1
#define _CRT_NONSTDC_NO_DEPRECATE 1
//### 题目：迷宫小游戏（基于console）
//
//### 功能要求：
//
//1. 在控制台上显示一个迷宫，包括：墙、玩家、出口等；
//1. 通过上下左右键，控制玩家行走；
//1. 当玩家到达出口，则显示玩家赢得了游戏；

#include<stdio.h>
#include<stdlib.h>
#include <windows.h>
#include<conio.h>

int main()
{
	SetConsoleTitle(L"maze");
    //迷宫
    char map[50][50] = {
                "********************",
                "*&   *    **********",
                "* *** *** **********",
                "* *** ***      *****",
                "*   * *O*** ** *****",
                "** ** * *** ** *** *",
                "** ** *     *****  *",
                "** ****** ******* **",
                "**        *       **",
                "**************** ***",
    };
    int i, j;
    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 20; j++)
        {
            printf("%c", map[i][j]);
        }
        printf("\n");
    }
    //定义位置
    int x = 4;
    int y = 7;//初始
    int a = 1;
    int b = 1;//结束
    //移动
    while (x != a || y != b)
    {
        char ch[1];
        scanf_s("%c", ch, 1);
        ch[0] = getch();
        if (ch[0] == 's')
        {
            if (map[x + 1][y] != '*')
            {
                map[x][y] = ' ';
                x++;
                map[x][y] = 'O';
            }
        }
        if (ch[0] == 'w')
        {
            if (map[x - 1][y] != '*')
            {
                map[x][y] = ' ';
                x--;
                map[x][y] = 'O';
            }
        }
        if (ch[0] == 'a')
        {
            if (map[x][y - 1] != '*')
            {
                map[x][y] = ' ';
                y--;
                map[x][y] = 'O';
            }
        }
        if (ch[0] == 'd')
        {
            if (map[x][y + 1] != '*')
            {
                map[x][y] = ' ';
                y++;
                map[x][y] = 'O';
            }
        }
        system("cls");
        int i, j;
        for (i = 0; i < 10; i++)
        {
            for (j = 0; j < 20; j++)
            {
                printf("%c", map[i][j]);
            }
            printf("\n");
        }
    } 
    system("cls");
    puts("通过！");
    Sleep(3000);
    return 0;   
}