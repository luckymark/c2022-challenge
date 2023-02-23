#include <stdio.h>
#include <math.h>

int Judge(int x);

int main(void)
{
    int First,Second,Third;

    for (int i=153; i <= 999;++i) {
//        printf("%d",((Judge(i)) ? i : ));         这行有办法让 语句（a ？b : c)里的 c 不输出任何东西吗？
        Judge(i)?printf("%d\n",i):i==i;

    }

}

int Judge(int x) {

    if (x == (int)pow(x % 10,3) + (int)pow(x / 10 % 10,3) + (int)pow(x / 100,3)) {
        return x;}
    else {
        return 0;}


}
