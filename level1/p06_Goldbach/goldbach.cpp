#include<stdio.h>
int isprime(int n)
{
	bool flag = true;
	for (int i = 2; i < n; i++)
	{
		if (n % i == 0)
			flag = false;
	}
	return flag ? 1: 0;
}
int main()
{
	int i;
	scanf_s("%d", &i);
	for (int x = 1; x <= i; x++)
	{
		if (isprime(x))
		{
			for(int y = x ; y <= i; y++)
				if (isprime(y))
				{
					for (int z = y; z <= i; z++)
					{
						if (x + y + z == i&&isprime(z))
						{
							printf("%d=%d+%d+%d\n", i, x, y, z);
						}
					}
				}
		}
	}
	return 0;
}