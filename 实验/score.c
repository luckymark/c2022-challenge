#include "gobang.h"
#define _CRT_SECURE_NO_WARNINGS

//返回p点d方向上相邻dr距离的点
struct Point nextPoint(struct Point p, int d, int dr) {
    const int direction[4][2] = { {1,0},{0,1},{1,1},{1,-1} };
    struct Point np;
    np.x = p.x + dr * direction[d][0];
    np.y = p.y + dr * direction[d][1];
    return np;
}

//获取p点d方向延伸的信息
void getBoundary(struct Point p, int d, int* s, int way, int player) {
    for (int i = 0; i < 4; i++)
    {
        struct Point np = nextPoint(p, d, way * i);
        if (inSide(np))//在棋盘内
            s[i] = innerBoard[np.x][np.y];
        else //遇到边界 视为对方子
            s[i] = opp(player);
    }
}

int singleScore(struct Point p, int player) {
    int score = 0;
    Type type = getType(p, player);

    if (num < 25) {//前几步少冲4，多走3
        score += (type.alive4 * 300000 + type.sleepy4 * 10000 + type.dead4 * 100
            + type.alive3 * 50000 + type.sleepy3 * 100 + type.dead3 * 50
            + type.alive2 * 500 + type.sleepy2 * 50 + type.dead2 * 5
            + type.alive1 * 10 + type.sleepy1 * 5 + type.dead1 * 1);
    }
    else {
        score += (type.alive4 * 500000 + type.sleepy4 * 30000 + type.dead4 * 100
            + type.alive3 * 50000 + type.sleepy3 * 100 + type.dead3 * 50
            + type.alive2 * 500 + type.sleepy2 * 50 + type.dead2 * 5
            + type.alive1 * 10 + type.sleepy1 * 5 + type.dead1 * 1);
    }
    if (type.more >= 1 || type.win5 >= 1)
        score += 20000000;
    if (type.alive4 >= 1 || type.sleepy4 >= 2 || (type.sleepy4 >= 1 && type.alive3 >= 1) || type.alive3 >= 2)//必胜
        score += 1000000;
    return score;
}

int singleScoreOppo(struct Point p, int player) {
    int score = 0;
    Type type = getType(p, player);

    if (num < 25) {
        score += (type.alive4 * 300000 + type.sleepy4 * 3000 + type.dead4 * 100
            + type.alive3 * 20000 + type.sleepy3 * 1000 + type.dead3 * 50
            + type.alive2 * 500 + type.sleepy2 * 50 + type.dead2 * 5
            + type.alive1 * 10 + type.sleepy1 * 5 + type.dead1 * 1);
    }
    else {
        score += (type.alive4 * 300000 + type.sleepy4 * 3000 + type.dead4 * 100
            + type.alive3 * 20000 + type.sleepy3 * 1000 + type.dead3 * 50
            + type.alive2 * 500 + type.sleepy2 * 50 + type.dead2 * 5
            + type.alive1 * 10 + type.sleepy1 * 5 + type.dead1 * 1);
    }
    if (type.more >= 1 || type.win5 >= 1)
        score += 20000000;
    if (type.alive4 >= 1 || type.sleepy4 >= 2 || (type.sleepy4 >= 1 && type.alive3 >= 1) || type.alive3 >= 2)//必胜
        score += 1000000;
    return score;
}

//棋盘整体局面分
LL wholeScore(int player) {
    int oppo = opp(player);
    LL ownScore = 0, oppoScore = 0;
    for (int i = 0; i < SIZEE; i++) {
        for (int j = 0; j < SIZEE; j++) {
            struct Point p = { i,j };
            if (innerBoard[i][j] == player)
                ownScore += singleScore(p, player);
            else if (innerBoard[i][j] == oppo)
                oppoScore += singleScoreOppo(p, oppo);
        }
    }
    return ownScore - oppoScore;
}

