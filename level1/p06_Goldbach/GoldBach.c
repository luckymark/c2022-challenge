#include <stdio.h>
#include <math.h>

int judgePrime(int n);

void main() {
    int n;

    printf("请输入一个NUMBER:\n");
    fflush(stdout);
    scanf("%d", &n);

    if (n > 2 && n % 2 == 0) {
        for (int i = 2; i <= (n / 2); i++) {
            int j = n - i;
            if (judgePrime(i) == 1 && judgePrime(j) == 1)
                printf("%d = %d + %d\n", n, i, j);
            fflush(stdout);
        }

    }
    else {printf("请输入大于2以上的偶数欧~~~");
        fflush(stdout);}
}
int judgePrime(int n){

    if(n==2){
        return 1;
    }
    for(int i=2;i<=sqrt(n);i++){

        if(n%i==0){
            return 0;
        }
    }
    return 1;
}

