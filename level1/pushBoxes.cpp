#include <stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
int main() {
	char ar[11][11] = {
		"0000000000",
		"0000000000",
		"0000000000",
		"000&000000",
		"000@000000",
		"000#*  000",
		"000 $  000",
		"000  00000",
		"0000000000",
		"0000000000",
		"0000000000"
	};
	char cha;
	int x = 5, y = 3, a = 4, b = 3, A = 5, B = 4, C = 6, D = 4, c = 3, d = 3, i, flag = 0;
	for (i = 0; i < 11;++i) {
		puts(ar[i]);
	}
	printf("*->@ $->&\nPlease use wasd to move");
	while (A != a || B != b || C != c || D != d) {
		cha = _getch();
		if (cha == 's') {
			if (ar[x + 1][y] == ' '||ar[x+1][y]=='@'||ar[x+1][y]=='&') {
				ar[x][y] = ' ';
				ar[++x][y] = '#';
				++flag;
			}
			else if (ar[x+2][y ] != '0') {
			     if ((ar[x + 1][y] == '*' || ar[x + 1][y] == '$') && (ar[x + 2][y] == '*' || ar[x + 2][y] == '$') && (ar[x + 3][y] != '0')) {
				    ar[C += 1][D] = '$';
				    ar[A += 1][B] = '*';
				    ar[x][y] = ' ';
				    ar[++x][y] = '#';
				++flag;
			}
				else if (ar[x+1][y ] == '*' && ar[x+2][y ] != '$') {
					ar[A+=1][B ] = '*';
					ar[x][y] = ' ';
					ar[++x][y] = '#';
					++flag;
				}
				else if (ar[x+1][y ] == '$' && ar[x+2][y ] != '*') {
					ar[C+=1][D ] = '$';
					ar[x][y] = ' ';
					ar[++x][y] = '#';
					++flag;
				}
			}
		}
		if (cha == 'w' ) {
			if (ar[x - 1][y] == ' ' || ar[x - 1][y] == '@' || ar[x - 1][y] == '&') {
				ar[x][y] = ' ';
				ar[--x][y] = '#';
				++flag;
			}
			else if (ar[x - 2][y] != '0') {
			 if ((ar[x - 3][y] != '0')&&(ar[x - 1][y] == '*' || ar[x - 1][y] == '$') && (ar[x - 2][y] == '*' || ar[x - 2][y] == '$')) {
				ar[C -= 1][D] = '$';
				ar[A -= 1][B] = '*';
				ar[x][y] = ' ';
				ar[--x][y] = '#';
				++flag;
			}
			 else if (ar[x - 1][y] == '*' && ar[x-2][y ] != '$') {
					ar[A -= 1][B] = '*';
					ar[x][y] = ' ';
					ar[--x][y] = '#';
					++flag;
				}
				else if (ar[x - 1][y] == '$' && ar[x-2][y ] != '*') {
					ar[C -= 1][D] = '$';
					ar[x][y] = ' ';
					ar[--x][y] = '#';
					++flag;
				}
			}
		}
		if (cha == 'd' && ar[x][y + 1] != '0') {
				if (ar[x][y + 1] == ' ' || ar[x][y + 1] == '@' || ar[x][y + 1] == '&') {
					ar[x][y] = ' ';
					ar[x][++y] = '#';
					++flag;
				}	
				else if (ar[x][y + 2] != '0') {
						if ((ar[x][y + 3] != '0')&&(ar[x][y + 1] == '*' || ar[x][y + 1] == '$') && (ar[x][y + 2] == '*' || ar[x][y + 2] == '$')) {
							ar[C][D += 1] = '$';
							ar[A][B += 1] = '*';
							ar[x][y] = ' ';
							ar[x][++y] = '#';
							++flag;
						}
			        else if (ar[x][y + 1] == '*'&&ar[x][y+2]!='$') {
					    ar[A][B += 1] = '*';
					    ar[x][y] = ' ';
					    ar[x][++y] = '#';
					    ++flag;
				    }
				    else if (ar[x][y + 1] == '$'&&ar[x][y+2]!='*') {
					    ar[C][D += 1] = '$';
					    ar[x][y] = ' ';
					    ar[x][++y] = '#';
					    ++flag;
				    }
			    }   
		}
		if (cha == 'a' && ar[x][y - 1] != '0') {
			if (ar[x][y - 1] == ' ' || ar[x][y - 1] == '@' || ar[x][y - 1] == '&') {
				ar[x][y] = ' ';
				ar[x][--y] = '#';
				++flag;
			}
			else if (ar[x][y - 2] != '0') {
				if ((ar[x][y - 1] == '*' || ar[x][y - 1] == '$') && (ar[x][y - 2] == '*' || ar[x][y - 2] == '$')&&(ar[x][y-3]!='0')) {
					ar[C][D -= 1] = '$';
					ar[A][B -= 1] = '*';
					ar[x][y] = ' ';
					ar[x][--y] = '#';
					++flag;
				}
				else if (ar[x][y - 1] == '*' && ar[x][y - 2] != '$') {
					ar[A][B -= 1] = '*';
					ar[x][y] = ' ';
					ar[x][--y] = '#';
					++flag;
				}
				else if (ar[x][y - 1] == '$' && ar[x][y - 2] != '*') {
					ar[C][D -= 1] = '$';
					ar[x][y] = ' ';
					ar[x][--y] = '#';
					++flag;
				}
			}
		}
		system("cls");
		if (ar[4][3] != '#'&& ar[4][3] != '$' && ar[4][3] != '*') { ar[4][3] = '@'; }
		if (ar[3][3] != '#' && ar[3][3] != '$' && ar[3][3] != '*') { ar[3][3] = '&'; }
		for (i = 0; i < 11; ++i) {
			puts(ar[i]);
		}
		Sleep(100);
	}
	printf("You win!The score is %d", 122-flag);
	return 0;
}
//int*p=()malloc(100*sizeof());free(p)