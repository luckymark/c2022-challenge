//### 题目：奔跑的字母
//
//### 功能要求：
//
//1. 在console上输出一个字母（或单词）
//1. 使该字母或单词，按一定速度从左至右运动
//1. 当遇到屏幕边界时反向运动


#include<stdio.h>
#include<stdlib.h>
#include<windows.h>

const int width = 100, w = 0;

int main()
{
	SetConsoleTitle(L"runningLetter");
    int a, b;
    char c[100];
    a = 0;
    b = 1;
    scanf_s("%s", c, 100);//输入字符
    system("cls");
    while (1)
    {
        a += b;
        if (a == width || a == w)
        {
            b = -b;
        }
        for (int i = 0; i <= a; i++)
        {
            printf(" ");
        }
        printf("%s",c);
        Sleep(100);
        system("cls");
    }
    system("pause");
    return 0;
}