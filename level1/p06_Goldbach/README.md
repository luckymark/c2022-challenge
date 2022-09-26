### 功能要求：

1. 在100范围内验证哥德巴赫猜想的正确性

#include <stdio.h>
#include <math.h>
int main() {
    int tol = 0;
    int num[100] = {};
    for (int i = 2;i <= 100;i++){
        int q = sqrt((double)i);
        for (int j = 2;j <= q;j++){
            if (i%j != 0){
                continue;
            }else{
                goto next;
            }
        }
        tol++;
        num[tol-1] = i;
        next: ;
    }
    for (int j = 4;j <= 100;j = j + 2) {
        for (int q = 0; q <= tol-1;q++) {
            int w;
            w = j - num[q];
            for (int y = 0;y <= tol-1;y++){
                if (w != num[y]){
                    continue;
                }
                goto next2;
            }
        }
        printf("%d不符合哥德巴赫猜想",j);
        return -1;
        next2: ;
        printf("%d符合哥德巴赫猜想 ",j);
    }
    printf("\n哥德巴赫猜想在0到100内成立");
    return 0;
}
