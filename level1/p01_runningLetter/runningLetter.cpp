//### ��Ŀ�����ܵ���ĸ
//
//### ����Ҫ��
//
//1. ��console�����һ����ĸ���򵥴ʣ�
//1. ʹ����ĸ�򵥴ʣ���һ���ٶȴ��������˶�
//1. ��������Ļ�߽�ʱ�����˶�


#include<stdio.h>
#include<stdlib.h>
#include<windows.h>

const int width = 100, w = 0;

int main()
{
	SetConsoleTitle(L"runningLetter");
    int a, b;
    char c[100];
    a = 0;
    b = 1;
    scanf_s("%s", c, 100);//�����ַ�
    system("cls");
    while (1)
    {
        a += b;
        if (a == width || a == w)
        {
            b = -b;
        }
        for (int i = 0; i <= a; i++)
        {
            printf(" ");
        }
        printf("%s",c);
        Sleep(100);
        system("cls");
    }
    system("pause");
    return 0;
}