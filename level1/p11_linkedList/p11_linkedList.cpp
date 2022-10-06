#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

struct node
{
	int data;
	struct node *next;
};

void begin(struct node *headNode);//输入数据 
void createNode(struct node *headNode,int data);//头插法构建链表
void printList(struct node *headNode);//打印链表 
void reprint(struct node *headNode);//逆序打印 
void Find_Five(struct node *headNode);//查找5 

int main()
{
	struct node *headNode;//头部链表
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
		cout<<"添加数据请按y"<<endl;
		cout<<"停止添加数据请按n"<<endl;
		char c;
		cin>>c;
		if(c=='y')
		{
			cout<<"请输入你要添加的数据："; 
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
			cout<<"输入有误，请重新输入";
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
				cout<<"以下节点的值为5："<<endl;
			}
			cout<<n<<' ';
		}
		n++;
		pMove=pMove->next; 
	}
	if(k=0)
	{
		cout<<"查找不到任何节点的值为5"<<endl<<"返回"<<k-1;
	}
		
}
