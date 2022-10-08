#include<stdio.h>
void encrypt() {
	char code;
	do {
		code = getchar();
		if (code != '\n') {
			if (code >= 'a' && code < 'z'
				|| code >= 'A' && code < 'Z'
				|| code >= '0' && code < '9') {
				putchar(++code);
			}
			else if (code == 'z' || code == 'Z') {
				putchar(code -= 25);
			}
			else if (code == '9') { putchar('0'); }
			else putchar(code);
		}
	} while (code != '\n');
}
void decrypt() {
	char code;
	do {
		code = getchar();
		if (code != '\n') {
			if (code > 'a' && code <= 'z'
				|| code > 'A' && code <= 'Z'
				|| code > '0' && code <= '9') {
				putchar(--code);
			}
			else if (code == 'a' || code == 'A') {
				putchar(code -= 25);
			}
			else if (code == '0') { putchar('9'); }
			else putchar(code);
		}
	} while (code != '\n');
}
int main() {
	printf("1.encrypt 2.decrypt\n");
	char judge[3]={};
	gets_s(judge,3);
	if (judge[0] == '1') { encrypt(); }
	if (judge[0] == '2') { decrypt(); }
	return 0;
}