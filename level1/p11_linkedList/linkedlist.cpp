#include<stdio.h>
#include<stdlib.h>
typedef struct List* list;
struct List
{
	int value;
	list next;
};
list ListCreate(int n,list tail)
{
	list l = (list)malloc(sizeof(list));
	l->value = n;
	l->next = NULL;
	return l;
}
void ListPrint(list head)
{
	while (head)
	{
		printf("%d ", head->value);
		head = head->next;
	}
	printf("\n");
}
list ListReversal(list head)
{
	list pre, cur, next;
	pre = head;
	cur = pre->next;
	next = cur->next;
	pre->next = NULL;
	while (next)
	{
		cur->next = pre;
		pre = cur;
		cur = next;
		next = next->next;
	}
	cur->next = pre;
	return cur;
}
int ListFind(int num,int time, list head)
{
	int n = 0;
	int t = 0;
	list cur = head->next;
	while (t<time&&cur)
	{
		if (cur->value == num)
		{
			t++;
		}
		n++;
		cur = cur->next;
	}
	if (t==time)
	{
		return n;
	}
	else
	{
		return -1;
	}
}
int main()
{
	list head = (list)malloc(sizeof(list));
	head->value = 0;
	head->next = NULL;
	int tmp;
	list tail = head;
	printf("输入数字增加链表，输入其他符号结束\n");
	while (scanf_s("%d", &tmp))
	{
		tail->next=ListCreate(tmp, tail);
		tail = tail->next;
		head->value++;
	}
	getchar();
	ListPrint(head->next);
	head->next=ListReversal(head->next);
	ListPrint(head->next);
	printf("请输入查找数和第几个\n");
	int num, time;
	scanf_s("%d%d", &num, &time);
	int i = ListFind(num, time, head);
	printf("该数字的序号为%d", i);
	return 0;
}