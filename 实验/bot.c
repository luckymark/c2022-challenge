#include "gobang.h"
#define _CRT_SECURE_NO_WARNINGS
int aix, aiy;
Point p;

//判断点是否有邻居
int hasNeighbor(Point p) {
    if (num == 1 || num == 2) {//开局第二第三个子只找黑子九宫格
        for (int i = 0; i < 4; i++) {//4个方向
            for (int j = -1; j <= 1; j++) {
                if (j != 0) {
                    Point np = nextPoint(p, i, j);
                    if (inSide(np) && innerBoard[np.x][np.y] == 1)
                        return 1;
                }
            }
        }
    }
    else {//之后找棋盘上有落子点2个距离内
        for (int i = 0; i < 4; i++) {
            for (int j = -2; j <= 2; j++) {
                if (j != 0) {
                    Point np = nextPoint(p, i, j);
                    if (inSide(np) && innerBoard[np.x][np.y] != 0)
                        return 1;
                }
            }
        }
    }
    return 0;
}

//极大极小搜索顶层入口
LL minmax(int depth, LL alpha, LL beta, int player) {
    Move moves[224];
    int length = inspireFind(moves, player);//搜索可落子点

    for (int i = 0; i < length; i++) {
        put(moves[i].p, player);//模拟落子
        LL tep = -alphaBeta(depth - 1, -beta, -alpha, opp(player), moves[i].p);//递归
        unPut(moves[i].p);//还原落子
        if (tep >= beta) {
            return beta;
        }
        if (tep > alpha) {
            alpha = tep;
            aix = moves[i].p.x;
            aiy = moves[i].p.y;
        }
    }
    return alpha;
}

//负极大极小值搜索 是一种综合了双方的简练写法
LL alphaBeta(int depth, LL alpha, LL beta, int player, Point p) {
    if (JudgeFive(p.x, p.y))
        return wholeScore(player);
    if (depth == 0 || num == SIZEE * SIZEE) {
        return wholeScore(player);
    }
    Move moves[224];
    int length = inspireFind(moves, player);

    for (int i = 0; i < length; i++) {
        put(moves[i].p, player);
        LL tep = -alphaBeta(depth - 1, -beta, -alpha, opp(player), moves[i].p);//取负值,交换alpha和beta
        unPut(moves[i].p);
        if (tep >= beta) {
            return beta;
        }
        if (tep > alpha) {
            alpha = tep;
        }
    }
    return alpha;
}

//启发式搜索
int inspireFind(Move* scoreBoard, int player) {
    int length = 0;
    for (int i = 0; i < SIZEE; i++) {
        for (int j = 0; j < SIZEE; j++) {
            if (innerBoard[i][j] == 0) {
                Point p = { i, j };
                if (hasNeighbor(p)) {
                    scoreBoard[length].score = singleScore(p, player);//我方适合进攻的点
                    scoreBoard[length++].p = p;
                }
            }
        }
    }
    shellSort(scoreBoard, length);
    return length;
}


void shellSort(Move* s, int len) {
    int i, j, gap;
    Move tep;
    for (gap = len / 2; gap > 0; gap /= 2) {
        for (i = gap; i < len; i += 1) {
            for (j = i - gap; j >= 0 && s[j].score < s[j + gap].score; j -= gap) {
                tep = s[j + gap];
                s[j + gap] = s[j];
                s[j] = tep;
            }
        }
    }
}

//算杀采取双方分开的写法 因此每个函数都有一个对称函数
int killSearch(void) {
    int depth = KILLDEPTH;
    Move kill[100];
    int length = findComKill(kill);
    if (length == 0)//没有找到杀点
        return 0;
    if (length > 9)//在杀点较多时减少深度
        depth = 8;
    for (int i = 0; i < length; i++) {
        put(kill[i].p, id);//模拟落子
        int killed = minKill(depth - 1, kill[i].p);//进入玩家极小层
        unPut(kill[i].p);//还原落子
        if (killed) {
            aix = kill[i].p.x;
            aiy = kill[i].p.y;
            return 1;
        }
    }
    return 0;
}

//极大算杀，电脑层
int maxKill(int depth, Point p) {
    if (JudgeFive(p.x, p.y))//玩家落子成五
        return 0;
    if (depth == 0)//到最深仍未杀棋成功
        return 0;

    Move kill[100];
    int length = findComKill(kill);
    if (length == 0)
        return 0;
    for (int i = 0; i < length; i++) {
        put(kill[i].p, id);
        int killed = minKill(depth - 1, kill[i].p);
        unPut(kill[i].p);
        if (killed) {//在下一层杀棋成功
            return 1;
        }
    }
    return 0;
}

//极小算杀，玩家层
int minKill(int depth, Point p) {
    if (JudgeFive(p.x, p.y))//电脑落子成五
        return 1;
    if (depth == 0)
        return 0;

    Move kill[100];
    int length = findHumKill(kill);
    if (length == 0)
        return 0;
    for (int i = 0; i < length; i++) {
        put(kill[i].p, opp(id));
        int killed = maxKill(depth - 1, kill[i].p);
        unPut(kill[i].p);
        if (!killed) {
            return 0;
        }
    }
    return 1;//都无法防住
}

//寻找电脑可落子点
int findComKill(Move* move) {
    int length = 0;
    for (int i = 0; i < SIZEE; i++) {
        for (int j = 0; j < SIZEE; j++) {
            if (innerBoard[i][j] == 0) {
                Point p = { i, j };
                if (hasNeighbor(p)) {
                    int score = singleScore(p, id);
                    if (score > 500000) {//只找杀点
                        move[length].score = score;
                        move[length++].p = p;
                    }
                }
            }
        }
    }
    shellSort(move, length);
    return length;
}

//寻找人类可落子点
int findHumKill(Move* move) {
    int length = 0;
    for (int i = 0; i < SIZEE; i++) {
        for (int j = 0; j < SIZEE; j++) {
            if (innerBoard[i][j] == 0) {
                Point p = { i, j };
                if (hasNeighbor(p)) {
                    int score = singleScore(p, opp(id));//玩家方杀点 进攻
                    if (score > 50000) {
                        move[length].score = score;
                        move[length++].p = p;
                    }
                }
            }
        }
    }
    shellSort(move, length);
    return length;
}
