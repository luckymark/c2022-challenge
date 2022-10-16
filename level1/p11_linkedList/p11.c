#include <stdio.h>
#include <stdlib.h>
typedef struct linklist{
    int score;
    struct linelist *next;
}linklist;

void creat(int n);
void reverse(int n);
linklist* get(int i);
void traverse(int n);
int find(int sta,int n,int a);

linklist *head,*node,*end;

int main() {
    int n;
    printf("请输入节点数：");
    scanf("%d",&n);
    creat(n);//创造单向链表
    traverse(n);//遍历单向链表
    reverse(n);//反序单向链表
    traverse(n);//遍历单向链表
    int a;
    printf("请输入要寻找的数：");
    scanf("%d",&a);
    find(1,n,a);//在节点1到n查找数据a
    printf("%d",find(1,n,a));
    if(find(1,n,a) != n){
        find(find(1,n,a)+1,n,a);
    }
    return 0;
}
void creat(int n) {
    head = (linklist*) malloc(sizeof(linklist));
    end = head;
    for(int i = 1;i <= n;++i) {
        node = (linklist*) malloc(sizeof(linklist));
        printf("请输入要存入的数据：");
        scanf("%d",&node->score);
        end->next = node;
        end = node;
    }
    end->next = NULL;
}

void traverse(int n) {
    for (int i = 1; i <= n; ++i) {
        printf("%d",get(i)->score);
    }
    printf("\n");
}
void reverse(int n) {
    for(int i = 1;i <= n/2;i++){
        int t;
        t = get(i)->score;
        get(i)->score = get(n-i+1)->score;
        get(n-i+1)->score = t;
    }
}
linklist* get(int i) {//取出除头结点外第i个节点的数据
    linklist* p = head->next;
    for(int k = 1;k != i;k++) {
        p = p->next;
    }
    return p;
}
int find(int sta,int n,int a) {
    for (int i = sta; i <= n; ++i) {
        if(get(i)->score == a){
            return i;
        }
    }
    return -1;
}
