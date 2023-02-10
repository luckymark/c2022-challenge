#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
	int a, b, c, d, n1, n2;
	for (a = 2; a <= 100; a++)
	{
		if (a % 2 == 0)
		{
			for (b = 2; b <= a / 2; b++)
			{
				for (c = 2; c < sqrt(b) + 1; ++c)
					if (b % c == 0)break;
				if (c > sqrt(b))
				{
					n2 = a - b;
					for (d = 2; d < sqrt(n2) + 1; ++d)
						if (n2 % d == 0)break;
					if (d > sqrt(n2))
						printf("%d=%d+%d\n", a, b, n2);
				}
			}
		}
	}
	return 0;
}
