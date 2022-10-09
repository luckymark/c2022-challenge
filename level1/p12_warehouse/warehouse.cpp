#define _CRT_SECURE_NO_DEPRECATE
//### 题目：简单进销存
//
//### 功能要求：
//
//1. 实现如下的菜单（按数字选择菜单功能）：
//- 显示存货列表
//- 入库
//- 出库
//- 退出程序
//1. 实现菜单对应功能（需记录货物的型号、数量等信息）；
//1. 程序启动时从文件中读取当前库存数据，退出时保存库存数据；

#include<stdio.h>
#include<stdlib.h>

const int MAX = 100;//存货系统中最大货品种类数

//货品结构体
struct goods
{
	char modelType[20]={0};//型号
	int num = 0;//数量
};

//存货系统结构体
struct system
{
	goods arr[MAX];//商品种类
	int size = 0;//目前个数
};
//菜单页面
void menu()
{
	puts("-----------------");
	puts("1、显示存货列表");
	puts("2、入库");
	puts("3、出库");
	puts("4、退出程序");
	puts("-----------------");
}

//显示存货列表
void show(struct system *sys)
{
	if (sys->size == 0)
	{
		printf("库存为空\n" );
	}
	else
	{
		for (int i = 0; i < sys->size; i++)
		{
			printf("型号：\t"); printf("%s\t\n", sys->arr[i].modelType);
			printf("数量：\t"); printf("%d\t\n", sys->arr[i].num);
		}
	}
	system("pause");
	system("cls");
}

//入库
void add(struct system* sys)
{
	if (sys->size == MAX)
	{
		printf("库存已满\n");
	}
	else
	{
		printf("请输入型号:\n");
		scanf_s("%s", &sys->arr[sys->size].modelType,20);
		printf("请输入数量:\n");
		scanf_s("%d", &sys->arr[sys->size].num);
	}
	sys->size++;
	puts("输入成功！\n");
	system("pause");
	system("cls");
}

//出库
int del1(struct system* sys, char nameArr[20]=0)
{
	for (int i = 0; i < sys->size; i++)
	{
		if (sys->arr[i].modelType == nameArr)
		{
			return i;
		}
		else
		{
			return 0;
		}
	}
}


void del2(struct system *sys)
{
	printf("请输入出库商品名:\n");
	char nameArr[20];
	scanf_s("%s", nameArr , 20);
	int dp = del1(sys, nameArr);

	if (dp == 0)
	{
		puts("未查询到该种商品");
	}
	else
	{
		int delNum = 0;
		puts("请输入出库后商品个数");
		scanf_s("%d", delNum);
		if (delNum == sys->arr[dp].num)
		{
			for (int j = dp; j < sys->size; j++)
			{
				sys->arr[j] = sys->arr[j + 1];
			}
			sys->size--;
			puts("删除成功");
		}
		else
		{
			puts("删改后数量");
			scanf_s("%d", sys->arr[dp].num);
			puts("修改完成");
		}
		system("pause");
		system("cls");
	}
}


//读取文件
int read(struct system* sys)
{
	FILE* fp = fopen("data.txt", "r");
	if (!fp)
	{
		printf("打开失败！\n");
		return -1; 
	}
	for (int i = 0; !feof(fp); i++)
	{
	   fscanf_s(fp,"%s %d\n",sys->arr[i].modelType, sys->arr[i].num);
	   sys->size = i+1;
	}
	fclose(fp);
}

//保存文件
int preserve(struct system* sys)
{
	FILE* fp = fopen("data.txt", "w");
	if (!fp)
	{
		printf("打开失败！\n");
		return -1; //返回异常
	}
	for (int i = 0; !feof(fp); i++)
	{
		fprintf(fp, "%s %d\n", sys->arr[i].modelType, sys->arr[i].num);
	}
	fclose(fp);
	return 0;

}

int main()
{
	struct system sys;
	sys.size = 0;
	int select1 = 0;
	read(&sys);
	while (1)
	{
		menu();
		scanf_s("%d", &select1);
		switch (select1)
		{
		case 1:
			show(&sys);
			break;
		case 2:
			add(&sys);
			break;
		case 3:
			del2(&sys);
			break;
		case 4:
			preserve(&sys);
			system("pause");
			return 0;
		default:
			puts("输入错误");
			system("pause");
			system("cls");
		}
	}
	system("pause");
	return 0;
}