#pragma once
#include<stdio.h>
#include<stdlib.h>
struct Node {
	int data;
	Node* next;
};
Node* createList(void);
void printList(Node* head);
Node* swapList(Node* head);
int searchFirstNode(Node* head, int num);
int searchNextNode(Node* head, int num, int last);