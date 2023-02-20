//本五子棋只支持玩家与AI对战，且玩家执黑

#include "play.h"
#include <cstdio>
#include <windows.h>
#include <graphics.h>
#include <conio.h>
#include <cmath>

typedef struct MouseHit{
    short x;
    short y;
}Mouse;

bool Winner(short x,short y);
Mouse* getMouse();
void paint();


int main() {
    for (int i = 0;i <= 16;++i) {
        for (int j = 0;j <= 16;++j) {
            if (i == 0||i == 16||j == 0||j == 16){
                map[i][j] = -1;
            }else{
                map[i][j] = 0;
            }
        }
    }
    Node* AIStep;

    initgraph(520,520);
    setbkcolor(RGB(241,167,37));
    setfillstyle(SOLID_FILL);
    paint();

    Mouse* mouse;

    while(true) {
        while(true){
            mouse = getMouse();
            if (map[mouse->x][mouse->y] == 0){
                map[mouse->x][mouse->y] = black;
                break;
            }
        }
        paint();
        if (Winner(mouse->x,mouse->y)){
            settextcolor(RED);
            settextstyle(50,0,"Consolas");
            outtextxy(180,210,"you win");
            break;
        }
        AIStep = playAI(mouse->x,mouse->y);
        paint();
        if (Winner(AIStep->X,AIStep->Y)){
            settextcolor(RED);
            settextstyle(50,0,"Consolas");
            outtextxy(180,210,"you lose");
            break;
        }
    }
    getch();
    closegraph();
    return 0;
}

bool Winner(short x,short y) {
    for (int k = 0;k <= 3;++k) {
        int i = 1;
        while(true) {
            if (map[x][y] != map[x+i*dir[k][0]][y+i*dir[k][1]]) break;
            i++;
        }
        int j = -1;
        while(true) {
            if (map[x][y] != map[x+j*dir[k][0]][y+j*dir[k][1]]) break;
            j--;
        }
        if ((i-j-1) >= 5) return true;
    }
    return false;
}

Mouse* getMouse(){
    auto* mouse = (Mouse*) malloc(sizeof(Mouse));
    while (true){
        if (MouseHit()){
            MOUSEMSG msg = GetMouseMsg();
            if (msg.uMsg == WM_LBUTTONUP){
                short x = floor((msg.x-50)/30.0+0.5);
                short y = floor((msg.y-50)/30.0+0.5);
                if (x >= 0 && x <= 14 && y >= 0 && y <= 14){
                    mouse->y = short(x+1);
                    mouse->x = short(y+1);
                    return mouse;
                }
            }
        }
        Sleep(10);
    }
}

void paint() {
    cleardevice();
    setlinecolor(BLACK);
    setlinestyle(PS_SOLID);
    for (int i = 0; i < 15; ++i) {
        line(50,50+i*30,470,50+i*30);
        line(50+i*30,50,50+i*30,470);
    }
    for (int i = 1;i <= 15; ++i){
        for (int j = 1;j <= 15; ++j){
            if (map[i][j] == 1){
                setcolor(BLACK);
                setfillcolor(BLACK);
                fillcircle(20+j*30,20+i*30,15);
            }else if (map[i][j] == 2) {
                setcolor(WHITE);
                setfillcolor(WHITE);
                fillcircle(20+j*30,20+i*30,15);
            }
            if (j == 15) putchar(10);
        }
    }
}
