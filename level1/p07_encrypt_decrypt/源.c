#include<stdio.h>
char* encrypt(char* ptr,int n)
{
	int i;
	char* ptr1= (char*)malloc(sizeof(char) * n);
	for (i = 0; i < n; i++)
	{
		ptr1[i] = ptr[i];
		if (ptr[i] == 'a')
		{
			ptr1[i] = '@';
		}
		if (ptr[i] == 'b')
		{
			ptr1[i] = '#';
		}
		if (ptr[i] == 'c')
		{
			ptr1[i] = '$';
		}
		if (ptr[i] == 'd')
		{
			ptr1[i] = '%';
		}
		if (ptr[i] == 'e')
		{
			ptr1[i] = '^';
		}
	}
	return ptr1;
}
char* decrypt(char* ptr, int n)
{
	int i;
	char* ptr1 = (char*)malloc(sizeof(char) * n);
	for (i = 0; i < n; i++)
	{
		ptr1[i] = ptr[i];
		if (ptr[i] == '@')
		{
			ptr1[i] = 'a';
		}
		if (ptr[i] == '#')
		{
			ptr1[i] = 'b';
		}
		if (ptr[i] == '$')
		{
			ptr1[i] = 'c';
		}
		if (ptr[i] == '%')
		{
			ptr1[i] = 'd';
		}
		if (ptr[i] == '^')
		{
			ptr1[i] = 'e';
		}
	}
	return ptr1;
}
int main()
{
	char* ptr;
	int n,i;
	char m;
	printf("输入字符串字数:");
	scanf_s("%d", &n);
	m = getchar();
	ptr = (char*)malloc(sizeof(char) * n);
	for (i = 0; i < n; i++)
	{
		ptr[i] = getchar();
	}
	printf("加密前%s\n", ptr);
	char* ptra = (char*)malloc(sizeof(char) * n);
	ptra = encrypt(ptr,n);
	printf("加密后%s\n", ptra);
	char* ptrb = (char*)malloc(sizeof(char) * n);
	ptrb = decrypt(ptra, n);
	printf("解密后%s", ptrb);
	return 0;
}