#include<stdio.h>
void main()
{
	for (double i = 30; i <= 100; i++)
	{
		if (i == i / 6 + i / 12 + i / 7 + 5 + i / 2 + 4)
		{
			printf("¶ª·¬Í¼µÄÄêÁäÊÇ%d", (int) i);
		}
	}
}