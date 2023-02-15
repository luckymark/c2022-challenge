#include <stdio.h>
#include <conio.h>
#include <stdbool.h>
#include <windows.h>

bool ifSuccess1(int n,int map[][n]);
bool ifSuccess2(int n,int map[][n]);
void paint(int n,int map[][n]);
void check1(int n,int map[][n]);
void check2(int n,int map[][n]);
int play1(int x,int y,int n,int m,int map[][n]);
int play2(int x,int y,int n,int m,int map[][n]);

int main() {
    int map1[9][11]={
            {0,1,1,1,1,1,1,1,1,1,0},
            {0,1,0,0,0,1,0,0,0,1,0},
            {0,1,0,0,3,0,0,0,0,1,0},
            {0,1,0,3,0,3,3,3,0,1,1},
            {0,1,0,0,0,2,0,0,0,0,1},
            {1,1,0,0,1,1,1,0,3,0,1},
            {1,0,4,4,0,4,0,0,0,0,1},
            {1,0,4,4,0,4,4,3,0,1,1},
            {1,1,1,1,1,1,1,1,1,1,0}
    }; // 0-blank 1-wall 2-people 3-box 4-target location
    int map2[9][11] = {
            {0,1,1,1,1,1,1,1,1,1,0},
            {0,1,0,0,0,1,0,0,0,1,0},
            {0,1,0,3,3,3,3,3,0,1,0},
            {0,1,0,3,0,3,0,3,0,1,1},
            {0,1,0,0,0,0,0,0,3,0,1},
            {1,0,0,1,1,1,1,0,3,0,1},
            {1,0,2, 4,4,4,4,1,0,0,1},
            {1,0,4,4,4,4,4,0,0,1,1},
            {1,1,1,1,1,1,1,1,1,1,0} };
    int score2 = play2(6,2,11,9,map2);
    int score1 = play1(4,5,11,9,map1);

    printf("\n%s %d","your total score is:",score1+score2);
    return 0;
}

bool ifSuccess1(int n,int map[][n]){
    if (map[6][2] == 3 && map[6][3] == 3 && map[6][5] == 3){
        if (map[7][2] == 3 && map[7][3] == 3 && map[7][5] == 3 && map[7][6] == 3){
            return true;
        }
    }
    return false;
}

bool ifSuccess2(int n,int map[][n]){
    if (map[6][2] == 3 && map[6][3] == 3 && map[6][4] == 3 && map[6][5] == 3 && map[6][6] == 3){
        if (map[7][2] == 3 && map[7][3] == 3 && map[7][4] == 3 && map[7][5] == 3 && map[7][6] == 3){
            return true;
        }
    }
    return false;
}

void check2(int n,int map[][n]){
    if (map[6][2] == 0) map[6][2] = 4;
    if (map[6][3] == 0) map[6][3] = 4;
    if (map[6][4] == 0) map[6][4] = 4;
    if (map[6][5] == 0) map[6][5] = 4;
    if (map[6][6] == 0) map[6][6] = 4;
    if (map[7][2] == 0) map[7][2] = 4;
    if (map[7][3] == 0) map[7][3] = 4;
    if (map[7][4] == 0) map[7][4] = 4;
    if (map[7][5] == 0) map[7][5] = 4;
    if (map[7][6] == 0) map[7][6] = 4;
}

void check1(int n,int map[][n]){
    if (map[6][2] == 0) map[6][2] = 4;
    if (map[6][3] == 0) map[6][3] = 4;
    if (map[6][5] == 0) map[6][5] = 4;
    if (map[7][2] == 0) map[7][2] = 4;
    if (map[7][3] == 0) map[7][3] = 4;
    if (map[7][5] == 0) map[7][5] = 4;
    if (map[7][6] == 0) map[7][6] = 4;
}

void paint(int n,int map[][n]){ // 0-blank 1-wall 2-people 3-box 4-target location
    system("cls");
    for (int i = 0; i < 99; ++i) {
        switch (*(*map + i)) {
            case 0:
                printf("%c",' ');
                break;
            case 1:
                printf("%c",'*');
                break;
            case 2:
                printf("%s","p");
                break;
            case 3:
                printf("%s","b");
                break;
            case 4:
                printf("%s","t");
        }
        if ((i+1)%11 == 0) putchar(10);
    }
}

