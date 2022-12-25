#include"p07_encrypt_decrypt.h"
int main() {
	printf("1.encrypt 2.decrypt\n");
	char judge[3]={};
	gets_s(judge,3);
	if (judge[0] == '1') { encrypt(); }
	if (judge[0] == '2') { decrypt(); }
	return 0;
}