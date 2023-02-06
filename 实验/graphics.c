#include "head.h"

void drawChessboard(int (*gobang)[SIZE]){
    ClearBackground(BROWN);
    for(int i=0;i<SIZE-2*BORDER;++i){
        DrawLine(INTERVAL,(i+1)*INTERVAL+ i * LINE_WID,
                 (SIZE-2*BORDER) * INTERVAL + (SIZE-2*BORDER - 1) * LINE_WID,
                 (i + 1) * INTERVAL + i * LINE_WID, BLACK);
    }
    for(int j=0;j<SIZE-2*BORDER;++j){
        DrawLine((j+1)*INTERVAL+ j * LINE_WID, INTERVAL,
                 (j + 1) * INTERVAL + j * LINE_WID,
                 (SIZE-2*BORDER) * INTERVAL + (SIZE-2*BORDER - 1) * LINE_WID, BLACK);
    }
    for(int i=BORDER;i<SIZE-BORDER;++i){
        for(int j=BORDER;j<SIZE-BORDER;++j){
            if(gobang[i][j]==humNum){
                DrawCircleV((Vector2){(j-BORDER+1)*INTERVAL+ (j-BORDER) * LINE_WID,
                                      (i - BORDER + 1) * INTERVAL + (i - BORDER) * LINE_WID},RADIUS, humColor);
            }
            else if(gobang[i][j]==comNum){
                DrawCircleV((Vector2){(j-BORDER+1)*INTERVAL+ (j-BORDER) * LINE_WID,
                                      (i - BORDER + 1) * INTERVAL + (i - BORDER) * LINE_WID},RADIUS, comColor);
            }
        }
    }
}

void chessPlay(int (*gobang)[SIZE]){
    Piece cur={0},move={0}; //分别记录玩家和AI的最新落子
    int spaceCount=(SIZE-2*BORDER)*(SIZE-2*BORDER); //初始化剩余空位数量
    clock_t start,end;

    InitWindow((SIZE-2*BORDER+1)*INTERVAL+ (SIZE-2*BORDER) * LINE_WID,
               (SIZE-2*BORDER + 1) * INTERVAL + (SIZE-2*BORDER) * LINE_WID, "Gobang Chessboard");
    SetTargetFPS(60);
    if (humNum==1){ //AI先手则先落中央
        gobang[7+BORDER][7+BORDER]=comNum;
        key^=comTable[7+BORDER][7+BORDER];
        move.value=evaluate(gobang,7+BORDER,7+BORDER,comNum)
                + valueMap[7][7] * MAP_VALUE;
        move.pos=(Coord){7 + BORDER, 7 + BORDER};
        score+=move.value;
        spaceCount--;
        printf("AI:%d\n",move.value);
    }
    while (move.value<L5){
        while (!IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
            BeginDrawing();
            drawChessboard(gobang);
            EndDrawing();
        }
        cur.pos= convertPosition(gobang);
        gobang[cur.pos.y][cur.pos.x]=humNum;
        BeginDrawing();
        drawChessboard(gobang);
        EndDrawing();
        key^=humTable[cur.pos.y][cur.pos.x];
        spaceCount--;
        cur.value=evaluate(gobang, cur.pos.x, cur.pos.y, humNum)
                + valueMap[cur.pos.y][cur.pos.x] * MAP_VALUE;
        score-=cur.value;
        printf("human:(%d,%d)\n", cur.pos.x-BORDER, cur.pos.y-BORDER);
        printf("human:%d\n",cur.value);
        if (cur.value>=L5){
            break;
        }
        start= clock();
        move=makeMove(gobang,spaceCount);
        end= clock();
        gobang[move.pos.y][move.pos.x]=comNum;
        key^=comTable[move.pos.y][move.pos.x];
        spaceCount--;
        score+=move.value;
        printf("duration:%f\n", (double)(end-start)/CLOCKS_PER_SEC);
        printf("AI:(%d,%d)\n", move.pos.x - BORDER, move.pos.y - BORDER);
        printf("AI:%d\n",move.value);
    }
    BeginDrawing();
    drawChessboard(gobang);
    if (cur.value>=L5){
        DrawText("you win!",INTERVAL,INTERVAL,50,BLUE);
    } else{
        DrawText("you lose!",INTERVAL,INTERVAL,50,RED);
    }
    EndDrawing();
    WaitTime(5);
    CloseWindow();
}

Coord convertPosition(int (*gobang)[SIZE]){
    Vector2 movePosition=GetMousePosition();
    Coord res;
    for(int i=0;i<SIZE;++i){
        if(movePosition.y-((i+1)*INTERVAL+ i * LINE_WID) < INTERVAL / 2){
            res.y=i+BORDER;
            break;
        }
    }
    for(int j=0;j<SIZE;++j){
        if(movePosition.x-((j+1)*INTERVAL+ j * LINE_WID) < INTERVAL / 2){
            res.x=j+BORDER;
            break;
        }
    }
    return res;
}