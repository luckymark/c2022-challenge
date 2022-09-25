### 功能要求：

1. 任意输入一个正整数n
1. 判断n是否为素数
#include <stdio.h>
int main() {
    int q;
    printf("请输入一个正整数：\n");
    scanf("%d",&q);
    for (int i = 2.0;i <= q-1;i = i + 1){
        if (q/i==q*1.0/i){
            printf("q不是素数");
            return 0;
        }
    }
    printf("q是素数");
    return 0;
}
