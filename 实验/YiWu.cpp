#define _CRT_SECURE_NO_WARNINGS 1
#include "YiWu.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <map>
using namespace std;

typedef unsigned long long ULL;

FILE *printer = fopen("trail.txt", "w");

int a[16][16] = {0};

ULL cur;

const int INF = 1e9;

//0空地，1玩家落子，2电脑落子


//1:BLACK 2:WHITE

ULL seed1[16][16], seed2[16][16];
void Zobrist(void) {
    srand(time(0));

    for (int i = 0; i < 16; ++i)
        for (int j = 0; j < 16; ++j) {
            seed1[i][j] = 1LL * rand() * rand() * rand() * rand();
            seed2[i][j] = 1LL * rand() * rand() * rand() * rand();
        }
}

void place1(int col, int hang, int lie) {
    if (col == 1)
        setfillcolor(BLACK);
    else
        setfillcolor(WHITE);

    solidcircle(lie, hang, 12);
    a[hang / 30][lie / 30] = col;
    cur ^= seed1[hang / 30][lie / 30];
}

void place2(int col, int x, int y) {
    setfillcolor(WHITE);
    a[x][y] = col;
    cur ^= seed2[x][y];
    solidcircle(20 + y * 30, 20 + x * 30, 12);
}

/*
    对棋局进行评分，分数=AI得分-玩家得分
成五，100000000
活四, 10000
活三，1000
活二，100
活一，10

死四,1000
死三，100
死二，10
*/

const int live[5] = {0, 10, 100, 1000, 10000};
const int dead[5] = {0, 1, 10, 100, 1000};
const int rush[6] = {0, 0, 5, 50, 500, 10000};
int calc(vector <int> v, int col) {
    v.push_back(0);

    for (int i = v.size() - 1; i > 0; --i)
        v[i] = v[i - 1];

    v[0] = 3 - col;
    v.push_back(3 - col);
    int lst = 0, ret = 0;

    for (int i = 1; i < v.size(); ++i) {
        if (v[i] != col) {
            int num = i - 1 - lst;

            if (num == 5)
                ret += 100000000;

            if (!v[lst] && !v[i])
                ret += live[num];
            else if (!v[lst] || !v[i])
                ret += dead[num];

            lst = i;
        } else if (v[i] == 0 && v[i - 1] == col && v[i + 1] == col) {
            int L;

            for (L = i - 1; L > 0 && v[L] == col; --L);

            int R;

            for (R = i + 1; R < v.size() && v[R] == col; ++R);

            ret += rush[min(i - 1 - L + R - i - 1, 5)];
        }
    }

    return ret;
}

int evaluate(void) {
    int ret = 0;
    vector <int> v;

    for (int i = 0; i < 16; ++i) {
        v.clear();

        for (int j = 0; j < 16; ++j)
            v.push_back(a[i][j]);

        ret += calc(v, 2) - calc(v, 1);
    }

    for (int j = 0; j < 16; ++j) {
        v.clear();

        for (int i = 0; i < 16; ++i)
            v.push_back(a[i][j]);

        ret += calc(v, 2) - calc(v, 1);
    }

    for (int i = 0; i < 16; ++i) {
        v.clear();

        for (int x = i, y = 0; x < 16 && y < 16; ++x, ++y)
            v.push_back(a[x][y]);

        ret += calc(v, 2) - calc(v, 1);
    }

    for (int j = 1; j < 16; ++j) {
        v.clear();

        for (int x = 0, y = j; x < 16 && y < 16; ++x, ++y)
            v.push_back(a[x][y]);

        ret += calc(v, 2) - calc(v, 1);
    }

    for (int i = 0; i < 16; ++i) {
        v.clear();

        for (int x = i, y = 15; x < 16 && y >= 0; ++x, --y)
            v.push_back(a[x][y]);

        ret += calc(v, 2) - calc(v, 1);
    }

    for (int j = 0; j < 15; ++j) {
        v.clear();

        for (int x = 0, y = j; x < 16 && y >= 0; ++x, --y)
            v.push_back(a[x][y]);

        ret += calc(v, 2) - calc(v, 1);
    }

    return ret;
}

