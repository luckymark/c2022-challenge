#include "head.h"

int humNum=1, comNum=2;
int score=0;

int zobrist_count;

void initGobang(int (*gobang)[SIZE]); //给gobang数组圈出宽度为BORDER的边界并将每个元素初始化为BORDER_NUM，再给双方的棋型数组赋值
void rankMove(int (*gobang)[SIZE], Piece *pieces, int playerNum, int spaceCount); //对传入的候选落子点按得分进行排序
int cmp(const void* p1, const void* p2); //比较两个待落子点在局部产生的得分
int alphaBeta(int (*gobang)[SIZE], int alpha, int beta, int depth, int player, int val, Piece cur, int spaceCount); //返回cur坐标所能产生的最大数值
int min(int a,int b);
int max(int a,int b);

int valueMap[SIZE][SIZE] = { {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                             {0,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
                             {0,1,2,2,2,2,2,2,2,2,2,2,2,1,0},
                             {0,1,2,3,3,3,3,3,3,3,3,3,2,1,0},
                             {0,1,2,3,4,4,4,4,4,4,4,3,2,1,0},
                             {0,1,2,3,4,5,5,5,5,5,4,3,2,1,0},
                             {0,1,2,3,4,5,6,6,6,5,4,3,2,1,0},
                             {0,1,2,3,4,5,6,7,6,5,4,3,2,1,0},
                             {0,1,2,3,4,5,6,6,6,5,4,3,2,1,0},
                             {0,1,2,3,4,5,5,5,5,5,4,3,2,1,0},
                             {0,1,2,3,4,4,4,4,4,4,4,3,2,1,0},
                             {0,1,2,3,3,3,3,3,3,3,3,3,2,1,0},
                             {0,1,2,2,2,2,2,2,2,2,2,2,2,1,0},
                             {0,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
                             {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0} };


int main(void){
    int gobang[SIZE][SIZE];
    memset(gobang,0,sizeof(gobang));
    initGobang(gobang);

    initZobrist();
    chessPlay(gobang,humNum,comNum,RAYWHITE,BLACK);
    //testCase(gobang,humNum,comNum,RAYWHITE,BLACK);
    return 0;
}

void initGobang(int (*gobang)[SIZE]){
    for (int i = 0; i < BORDER; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            gobang[i][j]=BORDER_NUM;
        }
    }
    for (int i = SIZE-BORDER; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            gobang[i][j]=BORDER_NUM;
        }
    }
    for (int j = 0; j < BORDER; ++j) {
        for (int i = BORDER; i < SIZE-BORDER; ++i) {
            gobang[i][j]=BORDER_NUM;
        }
    }
    for (int j = SIZE-BORDER; j < SIZE; ++j) {
        for (int i = BORDER; i < SIZE-BORDER; ++i) {
            gobang[i][j]=BORDER_NUM;
        }
    }
    setAddVal(humNum,comNum,humNum,comNum);
    setAddVal(comNum,humNum,humNum,comNum);
    setDeleteVal(humNum,comNum,humNum,comNum);
    setDeleteVal(comNum,humNum,humNum,comNum);
}
void rankMove(int (*gobang)[SIZE], Piece *pieces, int playerNum, int spaceCount) {
    int count=0;
    for (int i = BORDER; i < SIZE-BORDER; ++i) {
        for (int j = BORDER; j < SIZE-BORDER; ++j) {
            if (gobang[i][j] == 0) {
                pieces[count].value = evaluate(gobang, j, i, playerNum, humNum, comNum) + valueMap[i - BORDER][j - BORDER] * MAP_VALUE;
                pieces[count].pos.x = j;
                pieces[count].pos.y = i;
                ++count;
            }
        }
    }
    qsort((Piece *)pieces, spaceCount , sizeof(Piece), cmp);
}
int cmp(const void* p1, const void* p2) {
    Piece* ptr1=(Piece*)p1;
    Piece* ptr2 = (Piece*)p2;
    return (*ptr2).value - (*ptr1).value;
}
Piece makeMove(int (*gobang)[SIZE], int spaceCount) {
    zobrist_count=0;
    Piece *pieces = (Piece*)malloc(spaceCount * sizeof(Piece));
    if (pieces == NULL) {
        exit(1);
    }
    rankMove(gobang, pieces, comNum, spaceCount);
    int bestScore = -INF;
    Piece bestMove;
    for (int i = 0; i<spaceCount; ++i) {
        int curScore = alphaBeta(gobang, -INF, INF, DEP, !AI, score, pieces[i], spaceCount);
        if (curScore > bestScore) {
            bestScore = curScore;
            bestMove = pieces[i];
        }
    }
    free(pieces);
    printf("\nzobrist:%d\n",zobrist_count);
    return bestMove;
}
int alphaBeta(int (*gobang)[SIZE], int alpha, int beta, int depth, int player, int val, Piece cur, int spaceCount) {
    if (player) {
        if (cur.value>=L5)
            return val-cur.value;

        key^=humTable[cur.pos.y][cur.pos.x];
        //keyLock^=humTable[cur.pos.y][cur.pos.x];
        Hash *cache=&zobristCache[key&(TABLE_SIZE-1)];
        if(depth==0){
            if (cache->value!=-INF&&cache->lock==key&&cache->depth==depth){
                int value=zobristCache[key&(TABLE_SIZE-1)].value;
                key^=humTable[cur.pos.y][cur.pos.x];
                //keyLock^=humTable[cur.pos.y][cur.pos.x];
                ++zobrist_count;
                return value;
            }

            val-=cur.value;
            int best=0;
            for(int i=BORDER;i<SIZE-BORDER;++i){
                for(int j=BORDER;j<SIZE-BORDER;++j){
                    if (gobang[i][j]==0){
                        best= max(best, evaluate(gobang,j,i,comNum,humNum,comNum)+ valueMap[i-BORDER][j-BORDER] * MAP_VALUE);
                    }
                }
            }

            cache->value=val+best;
            cache->depth=depth;
            cache->lock=key;
            key^=humTable[cur.pos.y][cur.pos.x];
            //keyLock^=humTable[cur.pos.y][cur.pos.x];
            return val+best;
        }

        if (cache->value!=-INF&&cache->depth==depth&&cache->lock==key){
            int value=zobristCache[key&(TABLE_SIZE-1)].value;
            key^=humTable[cur.pos.y][cur.pos.x];
            //keyLock^=humTable[cur.pos.y][cur.pos.x];
            ++zobrist_count;
            return value;
        }

        gobang[cur.pos.y][cur.pos.x]=humNum;
        val -= cur.value;
        spaceCount--;
        Piece *pieces = (Piece*)malloc(spaceCount * sizeof(Piece));
        if (pieces == NULL) {
            exit(1);
        }
        rankMove(gobang, pieces, comNum, spaceCount);
        for (int i = 0; i < spaceCount; ++i) {
            alpha = max(alpha, alphaBeta(gobang, alpha, beta, depth - 1, !player, val, pieces[i], spaceCount));
            if (alpha >= beta) {
                break;
            }
        }
        gobang[cur.pos.y][cur.pos.x]=0;

        cache->value=alpha;
        cache->depth=depth;
        cache->lock=key;
        key^=humTable[cur.pos.y][cur.pos.x];
        //keyLock^=humTable[cur.pos.y][cur.pos.x];

        free(pieces);
        return alpha;
    }
    else if (!player) {
        if (cur.value>=L5)
            return val+cur.value;

        key^=comTable[cur.pos.y][cur.pos.x];
        //keyLock^=comTable[cur.pos.y][cur.pos.x];
        Hash *cache=&zobristCache[key&(TABLE_SIZE-1)];
        if(depth==0){
            if (cache->value!=-INF&&cache->lock==key&&cache->depth==depth){
                int value=cache->value;
                key^=comTable[cur.pos.y][cur.pos.x];
                //keyLock^=comTable[cur.pos.y][cur.pos.x];
                ++zobrist_count;
                return value;
            }

            val+=cur.value;
            int best=0;
            for(int i=BORDER;i<SIZE-BORDER;++i){
                for(int j=BORDER;j<SIZE-BORDER;++j){
                    if (gobang[i][j]==0){
                        best= max(best, evaluate(gobang,j,i,humNum,humNum,comNum)+ valueMap[i-BORDER][j-BORDER] * MAP_VALUE);
                    }
                }
            }

            cache->value=val-best;
            cache->depth=depth;
            cache->lock=key;
            key^=comTable[cur.pos.y][cur.pos.x];
            //keyLock^=comTable[cur.pos.y][cur.pos.x];
            return val-best;
        }

        if (cache->value!=-INF&&cache->lock==key&&cache->depth==depth){
            int value=cache->value;
            key^=comTable[cur.pos.y][cur.pos.x];
            //keyLock^=comTable[cur.pos.y][cur.pos.x];
            ++zobrist_count;
            return value;
        }

        gobang[cur.pos.y][cur.pos.x]=comNum;
        spaceCount--;
        Piece* pieces = (Piece*)malloc(spaceCount * sizeof(Piece));
        if (pieces == NULL) {
            exit(1);
        }
        rankMove(gobang, pieces, humNum, spaceCount);
        for (int i = 0; i < spaceCount; ++i) {
            beta = min(beta, alphaBeta(gobang, alpha, beta, depth - 1, !player, val, pieces[i], spaceCount));
            if (alpha >= beta) {
                break;
            }
        }
        gobang[cur.pos.y][cur.pos.x]=0;

        cache->value=beta;
        cache->depth=depth;
        cache->lock=key;
        key^=comTable[cur.pos.y][cur.pos.x];
        //keyLock^=comTable[cur.pos.y][cur.pos.x];

        free(pieces);
        return beta;
    }
}
inline int min(int a,int b){
    return a<=b?a:b;
}
inline int max(int a,int b){
    return a>=b?a:b;
}