#include<stdio.h>
#include<stdlib.h>

struct Node{
	int data;
	struct Node* next;
};

struct Node* createList()
{
	struct Node* headnode = (struct Node*)malloc(sizeof(struct Node));
	headnode->next = NULL;
	return headnode;	
}

struct Node* createNode(int data)
{
	struct Node* newnode = (struct Node*)malloc(sizeof(struct Node*));
	newnode->data = data;
	newnode->next = NULL;
	return newnode;	
}

void printList(struct Node* headnode)
{
	struct Node* pMove = headnode->next;
	while(pMove != NULL) {
		printf("%d ",pMove->data);
		pMove = pMove->next;
	}
}

void headinsert(struct Node* headnode,int data)
{
	struct Node* newnode = createNode(data);
	newnode->next = headnode->next;
	headnode->next = newnode;
}

void tailinsert(struct Node* headnode,int data)
{
	struct Node* newnode = createNode(data);
	struct Node* pMove = headnode;
	while(pMove->next) {
		pMove = pMove->next;
	}
	pMove->next = newnode;
}

void deleteData(struct Node* headnode,int data)
{
	struct Node* posnode = headnode->next;
	struct Node* posnodefront = headnode;
	if(posnode == NULL) {
		printf("无法删除");
		return;
	}
	while(posnode->data != data) {
		posnodefront = posnode;
		posnode = posnode->next;
		if(posnode == NULL) {
			printf("未找到指定位置");
			return;
		}	
	}
	posnodefront->next = posnode->next;
	free(posnode);
}

int search(struct Node* headnode,int num,int times)
{
	struct Node* newnode = headnode->next;
	int order = 1;
	int tot = 1;
	while(1)
	{
		if(newnode == NULL) return -1;
			if(newnode->data == num && tot == times) return order;
			else {
				if(newnode->data == num) tot++;
				newnode = newnode->next;
				order++;
			}
	}
}

void turn(struct Node* headnode)
{
	struct Node* pMove = headnode->next;
	struct Node* nMove;
	if(pMove == NULL) {
		printf("The list doesn't exist");
	}
	struct Node* qMove = pMove->next;
	pMove->next = NULL;
	while(1) {
		if(qMove == NULL) break;
		nMove = qMove->next;
		if(nMove == NULL) {
			qMove->next = pMove;
			headnode->next = qMove;
			break;
		}
		else {
			qMove->next = pMove;
			pMove = qMove;
			qMove = nMove;
			nMove = nMove->next;
		}
	}
	return;
}

int main()
{
	struct Node* list=createList();
	headinsert(list,1);
	headinsert(list,2);
	headinsert(list,5);
	headinsert(list,3);
	headinsert(list,5);
	printList(list);
	deleteData(list,2);
	printf("\n");
	printList(list);
	/*tailinsert(list,1);
	tailinsert(list,3);
	tailinsert(list,5);
	tailinsert(list,2);
	tailinsert(list,5);
	printList(list);
	printf("\n");
	deleteData(list,2);
	printList(list);
	printf("\n");*/
	int find = search(list,5,1);
	printf("%d\n",find);
	find = search(list,5,2);
	printf("%d\n",find);
	turn(list);
	printList(list);
	printf("\n");
	return 0;
}
