#include<stdio.h>
int main()
{
	double a, b, c,d, n;
	for (n = 0; n <= 200; n++)
	{
		for (a = 0; a < n; a++)
		{
			for (b = 0; b < n; b++)
			{
				for (c = 0; c < n; c++)
				{
					if (a == n / 6 && b == n / 12 && c == n / 7)
					{
						d = n / 2;
						if (a + b + c + 5 + d + 4 == n)
						{
							printf("丢番图的儿子死时他%f岁", n - 4);
						}
					}
				}
			}
		}
	}
	return 0;
}