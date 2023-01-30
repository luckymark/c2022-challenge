#include "head.h"

int humNum, comNum; //1：白 2：黑
Color humColor,comColor;
int score=0; //当前棋局的分值，越大表示AI越有优势

int valueMap[SIZE][SIZE] = { {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                             {0,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
                             {0,1,2,2,2,2,2,2,2,2,2,2,2,1,0},
                             {0,1,2,3,3,3,3,3,3,3,3,3,2,1,0},
                             {0,1,2,3,4,4,4,4,4,4,4,3,2,1,0},
                             {0,1,2,3,4,5,5,5,5,5,4,3,2,1,0},
                             {0,1,2,3,4,5,6,6,6,5,4,3,2,1,0},
                             {0,1,2,3,4,5,6,7,6,5,4,3,2,1,0},
                             {0,1,2,3,4,5,6,6,6,5,4,3,2,1,0},
                             {0,1,2,3,4,5,5,5,5,5,4,3,2,1,0},
                             {0,1,2,3,4,4,4,4,4,4,4,3,2,1,0},
                             {0,1,2,3,3,3,3,3,3,3,3,3,2,1,0},
                             {0,1,2,2,2,2,2,2,2,2,2,2,2,1,0},
                             {0,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
                             {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0} };

int main(void){
    int gobang[SIZE][SIZE];
    initSequence();
    memset(gobang,0,sizeof(gobang));
    initGobang(gobang);

    initZobrist();
    chessPlay(gobang);
    return 0;
}

void initGobang(int (*gobang)[SIZE]){
    for (int i = 0; i < BORDER; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            gobang[i][j]=BORDER_NUM;
        }
    }
    for (int i = SIZE-BORDER; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            gobang[i][j]=BORDER_NUM;
        }
    }
    for (int j = 0; j < BORDER; ++j) {
        for (int i = BORDER; i < SIZE-BORDER; ++i) {
            gobang[i][j]=BORDER_NUM;
        }
    }
    for (int j = SIZE-BORDER; j < SIZE; ++j) {
        for (int i = BORDER; i < SIZE-BORDER; ++i) {
            gobang[i][j]=BORDER_NUM;
        }
    }
    setAddVal(humNum,comNum);
    setAddVal(comNum,humNum);
    setDeleteVal(humNum,comNum);
    setDeleteVal(comNum,humNum);
}

void initSequence(void){
    const int width=500,height=200;
    SetTargetFPS(60);
    InitWindow(width,height,"Init");
    while (!IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
        BeginDrawing();
        ClearBackground(LIGHTGRAY);
        DrawText("Click to choose your color:",40,10,30,PINK);
        DrawText("Black",50,80,60,BLACK);
        DrawText("White",300,80,60,WHITE);
        EndDrawing();
    }
    if (GetMousePosition().x<=width/2){
        humNum=2;
        comNum=1;
        humColor=BLACK;
        comColor=RAYWHITE;
    } else{
        humNum=1;
        comNum=2;
        humColor=RAYWHITE;
        comColor=BLACK;
    }
    CloseWindow();
}