int evaluate_point(int x, int y) {
    int ret = 0;
    vector <int> v;
    v.clear();

    for (int i = 0; i < 16; ++i)
        v.push_back(a[x][i]);

    ret += calc(v, 2) - calc(v, 1);
    v.clear();

    for (int i = 0; i < 16; ++i)
        v.push_back(a[i][y]);

    ret += calc(v, 2) - calc(v, 1);
    int stx = x, sty = y;

    while (stx > 0 && sty > 0)
        --stx, --sty;

    v.clear();

    for (; stx < 16 && sty < 16; ++stx, ++sty)
        v.push_back(a[stx][sty]);

    ret += calc(v, 2) - calc(v, 1);
    stx = x, sty = y;

    while (stx > 0 && sty < 15)
        --stx, ++sty;

    v.clear();

    for (; stx < 16 && sty >= 0; ++stx, --sty)
        v.push_back(a[stx][sty]);

    ret += calc(v, 2) - calc(v, 1);
    return ret;
}

struct Data {
    int x, y, val;
};

vector <Data> generate(int dep) {
    vector <Data> v;

    for (int i = 0; i < 16; ++i)
        for (int j = 0; j < 16; ++j) {
            if (a[i][j])
                continue;

            bool flag = 0;

            for (int p = max(0, i - 1); p <= min(15, i + 1) && !flag; ++p)
                for (int q = max(0, j - 1); q <= min(15, j + 1) && !flag; ++q)
                    if (a[p][q])
                        v.push_back({i, j, 0}), flag = 1;

            if (dep < 2 || flag)
                continue;

            for (int p = max(0, i - 2); p <= min(15, i + 2) && !flag; ++p)
                for (int q = max(0, j - 2); q <= min(15, j + 2) && !flag; ++q)
                    if (a[p][q])
                        v.push_back({i, j, 0}), flag = 1;
        }

    return v;
}

bool cmp_min(const Data &A, const Data &B) {
    return A.val < B.val;
}
bool cmp_max(const Data &A, const Data &B) {
    return A.val > B.val;
}

const int MAX_DEEP = 6, CK_DEEP = 12, MAX_DIS = 1;

int nxt_x, nxt_y, cnt;

bool count(int x, int y, int dx, int dy, int num, int col) {
    for (int i = 1; i <= num; ++i) {
        int nx = x + i * dx, ny = y + i * dy;

        if (nx < 0 || nx > 15 || ny < 0 || ny > 15)
            return 0;

        if (a[nx][ny] != col)
            return 0;
    }

    return 1;
}

void defense(void) {
    bool flag = 0;

    for (int i = 0; i < 16 && !flag; ++i)
        for (int j = 0; j < 16 && !flag; ++j) {
            if (a[i][j])
                continue;

            for (int k = 4; k >= 0 && !flag; --k) {
                if (count(i, j, -1, 0, 4, 1) && count(i, j, 1, 0, 4 - k, 1))
                    nxt_x = i, nxt_y = j, flag = 1;

                if (count(i, j, 1, 0, 4, 1) && count(i, j, -1, 0, 4 - k, 1))
                    nxt_x = i, nxt_y = j, flag = 1;

                if (count(i, j, 0, -1, 4, 1) && count(i, j, 0, 1, 4 - k, 1))
                    nxt_x = i, nxt_y = j, flag = 1;

                if (count(i, j, 0, 1, 4, 1) && count(i, j, 0, -1, 4 - k, 1))
                    nxt_x = i, nxt_y = j, flag = 1;

                if (count(i, j, -1, -1, 4, 1) && count(i, j, 1, 1, 4 - k, 1))
                    nxt_x = i, nxt_y = j, flag = 1;

                if (count(i, j, -1, 1, 4, 1) && count(i, j, 1, -1, 4 - k, 1))
                    nxt_x = i, nxt_y = j, flag = 1;

                if (count(i, j, 1, -1, 4, 1) && count(i, j, -1, 1, 4 - k, 1))
                    nxt_x = i, nxt_y = j, flag = 1;

                if (count(i, j, 1, 1, 4, 1) && count(i, j, -1, -1, 4 - k, 1))
                    nxt_x = i, nxt_y = j, flag = 1;
            }
        }
}

int min_search(int dep, int alpha, int beta, ULL sts);
int max_search(int dep, int alpha, int beta, ULL sts);

map <ULL, int> status;

