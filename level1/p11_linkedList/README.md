### 题目：单向链表

### 功能要求：

1. 在 main 函数中创建一个单向链表；
1. 遍历该链表，依次现实各节点的 value；
1. 将该链表所有节点反序；
1. 在该链表中查找第一个值为 5 的节点，如
果找到则返回该节点的序号，否则返回－1；
1. 查找下一个值为 5 的节点，返回值同上；

### 技能强化（彻底搞定指针）：

欢迎大神们都去玩玩这个：
[Level2-实现 SkipList 算法](../../level2/SkipList/Readme.md)
```
#include<iostream>
using namespace std;

struct node
{
	int num;
	node* next;
};
node* createlist(int n)
{
	node* tmp = NULL, * head = NULL, *tail = NULL;
	head = new node;
	int num;
	cin >> num;
	head->num = num;
	head->next = NULL;
	tail = head;
	for (int i = 0; i < n - 1; i++)
	{
		cin >> num;
		tmp = new node;
		tmp->num = num;
		tmp->next = NULL;
		tail->next = tmp;
		tail = tmp;
	}
	return head;
}
node* delet(int n,node *head)
{
	node* tmp = head;
	while(head->num == n)
	{
		tmp->next = head;
		delete tmp;
		tmp = head;
	}
	node* cur = tmp->next;
	while (cur!=NULL)
	{
		if (cur->num == n)
		{
			tmp->next = cur->next;
			delete cur;
		}
		else
			tmp = tmp->next;
		cur = tmp->next;
	}
	return head;
}

node* reverse(node* head)
{
	node* cur = head->next;
	head->next = NULL;
	while (cur)
	{
		node* tmp = new node;
		node* t = cur;
		tmp->num = cur->num;
		tmp->next = head;
		head = tmp;
		cur = cur->next;
		delete t;
	}
	return head;
}
int find(node* head,int a)
{
	if (a == -1)
		return -1;
	int n = a;
	for (int i = 0; i < a; i++)
		head = head->next;
	while (head)
	{
		n++;
		if (head->num == 5)
			break;
		head = head->next;
	}
	return a;
}
int main()
{
	int n;
	cin >> n;
	node* tmp = createlist(n);
	tmp=delet(3,tmp);
	tmp = reverse(tmp);
	node* head = tmp;
	n=find(head,1);
	cout << n << endl;
	n=find(head, n);
	cout << n << endl;
	while (tmp != NULL)
	{
		cout << tmp->num << " ";
		tmp = tmp->next;
	}
	return 0;
}
```