#include<stdio.h>
#include<math.h>
int main()
{
	int i,a,b,c,j;
	for (i = 100; i <= 999; i++)
	{
		j = i;
		a = i % 10;
		i /= 10;
		b = i % 10;
		i /= 10;
		c = i % 10;
		if (j == pow(a, 3) + pow(b, 3) + pow(c, 3))
		{
			printf("%d是水仙花数\n", j);
		}
		i = j;
	}
	return 0;
}