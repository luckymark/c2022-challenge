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
Node* insertNode(Node* head,Node*node, int order, const char* way)
{
	int ret = -1;
	if (strcmp(way, "ahead") == 0) { ret = 1; }
	else if (strcmp(way, "behind") == 0) { ret = 2; }
	switch (ret) {
	case 1:head = insertAhead(head,node,order); break;
	case 2:insertBehind(head,node,order); break;
	default:printf("error"); system("puase"); return NULL; break;
	}
	return head;
}
Node*insertAhead(Node*head,Node*node,int order){
	Node* headNode = head;
	int flag = 1;
	if (order == 1) { node->next = head; return node; }
	else while (head->next != NULL) {
		++flag;
		if (flag == order) { node->next = head->next; head->next = node; return headNode; }
		head = head->next;
	}
	printf("error"); system("pause"); return headNode;
}
Node*insertBehind(Node*head,Node*node,int order){
	Node* headNode = head;
	int flag = 1;
	while (head!=NULL) {
		if (flag == order) {
			node->next = head->next;
			head->next = node;
			return headNode;
		}
		head = head->next;
		++flag;
	}
	printf("error"); system("pause");
	return headNode;
}
Node* insertTail(Node* head, Node* node) {
	Node* headNode = head;
	while (1) {
			if (head->next == NULL) { head->next = node; return headNode; }
			head = head->next;
	}
}
Node* deleteNode(Node*head,int order){
	Node* headNode = head;
	int flag = 1;
	if (order == 1) {
		if (head->next != NULL) {
			headNode = head->next;
			free(head);
			return headNode;
		}
		else { printf("empty"); system("pause"); return NULL; }
	}
	else while (head->next!=NULL) {
		++flag;
		if (order == flag) {
			Node* deleted = head->next;
			head->next = head->next->next;
			free(deleted);
			return headNode;
		}
		head = head->next;
	}
	printf("error"); system("pause");
	return headNode;
}
void deleteTail(Node* head) {
	Node* node = head, * last = NULL;
	if (head->next != NULL) {
		while (node->next != NULL) {
			last = node;
			node = node->next;
		}
		last->next = NULL;
		free(node);
	}
	else {
		printf("empty"); system("pause"); free(head);
	}
}