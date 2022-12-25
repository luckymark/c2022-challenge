#include <stdio.h>
int main()
{
    int one, ten, hundred;
    for (int num = 100; num < 1000; ++num) {
        one = num / 100;
        ten = (num - one * 100) / 10;
        hundred = num - one * 100 - ten * 10;
        if (one * one * one + ten * ten * ten + hundred * hundred * hundred == num)
        {
            printf("%d ", num);
        }
    }
    return 0;
}

