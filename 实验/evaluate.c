#include "head.h"

int humAddVal[4][4][4][4][4][4][4][4]; //某种棋型的分数
int comAddVal[4][4][4][4][4][4][4][4];
int humDeVal[4][4][4][4][4][4][4][4];
int comDeVal[4][4][4][4][4][4][4][4];

int evaluate(int (*gobang)[SIZE],int x, int y, int playerNum) {
    int netScore=0;
    int h=1,v=0;
    if (playerNum==humNum){
        netScore-=humDeVal[gobang[y - 4 * v][x - 4 * h]][gobang[y - 3 * v][x - 3 * h]]
                [gobang[y - 2 * v][x - 2 * h]][gobang[y - v][x - h]][gobang[y + v][x + h]]
                [gobang[y + 2 * v][x + 2 * h]][gobang[y + 3 * v][x + 3 * h]][gobang[y + 4 * v][x + 4 * h]];
        netScore+=humAddVal[gobang[y - 4 * v][x - 4 * h]][gobang[y - 3 * v][x - 3 * h]]
                [gobang[y - 2 * v][x - 2 * h]][gobang[y - v][x - h]][gobang[y + v][x + h]]
                [gobang[y + 2 * v][x + 2 * h]][gobang[y + 3 * v][x + 3 * h]][gobang[y + 4 * v][x + 4 * h]];
        h=0;
        v=1;
        netScore-=humDeVal[gobang[y - 4 * v][x - 4 * h]][gobang[y - 3 * v][x - 3 * h]]
                [gobang[y - 2 * v][x - 2 * h]][gobang[y - v][x - h]][gobang[y + v][x + h]]
                [gobang[y + 2 * v][x + 2 * h]][gobang[y + 3 * v][x + 3 * h]][gobang[y + 4 * v][x + 4 * h]];
        netScore+=humAddVal[gobang[y - 4 * v][x - 4 * h]][gobang[y - 3 * v][x - 3 * h]]
                [gobang[y - 2 * v][x - 2 * h]][gobang[y - v][x - h]][gobang[y + v][x + h]]
                [gobang[y + 2 * v][x + 2 * h]][gobang[y + 3 * v][x + 3 * h]][gobang[y + 4 * v][x + 4 * h]];
        h=1;
        v=1;
        netScore-=humDeVal[gobang[y - 4 * v][x - 4 * h]][gobang[y - 3 * v][x - 3 * h]]
                [gobang[y - 2 * v][x - 2 * h]][gobang[y - v][x - h]][gobang[y + v][x + h]]
                [gobang[y + 2 * v][x + 2 * h]][gobang[y + 3 * v][x + 3 * h]][gobang[y + 4 * v][x + 4 * h]];
        netScore+=humAddVal[gobang[y - 4 * v][x - 4 * h]][gobang[y - 3 * v][x - 3 * h]]
                [gobang[y - 2 * v][x - 2 * h]][gobang[y - v][x - h]][gobang[y + v][x + h]]
                [gobang[y + 2 * v][x + 2 * h]][gobang[y + 3 * v][x + 3 * h]][gobang[y + 4 * v][x + 4 * h]];
        h=1;
        v=-1;
        netScore-=humDeVal[gobang[y - 4 * v][x - 4 * h]][gobang[y - 3 * v][x - 3 * h]]
                [gobang[y - 2 * v][x - 2 * h]][gobang[y - v][x - h]][gobang[y + v][x + h]]
                [gobang[y + 2 * v][x + 2 * h]][gobang[y + 3 * v][x + 3 * h]][gobang[y + 4 * v][x + 4 * h]];
        netScore+=humAddVal[gobang[y - 4 * v][x - 4 * h]][gobang[y - 3 * v][x - 3 * h]]
                [gobang[y - 2 * v][x - 2 * h]][gobang[y - v][x - h]][gobang[y + v][x + h]]
                [gobang[y + 2 * v][x + 2 * h]][gobang[y + 3 * v][x + 3 * h]][gobang[y + 4 * v][x + 4 * h]];
    }
    else if (playerNum==comNum){
        netScore-=comDeVal[gobang[y - 4 * v][x - 4 * h]][gobang[y - 3 * v][x - 3 * h]]
                [gobang[y - 2 * v][x - 2 * h]][gobang[y - v][x - h]][gobang[y + v][x + h]]
                [gobang[y + 2 * v][x + 2 * h]][gobang[y + 3 * v][x + 3 * h]][gobang[y + 4 * v][x + 4 * h]];
        netScore+=comAddVal[gobang[y - 4 * v][x - 4 * h]][gobang[y - 3 * v][x - 3 * h]]
                [gobang[y - 2 * v][x - 2 * h]][gobang[y - v][x - h]][gobang[y + v][x + h]]
                [gobang[y + 2 * v][x + 2 * h]][gobang[y + 3 * v][x + 3 * h]][gobang[y + 4 * v][x + 4 * h]];
        h=0;
        v=1;
        netScore-=comDeVal[gobang[y - 4 * v][x - 4 * h]][gobang[y - 3 * v][x - 3 * h]]
                [gobang[y - 2 * v][x - 2 * h]][gobang[y - v][x - h]][gobang[y + v][x + h]]
                [gobang[y + 2 * v][x + 2 * h]][gobang[y + 3 * v][x + 3 * h]][gobang[y + 4 * v][x + 4 * h]];
        netScore+=comAddVal[gobang[y - 4 * v][x - 4 * h]][gobang[y - 3 * v][x - 3 * h]]
                [gobang[y - 2 * v][x - 2 * h]][gobang[y - v][x - h]][gobang[y + v][x + h]]
                [gobang[y + 2 * v][x + 2 * h]][gobang[y + 3 * v][x + 3 * h]][gobang[y + 4 * v][x + 4 * h]];
        h=1;
        v=1;
        netScore-=comDeVal[gobang[y - 4 * v][x - 4 * h]][gobang[y - 3 * v][x - 3 * h]]
                [gobang[y - 2 * v][x - 2 * h]][gobang[y - v][x - h]][gobang[y + v][x + h]]
                [gobang[y + 2 * v][x + 2 * h]][gobang[y + 3 * v][x + 3 * h]][gobang[y + 4 * v][x + 4 * h]];
        netScore+=comAddVal[gobang[y - 4 * v][x - 4 * h]][gobang[y - 3 * v][x - 3 * h]]
                [gobang[y - 2 * v][x - 2 * h]][gobang[y - v][x - h]][gobang[y + v][x + h]]
                [gobang[y + 2 * v][x + 2 * h]][gobang[y + 3 * v][x + 3 * h]][gobang[y + 4 * v][x + 4 * h]];
        h=1;
        v=-1;
        netScore-=comDeVal[gobang[y - 4 * v][x - 4 * h]][gobang[y - 3 * v][x - 3 * h]]
                [gobang[y - 2 * v][x - 2 * h]][gobang[y - v][x - h]][gobang[y + v][x + h]]
                [gobang[y + 2 * v][x + 2 * h]][gobang[y + 3 * v][x + 3 * h]][gobang[y + 4 * v][x + 4 * h]];
        netScore+=comAddVal[gobang[y - 4 * v][x - 4 * h]][gobang[y - 3 * v][x - 3 * h]]
                [gobang[y - 2 * v][x - 2 * h]][gobang[y - v][x - h]][gobang[y + v][x + h]]
                [gobang[y + 2 * v][x + 2 * h]][gobang[y + 3 * v][x + 3 * h]][gobang[y + 4 * v][x + 4 * h]];
    }
    return netScore;
}

