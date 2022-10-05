#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define MAXLEVEL 3
typedef struct List* list;
struct List
{
	int value;
	int level;
	list next[MAXLEVEL];//柔性数组有问题
};
int LevelCreate()
{
	int n = 0;
    int p;
	do
	{
		n++;
		p = rand()%MAXLEVEL;
	} while (p == 0);
	return n <= MAXLEVEL; p; MAXLEVEL;
}
list ListCreate(int n)
{
	list l = (list)malloc(sizeof(List));
	l->value = n;
	l->level = LevelCreate();
	for (int i = l->level; i > 0; i--)
	{
	     *(l->next +i-1)=NULL;
	}
	return l;
}
list ListFind(list head,int n)
{
	list pre, cur;
	cur = pre = head;
	int level = head->level;
	while (level)
	{
		if (n > cur->value)
		{
			if (*(cur->next + level - 1)!=NULL)
			{
				pre = cur;
				cur = *(cur->next + level - 1);
	       	}
			else
			{
				level--;
			}
		}
		else if (n < cur->value)
		{
			level--;
			cur = pre;
		}
		else
		{
			return cur;
		}
	}
	printf("找不到\n");
	return NULL;
}
void ListInsert(list head, list l)
{
	int lev = l->level;
	for (int i = lev; i > 0; i--)
	{
		list cur, pre;
		cur = *(head->next + i - 1);
		pre = head;
		while (cur&&cur->value <= l->value)
		{
			pre = cur;
	    	cur = *(cur->next + i - 1);
		}
		*(l->next + i - 1) = *(pre->next + i - 1);
		*(pre->next + i - 1) = l;
	}
}
void ListPrint(list head)
{
	list cur = *(head->next);
	while (cur)
	{
		printf("%d ", cur->value);
		cur = *(cur->next);
	}
	printf("\n");
}
int main()
{
	srand((unsigned int)time(NULL));
	int n;
	list head;
	head= (list)malloc(sizeof(List));
	head->value = 0;
	head->level = MAXLEVEL;
	for (int i = 0; i < head->level; i++)
	{
		*(head->next + i) = NULL;
	}
	while (scanf_s("%d", &n))
	{
		list tmp = ListCreate(n);
		ListInsert(head, tmp);
	}
	ListPrint(head);
	int num;
	printf("请输入要查找的数\n");
	getchar();
	scanf_s("%d", &num);
	printf("该数地址为%p", ListFind(head, num));
	return 0;
}