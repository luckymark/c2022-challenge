#include<stdio.h>
#include<stdlib.h>
//��100��Χ����֤��°ͺղ������ȷ��
//ÿ������2��ż��������д����������֮��

/*�ж��Ƿ�������*/
int isPrime(int num)
{
    int i = 0;
    if (num <= 1)
    {
        return 0;
    }
    if (num == 2)
    {
        return 1;
    }
    for (i = 2; i < num; i++)
    {
        if (num % i == 0)
        {
            return 0;
        }
    }
    return 1;
}

int judge()
{
    for (int i = 4; i <= 100; i+=2)
    {
        int a = 0;
        for (int j = 1; j < i; j++)
        {
            int k = i - j;
            int num1 = isPrime(j);
            int num2 = isPrime(k);
            if (num1 == num2 == 1)
            {
                a = 1;
                break;
            }
        }
        if (a != 1)
        {
            return 0;
            break;
        }
    }
}
int main()
{
    if (judge() == 0)
    {
        puts("no");
    }
    else
    {
        puts("yes");
    }

	system("pause");
	return 0;
}