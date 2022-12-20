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