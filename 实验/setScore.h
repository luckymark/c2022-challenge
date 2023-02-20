#ifndef GOBANG2_SETSCORE_H
#define GOBANG2_SETSCORE_H

#endif //GOBANG2_SETSCORE_H


#include "tree.h"

extern int subMap[17][17];
extern int dir[4][2];

void defendScore(Node *node);
void attackScore(Node *node);
Node *cmpScore(Node *node);
bool ifWinner(Node *node); //输入落子，判断落子后是否赢
void inputToMap(Node *node);
void defend_attack(Node *node);
