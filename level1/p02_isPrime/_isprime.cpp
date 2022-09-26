#include<stdio.h>
int main()
{
	int n = 0;
	bool flag = true;
	scanf_s("%d", &n);
	for (int i = 2; i < n; i++)
	{
		if (n % i == 0)
			flag = false;
	}
	if (flag)
	{
		printf("%d is prime", n);
	}
	else
	{
		printf("%d is not prime", n);
	}
	return 0;
}