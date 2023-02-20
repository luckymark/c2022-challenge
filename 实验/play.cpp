//
// Created by Administrator on 22/11/2022.
//
#include "play.h"
#include <cstdlib>
#include <cassert>

void traverse(Node *node);

static int traverseHalfWidth = traverseWidth/2;

void traverse(Node *node) { //在node节点下围绕map[x][y]遍历traverseWidth*traverseWidth方格生成子节点
    for (int i = -traverseHalfWidth; i <= traverseHalfWidth; ++i) {
        for (int j = -traverseHalfWidth; j <= traverseHalfWidth; ++j) {
            if (cut(node->X+i,node->Y+j,node)){
                addChildrenNode(node,(short)(node->X+i),(short)(node->Y+j));
                attackScore(node->treeChildren[node->childrenNum-1]);
                if (node->attackScore >= 100000){
                    return;
                }
                defendScore(node->treeChildren[node->childrenNum-1]);
                if (node->depth < stepDepth-1){
                    traverse(node->treeChildren[node->childrenNum-1]);
                }
            }
        }
    }
    defend_attack(node);
    if (node->treeChildren[0] == nullptr) return;
    if (node->treeChildren[0]->depth%2 == 1 && node->childrenNum >= 2){ //判定是否为人方，若为则只取最强手
        int max = node->treeChildren[0]->attackScore;
        int maxInd = 0;
        for (int i = 1; i < node->childrenNum; ++i) {
            if (node->treeChildren[i]->attackScore > max){
                max = node->treeChildren[i]->attackScore;
                maxInd = i;
            }
        }
        keepTree(node->treeChildren[maxInd]);
        return;
    }
    int index = 0;
    for (int i = 0;i <= node->childrenNum-1; ++i) {
        if (node->treeChildren[i]->attackScore <= 20000) continue;
        if (node->treeChildren[i]->attackScore > node->treeChildren[index]->attackScore) index = i;
    }
    if (index != 0){
        keepTree(node->treeChildren[index]);
    }else{
        if (node->treeChildren[0]->attackScore >= 20000) keepTree(node->treeChildren[0]);
    }
}


Node *playAI(short x,short y) {
    Node *node = creatTree(x,y);
    traverse(node);
    Node *AIStep = (Node *) malloc(sizeof(Node));
    AIStep->X = cmpScore(node)->X;
    AIStep->Y = cmpScore(node)->Y;
    map[AIStep->X][AIStep->Y] = white;
    deleteTree1(node);
    return AIStep;
}
