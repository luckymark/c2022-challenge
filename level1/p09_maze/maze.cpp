#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<windows.h>
#define ROW 45
#define LINE 90
int board[ROW][LINE]={0};
int checkrow(int r, int l)
{
	if (board[r-1][l] == 0 && board[r+1][l] == 0)
		return 1;
	else
		return 0;
}
int checkline(int r, int l)
{
	if (board[r][l-1] == 0 && board[r][l+1] == 0)
		return 1;
	else
		return 0;
}
void MainRoad(int * str_r,int * str_l)
{
	srand((unsigned int)time(NULL));
	 *str_r = rand() % (ROW - 4) + 2;
	 *str_l = 0;
	int pass_r = *str_r;
	int pass_l = *str_l+3;
	int a = 0;
	for (int i = *str_l; i <= pass_l; i++)
	{
		board[pass_r][i] = 1;
	}
	while (pass_l != LINE -1&&a<100)
	{
		a++;
		int dis = rand() % 3 + 3;
		int dir = rand() % 4 + 1;
		int flag = 1;
		int pre_r = pass_r;
		int pre_l = pass_l;
		switch (dir)
		{
		case 1:
			for (int i = 1; i <= dis; i++)
			{
				if (checkrow(pass_r, pass_l + i) == 0)
					flag = 0;
			}
			if (flag)
			{
				if ((pass_l += dis) > LINE-1)
					pass_l = LINE-1;
				for (int i = pre_l; i <= pass_l; i++)
				{
					board[pass_r][i] = 1;
				}
			}
			break;
		case 2:
			for (int i = 1; i <= dis; i++)
			{
				if (checkrow(pass_r, pass_l - i) == 0)
					flag = 0;
			}
			if (flag)
			{
				if ((pass_l -= dis) < 1)
				{
					pass_l = 1;
				}
				for (int i = pre_l; i >= pass_l; i--)
				{
					board[pass_r][i] = 1;
				}
			}
			break;
		case 3:
			for (int i = 1; i <= dis; i++)
			{
				if (checkline(pass_r+i, pass_l) == 0)
					flag = 0;
			}
			if (flag)
			{
				if ((pass_r += dis) >ROW-2)
				{
					pass_r = ROW-2;
				}
				for (int i = pre_r; i <= pass_r; i++)
				{
					board[i][pass_l] = 1;
				}
			}
			break;
		case 4:
			for (int i = 1; i <= dis; i++)
			{
				if (checkline(pass_r - i, pass_l) == 0)
					flag = 0;
			}
			if (flag)
			{
				if ((pass_r -= dis) <1)
				{
					pass_r = 1;
				}
				for (int i = pre_r; i >= pass_r; i--)
				{
					board[i][pass_l] = 1;
				}
			}
			break;
		}
	}
	if (a == 100)
	{
		int str_r = 1;
		int str_l = LINE - 1;
		while (!board[str_r][str_l])
		{
			str_r++;
			if (str_r == ROW - 2)
			{
				str_r = 1;
				str_l--;
			}
		}
	    pass_r = str_r;
		pass_l = str_l + 3;
	    a = 0;
		for (int i = str_l; i <= pass_l; i++)
		{
			board[pass_r][i] = 1;
		}
		while (pass_l != LINE - 1 && a < 100)
		{
			a++;
			int dis = rand() % 3 + 3;
			int dir = rand() % 4 + 1;
			int flag = 1;
			int pre_r = pass_r;
			int pre_l = pass_l;
			switch (dir)
			{
			case 1:
				for (int i = 1; i <= dis; i++)
				{
					if (checkrow(pass_r, pass_l + i) == 0)
						flag = 0;
				}
				if (flag)
				{
					if ((pass_l += dis) > LINE - 1)
						pass_l = LINE - 1;
					for (int i = pre_l; i <= pass_l; i++)
					{
						board[pass_r][i] = 1;
					}
				}
				break;
			case 2:
				for (int i = 1; i <= dis; i++)
				{
					if (checkrow(pass_r, pass_l - i) == 0)
						flag = 0;
				}
				if (flag)
				{
					if ((pass_l -= dis) < 1)
					{
						pass_l = 1;
					}
					for (int i = pre_l; i >= pass_l; i--)
					{
						board[pass_r][i] = 1;
					}
				}
				break;
			case 3:
				for (int i = 1; i <= dis; i++)
				{
					if (checkline(pass_r + i, pass_l) == 0)
						flag = 0;
				}
				if (flag)
				{
					if ((pass_r += dis) > ROW - 2)
					{
						pass_r = ROW - 2;
					}
					for (int i = pre_r; i <= pass_r; i++)
					{
						board[i][pass_l] = 1;
					}
				}
				break;
			case 4:
				for (int i = 1; i <= dis; i++)
				{
					if (checkline(pass_r - i, pass_l) == 0)
						flag = 0;
				}
				if (flag)
				{
					if ((pass_r -= dis) < 1)
					{
						pass_r = 1;
					}
					for (int i = pre_r; i >= pass_r; i--)
					{
						board[i][pass_l] = 1;
					}
				}
				break;
			}
		}

	}
	if (a == 100)
	{
		int str_r = 1;
		int str_l = LINE - 1;
		while (!board[str_r][str_l])
		{
			str_r++;
			if (str_r == ROW - 2)
			{
				str_r = 1;
				str_l--;
			}
		}
		pass_r = str_r;
		pass_l = str_l + 3;
		a = 0;
		for (int i = str_l; i <= pass_l; i++)
		{
			board[pass_r][i] = 1;
		}
		while (pass_l != LINE - 1 && a < 100)
		{
			a++;
			int dis = rand() % 3 + 3;
			int dir = rand() % 4 + 1;
			int flag = 1;
			int pre_r = pass_r;
			int pre_l = pass_l;
			switch (dir)
			{
			case 1:
				for (int i = 1; i <= dis; i++)
				{
					if (checkrow(pass_r, pass_l + i) == 0)
						flag = 0;
				}
				if (flag)
				{
					if ((pass_l += dis) > LINE - 1)
						pass_l = LINE - 1;
					for (int i = pre_l; i <= pass_l; i++)
					{
						board[pass_r][i] = 1;
					}
				}
				break;
			case 2:
				for (int i = 1; i <= dis; i++)
				{
					if (checkrow(pass_r, pass_l - i) == 0)
						flag = 0;
				}
				if (flag)
				{
					if ((pass_l -= dis) < 1)
					{
						pass_l = 1;
					}
					for (int i = pre_l; i >= pass_l; i--)
					{
						board[pass_r][i] = 1;
					}
				}
				break;
			case 3:
				for (int i = 1; i <= dis; i++)
				{
					if (checkline(pass_r + i, pass_l) == 0)
						flag = 0;
				}
				if (flag)
				{
					if ((pass_r += dis) > ROW - 2)
					{
						pass_r = ROW - 2;
					}
					for (int i = pre_r; i <= pass_r; i++)
					{
						board[i][pass_l] = 1;
					}
				}
				break;
			case 4:
				for (int i = 1; i <= dis; i++)
				{
					if (checkline(pass_r - i, pass_l) == 0)
						flag = 0;
				}
				if (flag)
				{
					if ((pass_r -= dis) < 1)
					{
						pass_r = 1;
					}
					for (int i = pre_r; i >= pass_r; i--)
					{
						board[i][pass_l] = 1;
					}
				}
				break;
			}
		}

	}
	if (a == 100)
	{
		int str_r = 1;
		int str_l = LINE - 1;
		while (!board[str_r][str_l])
		{
			str_r++;
			if (str_r == ROW - 2)
			{
				str_r = 1;
				str_l--;
			}
		}
		for (int i = str_l; i <= LINE - 1; i++)
		{
			board[str_r][i] = 1;
		}
	}
}
void BranchRoad(int i)
{
	int br, bl;
	if (i <= 1000)
	{
		do
		{
			br = rand() % (ROW - 2) + 1;
			bl = rand() % (LINE - 2) + 1;
		} while (board[br][bl] == 0);
	}
	else
	{
		br = rand() % (ROW - 2) + 1;
		bl = rand() % (LINE - 2) + 1;
	}
	int dis = rand() % 3 + 5;
	int dir = rand() % 4 + 1;
	switch (dir)
	{
	case 1:
		if (bl + dis >= LINE-1)
			dis = LINE - 2 - bl;
		for (int i = bl; i <= bl + dis; i++)
		{
			if (checkrow(br, i+1) == 0 || (board[br][i] == 1&&i!=bl))
				break;
			board[br][i] = 1;
		}
		break;
	case 2:
		if (bl - dis < 1)
		{
			dis = bl - 1;
		}
		for (int i = bl; i >= bl - dis; i--)
		{
			if (checkrow(br, i+1) == 0 || (board[br][i] == 1 && i != bl))
				break;
			board[br][i] = 1;
		}
		break;
	case 3:
		if (br + dis >= ROW - 1)
		{
			dis = ROW - 2 - br;
		}
		for (int i = br; i <= br + dis; i++)
		{
			if (checkline(i+1, bl) == 0 || (board[i][bl] == 1&&i!=br))
				break;
			board[i][bl] = 1;
		}
		break;
	case 4:
		if (br - dis < 1)
		{
			dis = br - 2;
		}
		for (int i = br; i >= br - dis; i--)
		{
			if (checkline(i+1, bl) == 0 || (board[i][bl] == 1 && i != br))
				break;
			board[i][bl] = 1;
		}
		break;
	}
}
void color(int x)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), x);
}
void RoleMove(char * move,int * pr,int * pl)
{
	switch (*move)
	{
	case 'w':
	case 'W':
		if (board[*pr - 1][*pl] == 1)
		{
			board[*pr][*pl] = 1;
			*pr -= 1;
			board[*pr][*pl] = 2;
		}
		break;
	case 's':
	case 'S':
		if (board[*pr + 1][*pl] == 1)
		{
			board[*pr][*pl] = 1;
			*pr += 1;
			board[*pr][*pl] = 2;
		}
		break;
	case 'a':
	case 'A':
		if (board[*pr ][*pl - 1] == 1)
		{
			board[*pr][*pl] = 1;
			*pl -= 1;
			board[*pr][*pl] = 2;
		}
		break;
	case 'd':
	case 'D':
		if (board[*pr][*pl + 1] == 1)
		{
			board[*pr][*pl] = 1;
			*pl += 1;
			board[*pr][*pl] = 2;
		}
		break;
	}
}
void BoardPrint()
{
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < LINE; j++)
		{
			if (board[i][j] == 0)
				printf("# ");
			else if (board[i][j] == 1)
				printf("  ");
			else
			{
				color(4);
				printf("i ");
				color(7);
			}
		}
		printf("\n");
	}
}
int main()
{
	int str_r, str_l;
	MainRoad(&str_r,&str_l);
	for (int i = 0; i < 2000; i++)
	{
		BranchRoad(i);
	}
	int pr = str_r;
	int pl = str_l;
	board[pr][pl] = 2;
	char move ;
	while (pl!=LINE-1)
	{
		BoardPrint();
		scanf_s("%c", &move,1);
		RoleMove(&move, &pr, &pl);
		system("cls");
	}
	color(9);
	printf("you win!");
	return 0;
}