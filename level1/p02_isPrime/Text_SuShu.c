#include <stdio.h>
#include <math.h>

int judge(int Number);

int main() {
    int Number;
    scanf("%d", &Number);

//    if (judge(Number)) {
//        printf("是素数");
//    } else{
//        printf("不是素数");
//    }

    printf(judge(Number)?"是素数":"不是素数");


}

int judge(int Number) {
    for (int i = 2; i <= sqrt(Number); ++i) {
        if (Number % i == 0)
            return 0;
    }

    return 1;


}












