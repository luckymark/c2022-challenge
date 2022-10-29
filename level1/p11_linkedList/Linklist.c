#include<stdio.h>
#include<stdlib.h>
//### ��Ŀ����������
//### ����Ҫ��
//
//1. �� main �����д���һ����������
//2. ����������������ʵ���ڵ�� value��
//3. �����������нڵ㷴��
//4. �ڸ������в��ҵ�һ��ֵΪ 5 �Ľڵ㣬����ҵ��򷵻ظýڵ����ţ����򷵻أ�1��
//5. ������һ��ֵΪ 5 �Ľڵ㣬����ֵͬ�ϣ�

//���嵥��������ݽṹ
typedef struct listnode
{
    int data;//������
    struct listnode* next;//��һ�����ĵ�ַ
    int position;
}*list;
struct listnode mallocnode;//�������ڴ�
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
    //i:λ��
    //e:Ԫ��
    head = (list)malloc(sizeof(mallocnode));
    head->next = NULL;
    system("pause");
    return 0;
}




//1��2
//������Ľ���
//��1�����嵥��������ݽṹ��
//��2����ȡ���ݣ�
//��3�������½�㣻
//��4�������ݴ�����ĳ�Ա�����У�
//��5�����½�����ӵ���ͷ���β��
//�ظ���2��~��5��ֱ�����������


void CreateList(list head)
{
    list p, rear = head;
    puts("������������������-1��ʾ�������");
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
        printf("iֵ����\n");
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
        printf("iֵ����\n");
        return;
    }
    p = (list)malloc(sizeof(mallocnode));
    p->data = e;
    p->position = i;
    p->next = pre->next;
    pre->next = p;
}

//����
void ReverseList(list head) 
{
    //����Ϊ��ֱ�ӷ���
    if (head->next == NULL)  
    {
        return;
    }

    //����һ��������ָ��(����)���������Ǳ���ԭ��������
    list cur = head->next;
    list next = NULL;
    list ReverseHead = head;
    //����ԭ��������ÿ����һ���ڵ㣬�ͽ���ȡ�����������µ�����reverseHead ����ǰ��

    while (cur != NULL)
    {
        next = cur->next;//����ʱ���浱ǰ�ڵ����һ���ڵ㣬��Ϊ������Ҫʹ��
        cur->next = ReverseHead->next;//��cur����һ���ڵ�ָ���µ��������ǰ��
        ReverseHead->next = cur; //��cur ���ӵ��µ�������
        cur = next;//��cur����
    }
    
    head->next = ReverseHead->next;

}
//����
int GetNode1(list head)//Ѱ�ҽڵ���1 
{
    int cnt = 0;
    while (head->data != 5)
    {
        head = head->next;
        cnt++;
    }
    return cnt;  
}
int GetNode2(list head)//Ѱ�ҽڵ���2 
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