//获取p点连子的长度和两边延伸4子的信息
int Length(Point p, int d, int* left, int* right, int player)
{
    int i;
    int shu = 1;
    for (i = 1; ; i++) {
        Point np = nextPoint(p, d, -i);
        if (inSide(np) && player == innerBoard[np.x][np.y])
            shu++;
        else {
            getBoundary(np, d, left, -1, player);
            break;
        }
    }
    for (i = 1; ; i++) {
        Point np = nextPoint(p, d, i);
        if (inSide(np) && player == innerBoard[np.x][np.y])
            shu++;
        else {
            getBoundary(np, d, right, 1, player);
            break;
        }
    }
    return shu;
}

//获取p点周围的棋型
Type getType(struct Point p, int player) {
    Type tep = { 0 };
    for (int i = 0; i < 4; i++) {
        Type type[4];
        int length, left[4], right[4];
        length = Length(p, i, left, right, player);
        type[i] = typeAnalysis(length, left, right, player);
        tep.more += type[i].more;
        tep.win5 += type[i].win5;
        tep.alive4 += type[i].alive4;
        tep.sleepy4 += type[i].sleepy4;
        tep.dead4 += type[i].dead4;
        tep.alive3 += type[i].alive3;
        tep.sleepy3 += type[i].sleepy3;
        tep.dead3 += type[i].dead3;
        tep.alive2 += type[i].alive2;
        tep.sleepy2 += type[i].sleepy2;
        tep.dead2 += type[i].dead2;
        tep.alive1 += type[i].alive1;
        tep.sleepy1 += type[i].sleepy1;
        tep.dead1 += type[i].dead1;
    }
    return tep;
}

