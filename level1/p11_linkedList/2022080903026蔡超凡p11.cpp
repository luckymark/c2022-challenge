#include <iostream>
using namespace std;
struct node
{
	int value;
	node* next;
};

int amount = 0;//�ڵ���� ��1��ʼ����
int number = 1;//ֵΪ5�Ľڵ�����
static node* n = new node;

void traverse(node* head);
int findfive(node* head);
int findnextfive();
void up_side_down(node* head, node* end);
void main()
{
	
	node* head = new node;  //����ͷ�ڵ�
	node* end = new node;  //����β�ڵ�
	end = head;
	while (true)  //������������
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


//�ڵ�����
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






//��������
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

//����ֵΪ5�Ľڵ�
int findfive(node* head)
{
	n = head;
	for(int i = 1;i < amount;i++)
	{
		if (n->value == 5)
		{
			cout << "ֵΪ5�Ľڵ���" << number << endl;
			return number;
			break;
		}
		number++;
		n = n->next;
	}
	return -1;
}

//������һ��ֵΪ5�Ľڵ�
int findnextfive()
{
	for (int i = number; i < amount-1; i++)
	{
		n = n->next;
		number++;
		if (n->value == 5)
		{
			cout << "��һ��ֵΪ5�Ľڵ���" << number << endl;
			return number;
			break;
		}
	}
	return -1;
}