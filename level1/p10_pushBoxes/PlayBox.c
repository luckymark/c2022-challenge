#include<stdlib.h>
#include <stdio.h>
#include<conio.h>

int Board[21][41] = { 0 };
int step = 0;
void draw();
void control(int level);

int main()
{
	int i, j;
	char tem;
	int x, y, level, count, N;
	printf("请输入游戏难度(1-9)：");
	scanf_s("%d", &level);
	control(level);
	draw();
	while (1) {
		count = 0;
		tem = _getch();
		if (tem == 77) {
			for (i = 0; i < 21; i++) {
				for (j = 0; j < 41; j++) {
					if (Board[i][j] == 9) {
						y = i;
						x = j;
					}
				}
			}
			if (x + 1 > 39) {
				continue;
			}
			if (Board[y][x + 1] == 8) {
				if (x + 2 > 39) {
					continue;
				}
				if (Board[y][x + 2] == 6 || Board[y][x + 2] == 8) {
					continue;
				}
				Board[y][x + 2] = 8;
			}
			if (Board[y][x + 1] == 6) {
				continue;
			}
			if (Board[y][x + 1] == 7) {
				continue;
			}
			Board[y][x] = 0;
			Board[y][x + 1] = 9;
			step++;
			draw();
		}//向右 
		if (tem == 80) {
			for (i = 0; i < 21; i++) {
				for (j = 0; j < 41; j++) {
					if (Board[i][j] == 9) {
						y = i;
						x = j;
					}
				}
			}
			if (y + 1 > 19) {
				continue;
			}
			if (Board[y + 1][x] == 8) {
				if (y + 2 > 19) {
					continue;
				}
				if (Board[y + 2][x] == 6 || Board[y + 2][x] == 8) {
					continue;
				}
				Board[y + 2][x] = 8;
			}
			if (Board[y + 1][x] == 6) {
				continue;
			}
			if (Board[y + 1][x] == 7) {
				continue;
			}
			Board[y][x] = 0;
			Board[y + 1][x] = 9;
			step++;
			draw();
		}//向下
		if (tem == 72) {
			for (i = 0; i < 21; i++) {
				for (j = 0; j < 41; j++) {
					if (Board[i][j] == 9) {
						y = i;
						x = j;
					}
				}
			}
			if (y - 1 < 0) {
				continue;
			}
			if (Board[y - 1][x] == 8) {
				if (y - 2 < 0) {
					continue;
				}
				if (Board[y - 2][x] == 6 || Board[y - 2][x] == 8) {
					continue;
				}
				Board[y - 2][x] = 8;
			}
			if (Board[y - 1][x] == 6) {
				continue;
			}
			if (Board[y - 1][x] == 7) {
				continue;
			}
			Board[y][x] = 0;
			Board[y - 1][x] = 9;
			step++;
			draw();
		}//向上
		if (tem == 75) {
			for (i = 0; i < 21; i++) {
				for (j = 0; j < 41; j++) {
					if (Board[i][j] == 9) {
						y = i;
						x = j;
					}
				}
			}
			if (x - 1 < 0) {
				continue;
			}
			if (Board[y][x - 1] == 8) {
				if (x - 2 < 0) {
					continue;
				}
				if (Board[y][x - 2] == 6 || Board[y][x - 2] == 6) {
					continue;
				}
				Board[y][x - 2] = 8;
			}
			if (Board[y][x - 1] == 6) {
				continue;
			}
			if (Board[y][x - 1] == 7) {
				continue;
			}
			Board[y][x] = 0;
			Board[y][x - 1] = 9;
			step++;
			draw();
		} //向左 
		if (tem == 0x1b) {
			system("cls");
			break;
		}
		for (i = 0; i < 21; i++) {
			for (j = 0; j < 51; j++) {
				if (Board[i][j] == 7) {
					count++;
				}
			}
		}
		if (count == 0) {
			for (i = 0; i < 21; i++) {
				for (j = 0; j < 41; j++) {
					Board[i][j] = 0;
				}
			}
			printf("\n\n过关了!\n");
			printf("按任意键继续\n");
			getchar();
			level++;
			if (level == 10) {
				system("cls");
				printf("通关了!\n");
				break;
			}
			control(level);
			draw();
		}
	}
	system("pause");
	return 0;
}


void draw() {
	int i, j;
	system("cls");
	for (i = 0; i < 21; i++) {
		for (j = 0; j < 41; j++) {
			if (Board[i][j] == 0) {
				printf(" ");
			}
			else if (Board[i][j] == 1) {
				printf("|");
			}
			else if (Board[i][j] == 2) {
				printf("-");
			}
			else if (Board[i][j] == 9) {
				printf("&");
			}
			else if (Board[i][j] == 8) {
				printf("#");
			}
			else if (Board[i][j] == 7) {
				printf("$");
			}
			else if (Board[i][j] == 6) {
				printf("+");
			}
		}
		printf("\n");
	}
	printf("\n\n");
	printf("请使用方向键控制小人推箱子！\n");
	printf("当前步数是%d\n", step);
	printf("&是小人，#是箱子，$是目的地！\n");
}