void setDeleteVal(int playerNum,int oppoNum){
    int p=playerNum,r=oppoNum,factor=1;
    int (*temp)[4][4][4][4][4][4][4];
    if (playerNum==humNum){
        temp=humDeVal;
        factor=FACTOR;
    }
    else if (playerNum==comNum)
        temp=comDeVal;
    //略去删除落子点附近L1的值
    //1
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            for (int k = 0; k < 4; ++k) {
                for (int l = 0; l < 4; ++l) {
                    for (int m = 0; m < 4; ++m) {
                        temp[i][j][k][l][p][p][0][m]=D2;
                        temp[i][0][p][p][j][k][l][m]=D2;
                    }
                }
            }
        }
    }
    //2
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            for (int k = 0; k < 4; ++k) {
                for (int l = 0; l < 4; ++l) {
                    temp[i][j][k][l][p][0][p][0]=D2;
                    temp[i][j][0][p][p][0][j][l]=D2;
                    temp[0][p][0][p][i][j][k][l]=D2;
                }
            }
        }
    }
    //3
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            for (int k = 0; k < 4; ++k) {
                temp[i][0][p][0][p][0][j][k]=D2;
                temp[i][j][0][p][0][p][0][k]=D2;
            }
        }
    }
    //4
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            for (int k = 0; k < 4; ++k) {
                for (int l = 0; l < 4; ++l) {
                    for (int m = 0; m < 4; ++m) {
                        temp[i][j][k][l][p][p][r][m]=D2;
                        temp[i][r][p][p][j][k][l][m]=D2;
                    }
                }
            }
        }
    }
    //5
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            for (int k = 0; k < 4; ++k) {
                for (int l = 0; l < 4; ++l) {
                    temp[i][j][0][p][p][r][k][l]=D2;
                    temp[i][j][k][l][p][0][p][r]=D2;
                    temp[r][p][0][p][i][j][k][l]=D2;
                    temp[i][j][r][p][p][0][k][l]=D2;
                }
            }
        }
    }
    //6
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            for (int k = 0; k < 4; ++k) {
                temp[i][0][p][0][p][r][j][k]=D2;
                temp[i][j][0][p][0][p][r][k]=D2;
                temp[i][j][r][p][0][p][0][k]=D2;
                temp[i][r][p][0][p][0][j][k]=D2;
            }
        }
    }
    //7
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            temp[0][p][0][0][p][0][i][j]=D2;
            temp[i][0][p][0][0][p][0][j]=D2;
            temp[i][j][0][p][0][0][p][0]=D2;
        }
    }
    //8
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            for (int k = 0; k < 4; ++k) {
                for (int l = 0; l < 4; ++l) {
                    temp[0][p][p][p][i][j][k][l]=L3*factor;
                    temp[i][j][k][l][p][p][p][0]=L3*factor;
                }
            }
        }
    }
    //9
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            for (int k = 0; k < 4; ++k) {
                temp[i][j][0][p][p][p][0][k]=D3;
                temp[i][0][p][p][p][0][j][k]=D3;
            }
        }
    }
    //10
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            for (int k = 0; k < 4; ++k) {
                for (int l = 0; l < 4; ++l) {
                    temp[i][j][k][l][p][p][p][r]=D3;
                    temp[r][p][p][p][i][j][k][l]=D3;
                }
            }
        }
    }
    //11
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            for (int k = 0; k < 4; ++k) {
                temp[i][j][0][p][p][p][r][k]=D3;
                temp[i][r][p][p][p][0][j][k]=D3;
            }
        }
    }
    //12
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            for (int k = 0; k < 4; ++k) {
                temp[i][0][p][p][p][r][j][k]=D3;
                temp[i][j][r][p][p][p][0][k]=D3;
            }
        }
    }
    //13
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            temp[i][0][p][0][p][p][0][j]=D3;
            temp[i][j][0][p][0][p][p][0]=D3;
            temp[i][0][p][p][0][p][0][j]=D3;
            temp[0][p][p][0][p][0][i][j]=D3;
        }
    }
    //14
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            temp[0][p][0][p][p][0][i][j]=D3;
            temp[i][j][0][p][p][0][p][0]=D3;
        }
    }
    //15
    //16
    //17
    //18
    //19
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            temp[i][j][0][p][p][p][p][0]=D4*factor;
            temp[0][p][p][p][p][0][i][j]=D4*factor;
        }
    }
    //20
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            temp[i][0][p][p][p][p][0][j]=D4*factor;
        }
    }
}

