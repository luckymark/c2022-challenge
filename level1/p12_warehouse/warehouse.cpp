#define _CRT_SECURE_NO_DEPRECATE
//### ��Ŀ���򵥽�����
//
//### ����Ҫ��
//
//1. ʵ�����µĲ˵���������ѡ��˵����ܣ���
//- ��ʾ����б�
//- ���
//- ����
//- �˳�����
//1. ʵ�ֲ˵���Ӧ���ܣ����¼������ͺš���������Ϣ����
//1. ��������ʱ���ļ��ж�ȡ��ǰ������ݣ��˳�ʱ���������ݣ�

#include<stdio.h>
#include<stdlib.h>

const int MAX = 100;//���ϵͳ������Ʒ������

//��Ʒ�ṹ��
struct goods
{
	char modelType[20]={0};//�ͺ�
	int num = 0;//����
};

//���ϵͳ�ṹ��
struct system
{
	goods arr[MAX];//��Ʒ����
	int size = 0;//Ŀǰ����
};
//�˵�ҳ��
void menu()
{
	puts("-----------------");
	puts("1����ʾ����б�");
	puts("2�����");
	puts("3������");
	puts("4���˳�����");
	puts("-----------------");
}

//��ʾ����б�
void show(struct system *sys)
{
	if (sys->size == 0)
	{
		printf("���Ϊ��\n" );
	}
	else
	{
		for (int i = 0; i < sys->size; i++)
		{
			printf("�ͺţ�\t"); printf("%s\t\n", sys->arr[i].modelType);
			printf("������\t"); printf("%d\t\n", sys->arr[i].num);
		}
	}
	system("pause");
	system("cls");
}

//���
void add(struct system* sys)
{
	if (sys->size == MAX)
	{
		printf("�������\n");
	}
	else
	{
		printf("�������ͺ�:\n");
		scanf_s("%s", &sys->arr[sys->size].modelType,20);
		printf("����������:\n");
		scanf_s("%d", &sys->arr[sys->size].num);
	}
	sys->size++;
	puts("����ɹ���\n");
	system("pause");
	system("cls");
}

//����
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
	printf("�����������Ʒ��:\n");
	char nameArr[20];
	scanf_s("%s", nameArr , 20);
	int dp = del1(sys, nameArr);

	if (dp == 0)
	{
		puts("δ��ѯ��������Ʒ");
	}
	else
	{
		int delNum = 0;
		puts("������������Ʒ����");
		scanf_s("%d", delNum);
		if (delNum == sys->arr[dp].num)
		{
			for (int j = dp; j < sys->size; j++)
			{
				sys->arr[j] = sys->arr[j + 1];
			}
			sys->size--;
			puts("ɾ���ɹ�");
		}
		else
		{
			puts("ɾ�ĺ�����");
			scanf_s("%d", sys->arr[dp].num);
			puts("�޸����");
		}
		system("pause");
		system("cls");
	}
}


//��ȡ�ļ�
int read(struct system* sys)
{
	FILE* fp = fopen("data.txt", "r");
	if (!fp)
	{
		printf("��ʧ�ܣ�\n");
		return -1; 
	}
	for (int i = 0; !feof(fp); i++)
	{
	   fscanf_s(fp,"%s %d\n",sys->arr[i].modelType, sys->arr[i].num);
	   sys->size = i+1;
	}
	fclose(fp);
}

//�����ļ�
int preserve(struct system* sys)
{
	FILE* fp = fopen("data.txt", "w");
	if (!fp)
	{
		printf("��ʧ�ܣ�\n");
		return -1; //�����쳣
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
			puts("�������");
			system("pause");
			system("cls");
		}
	}
	system("pause");
	return 0;
}