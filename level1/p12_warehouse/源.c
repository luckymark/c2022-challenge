#include<stdio.h>
#include<errno.h>
#include<stdlib.h>
int main()
{
	int a=0, b=0, c=0,i=0,j=0,g,num;
	char s[1000] = { 0 };
	char m,n,ch[1000];
	FILE* fp;
	fopen_s(&fp, "test.txt", "w");
	if (fp == NULL)
	{
		perror("fail");
		return 0;
	}
	fprintf(fp, "a:%d\n", a);
	fprintf(fp, "b:%d\n", b);
	fprintf(fp, "c:%d\n", c);
	fclose(fp);
	do {
		printf("��ѡ���ܣ�\n1.��ʾ���\n2.���\n3.����\n4.�˳�\n");
		scanf_s("%d", &g);
		m = getchar();
		switch (g)
		{
		case 1:
		{
			fopen_s(&fp, "test.txt", "w");
			if (fp == NULL)
			{
				perror("fail");
				return 0;
			}
			fprintf(fp, "a:%d\n", a);
			fprintf(fp, "b:%d\n", b);
			fprintf(fp, "c:%d\n", c);
			fclose(fp);
			fopen_s(&fp, "test.txt", "r");
			if (fp == NULL)
			{
				perror("fail");
				return 0;
			}
			while (fgets(s, 999, fp) != NULL)
			{
				printf("%s", s);
			}
			fclose(fp);
		}; break;
		case 2:
		{
			printf("�������������ͣ�һ������һ������a | b | c\n");
			scanf_s("%c", &n, 1);
			printf("����������\n");
			scanf_s("%d", &num);
			m = getchar();
			switch (n)
			{
			case 'a':
			{
				a += num;
				/*fopen_s(&fp, "test.txt", "a");
				if (fp == NULL)
				{
					perror("fail");
					return 0;
				}
				fseek(fp, 0, 0);
				fseek(fp, 0, 1);
				fprintf(fp, "a:%d", a);
				fclose(fp);*/
			};
			printf("a�Ŀ���%d\n", num);
			break;
			case 'b':
			{
				b += num;
				/*fopen_s(&fp, "test.txt", "a");
				if (fp == NULL)
				{
					perror("fail");
					return 0;
				}
				fseek(fp, 0, 0);
				fgets(ch, 500, fp);
				fseek(fp, -1, 1);
				fprintf(fp, "b:%d", b);
				fclose(fp);*/
			};
			printf("b�Ŀ���%d\n", num);
			break;
			case 'c':
			{
				c += num;
				/*fopen_s(&fp, "test.txt", "a");
				if (fp == NULL)
				{
					perror("fail");
					return 0;
				}
				fseek(fp, 0, 0);
				fgets(ch, 500, fp);
				fgets(ch, 500, fp);
				fseek(fp, -1, 1);
				fprintf(fp, "c:%d", c);
				fclose(fp);*/
			};
			printf("b�Ŀ���%d\n", num);
			break;
			default:break;
			}
		}; break;
		case 3:
		{
			printf("�������������ͣ�һ������һ������a | b | c\n");
			scanf_s("%c", &n, 1);
			printf("����������\n");
			scanf_s("%d", &num);
			m = getchar();
			switch (n)
			{
			case 'a':
			{
				if (a > 0)
				{
					a-=num;
					if (a >= 0)
					{
						/*fopen_s(&fp, "test.txt", "a");
						if (fp == NULL)
						{
							perror("fail");
							return 0;
						}
						fseek(fp, 0, 0);
						fseek(fp, -1,1);
						fprintf(fp, "a:%d", a);
						fclose(fp);*/
					}
					else
					{
						printf("a�Ŀ�治��\n");
					}
				}
				else
				{
					printf("a��ʣ��\n");
				}
			}; 
			printf("a�Ŀ���%d\n", num)
				; break;
			case 'b':
			{
				if (b > 0)
				{
					b-=num;
					if (b >= 0)
					{
						/*fopen_s(&fp, "test.txt", "a");
						if (fp == NULL)
						{
							perror("fail");
							return 0;
						}
						fseek(fp, 0, 0);
						fgets(ch, 500, fp);
						fgets(ch, 500, fp);
						fseek(fp, -1,1);
						fprintf(fp, "b:%d", b);
						fclose(fp);*/
					}
					else
					{
						printf("b�Ŀ�治��\n");
					}
				}
				else
				{
					printf("b��ʣ��\n");
				}
			}; 
			printf("b�Ŀ���%d\n", num);
			break;
			case 'c':
			{
				if (c > 0)
				{
					c-num;
					if (c >= 0)
					{
						/*fopen_s(&fp, "test.txt", "a");
						if (fp == NULL)
						{
							perror("fail");
							return 0;
						}
						fseek(fp, 0, 0);
						fgets(ch, 500, fp);
						fgets(ch, 500, fp);
						fseek(fp, -1, 1);
						fprintf(fp, "c:%d", c);
						fclose(fp);*/
					}
					else
					{
						printf("c�Ŀ�治��\n");
					}
				}
				else
				{
					printf("c��ʣ��\n");
				}
			}; 
			printf("c�Ŀ���%d\n", num); 
			break;
			default:break;
			}; break;
		default:break;
		}
		}
	}while (g != 4);
	return 0;
}