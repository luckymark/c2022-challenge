#include <stdio.h>
#include "HanLo.h"


void HanLo(int n, char Source, char Auxiliary, char Target, pstack A, pstack B, pstack C);

void main() {

    int data,Tier = 5;
    pstack A, B, C;

    A = creatStack(Tier);//分配三座塔的内存
    B = creatStack(Tier);
    C = creatStack(Tier);

    for (int i = Tier ; i>0 ; i--) {//给 起始塔 接受数据
        push(A, i);
    }

    HanLo(Tier, 'A', 'B', 'C', A, B, C);

    printf("A塔状态:\n");
    for (int i = 1;i<=Tier;i++) {
        printf("    | %c |\n", pop(A)); }

    printf("C塔状态:\n");
    for (int i = 1;i<=Tier;i++) {
        printf("    | %d |\n", pop(C)); }


}



void HanLo(int n, char Source, char Auxiliary, char Target, pstack A, pstack B, pstack C) {
    int temData;

    if (n == 1) {
        printf("%c -> %c\n", Source, Target);
        temData = pop(A);
        push(C, temData);
    }
    else {
        HanLo(n - 1, Source, Target, Auxiliary, A, C, B);

        printf("%c -> %c\n", Source, Target);
        temData = pop(A);
        push(C, temData);

        HanLo(n - 1, Auxiliary, Source, Target, B, A, C);
    }

}
