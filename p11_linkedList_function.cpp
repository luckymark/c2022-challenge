#include"p11_linkedList.h"
Node* createList(void) {
	Node* head = NULL;
	Node* now;
	Node* tail = NULL;
	int Data;
	do {
		scanf_s("%d", &Data);
		if (Data != -1) {
			now = (Node*)malloc(sizeof(Node));
			if (now != NULL) {
				now->data = Data;
				if (head == NULL) {
					head = now;
				}
				else if (head->next == NULL) {
					head->next = now;
				}
				else { tail->next = now; }
				tail = now;
				now->next = NULL;
			}
			else { printf("error"); system("pause"); }
		}
	} while (Data != -1);//-1 is the mark of the end
	return head;
}
void printList(Node* head) {
	printf("\n");
	Node* node = head;
	while (node != NULL) {
		printf("%d ", node->data);
		node = node->next;
	}
}
Node* swapList(Node* head) {
	Node* p1, * p2, * p3;
	p1 = head;
	p2 = head->next;
	head->next = NULL;
	while (p2 != NULL) {
		p3 = p2->next;
		p2->next = p1;
		p1 = p2;
		p2 = p3;
	}
	return p1;
}
int searchFirstNode(Node* head, int num) {
	int flag = 1, flag2 = 0;
	Node* node = head;
	while (node != NULL) {
		if (node->data == num) { flag2 = 1; break; }
		node = node->next;
		++flag;
	} 
	if (flag2 == 1) {
		return flag;
	}
	else { return -1; }
}
int searchNextNode(Node* head, int num, int last) {
	int flag = 1, flag2 = 0;
	Node* node = head;
	while (node != NULL) {
		if (node->data == num && flag != last) { flag2 = 1; break; }
		node = node->next;
		++flag;
	}
	if (flag2 == 1) {
		return flag;
	}
	else { return -1; }
}