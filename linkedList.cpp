#include<stdio.h>
#include<stdlib.h>
typedef struct List{
	int data;
  List*next=NULL;
}List;
List* creatlist() {
	List* head=NULL;
	List* now;
	List* tail=NULL;
	int Data;
  do{
	  scanf_s("%d", &Data);
		now = (List*)malloc(sizeof(List));
		if (now) {
			now->data = Data;
		}
		if (!head) {
			head = now;
		}
		else if (head->next == NULL) {
			head->next = now;
		}
		else {tail->next = now;}
		tail = now;	
	}	while (Data != -1);
	return head;
}
void printlist(List*list) {
	printf("\n");
	while (list) {
		if (list->data == -1) { break; }
			printf("%d ", list->data);			
		list = list->next;
	}
}
List*swaplist(List*head){
	List* p1, * p2, * p3;
	p1 = head;
	p2 = head->next;
  while(p2){
	  if (p2->data ==-1) { break; }
	  p3 = p2->next;
	  p2->next = p1;
	  p1 = p2;
	  p2 = p3;
  }
  head->next = NULL;
  return p1;
}
int searchfirstnode(List* list, int n) {
	int flag = 1, flag2=0;
	while (list) {
		if (list->data == -1) { break; }
		if (list->data == n) { flag2 = 1; break; }
		list = list->next;
		++flag;
	}
	if (flag2 == 1) {
		return flag;
	}
	else return -1;
}
int searchnextnode(List* list, int n,int last) {
	int flag = 1, flag2 = 0;
	while (list) {
		if (list->data == -1) { break; }
		if (list->data == n&&flag!=last) { flag2 = 1; break; }
		list = list->next;
		++flag;
	}
	if (flag2 == 1) {
		return flag;
	}
	else return -1;
}
int main() {
	List*list=creatlist();
	int first = searchfirstnode(list, 5), next = searchnextnode(list, 5, searchfirstnode(list, 5));
	printlist(list);
	printlist(swaplist(list));
	if (first != -1) { printf("\nNO:%d is the first 5", first); }
	if (next != -1) { printf("\nNO:%d is 5, too", next); }
	return 0;
}