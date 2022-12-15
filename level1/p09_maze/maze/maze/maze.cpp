#include"maze.h"



int Random()
{
	
	int RandomNumber;
	RandomNumber = rand() % 4;
	return RandomNumber;
}

void CreateRoad(int x, int y, int num, int way)
{
	if (RoadCreate)
	{
		return;
	}
	if (x == Width - 1 && y == Length - 1)
	{
		RoadCreate = true;
		return;
	}
	if (x <= 0 || x >= Width || y <= 0 || y >= Length)
	{
		return;
	}
	if (num < Maxnum)
	{
		maze[x][y] = ' ';
		switch (way) {
		case 1:if (maze[x - 1][y] == '#' && maze[x - 2][y] == '#')
			CreateRoad(x - 1, y, num + 1, way); break;
		case 2:if (maze[x][y + 1] == '#' && maze[x][y + 2] == '#')
			CreateRoad(x, y + 1, num + 1, way); break;
		case 3:if (maze[x + 1][y] == '#' && maze[x + 2][y] == '#')
			CreateRoad(x + 1, y, num + 1, way); break;
		case 4:if (maze[x][y - 1] == '#' && maze[x][y - 2] == '#')
			CreateRoad(x, y - 1, num + 1, way); break;
		default:return;
		}
	}
	if (num == Maxnum)
	{
		maze[x][y] = ' ';
		for (int i = 1; i <= MaxStep; i++)
		{
			switch (Random()) {
			case 0:if (maze[x - 1][y] == '#' && maze[x - 2][y] == '#') CreateRoad(x - 1, y, 0, 1); break;
			case 1:if (maze[x][y + 1] == '#' && maze[x][y + 2] == '#') CreateRoad(x, y + 1, 0, 2); break;
			case 2:if (maze[x + 1][y] == '#' && maze[x + 2][y] == '#') CreateRoad(x + 1, y, 0, 3); break;
			case 3:if (maze[x][y - 1] == '#' && maze[x][y - 2] == '#') CreateRoad(x, y - 1, 0, 4); break;
			default:return;
			}
		}
	}
}

void CreateMaze()
{
	for (int i = 0; i <= Width + 1; i++)
		for (int j = 0; j <= Length + 1; j++)
		{
			maze[i][j] = '#';
		}
	maze[Width - 1][Length - 1] = '*';
	RoadCreate = false;
	CreateRoad(1, 1, 0, 2);
	PrintMaze();
}


void StartGame()
{
	char c;
	CreateMaze();
	Move();
}

void Move() {
	int your_pos_y = 1, your_pos_x = 1;
	int o_y = Length - 1, o_x = Width - 1;

	while (1)
	{
		system("cls");
		for (int i = 0; i < Length; i++)
		{
			for (int j = 0; j < Width; j++)
			{
				if (i == your_pos_y && j == your_pos_x)
				{
					printf("@");
				}
				else
				{
					printf("%c", maze[i][j]);
				}
			}
			printf("\n");
		}
		if (your_pos_y == o_y
			&&
			your_pos_x == o_x)
		{

			printf("YOU WIN !!!");
			break;
		}

	

		switch (_getch())
		{
		case 72:
			if (maze[your_pos_y - 1][your_pos_x] != '#')
			{
				your_pos_y--;
			}
			break;
		case 80:
			if (maze[your_pos_y + 1][your_pos_x] != '#')
			{
				your_pos_y++;
			}
			break;
		case 75:
			if (maze[your_pos_y][your_pos_x - 1] != '#')
			{
				your_pos_x--;
			}
			break;
		case 77:
			if (maze[your_pos_y][your_pos_x + 1] != '#')
			{
				your_pos_x++;
			}
			break;
			
		}
	
	}
}
void PrintMaze(){
	for (int i = 0; i <= Width; i++)
	{
		for (int j = 0; j <= Length; j++)
		{
			cout << maze[i][j];
		}
		cout << endl;
	}
}