#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>

char *Encrypt(char *pText);
char *Decrypt(char *pText);
void main(){

    int len;
    char *pText;
    pText=(char *)malloc(sizeof(char));

    printf("请输入密码:\n");
    fflush(stdout);
    scanf("%s",pText);


    pText=Encrypt(pText);
    printf("加密后的密码是%s\n",pText);

    pText= Decrypt(pText);
    printf("解密后的密码是%s\n",pText);
}

char *Encrypt(char *pText){
    int len,i=0;

    char *pTem=NULL;
    pTem=(char *)malloc(sizeof(char));

    len=strlen(pText);

    for (i ; i<len ; i++) { pTem[i] = pText[i] + 1; }

    pTem[i]='\000';

    return pTem;
}

char *Decrypt(char *pText) {
    int len, i = 0;

    char *pTem = NULL;
    pTem = (char *) malloc(sizeof(char));

    len = strlen(pText);

    for (i; i < len; i++) { pTem[i] = pText[i] - 1; }

    pTem[i] = '\000';

    return pTem;
}