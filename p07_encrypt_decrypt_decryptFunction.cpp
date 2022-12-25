#include"p07_encrypt_decrypt.h"
void decrypt(void) {
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
				putchar(code += 25);
			}
			else if (code == '0') { putchar('9'); }
			else putchar(code);
		}
	} while (code != '\n');
}