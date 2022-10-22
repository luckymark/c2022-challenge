#include<stdio.h>
#include<stdlib.h>
//### 题目：单向链表
//### 功能要求：
//
//1. 在 main 函数中创建一个单向链表；
//2. 遍历该链表，依次现实各节点的 value；
//3. 将该链表所有节点反序；
//4. 在该链表中查找第一个值为 5 的节点，如果找到则返回该节点的序号，否则返回－1；
//5. 查找下一个值为 5 的节点，返回值同上；

//定义单链表的数据结构
typedef struct listnode
{
    int data;//数据域
    struct listnode* next;//下一个结点的地址
    int position;
}*list;
struct listnode mallocnode;//用来赋内存
list listnode = NULL;


void CreateList(list head);
void PrintList(list head);
void ListDelete(list head, int i, int* e);
void ListInsert(list head, int i, int e);
void ReverseList(list head);
int GetNode1(list head);
int GetNode2(list head);

int main()
{
    list head;
    int i, e, select;
    //i:位置
    //e:元素
    head = (list)malloc(sizeof(mallocnode));
    head->next = NULL;
    system("pause");
    return 0;
}




//1、2
//单链表的建立
//（1）定义单链表的数据结构；
//（2）读取数据；
//（3）生成新结点；
//（4）将数据存入结点的成员变量中；
//（5）将新结点连接到表头或表尾。
//重复（2）~（5）直到输入结束。


void CreateList(list head)
{
    list p, rear = head;
    puts("输入若干整数，输入-1表示输入结束");
    int num;
    scanf_s("%d", &num);
    while (num != -1)
    {
        p = (list)malloc(sizeof(listnode));
        p->data = num;
        rear->next = p;
        rear = p;
    }
    rear->next = NULL;
}

void PrintList(list head)
{
    list p = head->next;
    while (p)
    {
        printf("%d ", p->data);
        p = p->next;
    }
}

void ListDelete(list head, int i, int* e)
{
    list p, pre = head;
    int j = 0;
    while (pre && j < i - 1)
    {
        pre = pre->next;
        j++;
    }
    if (!pre || i < 1)
    {
        printf("i值错误\n");
        return;
    }

    p = pre->next;
    pre->next = p->next;
    *e = p->data;
    free(p);
}
void ListInsert(list head, int i, int e)
{
    list p, pre = head;
    int j = 0;
    while (pre && j < i - 1)
    {
        pre = pre->next;
        j++;
    }
    if (!pre || i < 1)
    {
        printf("i值错误\n");
        return;
    }
    p = (list)malloc(sizeof(mallocnode));
    p->data = e;
    p->position = i;
    p->next = pre->next;
    pre->next = p;
}

//反序
void ReverseList(list head) 
{
    //链表为空直接返回
    if (head->next == NULL)  
    {
        return;
    }

    //定义一个辅助的指针(变量)，帮助我们遍历原来的链表
    list cur = head->next;
    list next = NULL;
    list ReverseHead = head;
    //遍历原来的链表，每遍历一个节点，就将其取出，并放在新的链表reverseHead 的最前端

    while (cur != NULL)
    {
        next = cur->next;//先暂时保存当前节点的下一个节点，因为后面需要使用
        cur->next = ReverseHead->next;//将cur的下一个节点指向新的链表的最前端
        ReverseHead->next = cur; //将cur 连接到新的链表上
        cur = next;//让cur后移
    }
    
    head->next = ReverseHead->next;

}
//查找
int GetNode1(list head)//寻找节点数1 
{
    int cnt = 0;
    while (head->data != 5)
    {
        head = head->next;
        cnt++;
    }
    return cnt;  
}
int GetNode2(list head)//寻找节点数2 
{
    static int cnt1 = 0;
    int cnt2 = 0;
    while (cnt2<2)
    {
        while (head->data != 5)
        {
            head = head->next;
            cnt1++;
        }
        cnt2++;
    }
    return cnt1;
}