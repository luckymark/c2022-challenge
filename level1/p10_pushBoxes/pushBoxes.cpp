//1. �ڵ�ͼ���������ӡ�����Ŀ��λ�õ�ͼ�Σ�
//1. ����ҽ��������ӹ�λ������ʾ���Ӯ������Ϸ��
//1. ������߶������Ƿ֣�
//1. ��ƶ���ؿ���ÿһ�صĵ�ͼ���ļ��ж�ȡ�����ÿ�صķ�����¼���ļ��У�


#include<stdio.h>
#include<stdlib.h>
#include <windows.h>
#include<conio.h>
#include"pushboxes.h"
static int recordgrades = 0;

int read(pushboxes *boxes)
{
    FILE* fp;
    int a, b;
    const char read_level[] = { "./pushboxes.txt" };
    if ((fp = fopen(read_level, "r")) == NULL)
    {
        return 0;
    }
    a = (int)fgetc(fp) - 48;
    boxes->len = a * 10 + (int)fgetc(fp) - 48;
    b = (int)fgetc(fp) - 48;
    boxes->wid = b * 10 + (int)fgetc(fp) - 48;
    for (int i = 0; i < boxes->wid; i++)
    {
        for (int j = 0; j < boxes->len; j++)
        {
            boxes->map_data[i][j] = (int)fgetc(fp) - 48;
            //���ݼ��
            printf("%d", boxes->map_data[i][j] = (int)fgetc(fp) - 48);
        }
    }
    fclose(fp);
    return 1;
}
void printPushboxes1(pushboxes *boxes)
{
    for (int i = 0; i < boxes->len; i++)
    {
        for (int j = 0; j < boxes->wid; j++)
        {
            if (boxes->map_data[i][j] == 0)//0->#��ǽ
            {
                boxes->map_dataprint[i][j] = '#';
                printf(boxes->map_dataprint[i][j]);
            }
            else if (boxes->map_data[i][j] == 1)//1->@������
            {
                boxes->map_dataprint[i][j] = '@';
                printf(boxes->map_dataprint[i][j]);
            }
            else if (boxes->map_data[i][j] == 2)//2->$����
            {
                boxes->map_dataprint[i][j] = '$';
                printf(boxes->map_dataprint[i][j]);
            }
            else if (boxes->map_data[i][j] == 3)//3->*��Ŀ��λ��
            {
                boxes->map_dataprint[i][j] = '*';
                printf(boxes->map_dataprint[i][j]);
            }
        }
    }
}
void printPushboxes2(pushboxes* boxes)
{
    for (int i = 0; i < boxes->len; i++)
    {
        for (int j = 0; j < boxes->wid; j++)
        {                  
            printf(boxes->map_dataprint[i][j]);
        }
    }
}
void findPosition(pushboxes *boxes)
{
    for (int i = 0; i < boxes->len; i++)
    {
        for (int j = 0; j < boxes->wid; j++)
        {
            if (boxes->map_data[i][j] == 1)
            {
                boxes->X_now = j;
                boxes->Y_now = i;
            }
            else if (boxes->map_data[i][j] == 2)
            {
                boxes->x_now = j;
                boxes->y_now = i;
            }
            else if (boxes->map_data[i][j] == 3)
            {
                boxes->X = j;
                boxes->Y = i;
            }
        }
    }
}

int ChangePosition(pushboxes* boxes)
{
    while (boxes->X_now != boxes->X || boxes->Y_now != boxes->Y)
    {
        char ch;
        scanf_s("%c", &ch);
        ch = getch();
        if (ch == 's')
        {
            if (boxes->map_data[boxes->x_now + 1][boxes->y_now] != '#')
            {
                boxes->map_data[boxes->x_now][boxes->y_now] = ' ';
                if (boxes->map_data[boxes->x_now + 1][boxes->y_now] = '@')
                {
                    boxes->X_now++;
                    boxes->x_now++;
                    boxes->map_dataprint[boxes->x_now][boxes->y_now] = '$';
                    boxes->map_dataprint[boxes->X_now][boxes->Y_now] = '@';
                }
                else
                {
                    boxes->x_now++;
                    boxes->map_dataprint[boxes->x_now][boxes->y_now] = '$';
                }
            }
        }
        if (ch == 'w')
        {
            if (boxes->map_data[boxes->x_now + 1][boxes->y_now] != '#')
            {
                boxes->map_data[boxes->x_now][boxes->y_now] = ' ';
                if (boxes->map_data[boxes->x_now + 1][boxes->y_now] = '@')
                {
                    boxes->X_now--;
                    boxes->x_now--;
                    boxes->map_dataprint[boxes->x_now][boxes->y_now] = '$';
                    boxes->map_dataprint[boxes->X_now][boxes->Y_now] = '@';
                }
                else
                {
                    boxes->x_now--;
                    boxes->map_dataprint[boxes->x_now][boxes->y_now] = '$';
                }
            }
        }
        if (ch == 'a')
        {
            if (boxes->map_data[boxes->x_now + 1][boxes->y_now] != '#')
            {
                boxes->map_data[boxes->x_now][boxes->y_now] = ' ';
                if (boxes->map_data[boxes->x_now + 1][boxes->y_now] = '@')
                {
                    boxes->Y_now--;
                    boxes->y_now--;
                    boxes->map_dataprint[boxes->x_now][boxes->y_now] = '$';
                    boxes->map_dataprint[boxes->X_now][boxes->Y_now] = '@';
                }
                else
                {
                    boxes->y_now--;
                    boxes->map_dataprint[boxes->x_now][boxes->y_now] = '$';
                }
            }
        }
        if (ch == 'd')
        {
            if (boxes->map_data[boxes->x_now + 1][boxes->y_now] != '#')
            {
                boxes->map_data[boxes->x_now][boxes->y_now] = ' ';
                if (boxes->map_data[boxes->x_now + 1][boxes->y_now] = '@')
                {
                    boxes->Y_now++;
                    boxes->y_now++;
                    boxes->map_dataprint[boxes->x_now][boxes->y_now] = '$';
                    boxes->map_dataprint[boxes->X_now][boxes->Y_now] = '@';
                }
                else
                {
                    boxes->y_now++;
                    boxes->map_dataprint[boxes->x_now][boxes->y_now] = '$';
                }
            }
        }
        recordgrades++;
        system("cls");
        printPushboxes2(boxes);
    }
    system("cls");
    puts("ͨ����");
    printf("%d", recordgrades);
    Sleep(3000);
    return 0;
}
void RecordFile(pushboxes* boxes)
{
    FILE* p;
    const char* filename = "/record.txt";
    int grades;
    p= fopen(filename, "w");   
    if (p == NULL)   
    {    
        puts("��ʧ��");    
    }
    else
    {
        fprintf(p, "%d\n",recordgrades);
        fclose(p);
    }
 }