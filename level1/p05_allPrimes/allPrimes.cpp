//��ӡ2 - 1000���ڵ���������
//��ӡ���ܵļ���ʱ��(�Ҳ��ᰡ
//�������Ż��㷨��Ч��
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
	clock_t start, end;
	start = clock();
	for (int i = 2; i <= 1000; i++)
	{
		int count = 0;
		for (int j = 2; j < i; j++)
		{
			if (i % j == 0)
			{
				count = 1;
				break;
			}
		}
		if (count == 0)
		{
			printf("%d\n", i);
		}
	}
	end = clock();
	printf("����ʱ��Ϊ%fms\n", (double)(end - start) / CLOCKS_PER_SEC);
	system("pause");
	return 0;
}