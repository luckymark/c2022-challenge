#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define KEY 13  // ƫ���� 

char* encrypt(char str[])  //���� 
{
	int i;
	int count = strlen(str); 
	for (i = 0; i < count; i++)
	{
		str[i] = str[i] + i + KEY;
	}
	return str;
}

char* encryptr(char str[]) //����
{
	int i;
	int count = strlen(str); 
	for (i = 0; i < count; i++)
	{
		str[i] = str[i] - i - KEY; 
	}
	return str; 
}
int main()
{
	char name[100];
	printf("��������Ҫ���ܵ��ַ���\n");
	scanf_s("%s", name);
	encrypt(name);
	printf("���ܺ���ַ�Ϊ��%s\n", name);
	printf("��������Ҫ���ܵ��ַ���\n");
	scanf_s("%s", name);
	encryptr(name);
	printf("���ܺ���ַ�Ϊ��%s\n", name);
	return 0;
}