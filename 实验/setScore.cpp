#include "setScore.h"
#include <cstdio>
#include <cstdlib>

// higher score--better step for the player or AI
//width%2 == 1 black
//width%2 == 0 white

int dir[4][2] = {0,1,1,0,1,1,-1,1};
int subMap[17][17] = {0};

void addScore(Node *node);
void getToBottom(Node *node);
void attack_4(Node *node,const int item[]);
void attack_3(Node *node,const int item[]);
void attack_2(Node *node,const int item[]);
void defend(Node *node,const int item[]);
void defend_2(Node *node,const int item[]);

bool ifWinner(Node *node) {
    inputToMap(node);
    for (int k = 0;k <= 3; ++k) {
        int i = 1;
        while(true) {
            if (subMap[node->X][node->Y] == subMap[node->X + i*dir[k][0]][node->Y + i*dir[k][1]]){
                i++;
            }else break;
        }
        int j = -1;
        while(true) {
            if (subMap[node->X][node->Y] == subMap[node->X + j*dir[k][0]][node->Y + j*dir[k][1]]){
                j--;
            }else break;
        }
        if ((i-j-1) >= 5) return true;
    }
    return false;
}

void addScore(Node *node) { //模拟时使用玩家较强的走法与AI方相匹配 只能输入玩家结点 node->depth == 奇数  将分数向下加和至底层
    if (node->treeChildren[0] == nullptr) return;
    for (int i = 0;i <= node->childrenNum-1; ++i) {
        node->treeChildren[i]->attackScore-=node->attackScore;
        if (node->treeChildren[i]->treeChildren[0] == nullptr) continue;
        node->treeChildren[i]->treeChildren[0]->attackScore = node->treeChildren[i]->attackScore - node->treeChildren[i]->treeChildren[0]->attackScore;
        addScore(node->treeChildren[i]->treeChildren[0]);
    }
}

static int maxScore;
static Node* maxScoreNode;

void getToBottom(Node *node) { //递归遍历至底层，并比较出最高分
    if (node->treeChildren[0] == nullptr){
        if (node->attackScore > maxScore){
            maxScoreNode = node;
            maxScore = node->attackScore;
        }
        return;
    }
    for (int i = 0;i <= node->childrenNum-1; ++i) {
        getToBottom(node->treeChildren[i]);
    }
}

Node *cmpScore(Node *node) { //比较底层分数，并返回选取的stepNode
    addScore(node);
    maxScore = -100000;
    maxScoreNode = nullptr;
    getToBottom(node);
    while(true) {
        if (maxScoreNode->depth == 2)break;
        maxScoreNode = maxScoreNode->treeParent;
    }
    return maxScoreNode;
}

void inputToMap(Node *node) {  //将树中的棋输入到缓存棋盘中
    for (int i = 0;i <= 16; ++i) {
        for (int j = 0;j <= 16; ++j) {
            subMap[i][j] = map[i][j];
        }
    }
    while(true){
        if (node->depth%2 == 1){
            subMap[node->X][node->Y] = black;
        }else{
            subMap[node->X][node->Y] = white;
        }
        if (node->depth == 1) break;
        node = node->treeParent;
    }
}

void attack_4(Node *node,const int item[]) { //输入要评分的步 4颗
    for (int d = 1;d!=-3;d-=2){ //对称性
        if (item[4] == item[4+d] && item[4+d] == item[4+2*d] && item[4+2*d] == item[4+3*d]) { // 0ooo
            if ((item[4+4*d] == 0 && item[4-d] * item[4] == 2)||(item[4+4*d]*item[4] == 2&&item[4-d] == 0)) {
                node->attackScore += 10;
            }else if (item[4+4*d] == 0 && item[4-d] == 0) {
                node->attackScore += 60000; //无遮挡成四
            }
        }else if (item[4+d] == item[4] && item[4] == item[4-d] && item[4-d] == item[4-2*d]){ // oo0o
            if ((item[4-2*d]*item[4-3*d] == 2 && item[4+2*d] == 0)||(item[4+2*d]*item[4] == 2 && item[4-3*d] == 0)){
                node->attackScore += 10;
            }else if (item[4+2*d] == 0&&item[4-3*d]){
                node->attackScore += 60000;
            }
        }else if (item[4] == item[4+d] && item[4+d] == item[4+2*d] && item[4+2*d] == item[4+4*d] && item[4+3*d] == 0){ // 0oo o
            if (item[4-d] == 0 && item[4-2*d] == 0){
                node->attackScore+=15;
            }else{
                node->attackScore+=10;
            }
        }else if (item[4] == item[4-d] && item[4] == item[4+d] && item[4+2*d] == 0 && item[4] == item[4+3*d]){ // o0o o
            if (item[4-2*d] == 0 && item[4-3*d] == 0){
                node->attackScore+=15;
            }else{
                node->attackScore+=10;
            }
        }else if (item[4+d] == 0 && item[4-2*d] == item[4] && item[4-d] == item[4] && item[4+2*d] == item[4]){ // oo0 o
            if (item[4-3*d] == 0 && item[4-4*d] == 0){
                node->attackScore+=15;
            }else{
                node->attackScore+=10;
            }
        }else if (item[4] == item[4-2*d] && item[4] == item[4-3*d] && item[4] == item[4-4*d] && item[4-d] == 0){ // ooo 0
            node->attackScore+=10;
        }else if (item[4] == item[4-d] && item[4] == item[4-3*d] && item[4] == item[4-4*d] && item[4-2*d] == 0){ // oo o0
            node->attackScore+=10;
        }else if (item[4] == item[4+d] && item[4-2*d] == item[4] && item[4-3*d] == item[4] && item[4-d] == 0){ // oo 0o
            node->attackScore+=10;
        }
    }
}

