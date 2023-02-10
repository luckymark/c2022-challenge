#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#define MaxLength 50
#define xLength 11
#define yLength 11
void wall();
int path(int x, int y);
void display();
char a[MaxLength + 2][MaxLength + 2] = { 0 };
int c1, c2;

int main() {
	int x = 2, y = 2;
	char ch, sh;
	int num = 1;
	wall();
	display();
	printf("请输入一个字符+enter开始游戏");
	while (x != xLength * 2 + 2 || y != yLength * 2 + 2)
	{	
		printf("Please send me a letter:\n");
	    printf("Send W,A,S,D to control your place:\n");
		printf("\n");
		getchar();
		while (sh = getchar() != '0') {
			ch = getchar();
			if (num == 1) {
				a[2][2] = 2;
			}
			if (ch == 'S')
			{
				if (a[x + 1][y] == 1)
				{
					a[x][y] = 1;
					x++;
					a[x][y] = 2;
				}
			}
			else if (ch == 'W')
			{
				if (a[x - 1][y] == 1)
				{
					a[x][y] = 1;
					x--;
					a[x][y] = 2;
				}
			}
			else if (ch == 'A')
			{
				if (a[x][y - 1] == 1)
				{
					a[x][y] = 1;
					y--;
					a[x][y] = 2;
				}
			}
			else if (ch == 'D')
			{
				if (a[x][y + 1] == 1)
				{
					a[x][y] = 1;
					y++;
					a[x][y] = 2;
				}
			}
			system("cls");
			num++;
			display();
			if (x >= xLength * 2 + 2 && y >= yLength * 2 + 1)
				break;
		}
	}
	system("cls");
	printf("WIN!");
	system("pause");
	return 0;
}

void wall() {
	for (c1 = 0, c2 = yLength * 2 + 2; c1 <= xLength * 2 + 2; ++c1) {
		a[c1][0] = 1;
		a[c1][c2] = 1;
	}
	for (c1 = xLength * 2 + 2, c2 = 0; c2 <= yLength * 2 + 2; ++c2) {
		a[0][c2] = 1;
		a[c1][c2] = 1;
	}
	a[2][1] = 1;
	a[xLength * 2][yLength * 2 + 1] = 1;
	srand((unsigned)time(NULL));
	path(rand() % xLength + 1, rand() % yLength + 1);
}

int path(int x, int y) {
	static int direction[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };
	int cx = x * 2;
	int cy = y * 2;
	a[cx][cy] = 1;
	int turn = rand() % 2 ? 1 : 3;
	int next, i;
	for (i = 0, next = rand() % 4; i < 4; ++i, next = (next + turn) % 4) {
		int x1 = cx + direction[next][0] * 2;
		int y1 = cy + direction[next][1] * 2;
		int x2 = cx + direction[next][0];
		int y2 = cy + direction[next][1];
		int x3 = x + direction[next][0];
		int y3 = y + direction[next][1];
		if (a[x1][y1] == 0) {
			a[x2][y2] = 1;
			path(x3, y3);
		}
	}
	return 0;
}
void display()
{
	for (int i = 0; i <= xLength * 2 + 2; ++i) {
		printf("\n");
		for (int j = 0; j <= yLength * 2 + 2; ++j) {
			if (a[i][j] == 1) {
				printf("  ");
			}
			else if (a[i][j] == 2) {
				printf("A");
			}
			else {
				printf("* ");
			}
		}
	}
}