void control(int level) {
	int i;
	step = 0;
	for (i = 0; i < 21; i++) {
		Board[i][40] = 1;
	}
	for (i = 0; i < 41; i++) {
		Board[20][i] = 2;
	}
	if (level == 1) {
		Board[1][1] = 9;
		Board[2][2] = 8;
		Board[15][30] = 7; 
	}
	else if (level == 2) {
		Board[1][1] = 9;
		Board[2][2] = 8;
		Board[15][30] = 7;
		for (i = 0; i < 20; i++) {
			if (i == 13 || i == 14) {
				continue;
			}
			Board[i][20] = 6;
		}
	}
	else if (level == 3) {
		Board[1][1] = 9;
		Board[17][19] = 8;
		Board[15][3] = 7;
		for (i = 0; i < 20; i++) {
			if (i == 15 || i == 16) {
				continue;
			}
			Board[i][20] = 6;
		}
	}
	else if (level == 4) {
		Board[1][1] = 9;
		Board[17][19] = 8;
		Board[15][3] = 7;
		for (i = 0; i < 20; i++) {
			if (i == 15 || i == 16) {
				continue;
			}
			Board[i][20] = 6;
		}
		Board[14][4] = 6;
		Board[14][3] = 6;
		Board[14][2] = 6;
		Board[15][4] = 6;
		Board[16][4] = 6;
		Board[16][3] = 6;
		Board[16][2] = 6;
	}
	else if (level == 5) {
		Board[1][1] = 9;
		Board[17][19] = 8;
		Board[17][30] = 8;
		Board[15][3] = 7;
		Board[2][30] = 7;
		for (i = 0; i < 20; i++) {
			if (i == 15 || i == 16) {
				continue;
			}
			Board[i][20] = 6;
		}
		Board[14][4] = 6;
		Board[14][3] = 6;
		Board[14][2] = 6;
		Board[15][4] = 6;
		Board[16][4] = 6;
		Board[16][3] = 6;
		Board[16][2] = 6;

		Board[1][30] = 6;
		Board[1][29] = 6;
		Board[2][29] = 6;
		Board[1][31] = 6;
		Board[2][31] = 6;
		Board[3][31] = 6;
		Board[3][29] = 6;
	}
	else if (level == 6) {
		Board[7][20] = 9;
		Board[7][17] = 8;
		Board[9][29] = 7;
		for (i = 5; i < 11; i++) {
			Board[i][15] = 6;
		}
		for (i = 5; i < 11; i++) {
			Board[i][30] = 6;
		}
		for (i = 16; i < 30; i++) {
			Board[5][i] = 6;
		}
		for (i = 16; i < 30; i++) {
			Board[10][i] = 6;
		}
	}
	else if (level == 7) {
		Board[7][20] = 9;
		Board[7][17] = 8;
		Board[8][17] = 8;
		Board[9][29] = 7;
		Board[6][29] = 7;
		for (i = 5; i < 11; i++) {
			Board[i][15] = 6;
		}
		for (i = 5; i < 11; i++) {
			Board[i][30] = 6;
		}
		for (i = 16; i < 30; i++) {
			Board[5][i] = 6;
		}
		for (i = 16; i < 30; i++) {
			Board[10][i] = 6;
		}
		for (i = 5; i < 11; i++) {
			if (i == 7 || i == 8) {
				continue;
			}
			Board[i][28] = 6;
		}
	}
	else if (level == 8) {
		Board[7][20] = 9;
		Board[7][17] = 8;
		Board[8][17] = 8;
		Board[8][19] = 8;
		Board[9][29] = 7;
		Board[6][29] = 7;
		Board[6][21] = 7;
		for (i = 5; i < 11; i++) {
			Board[i][15] = 6;
		}
		for (i = 5; i < 11; i++) {
			Board[i][30] = 6;
		}
		for (i = 16; i < 30; i++) {
			Board[5][i] = 6;
		}
		for (i = 16; i < 30; i++) {
			Board[10][i] = 6;
		}
		for (i = 5; i < 11; i++) {
			if (i == 7 || i == 8) {
				continue;
			}
			Board[i][28] = 6;
		}
		for (i = 5; i < 11; i++) {
			if (i == 7 || i == 8) {
				continue;
			}
			Board[i][20] = 6;
		}
	}
	else if (level == 9) {
		Board[7][20] = 9;
		Board[7][17] = 8;
		Board[8][17] = 8;
		Board[8][19] = 8;
		Board[8][24] = 8;
		Board[9][29] = 7;
		Board[6][29] = 7;
		Board[6][21] = 7;
		Board[9][21] = 7;
		for (i = 5; i < 11; i++) {
			Board[i][15] = 6;
		}
		for (i = 5; i < 11; i++) {
			Board[i][30] = 6;
		}
		for (i = 16; i < 30; i++) {
			Board[5][i] = 6;
		}
		for (i = 16; i < 30; i++) {
			Board[10][i] = 6;
		}
		for (i = 5; i < 11; i++) {
			if (i == 7 || i == 8) {
				continue;
			}
			Board[i][28] = 6;
		}
		for (i = 5; i < 11; i++) {
			if (i == 7 || i == 8) {
				continue;
			}
			Board[i][20] = 6;
		}
	}
}
