//
// Created by 18165 on 28/10/2022.
//
#include <stdio.h>
#ifndef MY_NOTE_MD_HANLO_H
#define MY_NOTE_MD_HANLO_H


//const int Size = 10,len=5;

typedef struct stack{
    int *data;
    int sp;

}*pstack,stack;

pstack creatStack(int i);
void push(pstack pStack,int NewData);
int pop(pstack pStack);

#endif //MY_NOTE_MD_HANLO_H
