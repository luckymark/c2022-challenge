#include<stdio.h>
#include<stdlib.h>

void encrypt();
void decrypt();
int main() {
	int choice;
	printf("Would you like to encrypt or decrypt?\n");
	printf("Input 1 for encrypt or 2 for decrypt:\n");
	scanf_s("%d", &choice);
	getchar();
	switch (choice) {
	case 1:
		encrypt();
		break;
	case 2:
		decrypt();
		break;
	default:
		break;
	}
	return 0;
}

void encrypt()
{
	int key;
	char string[128];
	char c;
    printf("Please input the key:\n");
	scanf_s("%d", &key);
	printf("Please input the encry string:\n");
	printf("The encoded string is:\n");
	getchar();
	while ((c = getchar()) != '\n') {
		int i = 0;
		string[i] = c;
		i++;
		printf("%c", c + key);
	}
	printf("\n");
}

void decrypt()
{
	int key;
	char string[128];
	char c;
	printf("Please input the key:\n");
	scanf_s("%d", &key);
	printf("Please input the encry string:\n");
	printf("The encoded string is:\n");
	getchar();
	while ((c = getchar()) != '\n') {
		int i = 0;
		string[i] = c;
		i++;
		printf("%c", c - key);
	}
	printf("\n");
}
