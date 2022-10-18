#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define KEY 13  // 偏移量 

char* encrypt(char str[])  //加密 
{
	int i;
	int count = strlen(str); 
	for (i = 0; i < count; i++)
	{
		str[i] = str[i] + i + KEY;
	}
	return str;
}

char* encryptr(char str[]) //解密
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
	printf("请输入需要加密的字符：\n");
	scanf_s("%s", name);
	encrypt(name);
	printf("加密后的字符为：%s\n", name);
	printf("请输入需要解密的字符：\n");
	scanf_s("%s", name);
	encryptr(name);
	printf("解密后的字符为：%s\n", name);
	return 0;
}