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
	 printf("               ��ӭ����ֿ�ϵͳ            \n");
	 printf("************************************************\n");
	 printf("            1����ʾ����б�\n");
	 printf("            2�����               \n");
	 printf("            3������               \n");
	 printf("            4���˳�ϵͳ               \n");
	 printf("************************************************\n");
	//�˵�����
}

void list()
{
	if(num==0) {
		printf("            ��ǰ�ֿⲢ�޻���\n");
		getchar();
	}
	else {
		printf("%10s%10s%8s%8s%8s\n","��������","����","����","���","�߶�");
		printf("---------------------------------------------------\n");
		for(int i=0;i<num;++i) {
			printf("%8s%10d%9d%9d%8d\n",goods[i].name,goods[i].total,goods[i].length,goods[i].width,goods[i].height);
		}
		getchar();
	}
	printf("�Ƿ��������?(y/n)");
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
	         printf("�����������:");
	         scanf("%s",&goods[num].name);
	         getchar();
	         printf("�������������:");
	         scanf("%d",&goods[num].total);
	         getchar();
	         if(search(goods[num].name) != -1) {
			 	int temp=search(goods[num].name);
			 	goods[temp].total+=goods[num].total;
			 }
			 else {
			 	printf("��������ﳤ��:");
				scanf("%d",&goods[num].length);
				getchar();
				printf("�����������:");
				scanf("%d",&goods[num].width);
				getchar();
				printf("���������߶�:");
				scanf("%d",&goods[num].height);
				getchar();
				num++;//������һ��λ��
			 }
	 		 printf("�Ƿ����?(y/n)");
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
				 	printf("�ֿ����޻���\n");
				 	printf("�Ƿ������(y/n)");
				 	getchar();
				 	char ch2=getchar();
				 	if (ch2=='n') exit(0);
				 	
				 	else if(ch2=='y') {
				 		Sleep(1000);
						break;
					}
		         }
				 printf("������Ҫ����Ļ�����:");
		         scanf("%s",&outGoods);
		         getchar();
		         if(search(outGoods) == -1) {
				 	printf("���ﲻ����");
				 }
				 else {
				 	outTemp=search(outGoods);
				 	printf("�ֿ��ڸû�������Ϊ:%d\n",goods[outTemp].total);
					printf("�������������:");
					scanf("%d",&outNum);
			        getchar();
			        if(outNum>goods[outTemp].total) {
						printf("�û����������㣬�޷�����\n");
					}
					else {
						goods[outTemp].total-=outNum;
						printf("�������ɹ�\n");
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
		 		 printf("�Ƿ����?(y/n)");
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
		printf("            ��ѡ��������Ҫ�ķ���:");
		scanf("%d",&n);
		system("cls");
		switch(n) {
			case(1):list();break;
			case(2):add();break;
			case(3):deletee();break;
			case(4):exit(0);
			default:
				{
					printf("������������������");
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
