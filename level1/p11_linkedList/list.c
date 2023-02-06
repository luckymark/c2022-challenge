#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct node {
    int val;
    int serial;                    //��¼�ýڵ�����
    struct node* next;
}Node;
typedef struct list {
    int count;                    //count�ڵ������
    Node* head;
    Node* end;                     //���㷴��ʱ��Ϊͷָ���ҷ�����ӽڵ�
}List;
void initializeList(List* plist);
bool addVal(int n, List* plist);              //n���û������룬�����Ƕ�̬��
void printVal(List* plist);
void reverse(List* plist);                   //��������������⣺���ѽڵ����ŵ��û����������ã���Ϊ�ǡ��������������Ҳ�ȡ�˵�һ��
int seekVal(void);                   //��Ϊ��̫�������ʲô��˼�������˸��Ƚϴֲڵ�ʵ�֣�Ҫ���ͷβ������ӡ��˫��������ö�
bool beenReversed;                                  //ÿ�ε���reverseʱ�жϴ�ʱΪ�����Ƿ���
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
    getchar();                                      //����û�������q�ͻ��з�
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
        (*plist).head = (*plist).end = pnew;                      //��ʱͷβ��Ϊ��һ���ڵ�
        (*plist).head->next = NULL;
        (*plist).count++;
        (*plist).head->serial = (*plist).count;
        (*plist).head->val = n;
        seekCur = (*plist).head;                                //head��Ϊ��ʱ��������ʼ��seekCur����Ϊhead
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
    Node* pnode = (*plist).head;                            //�������������Ƿ�Ϊ�յ��ж�
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
int seekVal(void) {                               //ȫ�ֱ����Ͳ��ô������ˣ�����С��ʱ���õ�ȷ��ʡ��
    Node* pnode = seekCur->next;                        //����ٶ�ʹ����addVal֮����seekVal��Ҳ���Գ�ʼ��seekCur֮���һ��seekCur�Ƿ�ΪNULL���ж�
    while (pnode != NULL) {
        if (pnode->val == 5) {
            seekCur = pnode;
            return pnode->serial;
        }
        pnode = pnode->next;
    }
    return -1;
}
