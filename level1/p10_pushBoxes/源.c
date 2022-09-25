#include <stdio.h>
#include<errno.h>
int play1(char b[])
{
	char m, n,c;
	int count=0,q=1870;
	do {
		printf("w-向上移动\ns-向下移动\na-向左移动\nd-向右移动\n先按方向键再按enter移动\n");
		printf("%s", b);
		m = getchar();
		n = getchar();
		switch (m)
		{
		case 119:
		{
			if (b[q - 120] == ' ')
			{
				count++;
				b[q] = ' ';
				q = q - 120;
				if (b[q] == 'O')
				{
					printf("请选择推的方向");
					scanf_s("%c", &c, 1);
					m = getchar();
					switch (c)
					{
					case 119:
					{
						if (b[q - 120] == 'N')
						{
							b[q - 120] = 'Y';
						}
						if (b[q - 120] == ' ')
						{
							b[q - 120] = 'O';
						}
					}
					break;
					case 115:
					{
						if (b[q + 120] == 'N')
						{
							b[q + 120] = 'Y';
						}
						if (b[q + 120] == ' ')
						{
							b[q + 120] = 'O';
						}
					}
					break;
					case 97:
					{
						if (b[q - 1] == 'N')
						{
							b[q - 1] = 'Y';
						}
						if (b[q - 1] == ' ')
						{
							b[q - 1] = 'O';
						}
					}
					break;
					case 100:
					{
						if (b[q + 1] == 'N')
						{
							b[q + 1] = 'Y';
						}
						if (b[q + 1] == ' ')
						{
							b[q + 1] = 'O';
						}
					}
					break;
					default: break;
					}
					b[q] = 'P';
				}
			}
			break;
		}
		case 115:
		{
			if (b[q + 120] == ' ')
			{
				count++;
				b[q] = ' ';
				q = q + 120;
				if (b[q] == 'O')
				{
					printf("请选择推的方向");
					scanf_s("%c", &c, 1);
					m = getchar();
					switch (c)
					{
					case 119:
					{
						if (b[q - 120] == 'N')
						{
							b[q - 120] = 'Y';
						}
						if (b[q - 120] == ' ')
						{
							b[q - 120] = 'O';
						}
					}
					break;
					case 115:
					{
						if (b[q + 120] == 'N')
						{
							b[q + 120] = 'Y';
						}
						if (b[q + 120] == ' ')
						{
							b[q + 120] = 'O';
						}
					}
					break;
					case 97:
					{
						if (b[q - 1] == 'N')
						{
							b[q - 1] = 'Y';
						}
						if (b[q - 1] == ' ')
						{
							b[q - 1] = 'O';
						}
					}
					break;
					case 100:
					{
						if (b[q + 1] == 'N')
						{
							b[q + 1] = 'Y';
						}
						if (b[q + 1] == ' ')
						{
							b[q + 1] = 'O';
						}
					}
					break;
					default: break;
					}
				}
				b[q] = 'P';
			}
		}
		break;
		case 97:
		{
			if (b[q - 1] == ' ')
			{
				count++;
				b[q] = ' ';
				q = q - 1;
				if (b[q] == 'O')
				{
					printf("请选择推的方向");
					scanf_s("%c", &c, 1);
					m = getchar();
					switch (c)
					{
					case 119:
					{
						if (b[q - 120] == 'N')
						{
							b[q - 120] = 'Y';
						}
						if (b[q - 120] == ' ')
						{
							b[q - 120] = 'O';
						}
					}
					break;
					case 115:
					{
						if (b[q + 120] == 'N')
						{
							b[q + 120] = 'Y';
						}
						if (b[q + 120] == ' ')
						{
							b[q + 120] = 'O';
						}
					}
					break;
					case 97:
					{
						if (b[q - 1] == 'N')
						{
							b[q - 1] = 'Y';
						}
						if (b[q - 1] == ' ')
						{
							b[q - 1] = 'O';
						}
					}
					break;
					case 100:
					{
						if (b[q + 1] == 'N')
						{
							b[q + 1] = 'Y';
						}
						if (b[q + 1] == ' ')
						{
							b[q + 1] = 'O';
						}
					}
					break;
					default: break;
					}
				}
				b[q] = 'P';
			}
		}
		break;
		case 100:
		{
			if (b[q + 1] == ' ')
			{
				count++;
				b[q] = ' ';
				q = q + 1;
				if (b[q] == 'O')
				{
					printf("请选择推的方向");
					scanf_s("%c", &c, 1);
					m = getchar();
					switch (c)
					{
					case 119:
					{
						if (b[q - 120] == 'N')
						{
							b[q - 120] = 'Y';
						}
						if (b[q - 120] == ' ')
						{
							b[q - 120] = 'O';
						}
					}
					break;
					case 115:
					{
						if (b[q + 120] == 'N')
						{
							b[q + 120] = 'Y';
						}
						if (b[q + 120] == ' ')
						{
							b[q + 120] = 'O';
						}
					}
					break;
					case 97:
					{
						if (b[q - 1] == 'N')
						{
							b[q - 1] = 'Y';
						}
						if (b[q - 1] == ' ')
						{
							b[q - 1] = 'O';
						}
					}
					break;
					case 100:
					{
						if (b[q + 1] == 'N')
						{
							b[q + 1] = 'Y';
						}
						if (b[q + 1] == ' ')
						{
							b[q + 1] = 'O';
						}
					}
					break;
					default: break;
					}
				}
				b[q] = 'P';
			}
		}
		break;
		default: break;
		}
		system("cls");
	} while (b[121] == 'N' || b[718] == 'N' || b[1081] == 'N');
	return count;
}
int main()
{
	int i = 0, q,p,count=0,l=0;
	char m, a[2300],b[2300], n,c;
	while (i >= 0 && i <= 119)
	{
		a[i] = '*'; i++;
	}
	for (i = 120; i <= 239; i++)
	{
		a[i] = ' ';
	}
	for (i = 240; i <= 359; i++)
	{
		a[i] = '*';
	}
	for (i = 360; i <= 479; i++)
	{
		a[i] = ' ';
	}
	for (i = 480; i <= 599; i++)
	{
		a[i] = '*';
	}
	for (i = 600; i <= 719; i++)
	{
		a[i] = ' ';
	}
	for (i = 720; i <= 839; i++)
	{
		a[i] = '*';
	}
	for (i = 840; i <= 959; i++)
	{
		a[i] = ' ';
	}
	for (i = 960; i <= 1079; i++)
	{
		a[i] = '*';
	}
	for (i = 1080; i <= 1199; i++)
	{
		a[i] = ' ';
	}
	for (i = 1200; i <= 1319; i++)
	{
		a[i] = '*';
	}
	for (i = 1320; i <= 1439; i++)
	{
		a[i] = ' ';
	}
	for (i = 1440; i <= 1559; i++)
	{
		a[i] = '*';
	}
	for (i = 1560; i <= 1679; i++)
	{
		a[i] = ' ';
	}
	for (i = 1680; i <= 1799; i++)
	{
		a[i] = '*';
	}
	for (i = 1800; i <= 1919; i++)
	{
		a[i] = ' ';
	}
	for (i = 1920; i <= 2039; i++)
	{
		a[i] = '*';
	}
	for (i = 2040; i < 2300; i++)
	{
		a[i] = ' ';
	}
	a[121] = 'N';
	a[718] = 'N';
	a[1081] = 'N';
	a[390] = 'O';
	a[870] = 'O';
	a[1570] = 'O';
	a[1870] = 'P';
	a[251] = ' ';
	a[730] = ' ';
	a[830] = ' ';
	a[1060] = ' ';
	a[1211] = ' ';
	a[1250] = ' ';
	a[1500] = ' ';
	a[1690] = ' ';
	a[1780] = ' ';
	a[487] = ' ';
	a[1120] = '*';
	a[220] = '*';
	a[430] = '*';
	a[660] = '*';
	a[1600] = '*';
	q = 1870;
	FILE* fp;
	errno_t err=fopen_s(&fp, "test.txt", "w");
	if (err!=0)
	{
		perror("fail");
		return 0;
	}
	if (fp == NULL)
	{
		return 0;
	}
	for (i = 0; i <= 2300; i++);
	{
		fputs(a, fp);
	}
	fclose(fp);
	FILE* fp1;
	errno_t err1 = fopen_s(&fp1, "test.txt", "w");
	if (err1 != 0)
	{
		perror("fail");
		return 0;
	}
	if (fp1 == NULL)
	{
		return 0;
	}
	for (i = 0; i <= 2300; i++);
	{
		fputs(a, fp1);
	}
	fclose(fp1);
	printf("选择关卡：1或2");
	scanf_s("%d", &p);
	m = getchar();
	switch (p)
	{
	case 1: 
	{
		fopen_s(&fp, "test.txt", "r");
		if (fp == NULL)
		{
			return 0;
		}
		fgets(b, 2300, fp);
		fclose(fp);
		count=play1(b);
		l++;
	};
	break;
	case 2:
	{
		fopen_s(&fp1, "test.txt", "r");
		if (fp == NULL)
		{
			return 0;
		}
		fgets(b, 2300, fp1);
		fclose(fp1);
		count=play1(b);
		l++;
	};
	break;
	}
	printf("你的分数是；%d", count);
	FILE* ptr2;
	fopen_s(&ptr2, "test2.txt", "a");
	if (ptr2 == NULL);
	{
		perror("fail");
		return 0;
	}
	fprintf(ptr2, "第%d次成绩为%d", l, count);
	close(ptr2);
	return 0;
}