int min_search(int dep, int alpha, int beta, ULL sts) { //col=1
    ++cnt;

    if (dep <= 0) {
        if (status.count(sts))
            return status[sts];

        return status[sts] = evaluate();
    }

    vector <Data> nxt = generate(MAX_DIS);

    for (int i = 0; i < nxt.size(); ++i) {
        int pre = evaluate_point(nxt[i].x, nxt[i].y);
        a[nxt[i].x][nxt[i].y] = 1;
        nxt[i].val = evaluate_point(nxt[i].x, nxt[i].y) - pre;
        a[nxt[i].x][nxt[i].y] = 0;
    }

    sort(nxt.begin(), nxt.end(), cmp_min);
    int best = INF;

    for (auto it : nxt) {
        int x = it.x, y = it.y, val = it.val;
        a[x][y] = 1;
        sts ^= seed1[x][y];
        int cur = max_search(dep - 1, min(best, alpha), beta, sts);
        a[x][y] = 0;
        sts ^= seed1[x][y];

        if (cur < best)
            best = cur;

        if (best < beta)
            break; //alpha-beta cut
    }

    return best;
}
int max_search(int dep, int alpha, int beta, ULL sts) { //col=2
    ++cnt;

    if (dep <= 0) {
        if (status.count(sts))
            return status[sts];

        return status[sts] = evaluate();
    }

    vector <Data> nxt = generate(MAX_DIS);

    for (int i = 0; i < nxt.size(); ++i) {
        int pre = evaluate_point(nxt[i].x, nxt[i].y);
        a[nxt[i].x][nxt[i].y] = 2;
        nxt[i].val = evaluate_point(nxt[i].x, nxt[i].y) - pre;
        a[nxt[i].x][nxt[i].y] = 0;
    }

    sort(nxt.begin(), nxt.end(), cmp_max);
    int best = -INF, tx, ty;

    for (auto it : nxt) {
        int x = it.x, y = it.y, val = it.val;
        a[x][y] = 2;
        sts ^= seed2[x][y];
        int cur = min_search(dep - 1, alpha, max(beta, best), sts);
        a[x][y] = 0;
        sts ^= seed2[x][y];

        if (cur > best)
            best = cur, tx = x, ty = y;

        if (best > alpha)
            break; //alpha-beta cut
    }

    if (dep == MAX_DEEP)
        nxt_x = tx, nxt_y = ty;

    return best;
}

void trail(int x, int y, int col) {
    if (col == 1)
        fprintf(printer, "Play Set: Row %d Col %d\n", x, y);
    else
        fprintf(printer, "AI Set: Row %d Col %d\n", x, y);
}

void Play::PlayGame(MOUSEMSG ms) {
    //玩家走子
    int success = 1;

    while (success) {
        ms = GetMouseMsg();

        for (int lie = 20; lie <= 490; lie += 30) {
            if (ms.x <= lie + 15 && ms.x >= lie - 15) {
                for (int hang = 20; hang <= 490; hang += 30) {
                    if (ms.y <= hang + 15 && ms.y >= hang - 15) {
                        if (a[hang / 30][lie / 30] == 0) {
                            place1(1, hang, lie);
                            success = 0;
                            trail(hang / 30, lie / 30, 1);
                            break;
                        }
                    }
                }
            }
        }
    }

    int win = Play().Win();

    if (win == 1) {
        //黑棋赢
        return;
    }

    //AI走子
    nxt_x = nxt_y = -1;
    defense();

    if (!~nxt_x) {
        if (!~nxt_x) {
            cnt = 0;
            max_search(MAX_DEEP, INF, -INF, cur);
            //printf("Have tried %d status\n", cnt);
        }
    }

    place2(2, nxt_x, nxt_y);
    trail(nxt_x, nxt_y, 2);
    win = Play().Win();

    if (win == 2) {
        //黑棋赢
        return;
    }
}

void Menu::Display() {
    //初始化绘图窗口
    initgraph(416, 624, SHOWCONSOLE);

    /*设置背景图*/
    IMAGE img;
    setaspectratio(1.1, 1);
    //从图片文件获取图像（图像的image指针，图像名，资源名称，图片的拉伸宽度、高度，是否自适应图片大小）
    loadimage(&img, "init.png", 377, 624, 1);
    putimage(0, 0, &img);

    /*控制鼠标移动操作*/
    MOUSEMSG m;//鼠标操作

    while (true) {
        m = GetMouseMsg();//获取鼠标消息

        //左键按下：WM_LBUTTONDOWN
        if (m.uMsg == WM_LBUTTONDOWN && (m.x >= 72 && m.x <= 307 && m.y >= 340 && m.y <= 400
                                         || m.x >= 72 && m.x <= 307 && m.y >= 420 && m.y <= 480)) {
            //uMsg鼠标信息  WM_MOUSEMOVE鼠标移动消息  x y表示鼠标位置坐标
            if (m.x >= 72 && m.x <= 307 && m.y >= 340 && m.y <= 400) {
                setlinecolor(YELLOW);
                setlinestyle(PS_SOLID | PS_JOIN_ROUND, 2);
                //空心矩形框
                rectangle(72, 340, 300, 400);
            } else if (m.x >= 72 && m.x <= 307 && m.y >= 420 && m.y <= 480) {
                setlinecolor(YELLOW);
                //空心矩形框
                rectangle(72, 420, 300, 480);
            }

            Sleep(500);
            //清除屏幕内容
            cleardevice();
            //休眠五秒
            Sleep(300);
            //关闭窗口
            closegraph();
            Menu().ChessBoard(m);
            break;
        }
    }
}

