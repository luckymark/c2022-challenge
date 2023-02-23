#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "Linker.h"

pNode CreateLinkList() {

        int length,data;
        pNode pTail = NULL,p_New = NULL;

       pNode pHead = (pNode)malloc(sizeof(node)); //创头节点

       if(pHead==NULL){
           printf("内存分配失败\n");
           exit(EXIT_FAILURE);
       }//assert(pHead!=NULL);

       pHead->data=0;
       pHead->pNext=NULL;
       pTail=pHead; //不理解

        printf("请输入链表长度");
        fflush(stdout);
        scanf("%d",&length);

        for(int i=1;i<=length;i++) {
            p_New = (pNode) malloc(sizeof(node));

            if (p_New == NULL) {
                printf("内存分配失败\n");
                exit(EXIT_FAILURE);
            }

            printf("请输入第%d个节点的值\n", i);
            fflush(stdout);
            scanf("%d", &(p_New->data));

            p_New->pNext = NULL; //防止野指针
            pTail->pNext = p_New;
            pTail = p_New;

            assert(pTail->pNext==NULL);
        }

return pHead;

}

void PrintLinkList(pNode pHead){

    pNode ptem = pHead->pNext;
    printf("print:");
    fflush(stdout);

    while  (ptem!=NULL){
        printf("%d\n",ptem->data);
        fflush(stdout);
        ptem=ptem->pNext;
    }
    putchar('\n');
}

pNode insertAtStart(pNode pHead)
{int i;
    pNode p_New = (pNode)malloc(sizeof(node));

    if (p_New == NULL) {
        printf("内存分配失败\n");
        exit(EXIT_FAILURE);
    }

    printf("请输入新的节点的值\n");
    fflush(stdout);
    scanf("%d",&p_New->data);

    p_New->pNext = pHead->pNext;
    pHead->pNext = p_New;

    return pHead;
}

pNode ReverseLinkList(pNode pHead){
    pNode p_Tem,p_Next;

      p_Next=pHead->pNext;//3个指针 指向节点1，2，3
      p_Tem=p_Next->pNext;
      pHead=p_Tem->pNext;

      p_Next->pNext=NULL;//节点1 的指针域为NULL

      while((pHead!=NULL)&&(pHead->pNext!=NULL)){
          p_Tem->pNext=p_Next;

          p_Next=p_Tem;
          p_Tem=pHead;
          pHead=pHead->pNext;


      }
    p_Tem->pNext=p_Next;
    pHead->pNext=p_Tem;
    p_Tem=pHead;


    pNode p;p->data=0;p->pNext=p_Tem;//创一个行的头接下去
    pHead=p;

    return pHead;
    }

int *SearchValue(pNode pHead,int length){

    const int value = 5 ;

    int Num=0;

    int *NN; //存放NodeNumber[length]的地址

    NN=(int*)malloc(length*sizeof(int));

    pNode pTem=pHead->pNext;

    while(pTem!=NULL){

        Num+=1;

        if(pTem->data==value) {
            NN[Num - 1] = Num; }
        else {
            NN[Num - 1] = -1; }
        pTem=pTem->pNext;
    }

    return NN;
}

int Countlength(pNode pHead){
    int length=0;

    pNode pTem = pHead->pNext;

    while(pTem!=NULL){
    length+=1;
        pTem = pTem->pNext;
}
//    printf("链表长度为%d",length);
//    fflush(stdout);
    return length;

}