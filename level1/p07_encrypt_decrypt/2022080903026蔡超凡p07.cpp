#include<stdio.h>
#include <malloc.h>
char* func(char ch[], int f);
void main()
{
	char* p = NULL, ch[100];
	int i;
	for (i = 0; i < 100; i++)
	{
		scanf_s("%c", &ch[i]);
		if (ch[i] == '\n')
		{
			break;
		}
	}
	p = func(ch, 1);//测试加密
	for (int j = 0; j < i; j++)
	{
		printf("%c", p[j]);
	}
	p = func(ch, 0);//测试解密
	for (int j = 0; j < i; j++)
	{
		printf("%c", p[j]);
	}
}



char* func(char ch[],int f)//f表示加密，!f表示解密
{
	char* p[2] = { NULL };//利用指针数组分别存放加密数据和原始数据
	p[0] = ch;
	p[1] = (char*)malloc(sizeof(ch));
	for (int i = 0; i < sizeof(ch); i++)
	{
		p[1][i] = '*';
	}
	if (f)
	{
		return p[1];
	}
	else
	{
		return p[0];
	}
}