void attack_3(Node *node,const int item[]) { // 3颗
    for (int d = 1;d != -3;d-=2) {
        if (item[4] == item[4-d] && item[4] == item[4-2*d]){ // oo0
            if (item[4+d] == 0 && item[4-3*d] == 0){
                if(item[4+2*d]*item[4] == 2 && item[4-4*d]*item[4] == 2){
                    node->attackScore+=5;
                }else{
                    node->attackScore+=10;
                }
            }else if((item[4+d] == 0 && item[4-3*d]*item[4] == 2) && (item[4+d]*item[4] == 2 && item[4-3*d] == 0)){

            }else{
                node->attackScore+=5;
            }
        }else if (item[4+d] == item[4] && item[4-d] == item[4]){ // o0o
            if (item[4+2*d] == 0 && item[4-2*d] == 0){
                if (item[4+3*d]*item[4] == 2 && item[4-3*d]*item[4] == 2){ //由对称性 该式会重复计算
                    if (d == 1){
                        node->attackScore+=5;
                    }
                }else{
                    if (d == 1){
                        node->attackScore+=10;
                    }
                }
            }else if (item[4-2*d]*item[4] == 2 && item[4+2*d]*item[4] == 2){

            }else{
                node->attackScore+=5;
            }
        }else if (item[4-2*d] == item[4] && item[4-3*d] == item[4] && item[4-d] == 0){ // oo 0
            if (item[4+d] == 0 && item[4-4*d] == 0){
                node->attackScore+=10;
            }else if (item[4+d]*item[4] == 2 && item[4-4*d]*item[4] == 2){

            }else{
                node->attackScore+=5;
            }
        }else if (item[4] == item[4-d] && item[4+2*d] == item[4] && item[4+d] == 0){ // o0 o
            if (item[4+3*d] == 0 && item[4-2*d] == 0){
                node->attackScore+=10;
            }else if (item[4+3*d]*item[4] == 2 && item[4-2*d]*item[4] == 2){

            }else{
                node->attackScore+=5;
            }
        }else if (item[4] == item[4+d] && item[4] == item[4+3*d] && item[4+2*d] == 0){ // 0o o
            if (item[4+4*d] == 0 && item[4-d] == 0){
                node->attackScore+=10;
            }else if (item[4+4*d]*item[4] == 2 && item[4-d]*item[4] == 2){

            }else{
                node->attackScore+=5;
            }
        }else if (item[4] == item[4-2*d] && item[4] == item[4-4*d] && item[4-d] == 0 && item[4-3*d] == 0) { // o o 0
            node->attackScore+=5;
        }else if (item[4] == item[4+2*d] && item[4] == item[4-2*d] && item[4-d] == 0 && item[4+d] == 0){ // o 0 o
            if (d == 1){
                node->attackScore+=5;
            }
        }
    }
}

void attack_2(Node *node,const int item[]) {
    for (int d = 1;d!=-3;d-=2) {
        if (item[4+d] == 0 && item[4+2*d] == 0 && item[4-d] == 0 && item[4-2*d] == item[4] && item[4-3*d]*item[4] == 2){ // *o-0--

        }else if (item[4+2*d] == item[4] && item[4+d] == 0 && item[4-d] == 0 && item[4-2*d] == 0 && item[4+3*d] == 0 && item[4+4*d] == 0){ // --0-o--
            node->attackScore+=1;
        }else if (item[4] == item[4+d] && item[4-3*d] == 0 && item[4-d] == 0 && item[4-2*d] == 0 && item[4+2*d] == 0 && item[4+3*d] == 0 && item[4+4*d] == 0){ // ---0o---
            node->attackScore+=1;
        }
    }
}

