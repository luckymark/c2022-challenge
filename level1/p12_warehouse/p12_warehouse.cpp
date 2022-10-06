#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#define MAX 1000
using namespace std;
struct things
{
	string name;//货物的名称 
	string type;//货物的型号 
	int sum;//货物的数量 
};
struct systems
{
	struct things goods[MAX];
	int num;//仓库货物种类的数目 
};
void Welcome();//显示操作项提醒 
void Print_warehouse(systems *warehouse);//展示货物清单 
void In_warehouse(systems *warehouse);//入库 
void Out_warehouse(systems *warehouse);//出库 
int Exist(systems *warehouse,string name,string type);//判断货物是否存在 
int main()
{
	//freopen("test.txt","r",stdin);
	//freopen("test.txt","w",stdout);
	systems warehouse;
	warehouse.num=0;
	int a=0;
	while(1)
	{
		Welcome();
		cout<<"请输入你要进行的操作"<<endl;
		cin>>a;
		switch(a)
		{
			case 1:
			{
				Print_warehouse(&warehouse);
				break;
			}
			case 2:
			{
				In_warehouse(&warehouse);
				break;
			}
			case 3:
			{
				Out_warehouse(&warehouse);
				break;
			}
			case 4:
			{
				cout<<"欢迎下次使用"<<endl;
				freopen("test.txt","w",stdout);
				for(int i=1;i<=warehouse.num;i++)
				{
					cout<<i<<"号货物"<<"   "<<"货物名称："<<warehouse.goods[i].name<<"   "<<"类型："<<warehouse.goods[i].type<<"   "<<"数量："<<warehouse.goods[i].sum<<endl;
				}
				return 0;
				break;
			}
		}
	}
	//fclose(stdin);
	//fclose(stdout);
	return 0;
}
void Welcome()
{
	cout<<"--------------------------------------------------------"<<endl;
	cout<<"--------------------1:显示存货列表----------------------"<<endl;
	cout<<"--------------------2:入库------------------------------"<<endl;
	cout<<"--------------------3:出库------------------------------"<<endl;
	cout<<"--------------------4:退出程序--------------------------"<<endl; 
	cout<<"--------------------------------------------------------"<<endl;
}
void Print_warehouse(systems *warehouse)
{
	int i;
	if(warehouse->num>0)
	{
		for(i=1;i<=warehouse->num;i++)
		{
			cout<<i<<"号货物"<<"   "<<"货物名称："<<warehouse->goods[i].name<<"   "<<"类型："<<warehouse->goods[i].type<<"   "<<"数量："<<warehouse->goods[i].sum<<endl;
		}
	}
	else
	{
		cout<<"暂无货物信息"<<endl;
	}
	system("pause");
	system("cls");
}
void In_warehouse(systems *warehouse)
{
	cout<<"你将要入库几种货物："<<endl;
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		string name;
		string type;
		int sum;
		cout<<"请输入你要入库货物的名称:"<<endl;		
		cin>>name;
		cout<<"请输入入库货物的型号："<<endl;
		cin>>type;
		cout<<"请输入你要进库该货物的数量："<<endl;
		cin>>sum;
		int k=Exist(warehouse,name,type);
		if(k>0)
		{
			warehouse->goods[k].sum+=sum;
		}
		else
		{
			warehouse->num++; 
			warehouse->goods[warehouse->num].name=name;
			warehouse->goods[warehouse->num].type=type;
			warehouse->goods[warehouse->num].sum=sum;
		}
	}
	cout<<"入库成功！"<<endl;
	system("pause");
	system("cls");
}
void Out_warehouse(systems *warehouse)
{
	if(warehouse->num==0)
	{
		cout<<"仓库暂时无货物"<<endl;
		system("pause");
		system("cls");		
		return ;
	}
	cout<<"你将要出库几种货物："<<endl;
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		string name;
		string type;
		int sum;
		cout<<"请输入你要出库货物的名称:"<<endl;		
		cin>>name;
		cout<<"请输入出库货物的型号："<<endl;
		cin>>type;
		cout<<"请输入你要出库该货物的数量："<<endl;
		cin>>sum;
		int k=Exist(warehouse,name,type);
		if(k>0 || sum==warehouse->goods[k].sum)
		{
			for(;k<=warehouse->num;k++)
			{
				warehouse->goods[k].name=warehouse->goods[k+1].name;
				warehouse->goods[k].type=warehouse->goods[k+1].type;
				warehouse->goods[k].sum=warehouse->goods[k+1].sum;	
			}
			warehouse->num--;
		}
		else if(k>0 &&sum<warehouse->goods[k].sum)
		{
			warehouse->goods[k].sum-=sum;
		}
		else
		{
			cout<<"输入信息有误，请重新输入"<<endl;
			i--;
		}
	}
	cout<<"出库成功！"<<endl;
	system("pause");
	system("cls");
}
int Exist(systems *warehouse,string name,string type)
{
	int k=0;
	for(int i=0;i<=warehouse->num;i++)
	{
		if(name==warehouse->goods[i].name && type==warehouse->goods[i].type)
		{
			k=i;
			break;
		}
	}
	return k;
}
