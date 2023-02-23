#include "WuZiQi.h"

int main(){
    printf("请选择模式\n输入0 or 1 or 2\n");
    printf("0. PVP\n");
    printf("1. PVE1 玩家先手\n");
    printf("2. PVE2 电脑先手\n");
    fflush(stdout);

    char choose;

    fflush(stdout);
    fflush(stdin);
    while(choose!='0'&&choose!='1'&&choose!='2') { scanf("%c", &choose); }

    switch(choose-'0'){
        case 0: PVP();break;
        case 1: PVE1();break;
        case 2: PVE2();break;
    }

}
//玩家先手
void PVE1() {
    init();
    int GameMode = PVE_1;
    while (1) {
        MOUSEMSG msg = GetMouseMsg(); //MOUSEMSG 定义 一个 msg,   (代码功能直到鼠标 click)
        if ((msg.uMsg == WM_LBUTTONDOWN || msg.uMsg == WM_RBUTTONDOWN) && Judge_Player_Down(msg)) {//如果鼠标信息是左键点击
            Player_go(msg);//player 走棋

            if (CheckOver(GameMode)) {
                EndGame();
                init();
                continue;
            }
        }
        else {
            continue;
        }

        AI_go();
        if (CheckOver(GameMode)) {
            EndGame();
            init();
            continue;
        }
    }
}
//玩家后手
void PVE2() {
    init();
    int GameMode = PVE_2;

    while (1) {
    if (num==0){
        if (Game.Player_Flag==-1) {
            chess_Down(8, 8, Chess_Black);
        }
        else {
            chess_Down(8, 8, Chess_White);
        }
        update_ChessDate(&Game,AI_x ,AI_y);
    }
    else {
        AI_go();
        if (CheckOver(GameMode)) {
            EndGame();
            init();
            continue;
        }
    }
    while(1) {
        MOUSEMSG msg = GetMouseMsg(); //MOUSEMSG 定义 一个 msg,   (代码功能直到鼠标 click)
        if ((msg.uMsg == WM_LBUTTONDOWN || msg.uMsg == WM_RBUTTONDOWN) && Judge_Player_Down(msg)) {//如果鼠标信息是左键点击
            Player_go(msg);//player 走棋

            if (CheckOver(GameMode)) {
                EndGame();
                init();
                continue;
            }
            break;
        }
    }

    }
}
void PVP() {
    init();
    int GameMode = PVP_;
    while (1) {//补一个选择双人对战
        MOUSEMSG msg = GetMouseMsg(); //MOUSEMSG 定义 一个 msg,   (代码功能直到鼠标 click)
        if ((msg.uMsg == WM_LBUTTONDOWN || msg.uMsg == WM_RBUTTONDOWN) && Judge_Player_Down(msg)) {//如果鼠标信息是左键点击
            Player_go(msg);//player1 走棋

            if (CheckOver(GameMode)) {
                EndGame();
                init(); //开新局  （后期改一下）
                continue;
            }
        } else {
            continue;
        }

    }
}