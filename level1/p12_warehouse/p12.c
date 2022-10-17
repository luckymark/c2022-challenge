#include <stdio.h>
#include <stdlib.h>
void function(int get_key,int* a,int* b,int* g);
void table(int a,int b,int g);
void get_in(int get_key2,int *a,int *b,int *g,int num);
void get_out(int get_key2,int *a,int *b,int *g,int num);

int main() {
    int get_key;
    int a = 2;
    int b = 3;
    int g = 2;
    while(1){
        printf("显示存货列表请按1，入库请按2，出库请按3，退出程序请按4");
        scanf("%d",&get_key);
        function(get_key,&a,&b,&g);
    }
}
void function(int get_key,int* a,int* b,int* g) {
    int get_key2;
    int num;
    switch (get_key) {
        case 1:
            table(*a,*b,*g);
            break;
        case 2:

            printf("请选择要入库的水果，苹果请按1，香蕉请按2，葡萄请按3");
            scanf("%d",&get_key2);
            printf("请输入要入库的数量：");
            scanf("%d",&num);
            get_in(get_key2,a,b,g,num);
            break;
        case 3:
            printf("请选择要出库的水果，苹果请按1，香蕉请按2，葡萄请按3");
            scanf("%d",&get_key2);
            printf("请输入要出库的数量：");
            scanf("%d",&num);
            get_out(get_key2,a,b,g,num);
            break;
        case 4:
            exit(0);
        default:
            printf("输入错误\n");
    }

}
void table(int a,int b,int g) {
    printf("apple:   %d\n",a);
    printf("banana:  %d\n",b);
    printf("grape:   %d\n",g);
}
void get_in(int get_key2,int *a,int *b,int *g,int num) {
    switch (get_key2) {
        case 1:
            *a = *a + num;
            break;
        case 2:
            *b = *b + num;
            break;
        case 3:
            *g = *g + num;
            break;
        default:
            printf("输入错误\n");
    }
}
void get_out(int get_key2,int *a,int *b,int *g,int num) {
    switch (get_key2) {
        case 1:
            *a = *a - num;
            if(*a < 0){
                *a = *a +num;
                printf("出库无效，无足够产品\n");
            }
            break;
        case 2:
            *b = *b - num;
            if(*a < 0){
                *a = *a +num;
                printf("出库无效，无足够产品\n");
            }
            break;
        case 3:
            *g = *g - num;
            if(*a < 0){
                *a = *a +num;
                printf("出库无效，无足够产品\n");
            }
            break;
        default:
            printf("输入错误\n");
    }
}
