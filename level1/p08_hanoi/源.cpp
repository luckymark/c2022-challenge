#include<stdio.h>
void Print(int str, int des)
{
	printf("%c -> %c\n", str + 64, des + 64);
}
void shift(int n, int str, int des)
{
	int tmp = 6 - str - des;
	if (n == 2)
	{
		Print(str, tmp);
		Print(str, des);
		Print(tmp, des);
	}
	else
	{
		shift(n - 1, str, tmp);
		Print(str, des);
		shift(n - 1, tmp, des);
	}
	return;
}
int main()
{
	shift(2,1,3);
	for (int i = 3; i <=10; i++)
	{
		shift(i - 1, 3, 2);
		Print(1, 3);
		shift(i - 1, 2, 3);
	}
	return 0;
}
//答案本来就那么多吗，还是我代码有问题？我CPU承受了他不该承受的