void attackScore(Node *node) {
    if (ifWinner(node)){
        node->attackScore+=100000;
        return;
    }
    int item[9] = {0};
    for (int k = 0;k <= 3; ++k) {
        for (int i = -4; i <= 4; ++i) {
            item[i+4] = subMap[node->X + i*dir[k][0]][node->Y + i*dir[k][1]];
        }
        attack_4(node, item);
        if (node->attackScore >= 60000) continue;
        attack_3(node, item);
        attack_2(node, item);
        defend_2(node,item);
    }
    if (node->attackScore >= 100000){
        if (node->attackScore%10000 == 12){
            node->attackScore = 70000;
        }else{
            node->attackScore = 100000;
        }
    }
}

void defend(Node *node,const int item[]) { //同级结点优先级总排名 win>遮挡四>成四>遮挡三 该分数只能在同父母的结点下有效 在大局观下其评分应为0 只defend必输棋
    int i = 1;
    while(true) {
        if (item[5]*item[5+i] != 2) break;
        i++;
    }
    int j = -1;
    while(true) {
        if (item[5]*item[5+j] != 2) break;
        j--;
    }
    if ((i - j) == 6){
        node->defendScore+=80000;// 遮挡四 优先级仅次于win
        return;
    }else if ((i - j) == 5){ // 遮挡三 优先级次于成四
        if(i == 1){
            if (item[1] == 0){
                if (item[6] != item[5]||item[0] != item[5]){
                    node->defendScore+=30000;
                }
            }
            return;
        }else if (j == -1){
            if (item[9] == 0){
                if (item[10] != item[5]||item[4] != item[5]){
                    node->defendScore+=30000;
                }
            }
            return;
        }
    }
}

void defend_2(Node *node,const int item[]){
    for (int d = 1;d != -3; d-=2) {
        if (item[4]*item[4+d] == 2 && item[4+d] == item[4+2*d]){
            if (item[4+3*d] == 0){
                node->attackScore+=2; //挡无遮挡2 oo
            }
        }
    }
}

void defendScore(Node *node) { //node需为最后一个子节点
    int item1[11] = {0};
    for (int k = 0;k <= 3;++k) {
        for (int i = -5;i <= 5;++i) {
            item1[i+5] = subMap[node->X + i*dir[k][0]][node->Y + i*dir[k][1]];
        }
        defend(node,item1);
    }
    if (node->defendScore == 160000||node->defendScore == 110000){
        node->defendScore = 80000;
    }else if (node->defendScore == 60000){
        node->defendScore = 40000;
    }
}

void defend_attack(Node *node) {
    int defend[30] = {0}; //预估不可能有超过三十个必须defend的点
    for (int i = 0,k = 0;i <= node->childrenNum-1; ++i) {
        if (node->treeChildren[i]->defendScore >= 30000) defend[k++] = node->treeChildren[i]->defendScore;
    }
    if (defend[0] == 0){
        return;
    }
    int defendNum = 0; //defendScore为80000的节点数
    for (int i = 0;i <= node->childrenNum-1; ++i) {
        if (node->treeChildren[i]->defendScore == 80000) defendNum++;
    }
    if (defendNum >= 2){
        if (node->depth == 1){
            for (int i = 0;i <= node->childrenNum-1;++i) {
                if (node->treeChildren[i]->defendScore == 80000){
                    keepTree(node->treeChildren[i]);
                    return;
                }
            }
        }
        Node* subNode1 = node;
        Node* subNode2 = node->treeParent;
        while(true){
            if (subNode2->depth == 1){
                if (subNode2->childrenNum >= 2){
                    deleteTree1(subNode1);
                }else{
                    deleteTree2(subNode1);
                }
                return;
            }
            deleteTree1(subNode1);
            if (subNode2->childrenNum >= 1) return;
            subNode2 = subNode2->treeParent;
            subNode1 = subNode2;
        }
    }
    if (defendNum == 1){
        int nodeInd = 0;
        for (int j = 0;j <= node->childrenNum-1;++j) {
            if (node->treeChildren[j]->defendScore == 80000) {
                nodeInd = j;
                break;
            }
        }
        keepTree(node->treeChildren[nodeInd]);
        return;
    }
    if (defendNum == 0){
        for (int i = 0;i <= node->childrenNum-1; ++i) {
            if (node->treeChildren[i]->attackScore%10000 >= 6) return;
        }
        for (int i = 0;i <= node->childrenNum-1; ++i) {
            if (node->treeChildren[i]->defendScore == 40000){
                keepTree(node->treeChildren[i]);
                return;
            }
        }
        for (int i = 0;i <= node->childrenNum-1; ++i) {
            if (node->treeChildren[i]->defendScore == 30000){
                keepTree(node->treeChildren[i]);
                return;
            }
        }
        return;
    }
}
