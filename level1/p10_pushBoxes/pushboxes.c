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
    char boxmaze[LEN][WID];                               //注意是boxmaze[y][x]
    int n = 1;                                           //关卡数
    openMap("map1.txt", boxmaze);
    boxmaze[cury][curx] = 1;                               //用3识别出玩家位置后重置为1
    while (count!=0) {
        move(boxmaze, &cury, &curx);
    }
    printf("you pass 1st maze!");    
    update("total.txt",n, score);
    openMap("map2.txt", boxmaze);
    boxmaze[cury][curx] = 1;                              //关卡多的话可以把这些都封装到一个函数里
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
    }                                                      //完成从map文件到boxmaze数组的复制
    for (int j = 0; j < line + 1; ++j) {                           //循环结束后i就是每行的元素数
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
                printf("@");                              //*是墙，#是箱子，@是玩家,D是目标位置
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
                ++score;                                            //注意误操作碰墙也计入步数
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
            else if (boxmaze[*y][*x+1] == '2' && boxmaze[*y][*x + 2] == '4') {      //处理把箱子推到终点的情况
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
                printf("@");                                      //不再处理#，此时已经被@覆盖
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
        boxmaze[desty][destx] = '4';                              //防止踩踏D时自动重置
    }
}
void update(char* ptr,int n,int score) {
    FILE* fp=fopen(ptr, "a");                                //"a"在没有该文件的时候可以自动创建新文件
    if (fp == NULL) {
        fprintf(stderr,"can't record your score.");
        exit(3);
    }
    fprintf(fp, "your score in maze %d is %d.", n, score);         //把该次成绩添加到fp指向的文件中
    score = 0;
}
void HideCursor(void) {
    CONSOLE_CURSOR_INFO cursor_info = { 1,0 };              
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}