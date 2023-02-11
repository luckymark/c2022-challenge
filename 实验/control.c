#include "gobang.h"
#define _CRT_SECURE_NO_WARNINGS
int num = 0;
int gameover = 0;
int id = 1;
Point lp;
int step = 0;
int Cancel = 0;

void Player(void)
{
    step = 0;
    MOUSEMSG Mouse;
    Point p = { -1,-1 };
be:    while (1)
    {
        MOUSEMSG GetMouseMsg();
        Mouse = GetMouseMsg();
        if (Mouse.uMsg == WM_LBUTTONDOWN)
        {
            if (regret(lp, Mouse.x, Mouse.y) == 1) {
                reinit();
                goto be;
            }
            for (int a = 0; a < 16; a++)
            {
                for (int b = 0; b < 16; b++)
                {
                    if (abs(Mouse.x - a * 30) < 15 && abs(Mouse.y - b * 30) < 15)
                    {
                        Mouse.x = a * 30;
                        Mouse.y = b * 30;
                        p.x = a, p.y = b;
                        lp = p;
                        if (innerBoard[a][b] == 0) {
                            innerBoard[a][b] = id;
                            displayBoard();
                            step = 1;
                            goto ha;
                        }
                        else
                            MessageBox(NULL, "Please point in the correct place", "WARNINGS", MB_OK);
                    }
                }
            }
        }
    }
ha:       id = opp(id);
    gameover = JudgeFive(p.x, p.y) * id;

}

int regret(Point p,int x, int y) {
    if (x <= 570 && x >= 470 && y >= 200 && y <= 250) {
        innerBoard[lp.x][lp.y] = 0;
        innerBoard[aix][aiy] = 0;
        displayBoard();
        return 1;
    }
    else return 0;
}

void menu()
{
    int m;
    int isai = MessageBox(NULL, "Do you want to play with AI or not?", "Time to decide!", MB_OKCANCEL);
    if (isai == IDCANCEL) m = 1;
    else {
        int isok = MessageBox(NULL, "You first?", "Time to decide!", MB_OKCANCEL);
        if (isok == IDOK) m = 2;
        else m = 3;
    }
    switch (m)
    {
    case 1://pvp
        while (1) {
            Player();
            if (JudgeDisplay()) {
                break;
            }
        }break;
    case 2:
        while (1) {
            Player();
            if (JudgeDisplay()) {
                break;
            }
            Computer();
            if (JudgeDisplay()) {
                break;
            }
        }break;
    case 3:
        while (1) {
            Computer();
            if (JudgeDisplay()) {
                break;
            }
            Player();
            if (JudgeDisplay()) {
                break;
            }
        }break;
    default:
        break;
    }

}

int inSide(struct Point p) {
    if (p.x >= 0 && p.x < SIZEE && p.y >= 0 && p.y < SIZEE)
        return 1;
    else
        return 0;
}

void put(struct Point p, int player) {
    innerBoard[p.x][p.y] = player;
    num++;
}

void unPut(Point p) {
    innerBoard[p.x][p.y] = 0;
    num--;
}

//电脑回合
void Computer(void)
{
    int kill = 0;
    if (num == 0) {
        aix = 7;
        aiy = 7;
    }
    else {
        kill = killSearch();
        if (!kill) {//算杀失败 采取极大极小搜索
            minmax(DEPTH, TOTALMIN, TOTALMAX, id);
        }
    }
    Point p = { aix,aiy };
    put(p, id);
    gameover = JudgeFive(aix, aiy) * id;
    displayBoard();
    id = opp(id);
    step = 0;
}

int opp(int player) {
    return (player == 1) ? 2 : 1;
}

int JudgeFive(int x, int y)
{
    int i, j, k;
    const int direction[4][2] = { {1,0},{0,1},{1,1},{1,-1} };
    for (i = 0; i < 4; ++i)
    {
        const int d[2] = { -1,1 };//表示左右两个方向
        int shu = 1;
        for (j = 0; j < 2; ++j) {
            for (k = 1; k <= 4; ++k) {
                int row = x + k * d[j] * direction[i][0];
                int col = y + k * d[j] * direction[i][1];
                if (row >= 0 && row < SIZEE && col >= 0 && col < SIZEE &&
                    innerBoard[x][y] == innerBoard[row][col])
                    shu++;
                else
                    break;
            }
        }
        if (shu >= 5)
            return 1;
    }
    return 0;
}

int JudgeDisplay(void)
{
    if (num == SIZEE * SIZEE)
    {
        MessageBox(NULL, "平局！", "GAMEOVER", MB_OK);
        return 1;
    }
    if (gameover == 1)
    {
        MessageBox(NULL, "黑棋获胜！", "GAMEOVER", MB_OK);
        return 1;
    }
    if (gameover == 2)
    {
        MessageBox(NULL, "白棋获胜！", "GAMEOVER", MB_OK);
        return 1;
    }
    return 0;
}
