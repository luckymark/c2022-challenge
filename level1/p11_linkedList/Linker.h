#include <stdio.h>

#ifndef MY_NOTE_MD_LINKER_H
#define MY_NOTE_MD_LINKER_H

typedef struct Node{

    int data;
    struct node *pNext;
}node,*pNode;

pNode CreateLinkList();// 声明
pNode insertAtStart(pNode pHead);
void PrintLinkList(pNode pHead);
pNode ReverseLinkList(pNode pHead);
int *SearchValue(pNode pHead,int length);
int Countlength(pNode pHead);

#endif //MY_NOTE_MD_LINKER_H
