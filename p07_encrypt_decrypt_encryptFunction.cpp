#include"p07_encrypt_decrypt.h"
void encrypt(void) {
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