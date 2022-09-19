### 题目：简单进销存

### 功能要求：

1. 实现如下的菜单（按数字选择菜单功能）：
	- 显示存货列表
	- 入库
	- 出库
	- 退出程序
1. 实现菜单对应功能（需记录货物的型号、数量等信息）；
1. 程序启动时从文件中读取当前库存数据，退出时保存库存数据；
```
#include<iostream>
#include<stdio.h>
#include<fstream>
#include<conio.h>
using namespace std;

struct store
{
	char name[10];
	int num;
	store* next;
};
store *head=NULL,*tail=NULL;
void create()
{
	store * tmp;
	head= new store;
	head->next = NULL;
	FILE* fp = fopen("list.txt", "r");
	fscanf(fp, "%s%d", head->name, &(head->num));
	tail = head;
	tmp = new store;
	while (fscanf(fp, "%s%d", tmp->name, &tmp->num) != EOF)
	{
		tmp->next = NULL;
		tail->next = tmp;
		tail = tmp;
		tmp = new store;
	}
	fclose(fp);
}
void print()
{
	printf("\n");
	printf("实现如下的菜单（按数字选择菜单功能）：\n");
	printf("1- 显示存货列表\n");
	printf("2- 入库\n");
	printf("3- 出库\n");
	printf("esc- 退出程序\n");
	printf("\n");
}
void input()
{
	char a[10];
	printf("请输入需要增加的物品：");
	cin >> a;
	store *tmp = head;
	int flag = 0;
	while (tmp)
	{
		if (strcmp(a,tmp->name)==0)
		{
			printf("请输入增加的个数：");
			int n;
			cin >> n;
			head->num += n;
			flag = 1;
			break;
		}
		tmp = tmp->next;
	}
	if (flag == 0)
		cout << "未找到该物品。";
}
void output()
{
	char a[10];
	printf("请输入需要取出的物品：");
	cin >> a;
	store* tmp = head;
	int flag = 0;
	while (tmp)
	{
		if (strcmp(a, tmp->name) == 0)
		{
			printf("请输入取出的个数：");
			int n;
			cin >> n;
			head->num -= n;
			flag = 1;
			break;
		}
		tmp = tmp->next;
	}
	if (flag == 0)
		cout << "未找到该物品。";
}
void out()
{
	store* tmp = head;
	while (tmp)
	{
		cout << tmp->name << '\t';
		tmp = tmp->next;
	}
	cout << endl;
	tmp = head;
	while (tmp)
	{
		cout << tmp->num << '\t';
		tmp = tmp->next;
	}
}
void filein()
{
	store* tmp=head;
	FILE* fp = fopen("list.txt", "w");
	while (tmp)
	{
		fprintf(fp, "%s\t%d\n",tmp->name,tmp->num);
		tmp = tmp->next;
	}
	fclose(fp);
}
int main()
{
	create();
	print();
	int flag = getch();
	cout << endl;
	switch (flag)
	{
	case 27:
		return 0;
	case 49:
		out();
		break;
	case 50:
		input();
		break;
	case 51:
		output();
		break;
	}
	system("cls");
	filein();
	cout << "以下是现有库存"<<endl;
	out();
	return 0;
}
```