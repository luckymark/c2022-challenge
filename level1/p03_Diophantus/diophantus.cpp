#include<stdio.h>
int main()
{
	float age = 0;
	while (1)
	{
		age++;
		float ans = age / 6 + age / 12 + age / 7 + 5 + age / 2 + 4;
		if (age == ans)
		{
			printf("ÄêÁäÎª%.0f", age);
			break;
		}
	}
	return 0;
}