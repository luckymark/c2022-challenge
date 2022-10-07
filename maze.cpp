#include <stdio.h>
#include<stdlib.h>
int main() {  
	char ar[11][40] = {
" 00000000000000000000000000000000000000",
" 00000  000000000    00000000    0000 @",
" 00     0         000       0 0     0 0",
" 0000 0 00000 000 000 00000 0 000 000 0",
" 0    0       0   0   0   0   0   0   0",
" 0 0000 00000 0 000 000 0 00000 00000 0",
" 0  0   00      0   0   0   0   0   0 0",
" 00 0 000    00 0 0 00 0000 0 0 0 0 0 0",
" 0#       0000    0       0   0   0   0",
" 00000000000000000000000000000000000000",
	};
	char cha;
	int x = 8, y = 2, a = 1, b = 38;
	int i,flag=0;
	for (i = 0; i < 10; ++i) {
		puts(ar[i]);
	}
	while (x != a || y != b) {
		cha = getchar();
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
		for (i = 0; i < 10; ++i) {
			puts(ar[i]);
		}
	}
	printf("You win!Goal is %d",167-flag);
	return 0;
}