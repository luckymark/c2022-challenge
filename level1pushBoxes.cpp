#include <stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
const int ROW = 7, QUEUE = 10;//include'\n' and NULL
char ar[ROW][QUEUE] = { 0 };
void map(char MAP[100]);
int play(void);
void savegoal(int Goal);
char MAP1[100] = "C:\\Users\\86134\\source\\repos\\box\\map1.txt";
char MAP2[100] = "C:\\Users\\86134\\source\\repos\\box\\map2.txt";
int main() {
	map(MAP1);
	int Goal=play();
	savegoal(Goal);
	printf("\nNext?\n1.yes 2.no\n");
	int choose = 2;
	scanf_s("%d", &choose);
	if (choose == 1) {
		map(MAP2);
		Goal=play();
		savegoal(Goal);
		return 0;
	}else{ return 0; }
}
void savegoal(int Goal) {
	FILE* fp;
	fopen_s(&fp, "C:\\Users\\86134\\source\\repos\\box\\goal.txt", "a");
	if (fp == NULL) {
		printf("fail\n");
		system("pause");
		exit(-1);
	}
	fprintf(fp, "%d\n", Goal);
	fclose(fp);
}
void map(char MAP[100]) {
	FILE* fp;
	fopen_s(&fp, MAP, "r");
	if (fp == NULL) {
		printf("fail\n");
		system("pause");
		exit(-1);
	}
	for (int i = 0; i < ROW; ++i) {
		fgets(ar[i], QUEUE, fp);
	}
	fclose(fp);
}
int play(void) {
	int x = 0, y = 0, A = 0, B = 0, C = 0, D = 0, a = 0, b = 0, c = 0, d = 0;//where to start(x,y) where is the boxes(A,B C,D) where is the goals(a,b c,d) 
	for (int i = 0; i < ROW; ++i) {
		for (int j = 0; j < QUEUE; ++j) {
			if (ar[i][j] == '#') { x = i; y = j; }
			if (ar[i][j] == '*') { A = i; B = j; }
			if (ar[i][j] == '@') { a = i; b = j; }
			if (ar[i][j] == '$') { C = i; D = j; }
			if (ar[i][j] == '&') { c = i; d = j; }
		}
	}
	system("cls");
	int  i;
	for (i = 0; i < ROW; ++i) {
		printf("%s", ar[i]);
	}
	printf("\n*->@ $->&\nPlease use W A S D to move");
	char cha;
	int step = 0;
	while (A != a || B != b || C != c || D != d) {
		cha = _getch();
		if (cha == 's') {
			if (ar[x + 1][y] == ' ' || ar[x + 1][y] == '@' || ar[x + 1][y] == '&') {
				ar[x][y] = ' ';
				ar[++x][y] = '#';
				++step;
			}
			else if (ar[x + 2][y] != '0') {
				if ((ar[x + 1][y] == '*' || ar[x + 1][y] == '$') && (ar[x + 2][y] == '*' || ar[x + 2][y] == '$') && (ar[x + 3][y] != '0')) {
					ar[C += 1][D] = '$';
					ar[A += 1][B] = '*';
					ar[x][y] = ' ';
					ar[++x][y] = '#';
					++step;
				}
				else if (ar[x + 1][y] == '*' && ar[x + 2][y] != '$') {
					ar[A += 1][B] = '*';
					ar[x][y] = ' ';
					ar[++x][y] = '#';
					++step;
				}
				else if (ar[x + 1][y] == '$' && ar[x + 2][y] != '*') {
					ar[C += 1][D] = '$';
					ar[x][y] = ' ';
					ar[++x][y] = '#';
					++step;
				}
			}
		}
		if (cha == 'w') {
			if (ar[x - 1][y] == ' ' || ar[x - 1][y] == '@' || ar[x - 1][y] == '&') {
				ar[x][y] = ' ';
				ar[--x][y] = '#';
				++step;
			}
			else if (ar[x - 2][y] != '0') {
				if ((ar[x - 3][y] != '0') && (ar[x - 1][y] == '*' || ar[x - 1][y] == '$') && (ar[x - 2][y] == '*' || ar[x - 2][y] == '$')) {
					ar[C -= 1][D] = '$';
					ar[A -= 1][B] = '*';
					ar[x][y] = ' ';
					ar[--x][y] = '#';
					++step;
				}
				else if (ar[x - 1][y] == '*' && ar[x - 2][y] != '$') {
					ar[A -= 1][B] = '*';
					ar[x][y] = ' ';
					ar[--x][y] = '#';
					++step;
				}
				else if (ar[x - 1][y] == '$' && ar[x - 2][y] != '*') {
					ar[C -= 1][D] = '$';
					ar[x][y] = ' ';
					ar[--x][y] = '#';
					++step;
				}
			}
		}
		if (cha == 'd' && ar[x][y + 1] != '0') {
			if (ar[x][y + 1] == ' ' || ar[x][y + 1] == '@' || ar[x][y + 1] == '&') {
				ar[x][y] = ' ';
				ar[x][++y] = '#';
				++step;
			}
			else if (ar[x][y + 2] != '0') {
				if ((ar[x][y + 3] != '0') && (ar[x][y + 1] == '*' || ar[x][y + 1] == '$') && (ar[x][y + 2] == '*' || ar[x][y + 2] == '$')) {
					ar[C][D += 1] = '$';
					ar[A][B += 1] = '*';
					ar[x][y] = ' ';
					ar[x][++y] = '#';
					++step;
				}
				else if (ar[x][y + 1] == '*' && ar[x][y + 2] != '$') {
					ar[A][B += 1] = '*';
					ar[x][y] = ' ';
					ar[x][++y] = '#';
					++step;
				}
				else if (ar[x][y + 1] == '$' && ar[x][y + 2] != '*') {
					ar[C][D += 1] = '$';
					ar[x][y] = ' ';
					ar[x][++y] = '#';
					++step;
				}
			}
		}
		if (cha == 'a' && ar[x][y - 1] != '0') {
			if (ar[x][y - 1] == ' ' || ar[x][y - 1] == '@' || ar[x][y - 1] == '&') {
				ar[x][y] = ' ';
				ar[x][--y] = '#';
				++step;
			}
			else if (ar[x][y - 2] != '0') {
				if ((ar[x][y - 1] == '*' || ar[x][y - 1] == '$') && (ar[x][y - 2] == '*' || ar[x][y - 2] == '$') && (ar[x][y - 3] != '0')) {
					ar[C][D -= 1] = '$';
					ar[A][B -= 1] = '*';
					ar[x][y] = ' ';
					ar[x][--y] = '#';
					++step;
				}
				else if (ar[x][y - 1] == '*' && ar[x][y - 2] != '$') {
					ar[A][B -= 1] = '*';
					ar[x][y] = ' ';
					ar[x][--y] = '#';
					++step;
				}
				else if (ar[x][y - 1] == '$' && ar[x][y - 2] != '*') {
					ar[C][D -= 1] = '$';
					ar[x][y] = ' ';
					ar[x][--y] = '#';
					++step;
				}
			}
		}
		system("cls");
		if (ar[a][b] != '#' && ar[a][b] != '$' && ar[a][b] != '*') { ar[a][b] = '@'; }
		if (ar[c][d] != '#' && ar[c][d] != '$' && ar[c][d] != '*') { ar[c][d] = '&'; }
		for (i = 0; i < ROW; ++i) {
			printf("%s", ar[i]);//incllude'\n'
		}
		Sleep(50);
	}
	int fullgoal = 100,goal;
	printf("\nYou win!The score is %d", goal=fullgoal - step);
	return goal;
}