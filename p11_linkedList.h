#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Node {
	int data;
	struct Node* next;
};
Node* createList(void);
void printList(Node* head);
Node* swapList(Node* head);
int searchFirstNode(Node* head, int num);
int searchNextNode(Node* head, int num, int last);
Node* insertNode(Node*head,Node*node,int order,const char*way);
Node* insertAhead(Node* head, Node* node, int order);
Node* insertBehind(Node* head, Node* node, int order);
Node* insertTail(Node*head,Node*node);
Node*deleteNode(Node*head,int order);
void deleteTail(Node*head);