#ifndef GOBANG_LAST_EDITION_TREE_H
#define GOBANG_LAST_EDITION_TREE_H

#endif //GOBANG_LAST_EDITION_TREE_H
#define traverseWidth 9//同步遍历的正方形的宽度,必须为奇数 且 9或11
#define stepDepth 3//遍历的深度 至少为2

#define black 1
#define white 2

typedef struct Node{
    short X:8;
    short Y:8;
    short depth:8; //遍历的深度
    short childrenNum:8; // <=127
    int defendScore;
    int attackScore;
    struct Node* treeParent;//上级结点
    struct Node* treeChildren[traverseWidth*traverseWidth]; //可以链表储存下级节点地址，并设置索引创建头结点
}Node;

extern int map[17][17];

void addChildrenNode(Node* treeParent,short X,short Y); //treeParent节点下加入map[x][y]的子节点
Node* creatTree(short X,short Y); //创建头节点
void deleteTree2(Node *node); //保留该节点并彻底删除其所有子节点
void deleteTree1(Node *node); //彻底删除该根节点
void keepTree(Node *node); //在该节点的兄弟节点中只保留该节点，彻底删除其他节点
