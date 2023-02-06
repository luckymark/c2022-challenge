#include<stdio.h>
#include<stdlib.h>
#include<windows.h> 
#define LEN 50
#define WID 50
static int cury, curx;
static int desty, destx;
static int score = 0,count;
void openMap(char* ptr, char(*boxmaze)[WID]);
void gotoxy(int x, int y);
void move(char(*boxmaze)[WID], int* y, int* x);
void update(char* ptr,int n,int score);
void HideCursor(void);

int main(void) {
    HideCursor();
    char boxmaze[LEN][WID];                               //ע����boxmaze[y][x]
    int n = 1;                                           //�ؿ���
    openMap("map1.txt", boxmaze);
    boxmaze[cury][curx] = 1;                               //��3ʶ������λ�ú�����Ϊ1
    while (count!=0) {
        move(boxmaze, &cury, &curx);
    }
    printf("you pass 1st maze!");    
    update("total.txt",n, score);
    openMap("map2.txt", boxmaze);
    boxmaze[cury][curx] = 1;                              //�ؿ���Ļ����԰���Щ����װ��һ��������
    while (count != 0) {
        move(boxmaze, &cury, &curx);
    }
    printf("you pass 2nd maze!");
    n = 2;
    update("total.txt", n, score);
    return 0;
}

void openMap(char* ptr, char(*boxmaze)[WID]) {
    count = 0;
    FILE* fp = fopen(ptr, "r");
    if (fp == NULL) {
        fprintf(stderr, "couldn't open the map.");
        exit(1);
    }
    char input;
    int line = 0, i = 0;
    while ((input = getc(fp)) != EOF) {
        if (input != '\n') {
            boxmaze[line][i] = input;
            ++i;
        }
        else {
            ++line;
            i = 0;
        }
    }                                                      //��ɴ�map�ļ���boxmaze����ĸ���
    for (int j = 0; j < line + 1; ++j) {                           //ѭ��������i����ÿ�е�Ԫ����
        for (int k = 0; k < i; ++k) {
            if (boxmaze[j][k] == '0') {
                printf("*");
            }
            else if (boxmaze[j][k] == '1') {
                printf(" ");
            }
            else if (boxmaze[j][k] == '2') {
                printf("#");
                ++count;
            }
            else if (boxmaze[j][k] == '3') {
                printf("@");                              //*��ǽ��#�����ӣ�@�����,D��Ŀ��λ��
                cury = j;
                curx = k;
            }
            else if (boxmaze[j][k] == '4') {
                printf("D");
                desty = j;
                destx = k;
            }
        }
        printf("\n");
    }
    fclose(fp);
}
void gotoxy(int x, int y) {
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(handle, pos);
}
void move(char(*boxmaze)[WID], int* y, int* x) {
    char input;
    gotoxy(*x, *y);
    if (_kbhit()) {
        printf(" ");
        input = _getch();
        if (input == 'a') {
            if (boxmaze[*y][*x - 1] == '1') {
                printf("\b\b@");                
                --(*x);
                ++score;
            }
            else if (boxmaze[*y][*x - 1] == '2' && boxmaze[*y][*x - 2] == '1') {
                printf("\b\b@"); 
                printf("\b\b#");
                ++score;
                boxmaze[*y][*x - 1] = '1';
                boxmaze[*y][*x - 2] = '2';
                --(*x);
            }
            else if (boxmaze[*y][*x - 1] == '2' && boxmaze[*y][*x - 2] == '4') {
                gotoxy(*x - 1, *y);
                printf("@");
                boxmaze[*y][*x - 1] = '1';
                --(*x);
                ++score;
                --count;
            }
            else {
                ++score;                                            //ע���������ǽҲ���벽��
                printf("\b@");
            }
        }
        else if (input == 'd') {
            if (boxmaze[*y][*x + 1] == '1') {
                printf("@");
                ++(*x);
                ++score;
            }
            else if (boxmaze[*y][*x + 1] == '2' && boxmaze[*y][*x + 2] == '1') {
                printf("@#");
                ++score;
                boxmaze[*y][*x + 1] = '1';
                boxmaze[*y][*x + 2] = '2';
                ++(*x);
            }
            else if (boxmaze[*y][*x+1] == '2' && boxmaze[*y][*x + 2] == '4') {      //����������Ƶ��յ�����
                gotoxy(*x+1, *y);
                printf("@");
                boxmaze[*y][*x+1] = '1';
                ++(*x);
                ++score;
                --count;
            }
            else {
                ++score;                                            
                printf("\b@");
            }
        }
        else if (input == 'w') {
            if (boxmaze[*y-1][*x] == '1') {
                gotoxy(*x, *y - 1);
                printf("@");
                --(*y);
                ++score;
            }
            else if (boxmaze[*y-1][*x] == '2' && boxmaze[*y - 2][*x] == '1') {
                gotoxy(*x, *y - 1);
                printf("@");
                gotoxy(*x, *y - 2);
                printf("#");
                ++score;
                boxmaze[*y-1][*x] = '1';
                boxmaze[*y-2][*x] = '2';
                --(*y);
            }
            else if (boxmaze[*y - 1][*x] == '2' && boxmaze[*y - 2][*x] == '4') {
                gotoxy(*x, *y - 1);
                printf("@");                                      //���ٴ���#����ʱ�Ѿ���@����
                boxmaze[*y - 1][*x] = '1';
                --(*y);
                ++score;
                --count;
            }
            else {
                ++score;
                printf("\b@");
            }
        }
        else if (input == 's') {
            if (boxmaze[*y + 1][*x] == '1') {
                gotoxy(*x, *y + 1);
                printf("@");
                ++(*y);
                ++score;
            }
            else if (boxmaze[*y + 1][*x] == '2' && boxmaze[*y + 2][*x] == '1') {
                gotoxy(*x, *y + 1);
                printf("@");
                gotoxy(*x, *y + 2);
                printf("#");
                ++score;
                boxmaze[*y + 1][*x] = '1';
                boxmaze[*y + 2][*x] = '2';
                ++(*y);
            }
            else if (boxmaze[*y + 1][*x] == '2' && boxmaze[*y + 2][*x] == '4') {
                gotoxy(*x, *y + 1);
                printf("@");
                boxmaze[*y + 1][*x] = '1';
                ++(*y);
                ++score;
                --count;
            }
            else {
                ++score;
                printf("\b@");
            }
        }       
        boxmaze[desty][destx] = '4';                              //��ֹ��̤Dʱ�Զ�����
    }
}
void update(char* ptr,int n,int score) {
    FILE* fp=fopen(ptr, "a");                                //"a"��û�и��ļ���ʱ������Զ��������ļ�
    if (fp == NULL) {
        fprintf(stderr,"can't record your score.");
        exit(3);
    }
    fprintf(fp, "your score in maze %d is %d.", n, score);         //�Ѹôγɼ���ӵ�fpָ����ļ���
    score = 0;
}
void HideCursor(void) {
    CONSOLE_CURSOR_INFO cursor_info = { 1,0 };              
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}