void Menu::ChessBoard(MOUSEMSG m) {
    //初始化绘图窗口
    initgraph(665, 490, SHOWCONSOLE);

    /*设置棋盘背景背景图*/
    IMAGE img;
    //缩放因子，例如设置宽度为100的单元格，实际的绘制宽度为（100*缩放因子）
    //setaspectratio(1.1, 1);
    //从图片文件获取图像（图像的image指针，图像名，资源名称，图片的拉伸宽度、高度，是否自适应图片大小）
    loadimage(&img, "chessborad.png", 665, 490);
    putimage(0, 0, &img);

    //绘制棋盘
    while (true) {
        for (int i = 20; i <= 470; i += 30) {
            setlinecolor(WHITE);
            line(20, i, 470, i);
            line(i, 20, i, 470);
        }

        //如果左键双人，跳入双人游戏
        if (m.uMsg == WM_LBUTTONDOWN && m.x >= 72 && m.x <= 307 && m.y >= 420 && m.y <= 480) {
            Play().TwoPlayerGame(m);
        } else {
            Play().ComputerUserGame(m);
        }
    }
}

void Play::buttonRingth(MOUSEMSG m, MOUSEMSG ms, int win) {
    if (ms.x >= 500 && ms.x <= 655 && ms.y >= 30 && ms.y <= 80) {
        memset(a, 0, sizeof(a));
        //重新开始
        setlinecolor(RED);
        //空心矩形框
        rectangle(500, 30, 655, 80);
        Sleep(300);
        Menu().ChessBoard(m);
    } else if (ms.x >= 500 && ms.x <= 655 && ms.y >= 115 && ms.y <= 165) {
        memset(a, 0, sizeof(a));
        //返回菜单
        setlinecolor(RED);
        //空心矩形框
        rectangle(500, 115, 655, 165);
        Sleep(300);
        Menu().Display();
    } else if (win == 0 && ms.x >= 500 && ms.x <= 655 && ms.y >= 200 && ms.y <= 250) {
        //悔棋
        setlinecolor(RED);
        //空心矩形框
        rectangle(500, 200, 655, 250);
    }
}
void Play::displayWin(int n1, int n2) {
    memset(a, 0, sizeof(a));
    //显示哪一方赢了,n1为0表示双人为1表示人机，n2为0表示黑、人为1表示白、机
    IMAGE img;

    // 读取图片至绘图窗口
    if (n1 == 0 && n2 == 0)
        loadimage(&img, "victory.jpg", 700, 600);

    if (n1 == 0 && n2 == 1)
        loadimage(&img, "defeat.jpg", 700, 600);

    if (n1 == 1 && n2 == 0)
        loadimage(&img, "victory.jpg", 700, 600);

    if (n1 == 1 && n2 == 1)
        loadimage(&img, "defeat.jpg", 700, 600);

    putimage(0, 0, &img);

    MOUSEMSG m;//鼠标操作

    while (1) {
        m = GetMouseMsg();

        if (m.uMsg == WM_LBUTTONDOWN && m.x >= 215 && m.x <= 270 && m.y >= 285 && m.y <= 320) {
            setlinecolor(YELLOW);
            //空心矩形框
            rectangle(215, 285, 270, 320);
            Sleep(300);
            Menu().Display();
            break;
        } else if (m.uMsg == WM_LBUTTONDOWN)
            exit(0);
    }
}