int play1(int x,int y,int n,int m,int map[m][n]){
    int times = 0;
    paint(n,map);
    while(true) {
        int a = getch();
        switch (a) { // i行 j列
            case 75: // left
                if((y-1) >= 0 && map[x][y-1] != 1){
                    if(map[x][y-1] == 3 && (y-2) >= 0 && (map[x][y-2] == 0 || map[x][y-2] == 4)){
                        map[x][y] = 0;
                        map[x][y-1] = 2;
                        map[x][y-2] = 3;
                        --y;
                        times++;
                    }else if (map[x][y-1] == 0 || map[x][y-1] == 4){
                        map[x][y] = 0;
                        map[x][y-1] = 2;
                        --y;
                        times++;
                    }

                }
                break;
            case 72: // up
                if ((x-1) >= 0 && map[x-1][y] != 1){
                    if (map[x-1][y] == 3 && (x-2) >= 0 && (map[x-2][y] == 0 || map[x-2][y] == 4)){
                        map[x][y] = 0;
                        map[x-1][y] = 2;
                        map[x-2][y] = 3;
                        --x;
                        times++;
                    }else if (map[x-1][y] == 0 || map[x-1][y] == 4){
                        map[x][y] = 0;
                        map[x-1][y] = 2;
                        --x;
                        times++;
                    }
                }
                break;
            case 77: // right
                if((y+1) <= n-1 && map[x][y+1] != 1){
                    if(map[x][y+1] == 3 && (y+2) <= n-1 && (map[x][y+2] == 0 || map[x][y+2] == 4)){
                        map[x][y] = 0;
                        map[x][y+1] = 2;
                        map[x][y+2] = 3;
                        ++y;
                        times++;
                    }else if (map[x][y+1] == 0 || map[x][y+1] == 4){
                        map[x][y] = 0;
                        map[x][y+1] = 2;
                        ++y;
                        times++;
                    }

                }
                break;
            case 80: // down
                if ((x+1) <= m-1 && map[x+1][y] != 1){
                    if (map[x+1][y] == 3 && (x+1) <= m-1 && (map[x+2][y] == 0 || map[x+2][y] == 4)){
                        map[x][y] = 0;
                        map[x+1][y] = 2;
                        map[x+2][y] = 3;
                        ++x;
                        times++;
                    }else if (map[x+1][y] == 0 || map[x+1][y] == 4){
                        map[x][y] = 0;
                        map[x+1][y] = 2;
                        ++x;
                        times++;
                    }

                }
                break;
            default:
                break;
        }
        if(ifSuccess1(n,map)){
            printf("%s\n","you win");
            printf("%s %d","your score:",100-times);
            getch();
            return 100-times;
        }
        check1(n,map);
        paint(n,map);
    }
}

int play2(int x,int y,int n,int m,int map[m][n]){
    int times = 0;
    paint(n,map);
    while(true) {
        int a = getch();
        switch (a) { // i行 j列
            case 75: // left
                if((y-1) >= 0 && map[x][y-1] != 1){
                    if(map[x][y-1] == 3 && (y-2) >= 0 && (map[x][y-2] == 0 || map[x][y-2] == 4)){
                        map[x][y] = 0;
                        map[x][y-1] = 2;
                        map[x][y-2] = 3;
                        --y;
                        times++;
                    }else if (map[x][y-1] == 0 || map[x][y-1] == 4){
                        map[x][y] = 0;
                        map[x][y-1] = 2;
                        --y;
                        times++;
                    }

                }
                break;
            case 72: // up
                if ((x-1) >= 0 && map[x-1][y] != 1){
                    if (map[x-1][y] == 3 && (x-2) >= 0 && (map[x-2][y] == 0 || map[x-2][y] == 4)){
                        map[x][y] = 0;
                        map[x-1][y] = 2;
                        map[x-2][y] = 3;
                        --x;
                        times++;
                    }else if (map[x-1][y] == 0 || map[x-1][y] == 4){
                        map[x][y] = 0;
                        map[x-1][y] = 2;
                        --x;
                        times++;
                    }

                }
                break;
            case 77: // right
                if((y+1) <= n-1 && map[x][y+1] != 1){
                    if(map[x][y+1] == 3 && (y+2) <= n-1 && (map[x][y+2] == 0 || map[x][y+2] == 4)){
                        map[x][y] = 0;
                        map[x][y+1] = 2;
                        map[x][y+2] = 3;
                        ++y;
                        times++;
                    }else if (map[x][y+1] == 0 || map[x][y+1] == 4){
                        map[x][y] = 0;
                        map[x][y+1] = 2;
                        ++y;
                        times++;
                    }

                }
                break;
            case 80: // down
                if ((x+1) <= m-1 && map[x+1][y] != 1){
                    if (map[x+1][y] == 3 && (x+1) <= m-1 && (map[x+2][y] == 0 || map[x+2][y] == 4)){
                        map[x][y] = 0;
                        map[x+1][y] = 2;
                        map[x+2][y] = 3;
                        ++x;
                        times++;
                    }else if (map[x+1][y] == 0 || map[x+1][y] == 4){
                        map[x][y] = 0;
                        map[x+1][y] = 2;
                        ++x;
                        times++;
                    }
                }
                break;
            default:
                break;
        }
        if(ifSuccess2(n,map)){
            printf("%s\n","you win");
            printf("%s %d","your score:",100-times);
            getch();
            return 100-times;
        }
        check2(n,map);
        paint(n,map);
    }
}
