#include "head.h"

uint64_t humTable[SIZE][SIZE];
uint64_t comTable[SIZE][SIZE];
uint64_t key;

Hash zobristCache[TABLE_SIZE];

uint64_t get64rand() {
    return
        (((uint64_t) rand() <<  0) & 0x000000000000FFFFull) |
        (((uint64_t) rand() << 16) & 0x00000000FFFF0000ull) |
        (((uint64_t) rand() << 32) & 0x0000FFFF00000000ull) |
        (((uint64_t) rand() << 48) & 0xFFFF000000000000ull);
}

void initZobrist(void){
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            humTable[i][j]=get64rand(); //为不同玩家、不同位置的棋子生成键值
            comTable[i][j]=get64rand();
        }
    }
    for (int i = 0; i < TABLE_SIZE; ++i) {
        zobristCache[i].value=-INF;
    }
    key=0;
}