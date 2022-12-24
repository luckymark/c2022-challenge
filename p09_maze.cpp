#include <stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
const int row = 10,queue=39, fullGoal = 167;
int main() {
	char ar[10][39] = {
"00000000000000000000000000000000000000",
"00000  000000000    00000000    0000 @",
"00     0         000       0 0     0 0",
"0000 0 00000 000 000 00000 0 000 000 0",
"0    0       0   0   0   0   0   0   0",
"0 0000 00000 0 000 000 0 00000 00000 0",
"0  0   00      0   0   0   0   0   0 0",
"00 0 000    00 0 0 00 0000 0 0 0 0 0 0",
"0#       0000    0       0   0   0   0",
"00000000000000000000000000000000000000"
	};

	int x , y , X , Y ;//where to start, where to end
	
	int i, flag = 0;
	for (i=0;i<row;++i) {
		for (int j = 0; j < queue-1; ++j) {
			if (ar[i][j] == '#') { x = i; y = j; }
			if (ar[i][j] == '@') { X = i; Y = j; }
		}
	}
	for (i = 0; i < row; ++i) {
		puts(ar[i]);
	}
	printf("Please use W A S D to move\n");
	char cha;
	while (x != X || y != Y) {
		cha = _getch();
		if (cha == 's' && ar[x + 1][y] != '0') {
			ar[x][y] = ' ';
			ar[++x][y] = '#';
			++flag;
		}
		else if (cha == 'w' && ar[x - 1][y] != '0') {
			ar[x][y] = ' ';
			ar[--x][y] = '#';
			++flag;
		}
		else if (cha == 'd' && ar[x][y + 1] != '0') {
			ar[x][y] = ' ';
			ar[x][++y] = '#';
			++flag;
		}
		else if (cha == 'a' && ar[x][y - 1] != '0') {
			ar[x][y] = ' ';
			ar[x][--y] = '#';
			++flag;
		}
		system("cls");
		for (i = 0; i <row; ++i) {
			puts(ar[i]);
		}
		Sleep(100);
	}
	printf("You win!Goal is %d", fullGoal - flag);
	return 0;
}