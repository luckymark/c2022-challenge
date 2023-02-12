#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>

struct Goods{
	char name[20];
	int total;
	int length;
	int width;
	int height;
}goods[1000];

int num=0;

void menu()
{
	 printf("               欢迎进入仓库系统            \n");
	 printf("************************************************\n");
	 printf("            1、显示存货列表\n");
	 printf("            2、入库               \n");
	 printf("            3、出库               \n");
	 printf("            4、退出系统               \n");
	 printf("************************************************\n");
	//菜单界面
}

void list()
{
	if(num==0) {
		printf("            当前仓库并无货物\n");
		getchar();
	}
	else {
		printf("%10s%10s%8s%8s%8s\n","货物名称","数量","长度","宽度","高度");
		printf("---------------------------------------------------\n");
		for(int i=0;i<num;++i) {
			printf("%8s%10d%9d%9d%8d\n",goods[i].name,goods[i].total,goods[i].length,goods[i].width,goods[i].height);
		}
		getchar();
	}
	printf("是否继续操作?(y/n)");
	if (getchar()=='n')	{
	    exit(0);
	}
}

int search(char name[])
{
	for(int i=0;i<num;++i) {
		if(strcmp(goods[i].name,name)==0) {
			return i;
		}
	}
	return -1;
}

void add()
{
	while(1)
	     {
	         printf("请输入货物名:");
	         scanf("%s",&goods[num].name);
	         getchar();
	         printf("请输入货物数量:");
	         scanf("%d",&goods[num].total);
	         getchar();
	         if(search(goods[num].name) != -1) {
			 	int temp=search(goods[num].name);
			 	goods[temp].total+=goods[num].total;
			 }
			 else {
			 	printf("请输入货物长度:");
				scanf("%d",&goods[num].length);
				getchar();
				printf("请输入货物宽度:");
				scanf("%d",&goods[num].width);
				getchar();
				printf("请输入货物高度:");
				scanf("%d",&goods[num].height);
				getchar();
				num++;//移向下一个位置
			 }
	 		 printf("是否继续?(y/n)");
	         if (getchar()=='n')
	         {
	              break;
	         }
	         system("cls");
	     }
}

void deletee()
{
	while(1)
		     {
		         char outGoods[100];
		         int outNum;
		         int outTemp;
		         if(num==0) {
				 	printf("仓库内无货物\n");
				 	printf("是否继续？(y/n)");
				 	getchar();
				 	char ch2=getchar();
				 	if (ch2=='n') exit(0);
				 	
				 	else if(ch2=='y') {
				 		Sleep(1000);
						break;
					}
		         }
				 printf("请输入要出库的货物名:");
		         scanf("%s",&outGoods);
		         getchar();
		         if(search(outGoods) == -1) {
				 	printf("货物不存在");
				 }
				 else {
				 	outTemp=search(outGoods);
				 	printf("仓库内该货物数量为:%d\n",goods[outTemp].total);
					printf("请输入出库数量:");
					scanf("%d",&outNum);
			        getchar();
			        if(outNum>goods[outTemp].total) {
						printf("该货物数量不足，无法出库\n");
					}
					else {
						goods[outTemp].total-=outNum;
						printf("货物出库成功\n");
						if(goods[outTemp].total==0) {
							for(int i=outTemp;i<num-1;++i) {
								strcpy(goods[i].name,goods[i+1].name);
								goods[i].total=goods[i+1].total;
								goods[i].length=goods[i+1].length;
								goods[i].width=goods[i+1].width;
								goods[i].height=goods[i+1].height;
							}
							num--;
						}
					}
				 }
		 		 printf("是否继续?(y/n)");
		         if (getchar()=='n')
		         {
		              break;
		         }
		         system("cls");
		     }
}

void Load()
{
	FILE*fp = fopen("warehouse.txt","r");
	fscanf(fp,"%d",&num);
	for(int i = 0 ; i< num ;i++)
	{
		fscanf(fp,"%s %d %d %d %d\n",goods[i].name,&goods[i].total,&goods[i].length,&goods[i].width,&goods[i].height);
	}
	fclose(fp);
}

void Save()
{
	FILE*fp = fopen("warehouse.txt","w+");
	fprintf(fp,"%d\n",num);
	for(int i = 0 ; i< num ;i++)
	{
		fprintf(fp,"%s %d %d %d %d\n",goods[i].name,goods[i].total,goods[i].length,goods[i].width,goods[i].height);
	}
	fclose(fp);
}

int main()
{
	menu();
	int n;
	while(1) {
		Load();
		printf("            请选择你所需要的服务:");
		scanf("%d",&n);
		system("cls");
		switch(n) {
			case(1):list();break;
			case(2):add();break;
			case(3):deletee();break;
			case(4):exit(0);
			default:
				{
					printf("输入有误，请重新输入");
					scanf("%d",&n);
					getchar();
				}
			break;
		}
		system("cls");
		menu();
		Save();
	}
}
