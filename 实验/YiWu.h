#include <graphics.h>
#include <conio.h>
#include <windows.h>
#define _CRT_SECURE_NO_WARNINGS 1

class Menu {
public:
    void Display();
    void ChessBoard(MOUSEMSG m);
};

class Play {
public:
    void TwoPlayerGame(MOUSEMSG m);
    void ComputerUserGame(MOUSEMSG m);
    void buttonRingth(MOUSEMSG m, MOUSEMSG ms, int win); //判断是否点击右侧工具栏
    void displayWin(int n1, int
                    n2);//显示哪一方赢了,n1为0表示双人为1表示人机，n2为0表示黑、人为1表示白、机
    void PlayGame(MOUSEMSG ms);
    int Win();
};
