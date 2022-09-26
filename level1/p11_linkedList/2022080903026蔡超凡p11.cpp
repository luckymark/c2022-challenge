#include <iostream>
using namespace std;
struct node
{
	int value;
	node* next;
};

int amount = 0;//节点个数 从1开始计算
int number = 1;//值为5的节点的序号
static node* n = new node;

void traverse(node* head);
int findfive(node* head);
int findnextfive();
void up_side_down(node* head, node* end);
void main()
{
	
	node* head = new node;  //链表头节点
	node* end = new node;  //链表尾节点
	end = head;
	while (true)  //创建单向链表
	{
		cin >> end->value;
		amount++;
		if (end->value == 0)
		{
			break;
		}
		node* temp = new node;
		end->next = temp;
		end = temp;
	}
	traverse(head);
	findfive(head);
	findnextfive();
	up_side_down(head, end);
}


//节点逆向
void up_side_down(node* head,node* end)
{
	int x=0;
	node* temp_end = end, * temp0 = NULL;
	for (int i = 1; i < amount; i++)
	{
		node* temp_front = head, * temp_back = head;
		for (int j = 1; j < amount - x ; j++)
		{
			temp_back = temp_back->next;
			if (j < amount - x - 1)
			{
				temp_front = temp_front->next;
			}
		}
		if (x > 0)
		{
			temp0 = temp_back;
		}
		temp_back = temp_front;
		temp_back->next = temp_front;
		if (x > 0)
		{
			temp0->next = temp_back;
		}
		if (x == 0)
		{	
			temp_end->next = temp_back;
		}
		if (x == amount - 3)
		{
			temp_back = head;
		}
	
		x++;
	}
	head = temp_end;
	traverse(head);

}






//遍历链表
void traverse(node* head)
{
	node* temp = new node;
	temp = head;
	for(int i = 0;i < amount;i++)
	{
		cout << temp->value << " ";
		temp = temp->next;
	}
}

//查找值为5的节点
int findfive(node* head)
{
	n = head;
	for(int i = 1;i < amount;i++)
	{
		if (n->value == 5)
		{
			cout << "值为5的节点是" << number << endl;
			return number;
			break;
		}
		number++;
		n = n->next;
	}
	return -1;
}

//查找下一个值为5的节点
int findnextfive()
{
	for (int i = number; i < amount-1; i++)
	{
		n = n->next;
		number++;
		if (n->value == 5)
		{
			cout << "下一个值为5的节点是" << number << endl;
			return number;
			break;
		}
	}
	return -1;
}