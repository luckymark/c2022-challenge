#include"wuziqi.h"

int stackpop(Stack* pStack) {
    return pStack->data[--pStack->sp];
}

void stackpush(Stack* pStack, int data) {
    pStack->data[pStack->sp++] = data;
}

Stack* creatRepentanceStack(int size) {
	Stack* pStack = (Stack*)malloc(sizeof(Stack));//��������ʼ���� 
	pStack->data = (int*)malloc(sizeof(int) * size);
	pStack->sp = 0;
	return pStack;
}

Stack* stack = creatRepentanceStack(510);
