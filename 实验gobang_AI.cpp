#include"minmax.h"

//flex4 needs 6 point
int type[4][4][4][4][4][4];//0 '_',1 '0',2 'X',3 '#'

int Board[17][17] = { 0 };

Points best_points;
Decision decision;

int sample[4][17];//统计4个方向上每种棋型的个数
int isEmpty[16][16];
int worth[16][16];

int ifWin(void) {
    int flag = 0, i = 1, j = 1;
    for (i=1; i <= 15; ++i) {
        for (j=1; j <= 15; ++j) {
            if (Board[i][j] == 1) { ++flag; }
            else { flag = 0; }
            if (flag == 5)
            { return 1; }
        }
    }
    for (i=1; i <= 15; ++i) {
        for (j=1; j <= 15; ++j) {
            if (Board[i][j] == 2) { ++flag; }
            else { flag = 0; }
            if (flag == 5)
            { return 2; }
        }
    }
    for (i=1; i <= 15; ++i) {
        for (j=1; j <= 15; ++j) {
            if (Board[j][i] == 1) { ++flag; }
            else { flag = 0; }
            if (flag == 5)
            { return 1; }
        }
    }
    for (i=1; i <= 15; ++i) {
        for (j=1; j <= 15; ++j) {
            if (Board[j][i] == 2) { ++flag; }
            else { flag = 0; }
            if (flag == 5) 
            { return 2; }
        }
    }
    for (int a = 11; a >= 1; --a) {
        i = a; j = 15;
        while (i <= 15 && j >= 1) {
            if (Board[i][j] == 1) { ++flag; }
            else { flag = 0; }
            ++i; --j;//
            if (flag == 5)
            { return 1; }
        }
    }
    for (int b = 14; b >= 5; --b) {
        i = 1; 
        j = b;
        while (i <= 15 && j >= 1) {
            if (Board[i][j] == 1) { ++flag; }
            else { flag = 0; }
            ++i; --j;//
            if (flag == 5)
            { return 1; }
        }
    }

    for (int a = 11; a >= 1; --a) {
        i = a; j = 15;
        while (i <= 15 && j >= 1) {
            if (Board[i][j] == 2) { ++flag; }
            else { flag = 0; }
            ++i; --j;//
            if (flag == 5)
            { return 2; }
        }
    }
    for (int b = 14; b >= 5; --b) {
        i = 1;
        j = b;
        while (i <= 15 && j >= 1) {
            if (Board[i][j] == 2) { ++flag; }
            else { flag = 0; }
            ++i; --j;//
            if (flag == 5)
            { return 2; }
        }
    }

    for (int a = 11; a >= 1; --a) {
        i = a;
        j = 1;
        while (i <= 15 && j <= 15) {
            if (Board[i][j] == 1) { ++flag; }
            else { flag = 0; }
            ++i; ++j;//
            if (flag == 5) 
            { return 1; }
        }
    }
    for (int b = 2; b <= 11; ++b) {
        i = 1; 
        j = b;
        while (i <= 15 && j <= 15) {
            if (Board[i][j] == 1) { ++flag; }
            else { flag = 0; }
            ++i; ++j;
            if (flag == 5) 
            { return 1; }
        }
    }

    for (int a = 11; a >= 1; --a) {
        i = a;
        j = 1;
        while (i <= 15 && j <= 15) {
            if (Board[i][j] == 2) { ++flag; }
            else { flag = 0; }
            ++i; ++j;//
            if (flag == 5)
            { return 2; }
        }
    }
    for (int b = 2; b <= 11; ++b) {
        i = 1;
        j = b;
        while (i <= 15 && j <= 15) {
            if (Board[i][j] == 2) { ++flag; }
            else { flag = 0; }
            ++i; ++j;
            if (flag == 5)
            { return 2; }
        }
    }
    return 0;
}
void init6type(void) {
    for (int i = 0; i <= 16; ++i) { Board[i][0] = 3; Board[i][16] = 3;}
    for (int i = 1; i <= 15; ++i) { Board[0][i] = 3; Board[16][i] = 3;}
    memset(type, 0, sizeof(type));

    type[2][2][2][2][2][2] = WIN;
    type[2][2][2][2][2][0] = WIN;
    type[0][2][2][2][2][2] = WIN;
    type[2][2][2][2][2][1] = WIN;
    type[1][2][2][2][2][2] = WIN;
    type[3][2][2][2][2][2] = WIN;
    type[2][2][2][2][2][3] = WIN;

    type[1][1][1][1][1][1] = LOSE;
    type[1][1][1][1][1][0] = LOSE;
    type[0][1][1][1][1][1] = LOSE;
    type[1][1][1][1][1][2] = LOSE;
    type[2][1][1][1][1][1] = LOSE;
    type[3][1][1][1][1][1] = LOSE;
    type[1][1][1][1][1][3] = LOSE;

    type[0][2][2][2][2][0] = FLEX4;

    type[0][1][1][1][1][0] = flex4;

    type[0][2][2][2][0][0] = FLEX3;
    type[0][0][2][2][2][0] = FLEX3;
    type[0][2][0][2][2][0] = FLEX3;
    type[0][2][2][0][2][0] = FLEX3;

    type[0][1][1][1][0][0] = flex3;
    type[0][0][1][1][1][0] = flex3;
    type[0][1][0][1][1][0] = flex3;
    type[0][1][1][0][1][0] = flex3;

    type[0][2][2][0][0][0] = FLEX2;
    type[0][2][0][2][0][0] = FLEX2;
    type[0][2][0][0][2][0] = FLEX2;
    type[0][0][2][2][0][0] = FLEX2;
    type[0][0][2][0][2][0] = FLEX2;
    type[0][0][0][2][2][0] = FLEX2;

    type[0][1][1][0][0][0] = flex2;
    type[0][1][0][1][0][0] = flex2;
    type[0][1][0][0][1][0] = flex2;
    type[0][0][1][1][0][0] = flex2;
    type[0][0][1][0][1][0] = flex2;
    type[0][0][0][1][1][0] = flex2;

    type[0][2][0][0][0][0] = FLEX1;
    type[0][0][2][0][0][0] = FLEX1;
    type[0][0][0][2][0][0] = FLEX1;
    type[0][0][0][0][2][0] = FLEX1;

    type[0][1][0][0][0][0] = flex1;
    type[0][0][1][0][0][0] = flex1;
    type[0][0][0][1][0][0] = flex1;
    type[0][0][0][0][1][0] = flex1;

    int p1, p2, p3, p4, p5, p6, x, y, ix, iy;//x:左5中'0'个数,y:左5中'X'个数,ix:右5中'0'个数,iy:右5中'X'个数
    for (p1 = 0; p1 <= 3; ++p1) {
        for (p2 = 0; p2 <= 2; ++p2) {
            for (p3 = 0; p3 <= 2; ++p3) {
                for (p4 = 0; p4 <= 2; ++p4) {
                    for (p5 = 0; p5 <= 2; ++p5) {
                        for (p6 = 0; p6 <= 3; ++p6) {
                            x = y = ix = iy = 0;

                            if (p1 == 1) { ++x; }
                            else if (p1 == 2) { ++y; }

                            if (p2 == 1) { ++x; ++ix; }
                            else if (p2 == 2) { ++y; ++iy; }

                            if (p3 == 1) { ++x; ++ix; }
                            else if (p3 == 2) { ++y; ++iy; }

                            if (p4 == 1) { ++x; ++ix; }
                            else if (p4 == 2) { ++y; ++iy; }

                            if (p5 == 1) { ++x; ++ix; }
                            else if (p5 == 2) { ++y; ++iy; }

                            if (p6 == 1) { ++ix; }
                            else if (p6 == 2) { ++iy; }

                           
                            if ((p1 == 3 && p6 != 3) || (p1 != 3 && p6 == 3)) {//有边界  

                                    if (ix == 0 && iy == 4) {
                                        if (type[p1][p2][p3][p4][p5][p6] == 0)
                                        {
                                            type[p1][p2][p3][p4][p5][p6] = BLOCK4;
                                        }
                                    }

                                    if (ix == 4 && iy == 0) {
                                        if (type[p1][p2][p3][p4][p5][p6] == 0)
                                        {
                                            type[p1][p2][p3][p4][p5][p6] = block4;
                                        }
                                    }

                                    if (ix == 0 && iy == 3) {
                                        if (type[p1][p2][p3][p4][p5][p6] == 0)
                                        {
                                            type[p1][p2][p3][p4][p5][p6] = BLOCK3;
                                        }
                                    }

                                    if (ix == 3 && iy == 0) {
                                        if (type[p1][p2][p3][p4][p5][p6] == 0)
                                        {
                                            type[p1][p2][p3][p4][p5][p6] = block3;
                                        }
                                    }

                                    if (ix == 0 && iy == 2) {
                                        if (type[p1][p2][p3][p4][p5][p6] == 0)
                                        {
                                            type[p1][p2][p3][p4][p5][p6] = BLOCK2;
                                        }
                                    }

                                    if (ix == 2 && iy == 0) {
                                        if (type[p1][p2][p3][p4][p5][p6] == 0)
                                        {
                                            type[p1][p2][p3][p4][p5][p6] = block2;
                                        }
                                    }
                            }
                              
                            
                            else if(p1!=3&&p6!=3) {//无边界
                                if ((x == 0 && y == 4) || (ix == 0 && iy == 4)) {
                                    if (type[p1][p2][p3][p4][p5][p6] == 0)
                                        type[p1][p2][p3][p4][p5][p6] = BLOCK4;
                                }

                                if ((x == 4 && y == 0) || (ix == 4 && iy == 0)) {
                                    if (type[p1][p2][p3][p4][p5][p6] == 0)
                                        type[p1][p2][p3][p4][p5][p6] = block4;
                                }

                                if ((x == 0 && y == 3) || (ix == 0 && iy == 3)) {
                                    if (type[p1][p2][p3][p4][p5][p6] == 0)
                                        type[p1][p2][p3][p4][p5][p6] = BLOCK3;
                                }

                                if ((x == 3 && y == 0) || (ix == 3 && iy == 0)) {
                                    if (type[p1][p2][p3][p4][p5][p6] == 0)
                                        type[p1][p2][p3][p4][p5][p6] = block3;
                                }

                                if ((x == 0 && y == 2) || (ix == 0 && iy == 2)) {
                                    if (type[p1][p2][p3][p4][p5][p6] == 0)
                                        type[p1][p2][p3][p4][p5][p6] = BLOCK2;
                                }

                                if ((x == 2 && y == 0) || (ix == 2 && iy == 0)) {
                                    if (type[p1][p2][p3][p4][p5][p6] == 0)
                                        type[p1][p2][p3][p4][p5][p6] = block2;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

int evaluate(void) {
    //全局估值 
    memset(sample, 0, sizeof(sample));

    int i, j, Type;

    //判断竖向棋型
    for (i = 1; i <= 15; ++i) {
        for (j = 0; j <= 11; ++j) {
            Type = type[Board[i][j]][Board[i][j + 1]][Board[i][j + 2]][Board[i][j + 3]][Board[i][j + 4]][Board[i][j + 5]];
            ++sample[0][Type];
        }
    }
    //判断横向棋型
    for (j = 1; j <= 15; ++j) {
        for (i = 0; i <= 11; ++i) {
            Type = type[Board[i][j]][Board[i + 1][j]][Board[i + 2][j]][Board[i + 3][j]][Board[i + 4][j]][Board[i + 5][j]];
            ++sample[1][Type];
        }
    }
    //判断左上至右下棋型
    for (i = 0; i <= 11; ++i) {
        for (j = 16; j >= 5; --j) {
            Type = type[Board[i][j]][Board[i + 1][j - 1]][Board[i + 2][j - 2]][Board[i + 3][j - 3]][Board[i + 4][j - 4]][Board[i + 5][j - 5]];
            ++sample[2][Type];
        }
    }
    //判断右上至左下棋型
    for (i = 0; i <= 11; ++i) {
        for (j = 11; j >= 0; --j) {
            Type = type[Board[i][j]][Board[i + 1][j + 1]][Board[i + 2][j + 2]][Board[i + 3][j + 3]][Board[i + 4][j + 4]][Board[i + 5][j + 5]];
            ++sample[3][Type];
        }
    }
    int score = 0;
    for (i = 1; i <= 16; ++i) {
        score += (sample[0][i] + sample[1][i] + sample[2][i] + sample[3][i]) * weight[i];//初步计分
    }
    return score;
}

void seekPoints(int blackORwhite) {
    // 寻找落子点
    memset(isEmpty, 0, sizeof(isEmpty));

    memset(best_points.x, 0, sizeof(best_points.x));
    memset(best_points.y, 0, sizeof(best_points.y));
    memset(best_points.score, 0, sizeof(best_points.score));

    int num = 3;
    for (int i = 1; i <= 15; ++i) {//每个非空点附近8个方向延伸3个深度,若不越界则标记为可走
        for (int j = 1; j <= 15; ++j) {
            if (Board[i][j] != 0) {
                for (int k = -num; k <= num; ++k) {
                    if (i + k >= 1 && i + k <= 15) {
                        isEmpty[i + k][j] = 1;//非偏僻
                        if (j + k >= 1 && j + k <= 15) { isEmpty[i + k][j + k] = 1; }
                        if (j - k >= 1 && j - k <= 15) { isEmpty[i + k][j - k] = 1; }
                    }
                    if (j + k >= 1 && j + k <= 15) { isEmpty[i][j + k] = 1; }
                }
            }
        }
    }

    for (int i = 1; i <= 15; ++i) {
        for (int j = 1; j <= 15; ++j) {
            if (blackORwhite == 2){worth[i][j] = -INT_MAX;}
            else if(blackORwhite==1) { worth[i][j] = INT_MAX; }
            if (Board[i][j] == 0&& isEmpty[i][j] == 1) {
                Board[i][j] = blackORwhite; 
                worth[i][j] = evaluate();
                Board[i][j] = 0;
            }
        }
    }

    int goal;
    for (int k = 1; k <= 10; ++k) {
        if(blackORwhite==2) 
        { goal = -INT_MAX; }
        else if (blackORwhite == 1) {goal=INT_MAX;}
        for (int i = 1; i <= 15; ++i) {
            for (int j = 1; j <= 15; ++j) {
                if (blackORwhite == 2) {
                    if (worth[i][j] > goal) {
                        goal = worth[i][j];
                        best_points.x[k] = i;
                        best_points.y[k] = j;
                    }
                }
                else if(blackORwhite==1) {
                    if (worth[i][j] < goal) {
                        goal = worth[i][j];
                        best_points.x[k] = i;
                        best_points.y[k] = j;
                    }
                }
            }
        }
        best_points.score[k] = goal;
        if (blackORwhite == 2) {
            worth[best_points.x[k]][best_points.y[k]] = -INT_MAX;
        }
        else if(blackORwhite==1) 
        { worth[best_points.x[k]][best_points.y[k]] = INT_MAX; }
        //清除掉上一点,计算下一点的位置和分数
    }
}

int analyse(int depth, int alpha, int beta, int Depth) {//alpha max beta -max
    int tempX, tempY, temp;
    if (ifWin() != 0) {
        return evaluate();//如果模拟落子可以分出输赢，那么直接返回结果
    }
    else if (depth == 0)
    {   //生成最佳的可能落子位置
        seekPoints(2);
        return best_points.score[1];
        //返回最佳位置对应的最高分
    }
    else if (depth % 2 == 0) {//max层ai决策    
        for (int i = 1; i <= 10; ++i) {
            seekPoints(2);
            tempX = best_points.x[i], tempY = best_points.y[i];
            Board[tempX][tempY] = 2;
            temp = analyse(depth - 1, alpha, beta, Depth);
            Board[tempX][tempY] = 0;
            if (depth == Depth) {
                decision.x[i] = tempX;
                decision.y[i] = tempY;
                decision.eval[i] = temp;
            }
            if (temp > alpha) {
                alpha = temp;
            }
            if (temp<alpha&&depth!=Depth)
            { break; }
        }
        return alpha;
    }
    else if (depth % 2 == 1) {//min层,敌方决策
        for (int i = 1; i <= 10; ++i) {
            seekPoints(1);
            tempX = best_points.x[i], tempY = best_points.y[i];
            Board[tempX][tempY] = 1;
            temp = analyse(depth - 1, alpha, beta, Depth);
            Board[tempX][tempY] = 0;
            if (temp < beta) { beta = temp; }
            if (beta <temp) 
            { break; }
        }
        return beta;
    }
}