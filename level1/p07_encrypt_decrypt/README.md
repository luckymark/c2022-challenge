### 功能要求：

1. 分别编写“加密”、“解密”函数，输入为任意长度的字符串

#include <stdio.h>
#include <windows.h>
void decrypt(char *c,int num);
void encrypt(char *c,int n);
int main() {
    char *pe = NULL;
    char *pd = NULL;
    char c[100] = {};
    int num = 0;
    printf("请输入字符串：");
    scanf("%s",c);
    for (num = 0;num >= 0;num++){
        if (c[num] == 0){
            break;
        }
    }
    encrypt(&c,num);
    printf("\n加密完成");
    printf("\n请设置数字密码：");
    int code;
    scanf("%d",&code);
    system("cls");
    next: ;
    printf("请输入密码进行解密：");
    int code1;
    scanf("%d",&code1);

    if (code == code1){
        decrypt(&c,num);
    }else{
        printf("密码错误请重试\n");
        Sleep(1000);
        goto next;
    }
    return 0;
}

void encrypt(char *c,int num){
    printf("加密后字符串为");
    for (int i = 0;i <= num-1;i++) {
        c[i]++;
        printf("%c",c[i]);
    }
    return;
}

void decrypt(char *c,int num) {
    printf("解密成功，字符串为：");
    for (int i = 0;i <= num-1;i++) {
        c[i]--;
        printf("%c",c[i]);
    }
    return;
}
