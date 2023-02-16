#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#define MAX 1000
using namespace std;
struct things
{
	string name;//��������� 
	string type;//������ͺ� 
	int sum;//��������� 
};
struct systems
{
	struct things goods[MAX];
	int num;//�ֿ�����������Ŀ 
};
void Welcome();//��ʾ���������� 
void Print_warehouse(systems *warehouse);//չʾ�����嵥 
void In_warehouse(systems *warehouse);//��� 
void Out_warehouse(systems *warehouse);//���� 
int Exist(systems *warehouse,string name,string type);//�жϻ����Ƿ���� 
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
		cout<<"��������Ҫ���еĲ���"<<endl;
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
				cout<<"��ӭ�´�ʹ��"<<endl;
				freopen("test.txt","w",stdout);
				for(int i=1;i<=warehouse.num;i++)
				{
					cout<<i<<"�Ż���"<<"   "<<"�������ƣ�"<<warehouse.goods[i].name<<"   "<<"���ͣ�"<<warehouse.goods[i].type<<"   "<<"������"<<warehouse.goods[i].sum<<endl;
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
	cout<<"--------------------1:��ʾ����б�----------------------"<<endl;
	cout<<"--------------------2:���------------------------------"<<endl;
	cout<<"--------------------3:����------------------------------"<<endl;
	cout<<"--------------------4:�˳�����--------------------------"<<endl; 
	cout<<"--------------------------------------------------------"<<endl;
}
void Print_warehouse(systems *warehouse)
{
	int i;
	if(warehouse->num>0)
	{
		for(i=1;i<=warehouse->num;i++)
		{
			cout<<i<<"�Ż���"<<"   "<<"�������ƣ�"<<warehouse->goods[i].name<<"   "<<"���ͣ�"<<warehouse->goods[i].type<<"   "<<"������"<<warehouse->goods[i].sum<<endl;
		}
	}
	else
	{
		cout<<"���޻�����Ϣ"<<endl;
	}
	system("pause");
	system("cls");
}
void In_warehouse(systems *warehouse)
{
	cout<<"�㽫Ҫ��⼸�ֻ��"<<endl;
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		string name;
		string type;
		int sum;
		cout<<"��������Ҫ�����������:"<<endl;		
		cin>>name;
		cout<<"��������������ͺţ�"<<endl;
		cin>>type;
		cout<<"��������Ҫ����û����������"<<endl;
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
	cout<<"���ɹ���"<<endl;
	system("pause");
	system("cls");
}
void Out_warehouse(systems *warehouse)
{
	if(warehouse->num==0)
	{
		cout<<"�ֿ���ʱ�޻���"<<endl;
		system("pause");
		system("cls");		
		return ;
	}
	cout<<"�㽫Ҫ���⼸�ֻ��"<<endl;
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		string name;
		string type;
		int sum;
		cout<<"��������Ҫ������������:"<<endl;		
		cin>>name;
		cout<<"��������������ͺţ�"<<endl;
		cin>>type;
		cout<<"��������Ҫ����û����������"<<endl;
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
			cout<<"������Ϣ��������������"<<endl;
			i--;
		}
	}
	cout<<"����ɹ���"<<endl;
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
