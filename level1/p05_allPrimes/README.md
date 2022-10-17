### 功能要求：

1. 打印2-1000以内的所有素数
1. 打印出总的计算时间
1. 尽可能优化算法的效率

#include <stdio.h>
#include <time.h>
#include <math.h>
int main() {
    clock_t t1,t2;
    t1 = clock();
    for (int i = 2;i <= 1000;i++){
        int q = sqrt((double)i);
        for (int j = 2;j <= q;j++){
            if (i%j != 0){
                continue;
            }else{
                goto next;
            }
        }
        printf("%d,",i);
        next: ;
    }
    t2 = clock();
    double t = 1.0*(t2 - t1)/CLK_TCK;
    printf("\n程序计算所用时间为：%lf秒",t);
    return 0;
}
