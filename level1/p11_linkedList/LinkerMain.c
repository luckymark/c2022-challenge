#include "Linker.h"


void main(){
    pNode l;
    int length;
    l=CreateLinkList();// 创链表

    PrintLinkList(l); //打链表

//    insertAtStart(l); //第一个位置插入节点
    l=ReverseLinkList(l);

    PrintLinkList(l);

    length= Countlength(l);

    int *NN=NULL;//存放NodeNumber[length]的地址
    NN=SearchValue(l,length);

    for (int i=0;i<length;i++){
        printf("%2d",NN[i]);
        fflush(stdout);
    }

}
