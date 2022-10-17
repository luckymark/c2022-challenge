### 功能要求：

1. 打印出所有3位水仙花数

水仙花数：n位数的每个数位的n次方之和等于该n位数本身

例如：153=1^3+5^3+3^3

#include <stdio.h>

int main() {
    for (int i = 100; i < 999; ++i) {
        int a = i/100;
        int b = (i-100*a)/10;
        int c = i%10;
        if (a*a*a+b*b*b+c*c*c==i){
            printf("%d\t",i);
        }
    }
    return 0;
}