void Play::TwoPlayerGame(MOUSEMSG m) {
    int win = 0;
    int play1 = 1, play2 = 0;
    MOUSEMSG ms;

    //一直获取鼠标信息，判断操做
    while (win == 0) {
        //判断是否点击右侧工具栏或者棋盘
        ms = GetMouseMsg();

        if (ms.uMsg == WM_LBUTTONDOWN) {
            //判断是否点击右侧工具栏
            buttonRingth(m, ms, win);

            //判断是否点击棋盘
            for (int lie = 20; lie <= 490; lie += 30) {
                if (ms.x <= lie + 15 && ms.x >= lie - 15) {
                    for (int hang = 20; hang <= 490; hang += 30) {
                        if (ms.y <= hang + 15 && ms.y >= hang - 15) {
                            if (play1 == 1 && a[hang / 30 - 1][lie / 30 - 1] == 0) {
                                place1(1, hang, lie);
                                play1 = 0;
                                break;
                            }

                            if (play1 == 0 && a[hang / 30 - 1][lie / 30 - 1] == 0) {

                                place1(2, hang, lie);
                                play1 = 1;
                                break;
                            }
                        }
                    }
                }
            }

            //判断玩家是否赢
            //DEBUG
            /*printf("%d\n",evaluate());
            if (play1==1)
            {
                vector <pair<int,int>> nxt=generate(2);
                for (auto it:nxt)
                {
                    printf("%d %d %d\n",it.x,it.y,it.val);
                }
            }*/
            win = Play().Win();

            if (win == 1) {
                //黑棋赢
                displayWin(0, 0);
                break;
            } else if (win == 2) {
                //白棋赢
                displayWin(0, 1);
                break;
            }
        }
    }
}

void Play::ComputerUserGame(MOUSEMSG m) {
    int win = 0;

    Zobrist();

    MOUSEMSG ms;

    //一直获取鼠标信息，判断操做
    while (win == 0) {
        //判断是否点击右侧工具栏或者棋盘
        ms = GetMouseMsg();

        if (ms.uMsg == WM_LBUTTONDOWN) {
            //判断是否点击右侧工具栏
            buttonRingth(m, ms, win);
            //判断是否点击棋盘并且判断是否该玩家落子
            Play::PlayGame(ms);
            //判断玩家是否赢
            win = Play().Win();

            if (win == 1) {
                //人赢
                displayWin(1, 0);
                break;
            } else if (win == 2) {
                //电脑赢
                displayWin(1, 1);
                break;
            }
        }
    }
}



int Play::Win() {
    int win = 0;

    //判断是否赢
    for (int j = 0; j < 16 && (win == 0); j++) {
        for (int i = 0; i < 16; i++) {

            if ((a[j][i] == 1 && a[j][i + 1] == 1 && a[j][i + 2] == 1 && a[j][i + 3] == 1 && a[j][i + 4] == 1)
                    || (a[i][j] == 1 && a[i + 1][j] == 1 && a[i + 2][j] == 1 && a[i + 3][j] == 1 &&
                        a[i + 4][j] == 1)) { //横纵是5个子play1 win
                win = 1;
                Sleep(100);
                break;
            }

            if ((a[j][i] == 2 && a[j][i + 1] == 2 && a[j][i + 2] == 2 && a[j][i + 3] == 2 && a[j][i + 4] == 2)
                    || (a[i][j] == 2 && a[i + 1][j] == 2 && a[i + 2][j] == 2 && a[i + 3][j] == 2 &&
                        a[i + 4][j] == 2)) { //横纵是5个子play2 win
                win = 2;
                Sleep(100);
                break;
            }
        }
    }

    for (int j = 0; j < 12 && (win == 0); j++) {
        for (int i = 0; i < 12; i++) {
            if (a[j][i] == 1 && a[j + 1][i + 1] == 1 && a[j + 2][i + 2] == 1 && a[j + 3][i + 3] == 1 &&
                    a[j + 4][i + 4] == 1) { //向右倾斜时候play1 win
                win = 1;
                Sleep(100);
                break;

            }

            if (a[j][i] == 2 && a[j + 1][i + 1] == 2 && a[j + 2][i + 2] == 2 && a[j + 3][i + 3] == 2 &&
                    a[j + 4][i + 4] == 2) { //向右倾斜时候play2 win
                win = 2;
                Sleep(100);
                break;
            }
        }

        for (int i = 4; i < 16 && (win == 0); i++) {
            if (a[j][i] == 1 && a[j + 1][i - 1] == 1 && a[j + 2][i - 2] == 1 && a[j + 3][i - 3] == 1 &&
                    a[j + 4][i - 4] == 1) { //向左倾斜时候play1 win
                win = 1;
                Sleep(100);
                break;
            }

            if (a[j][i] == 2 && a[j + 1][i - 1] == 2 && a[j + 2][i - 2] == 2 && a[j + 3][i - 3] == 2 &&
                    a[j + 4][i - 4] == 2) { //向左倾斜时候play2 win
                win = 2;
                Sleep(100);
                break;
            }
        }
    }

    return win;
}