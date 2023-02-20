
#include <cstdlib>
#include "tree.h"

int map[17][17] = {0};
void deleteTree2_(Node *node);

Node* creatTree(short x,short y) {
    Node* firstNode = (Node *) malloc(sizeof(Node));
    firstNode->X = x;
    firstNode->Y = y;
    firstNode->depth = 1;
    firstNode->childrenNum = 0;
    firstNode->treeChildren[0] = nullptr;
    firstNode->treeParent = nullptr;
    firstNode->attackScore = 0;
    firstNode->defendScore = 0;
    return firstNode;
}

void addChildrenNode(Node* treeParent,short x,short y) {
    Node* node = (Node* ) malloc(sizeof(Node));
    node->childrenNum = 0;
    node->X = x;
    node->Y = y;
    node->depth = (short)(treeParent->depth + 1);
    node->attackScore = 0;
    node->defendScore = 0;
    node->treeParent = treeParent;
    treeParent->treeChildren[treeParent->childrenNum++] = node;
    node->treeChildren[0] = nullptr;
    treeParent->treeChildren[treeParent->childrenNum] = nullptr;
}

void deleteTree2_(Node *node){
    if (node->treeChildren[0] != nullptr){
        for (int i = 0;i < node->childrenNum; ++i) {
            deleteTree2_(node->treeChildren[i]);
            node->treeChildren[i] = nullptr;
        }
    }
    free(node);
}

void deleteTree2(Node* node) { // delete the tree below the head node
    if (node->treeChildren[0] != nullptr){
        for (int i = 0;i < node->childrenNum; ++i) {
            deleteTree2_(node->treeChildren[i]);
            node->treeChildren[i] = nullptr;
        }
    }
    node->childrenNum = 0;
}

void deleteTree1(Node *node) { // delete the tree, including the head node
    deleteTree2(node);
    if(node->treeParent == nullptr){
        free(node);
        return;
    }
    int nodeInd = 0;
    while(true){
        if (node == node->treeParent->treeChildren[nodeInd]) break;
        nodeInd++;
    }
    Node* subNode = node->treeParent;
    free(subNode->treeChildren[nodeInd]);
    subNode->treeChildren[nodeInd] = nullptr;
    subNode->childrenNum--;
    while(true){
        if (subNode->treeChildren[nodeInd+1] == nullptr) break;
        subNode->treeChildren[nodeInd] = subNode->treeChildren[nodeInd+1];
        subNode->treeChildren[++nodeInd] = nullptr;
    }
}

void keepTree(Node *node){ //同级结点下只保留node
    for (int i = node->treeParent->childrenNum-1;i >= 0;--i) {
        if (node->treeParent->treeChildren[i] == node){
            continue;
        }
        deleteTree1(node->treeParent->treeChildren[i]);
    }
}
