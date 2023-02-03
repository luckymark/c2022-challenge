#include <stdio.h>
#include <stdlib.h>
#include "HanLo.h"



//void main(){
//
//    int data;
//    pstack ST;
//    ST = creatStack(Size);//创堆栈
//
//    for (int i; i<len; i++) {
//        scanf("%d", &data);//接受数据
//        push(ST, data);
//    }
//
//    for (int i; i<len; i++) {
//        printf("%d",pop(ST));
//    }
//
//
//
//}

pstack creatStack(int i){
    pstack pStack;
    pStack = (pstack)malloc(sizeof(stack));
    pStack->data = (int*) malloc(sizeof(int)*i);

    pStack->sp = 0;

}

void push(pstack pStack,int NewData){

    pStack->sp +=1;
    pStack->data[pStack->sp] = NewData;


}

int pop(pstack pStack){
    int result;

    while((pStack->sp)>0) {
        result = pStack->data[pStack->sp];
        pStack->data[pStack->sp] = 0;

        pStack->sp -= 1;

        return result;
    }

    return ' ';
}