void setAddVal(int playerNum,int oppoNum){
    int p=playerNum,r=oppoNum,factor=1;
    int (*temp)[4][4][4][4][4][4][4];
    if (playerNum==humNum){
        temp=humAddVal;
        factor=FACTOR;
    }
    else if (playerNum==comNum)
        temp=comAddVal;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            for (int k = 0; k < 4; ++k) {
                for (int l = 0; l < 4; ++l) {
                    for (int m = 0; m < 4; ++m) {
                        for (int n = 0; n < 4; ++n) {
                            for (int i1 = 0; i1 < 4; ++i1) {
                                for (int j1 = 0; j1 < 4; ++j1) {
                                    temp[i][j][k][l][m][n][i1][j1]=L1;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    //1
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            for (int k = 0; k < 4; ++k) {
                for (int l = 0; l < 4; ++l) {
                    for (int m = 0; m < 4; ++m) {
                        temp[i][j][0][p][0][k][l][m]=L2;
                        temp[i][j][k][0][p][0][l][m]=L2;
                    }
                }
            }
        }
    }
    //2
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            for (int k = 0; k < 4; ++k) {
                for (int l = 0; l < 4; ++l) {
                    temp[i][j][k][0][0][p][0][l]=D2;
                    temp[i][0][p][0][0][j][k][l]=D2;
                }
            }
        }
    }
    //3
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            for (int k = 0; k < 4; ++k) {
                temp[i][j][k][0][0][0][p][0]=D2;
                temp[0][p][0][0][0][i][j][k]=D2;
            }
        }
    }
    //4
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            for (int k = 0; k < 4; ++k) {
                for (int l = 0; l < 4; ++l) {
                    for (int m = 0; m < 4; ++m) {
                        temp[i][j][k][0][p][r][l][m]=D2;
                        temp[i][j][0][p][r][k][l][m]=D2;
                        temp[i][j][r][p][0][k][l][m]=D2;
                        temp[i][j][k][r][p][0][l][m]=D2;
                    }
                }
            }
        }
    }
    //5
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            for (int k = 0; k < 4; ++k) {
                for (int l = 0; l < 4; ++l) {
                    temp[i][j][k][0][0][p][r][l]=D2;
                    temp[i][0][p][0][r][j][k][l]=D2;
                    temp[i][j][k][r][0][p][0][l]=D2;
                    temp[i][r][p][0][0][j][k][l]=D2;
                }
            }
        }
    }
    //6
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            for (int k = 0; k < 4; ++k) {
                temp[0][p][0][0][r][i][j][k]=D2;
                temp[i][j][k][0][0][0][p][r]=D2;
                temp[i][j][k][r][0][0][p][0]=D2;
                temp[r][p][0][0][0][i][j][k]=D2;
            }
        }
    }
    //7

    //8
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            for (int k = 0; k < 4; ++k) {
                for (int l = 0; l < 4; ++l) {
                    temp[i][j][k][0][p][p][0][l]=L3*factor;
                    temp[i][j][0][p][p][0][k][l]=L3*factor;
                    temp[i][0][p][p][0][j][k][l]=L3*factor;
                }
            }
        }
    }
    //9
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            for (int k = 0; k < 4; ++k) {
                temp[i][j][k][0][0][p][p][0]=D3;
                temp[i][0][p][0][p][0][j][k]=D3;
                temp[0][p][0][p][0][i][j][k]=D3;
                temp[i][j][k][0][p][0][p][0]=D3;
                temp[i][j][0][p][0][p][0][k]=D3;
                temp[0][p][p][0][0][i][j][k]=D3;
            }
        }
    }
    //10
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            for (int k = 0; k < 4; ++k) {
                for (int l = 0; l < 4; ++l) {
                    temp[i][0][p][p][r][j][k][l]=D3;
                    temp[i][j][0][p][p][r][k][l]=D3;
                    temp[i][j][k][0][p][p][r][l]=D3;
                    temp[i][j][k][r][p][p][0][l]=D3;
                    temp[i][j][r][p][p][0][k][l]=D3;
                    temp[i][r][p][p][0][j][k][l]=D3;
                }
            }
        }
    }
    //11
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            for (int k = 0; k < 4; ++k) {
                temp[i][j][k][0][0][p][p][r]=D3;
                temp[i][0][p][0][p][r][j][k]=D3;
                temp[0][p][0][p][r][i][j][k]=D3;
                temp[r][p][p][0][0][i][j][k]=D3;
                temp[i][j][r][p][0][p][0][k]=D3;
                temp[i][j][k][r][p][0][p][0]=D3;
            }
        }
    }
    //12
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            for (int k = 0; k < 4; ++k) {
                temp[i][j][k][0][p][0][p][r]=D3;
                temp[i][j][0][p][0][p][r][k]=D3;
                temp[0][p][p][0][r][i][j][k]=D3;
                temp[r][p][0][p][0][i][j][k]=D3;
                temp[i][r][p][0][p][0][j][k]=D3;
                temp[i][j][k][r][0][p][p][0]=D3;
            }
        }
    }
    //13
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            temp[0][p][0][0][p][0][i][j]=D3;
            temp[i][j][0][p][0][0][p][0]=D3;
        }
    }
    //14
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            temp[i][0][p][0][0][p][0][j]=D3;
        }
    }
    //15
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            temp[r][0][p][p][0][r][i][j]=D3;
            temp[i][r][0][p][p][0][r][j]=D3;
            temp[i][j][r][0][p][p][0][r]=D3;
        }
    }
    //16
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            for (int k = 0; k < 4; ++k) {
                for (int l = 0; l < 4; ++l) {
                    temp[p][p][p][p][i][j][k][l]=L5*factor;
                    temp[i][p][p][p][p][j][k][l]=L5*factor;
                    temp[i][j][p][p][p][p][k][l]=L5*factor;
                    temp[i][j][k][p][p][p][p][l]=L5*factor;
                    temp[i][j][k][l][p][p][p][p]=L5*factor;
                }
            }
        }
    }
    //17
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            for (int k = 0; k < 4; ++k) {
                temp[0][p][p][p][0][i][j][k]=L4*factor;
                temp[i][0][p][p][p][0][j][k]=L4*factor;
                temp[i][j][0][p][p][p][0][k]=L4*factor;
                temp[i][j][k][0][p][p][p][0]=L4*factor;
            }
        }
    }
    //18
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            for (int k = 0; k < 4; ++k) {
                temp[0][p][p][p][r][i][j][k]=D4*factor;
                temp[i][0][p][p][p][r][j][k]=D4*factor;
                temp[i][j][0][p][p][p][r][k]=D4*factor;
                temp[i][j][k][0][p][p][p][r]=D4*factor;
                temp[r][p][p][p][0][i][j][k]=D4*factor;
                temp[i][r][p][p][p][0][j][k]=D4*factor;
                temp[i][j][r][p][p][p][0][k]=D4*factor;
                temp[i][j][k][r][p][p][p][0]=D4*factor;
            }
        }
    }
    //19
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            temp[0][p][0][p][p][0][i][j]=D4*factor;
            temp[i][0][p][0][p][p][0][j]=D4*factor;
            temp[i][j][0][p][p][0][p][0]=D4*factor;
            temp[i][0][p][p][0][p][0][j]=D4*factor;
        }
    }
    //20
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            temp[i][j][0][p][0][p][p][0]=D4*factor;
            temp[0][p][p][0][p][0][i][j]=D4*factor;
        }
    }
}