Type typeAnalysis(int length, int* left, int* right, int player)
{
    Type tep = { 0 };
    if (length > 5)
        tep.more++;
    else if (length == 5)
        tep.win5++;

    else if (length == 4)
    {
        if (left[0] == 0 && right[0] == 0)
            tep.alive4++;
        else if (left[0] == 0 || right[0] == 0)
            tep.sleepy4++;
        else
            tep.dead4++;
    }

    else if (length == 3)
    {
        if ((left[0] == 0 && left[1] == player) && (right[0] == 0 && right[1] == player))
            tep.sleepy4 += 2;
        else if ((left[0] == 0 && left[1] == player) || (right[0] == 0 && right[1] == player))
            tep.sleepy4++;
        else if (left[0] == 0 && right[0] == 0 && (left[1] == 0 || right[1] == 0))
            tep.alive3++;
        else if ((left[0] == 0 && left[1] == 0) || (right[0] == 0 && right[1] == 0))
            tep.sleepy3++;
        else
            tep.dead3++;
    }

    else if (length == 2)
    {
        if ((left[0] == 0 && left[1] == player && left[2] == player) &&
            (right[0] == 0 && right[1] == player && right[2] == player))
            tep.sleepy4 += 2;
        else if ((left[0] == 0 && left[1] == player && left[2] == player) ||
            (right[0] == 0 && right[1] == player && right[2] == player))
            tep.sleepy4++;
        else if (left[0] == 0 && right[0] == 0 &&
            ((left[1] == player && left[2] == 0) ||
                (right[1] == player && right[2] == 0)))
            tep.alive3++;
        else if ((left[0] == 0 && left[2] == 0 && left[1] == player) ||
            (right[0] == 0 && right[2] == 0 && right[1] == player))
            tep.sleepy3++;
        else if ((left[0] == 0 && right[0] == 0) &&
            (left[1] == player || right[1] == player))
            tep.sleepy3++;
        else if ((left[0] == 0 && left[1] == 0 && left[2] == player) ||
            (right[0] == 0 && right[1] == 0 && right[2] == player))
            tep.sleepy3++;
        else if ((left[0] == 0 && right[0] == 0 && right[1] == 0 && right[2] == 0) ||
            (left[0] == 0 && left[1] == 0 && right[0] == 0 && right[1] == 0) ||
            (left[0] == 0 && left[1] == 0 && left[2] == 0 && right[0] == 0))
            tep.alive2++;
        else if ((left[0] == 0 && left[1] == 0 && left[2] == 0) ||
            (right[0] == 0 && right[1] == 0 && right[2] == 0))
            tep.sleepy2++;
    }

    else if (length == 1) {
        if ((left[0] == 0 && left[1] == player && left[2] == player && left[3] == player) &&
            (right[0] == 0 && right[1] == player && right[2] == player && right[3] == player))
            tep.sleepy4 += 2;
        else if ((left[0] == 0 && left[1] == player && left[2] == player && left[3] == player) ||
            (right[0] == 0 && right[1] == player && right[2] == player && right[3] == player))
            tep.sleepy4++;
        else if ((left[0] == 0 && right[0] == 0) && ((left[1] == player && left[2] == player && left[3] == 0) ||
            (right[1] == player && right[2] == player && right[3] == 0)))
            tep.alive3++;
        else if ((left[0] == 0 && right[0] == 0) &&
            ((left[1] == player && left[2] == player) || (right[1] == player && right[2] == player)))
            tep.sleepy3++;
        else if ((left[0] == 0 && left[3] == 0 && left[1] == player && left[2] == player) ||
            (right[0] == 0 && right[3] == 0 && right[1] == player && right[2] == player))
            tep.sleepy3++;
        else if ((left[0] == 0 && left[1] == 0 && left[2] == player && left[3] == player) ||
            (right[0] == 0 && right[1] == 0 && right[2] == player && right[3] == player))
            tep.sleepy3++;
        else if ((left[0] == 0 && left[2] == 0 && left[1] == player && left[3] == player) ||
            (right[0] == 0 && right[2] == 0 && right[1] == player && right[3] == player))
            tep.sleepy3++;
        else if ((left[0] == 0 && right[0] == 0 && right[2] == 0 && right[1] == player)
            && (left[1] == 0 || right[3] == 0))
            tep.alive2++;
        else if ((right[0] == 0 && left[0] == 0 && left[2] == 0 && left[1] == player) &&
            (right[1] == 0 || left[3] == 0))
            tep.alive2++;
        else if ((left[0] == 0 && right[0] == 0 && right[1] == 0 && right[3] == 0 && right[2] == player) ||
            (right[0] == 0 && left[0] == 0 && left[1] == 0 && left[3] == 0 && left[2] == player))
            tep.alive2++;
        else if ((left[0] == 0 && left[2] == 0 && left[3] == 0 && left[1] == player) ||
            (right[0] == 0 && right[2] == 0 && right[3] == 0 && right[1] == player))
            tep.sleepy2++;
        else if ((left[0] == 0 && right[0] == 0 && right[1] == 0 && left[1] == player) ||
            (right[0] == 0 && left[0] == 0 && left[1] == 0 && right[1] == player))
            tep.sleepy2++;
        else if ((left[0] == 0 && left[1] == 0 && left[3] == 0 && left[2] == player) ||
            (right[0] == 0 && right[1] == 0 && right[3] == 0 && right[2] == player))
            tep.sleepy2++;
        else if ((left[0] == 0 && left[1] == 0 && right[0] == 0 && left[2] == player) ||
            (right[0] == 0 && right[1] == 0 && left[0] == 0 && right[2] == player))
            tep.sleepy2++;
        else if ((left[0] == 0 && left[1] == 0 && left[2] == 0 && left[3] == player) ||
            (right[0] == 0 && right[1] == 0 && right[2] == 0 && right[3] == player))
            tep.sleepy2++;
        else if (left[0] == 0 && right[0] == 0)
            tep.alive1++;
        else if (left[0] == 0 || right[0] == 0)
            tep.sleepy1++;
        else
            tep.dead1++;
    }
    return tep;
}
