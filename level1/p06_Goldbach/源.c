#include<stdio.h>
#include<math.h>
int main()
{
	int i, a, j, count1 = 0, count2 = 0, count3 = 0;
	for (i = 4; i <= 100; i += 2)
	{
		for (a = 2; a <= i/2 ; a++)
		{
			for (j = 2; j < sqrt(a); j++)
			{
				if (a % j == 0)
				{
					count1++;
					break;
				}
			}
				if (count1 == 0)
				{
					for (j = 2; j < sqrt(i - a); j++)
					{
						if ((i - a) % j == 0)
						{
							count2++;
							break;
						}
					}
					if (count2 == 0)
					{
						count3++; break;
					}
					count2 = 0;
				}
				count1 = 0;
		}
	}
	if (count3 == 49)
	{
		printf("哥德巴赫猜想是对的");
	}
	else
	{
		printf("哥德巴赫猜想是不对的");
	}
	return 0;
}