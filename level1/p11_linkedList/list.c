#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct node {
    int val;
    int serial;                    //记录该节点的序号
    struct node* next;
}Node;
typedef struct list {
    int count;                    //count节点的总数
    Node* head;
    Node* end;                     //方便反序时换为头指针且方便添加节点
}List;
void initializeList(List* plist);
bool addVal(int n, List* plist);              //n是用户的输入，链表长是动态的
void printVal(List* plist);
void reverse(List* plist);                   //“反序”有两种理解：仅把节点的序号倒置或者链表方向倒置，因为是“单向链表”所以我采取了第一种
int seekVal(void);                   //因为不太清楚到底什么意思所以做了个比较粗糙的实现，要真的头尾调换打印用双向链表方便得多
bool beenReversed;                                  //每次调用reverse时判断此时为正序还是反序
Node* seekCur;

int main(void) {
    List values;
    initializeList(&values);
    int input;
    printf("enter the numbers in order(type 'q' to break):\n");
    while (scanf("%d", &input) == 1) {
        addVal(input, &values);
    }
    getchar();
    getchar();                                      //处理没被读入的q和换行符
    char choice;
    int seek;
    beenReversed = false;
    puts("enter your choice(type 'q' to break):");
    puts("p: print each value in order");
    puts("r: reverse the sequence");
    puts("s: find the sequence of the first Node where number 5 is");
    while ((scanf("%c", &choice)) == 1) {
        getchar();
        switch (choice) {
        case 'p':
            printVal(&values);
            break;
        case 'r':
            reverse(&values);
            puts("succeed in reversing!");
            break;
        case 's':
            seek=seekVal();
            if (seek != -1) {
                printf("the sequence of the Node where number 5 first appear is %d\n", seek);
            }
            else {
                puts("no number 5 left!");
            }
            break;
        default:
            puts("please enter p,r or s");
            break;
        }
    }
    return 0;
}

void initializeList(List* plist) {
    (*plist).head = NULL;
    (*plist).end = NULL;
    (*plist).count = 0;
}
bool addVal(int n, List* plist) {
    Node* pnew = (Node*)malloc(sizeof(Node));
    if (pnew == NULL) {
        puts("can't create a new Node!\n");
        return false;
    }
    if ((*plist).head == NULL) {
        (*plist).head = (*plist).end = pnew;                      //此时头尾都为第一个节点
        (*plist).head->next = NULL;
        (*plist).count++;
        (*plist).head->serial = (*plist).count;
        (*plist).head->val = n;
        seekCur = (*plist).head;                                //head不为空时将查找起始点seekCur设置为head
    }
    else {
        (*plist).end->next = pnew;
        (*plist).end = pnew;
        (*plist).end->next = NULL;
        (*plist).end->val = n;
        (*plist).count++;
        pnew->serial = (*plist).count;
    }
    return true;
}
void printVal(List* plist) {
    Node* pnode = (*plist).head;                            //可以增加链表是否为空的判断
    while (pnode != NULL) {
        printf("Node %d 's value is %d.\n", pnode->serial, pnode->val);
        pnode = pnode->next;
    }
}
void reverse(List* plist) {
    Node* pnode = (*plist).head;
    if (!beenReversed) {
        for (int i = (*plist).count; i > 0; --i) {
            pnode->serial = i;
            pnode = pnode->next;
        }
        beenReversed = true;
    }
    else {
        for (int i = 1; i < (*plist).count + 1; ++i) {
            pnode->serial = i;
            pnode = pnode->next;
        }
        beenReversed = false;
    }
}
int seekVal(void) {                               //全局变量就不用传参数了，程序小的时候用的确很省事
    Node* pnode = seekCur->next;                        //这里假定使用者addVal之后再seekVal，也可以初始化seekCur之后加一个seekCur是否为NULL的判断
    while (pnode != NULL) {
        if (pnode->val == 5) {
            seekCur = pnode;
            return pnode->serial;
        }
        pnode = pnode->next;
    }
    return -1;
}
