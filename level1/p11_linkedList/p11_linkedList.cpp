#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

struct node
{
	int data;
	struct node *next;
};

void begin(struct node *headNode);//�������� 
void createNode(struct node *headNode,int data);//ͷ�巨��������
void printList(struct node *headNode);//��ӡ���� 
void reprint(struct node *headNode);//�����ӡ 
void Find_Five(struct node *headNode);//����5 

int main()
{
	struct node *headNode;//ͷ������
	headNode = (struct node*)malloc(sizeof(struct node));
	headNode->next=NULL;
	begin(headNode);
	printList(headNode);
	reprint(headNode->next);
	cout<<endl;
	Find_Five(headNode); 
	system("pause");
	return 0;
}


void begin(struct node *headNode)
{
	while(1)
	{
		cout<<"��������밴y"<<endl;
		cout<<"ֹͣ��������밴n"<<endl;
		char c;
		cin>>c;
		if(c=='y')
		{
			cout<<"��������Ҫ��ӵ����ݣ�"; 
			int data;
			cin>>data;
			createNode(headNode,data);
			cout<<endl;
		}
		else if(c=='n')
		{
			break;
		}
		else
		{
			cout<<"������������������";
		}
	}
}


void createNode(struct node *headNode,int data)
{
	struct node *newNode=(struct node*)malloc(sizeof(struct node));
	newNode->data=data;
	newNode->next=headNode->next;
	headNode->next=newNode;
}


void printList(struct node *headNode)
{
	struct node *pMove=headNode->next;
	while(pMove)
	{
		printf("%d ",pMove->data);
		pMove=pMove->next; 
	}
	printf("\n");
}


void reprint(struct node *headNode)
{
	if(headNode->next==NULL)
	{
		cout<<headNode->data<<" ";
		return;
	}
	reprint(headNode->next);
	cout<<headNode->data<<" "; 
}

void Find_Five(struct node *headNode)
{
	struct node *pMove=headNode->next;
	int n=1,k=0;
	while(pMove)
	{
		if(pMove->data==5)
		{
			k++;
			if(k==1)
			{
				cout<<"���½ڵ��ֵΪ5��"<<endl;
			}
			cout<<n<<' ';
		}
		n++;
		pMove=pMove->next; 
	}
	if(k=0)
	{
		cout<<"���Ҳ����κνڵ��ֵΪ5"<<endl<<"����"<<k-1;
	}
		
}
