#include<stdio.h>
#include<math.h>
#include<time.h>
void main()
{
	clock_t t1 = clock(), t2;//��ʼ��ʱ
	printf("2 ");
	for (int i = 3; i < 1000; i++)
	{
		for (int j = 3; j < sqrt((float)i); j += 2)
		{
			if (i % j == 0)
			{
				goto next;
			}
		}
		printf("%d ", i);
		next : i++;
	}
	t2 = clock();//������ʱ
	printf("\n\033[40;32m�������е�ʱ��Ϊ%dms", t2 - t1);
}