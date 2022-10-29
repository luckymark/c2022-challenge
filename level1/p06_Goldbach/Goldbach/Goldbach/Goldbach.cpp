#include<stdio.h>
#include<stdlib.h>
//在100范围内验证哥德巴赫猜想的正确性
//每个大于2的偶数都可以写成两个素数之和

/*判断是否是素数*/
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