#include"p10_pushBoxes.h"

void savegoal(int Goal) {
	FILE* fp;
	fopen_s(&fp, "C:\\Users\\86134\\source\\repos\\p10_pushBoxes\\goal.txt", "a");
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
	int x , y , A = 0, B = 0, C = 0, D = 0, a = 0, b = 0, c = 0, d = 0;//where to start(x,y) where is the boxes(A,B C,D) where is the goals(a,b c,d) 
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
	int fullgoal = 100, goal;
	printf("\nYou win!The score is %d", goal = fullgoal - step);
	return goal;
}