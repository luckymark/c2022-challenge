#include<iostream>
#include<windows.h>
#include<conio.h>

// '0':空地 '1';墙壁 '3':箱子的目的地 4;箱子 '6';人  '7';箱子和目的地重合 '9';人站在目的地
char map[10][13] = { NULL };
const char* file_name = "map.txt";

void getMap()
{
	FILE* fp;
	errno_t err = fopen_s(&fp, file_name, "r"); 
	for (int i = 0; i < 10; i++)
	{
		fgets(map[i], 23, fp);

	}
	fclose(fp);
}
void drawMap()
{
	for (int i = 0; i < 10; i++)
	{

		for (int j =  0; j < 12; j++)
		{
			switch (map[i][j])
			{
			case  '0':
				printf(" ");
				break;
			case '1':
				printf("D");
				break;
			case '3':
				printf("☆");
				break;
			case '4':
				printf("X");
				break;
			case '6':
				printf("@");
				break;
			case '7':
				printf("◎");
				break;
			case '9':
				printf("#");
				break;
			}
		}
		printf("\n");
	}
}
POINT GetGamerPosition()
{
	POINT pos = { -1,-1 };
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 12; j++)
		{
			if (map[i][j] == '6' || map[i][j] == '9')
			{
				pos.x = i;
				pos.y = j;
				return pos;
			}
		}
	}
	return pos;
}
//移动
void up()
{
	POINT pos = GetGamerPosition();
	if (map[pos.x - 1][pos.y] == '0')
	{
		map[pos.x - 1][pos.y] = '6';

		if (map[pos.x][pos.y] == '9')
			map[pos.x][pos.y] = '3';
		else
			map[pos.x][pos.y] = '0';
	}
	if (map[pos.x - 1][pos.y] == '3')
	{
		map[pos.x - 1][pos.y] = '9';
		if (map[pos.x][pos.y] == '9')
			map[pos.x][pos.y] = '3';
		else
			map[pos.x][pos.y] = '0';
	}

	if (map[pos.x - 1][pos.y] == '4')
	{
		if (map[pos.x - 2][pos.y] == '0')
		{
			map[pos.x - 2][pos.y] = '4';
			map[pos.x - 1][pos.y] = '6';
			if (map[pos.x][pos.y] == '9')
				map[pos.x][pos.y] = '3';
			else
				map[pos.x][pos.y] = '0';
		}
		else
		{
			if (map[pos.x - 2][pos.y] == '3')
			{
				map[pos.x - 2][pos.y] = '7';
				map[pos.x - 1][pos.y] = '6';
				if (map[pos.x][pos.y] == '9')
					map[pos.x][pos.y] = '3';
				else
					map[pos.x][pos.y] = '0';

			}

		}

	}
	if (map[pos.x - 1][pos.y] == '7')
	{
		if (map[pos.x - 2][pos.y] == '0')
		{
			map[pos.x - 2][pos.y] = '4';
			map[pos.x - 1][pos.y] = '9';
			if (map[pos.x][pos.y] == '9')
				map[pos.x][pos.y] = '3';
			else
				map[pos.x][pos.y] = '0';
		}
		else
		{
			if (map[pos.x - 2][pos.y] == '3')
			{
				map[pos.x - 2][pos.y] = '7';
				map[pos.x - 1][pos.y] = '9';
				if (map[pos.x][pos.y] == '9')
					map[pos.x][pos.y] = '3';
				else
					map[pos.x][pos.y] = '0';

			}
		}
	}
}
void down()
{
	POINT pos = GetGamerPosition();
	if (map[pos.x + 1][pos.y] == '0')
	{
		map[pos.x + 1][pos.y] = '6';

		if (map[pos.x][pos.y] == '9')
			map[pos.x][pos.y] = '3';
		else
			map[pos.x][pos.y] = '0';
	}
	if (map[pos.x + 1][pos.y] == '3')
	{
		map[pos.x + 1][pos.y] = '9';
		if (map[pos.x][pos.y] == '9')
			map[pos.x][pos.y] = '3';
		else
			map[pos.x][pos.y] = '0';
	}

	if (map[pos.x + 1][pos.y] == '4')
	{
		if (map[pos.x + 2][pos.y] == '0')
		{
			map[pos.x + 2][pos.y] = '4';
			map[pos.x + 1][pos.y] = '6';
			if (map[pos.x][pos.y] == '9')
				map[pos.x][pos.y] = '3';
			else
				map[pos.x][pos.y] = '0';
		}
		else
		{
			if (map[pos.x + 2][pos.y] == '3')
			{
				map[pos.x + 2][pos.y] = '7';
				map[pos.x + 1][pos.y] = '6';
				if (map[pos.x][pos.y] == '9')
					map[pos.x][pos.y] = '3';
				else
					map[pos.x][pos.y] = '0';

			}

		}

	}
	if (map[pos.x + 1][pos.y] == '7')
	{
		if (map[pos.x + 2][pos.y] == '0')
		{
			map[pos.x + 2][pos.y] = '4';
			map[pos.x + 1][pos.y] = '9';
			if (map[pos.x][pos.y] == '9')
				map[pos.x][pos.y] = '3';
			else
				map[pos.x][pos.y] = '0';
		}
		else
		{
			if (map[pos.x + 2][pos.y] == '3')
			{
				map[pos.x + 2][pos.y] = '7';
				map[pos.x + 1][pos.y] = '9';
				if (map[pos.x][pos.y] == '9')
					map[pos.x][pos.y] = '3';
				else
					map[pos.x][pos.y] = '0';

			}
		}
	}
}
void left()
{

	POINT pos = GetGamerPosition();
	if (map[pos.x][pos.y - 1] == '0')
	{
		map[pos.x][pos.y - 1] = '6';

		if (map[pos.x][pos.y] == '9')
			map[pos.x][pos.y] = '3';
		else
			map[pos.x][pos.y] = '0';
	}
	if (map[pos.x][pos.y - 1] == '3')
	{
		map[pos.x][pos.y - 1] = '9';
		if (map[pos.x][pos.y] == '9')
			map[pos.x][pos.y] = '3';
		else
			map[pos.x][pos.y] = '0';
	}

	if (map[pos.x][pos.y - 1] == '4')
	{
		if (map[pos.x][pos.y - 2] == '0')
		{
			map[pos.x][pos.y - 2] = '4';
			map[pos.x][pos.y - 1] = '6';
			if (map[pos.x][pos.y] == '9')
				map[pos.x][pos.y] = '3';
			else
				map[pos.x][pos.y] = '0';
		}
		else
		{
			if (map[pos.x][pos.y - 2] == '3')
			{
				map[pos.x][pos.y - 2] = '7';
				map[pos.x][pos.y - 1] = '6';
				if (map[pos.x][pos.y] == '9')
					map[pos.x][pos.y] = '3';
				else
					map[pos.x][pos.y] = '0';

			}

		}

	}
	if (map[pos.x][pos.y - 1] == '7')
	{
		if (map[pos.x][pos.y - 2] == '0')
		{
			map[pos.x][pos.y - 2] = '4';
			map[pos.x][pos.y - 1] = '9';
			if (map[pos.x][pos.y] == '9')
				map[pos.x][pos.y] = '3';
			else
				map[pos.x][pos.y] = '0';
		}
		else
		{
			if (map[pos.x][pos.y - 2] == '3')
			{
				map[pos.x][pos.y - 2] = '7';
				map[pos.x][pos.y - 1] = '9';
				if (map[pos.x][pos.y] == '9')
					map[pos.x][pos.y] = '3';
				else
					map[pos.x][pos.y] = '0';

			}
		}
	}
}
void right()
{
	POINT pos = GetGamerPosition();
	if (map[pos.x][pos.y + 1] == '0')
	{
		map[pos.x][pos.y + 1] = '6';

		if (map[pos.x][pos.y] == '9')
			map[pos.x][pos.y] = '3';
		else
			map[pos.x][pos.y] = '0';
	}
	if (map[pos.x][pos.y + 1] == '3')
	{
		map[pos.x][pos.y + 1] = '9';
		if (map[pos.x][pos.y] == '9')
			map[pos.x][pos.y] = '3';
		else
			map[pos.x][pos.y] = '0';
	}

	if (map[pos.x][pos.y + 1] == '4')
	{
		if (map[pos.x][pos.y + 2] == '0')
		{
			map[pos.x][pos.y + 2] = '4';
			map[pos.x][pos.y + 1] = '6';
			if (map[pos.x][pos.y] == '9')
				map[pos.x][pos.y] = '3';
			else
				map[pos.x][pos.y] = '0';
		}
		else
		{
			if (map[pos.x][pos.y + 2] == '3')
			{
				map[pos.x][pos.y + 2] = '7';
				map[pos.x][pos.y + 1] = '6';
				if (map[pos.x][pos.y] == '9')
					map[pos.x][pos.y] = '3';
				else
					map[pos.x][pos.y] = '0';

			}

		}

	}
	if (map[pos.x][pos.y - 1] == '7')
	{
		if (map[pos.x][pos.y + 2] == '0')
		{
			map[pos.x][pos.y + 2] = '4';
			map[pos.x][pos.y + 1] = '9';
			if (map[pos.x][pos.y] == '9')
				map[pos.x][pos.y] = '3';
			else
				map[pos.x][pos.y] = '0';
		}
		else
		{
			if (map[pos.x][pos.y + 2] == '3')
			{
				map[pos.x][pos.y + 2] = '7';
				map[pos.x][pos.y + 1] = '9';
				if (map[pos.x][pos.y] == '9')
					map[pos.x][pos.y] = '3';
				else
					map[pos.x][pos.y] = '0';

			}
		}
	}
}
//获得剩余箱子个数
int getRestBox()
{
	int CountBox = 0;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 12; j++)
		{
			if (map[i][j] == '4')
				CountBox++;
		}
	}
	return CountBox;
}
int main()
{
	getMap();
	//system("mode con cols=26 lines=12");
	while (1)
	{
		system("cls");
		drawMap();
		if (getRestBox() == 0)
		{
			printf("you win");
			exit(1);
		}
		char ch = _getch();


		switch (ch)
		{
		case 'w':
			up();
			break;
		case 's':
			down();
			break;
		case 'a':
			left();
			break;
		case 'd':
			right();
			break;
		}
	}
	return 0;
}