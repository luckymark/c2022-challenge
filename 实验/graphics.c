#include "head.h"

void quickStart(int (*gobang)[SIZE], int humNum, int comNum, Color humColor, Color comColor, Piece *move, Piece *cur, int *spaceCount);

void drawChessboard(int (*gobang)[SIZE],int humNum,int comNum,Color humColor,Color comColor){
    ClearBackground(BROWN);
    for(int i=0;i<SIZE-2*BORDER;++i){
        DrawLine(INTERVAL,(i+1)*INTERVAL+ i * LINE_WID, (SIZE-2*BORDER) * INTERVAL + (SIZE-2*BORDER - 1) * LINE_WID, (i + 1) * INTERVAL + i * LINE_WID, BLACK);
    }
    for(int j=0;j<SIZE-2*BORDER;++j){
        DrawLine((j+1)*INTERVAL+ j * LINE_WID, INTERVAL, (j + 1) * INTERVAL + j * LINE_WID, (SIZE-2*BORDER) * INTERVAL + (SIZE-2*BORDER - 1) * LINE_WID, BLACK);
    }
    for(int i=BORDER;i<SIZE-BORDER;++i){
        for(int j=BORDER;j<SIZE-BORDER;++j){
            if(gobang[i][j]==humNum){
                DrawCircleV((Vector2){(j-BORDER+1)*INTERVAL+ (j-BORDER) * LINE_WID, (i - BORDER + 1) * INTERVAL + (i - BORDER) * LINE_WID}, RADIUS, humColor);
            }
            else if(gobang[i][j]==comNum){
                DrawCircleV((Vector2){(j-BORDER+1)*INTERVAL+ (j-BORDER) * LINE_WID, (i - BORDER + 1) * INTERVAL + (i - BORDER) * LINE_WID}, RADIUS, comColor);
            }
        }
    }
}
void quickStart(int (*gobang)[SIZE], int humNum, int comNum, Color humColor, Color comColor, Piece *move, Piece *cur, int *spaceCount){
    BeginDrawing();
    drawChessboard(gobang,humNum,comNum,humColor,comColor);
    EndDrawing();

    gobang[7+BORDER][7+BORDER]=comNum;

    key^=comTable[7+BORDER][7+BORDER];
    //keyLock^=comTable[7+BORDER][7+BORDER];

    move->value= evaluate(gobang,7+BORDER,7+BORDER,comNum,humNum,comNum)+ valueMap[7][7] * MAP_VALUE;
    move->pos=(Coord){7 + BORDER, 7 + BORDER};
    score+=move->value;
    (*spaceCount)--;
    printf("AI:%d\n",move->value);

    while (!IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
        BeginDrawing();
        drawChessboard(gobang,humNum,comNum,humColor,comColor);
        EndDrawing();
    }
    cur->pos= convertPosition(gobang);
    cur->value= evaluate(gobang, cur->pos.x, cur->pos.y, humNum, humNum, comNum) + valueMap[cur->pos.y][cur->pos.x] * MAP_VALUE;
    gobang[cur->pos.y][cur->pos.x]=humNum;

    key^=humTable[cur->pos.y][cur->pos.x];
    //keyLock^=humTable[cur->pos.y][cur->pos.x];

    (*spaceCount)--;
    score-=(cur->value);
    printf("human:(%d,%d)\n", cur->pos.x - BORDER, cur->pos.y - BORDER);
    printf("human:%d\n",cur->value);
}

void chessPlay(int (*gobang)[SIZE],int humNum,int comNum,Color humColor,Color comColor){
    InitWindow((SIZE-2*BORDER+1)*INTERVAL+ (SIZE-2*BORDER) * LINE_WID, (SIZE-2*BORDER + 1) * INTERVAL + (SIZE-2*BORDER) * LINE_WID, "Gobang Chessboard");
    SetTargetFPS(60);
    Piece cur,move; //cur是玩家，move是AI
    int spaceCount=(SIZE-2*BORDER)*(SIZE-2*BORDER);

    clock_t start,end;

    quickStart(gobang,humNum,comNum,humColor,comColor,&move,&cur,&spaceCount);
    do{
        BeginDrawing();
        drawChessboard(gobang,humNum,comNum,humColor,comColor);
        EndDrawing();

        start= clock();

        move=makeMove(gobang,spaceCount);
        gobang[move.pos.y][move.pos.x]=comNum;

        key^=comTable[move.pos.y][move.pos.x];
        //keyLock^=comTable[move.pos.y][move.pos.x];

        spaceCount--;

        end= clock();
        printf("duration:%f\n", (double)(end-start)/CLOCKS_PER_SEC);

        score+=move.value;

        printf("AI:(%d,%d)\n", move.pos.x - BORDER, move.pos.y - BORDER);
        printf("AI:%d\n",move.value);
        if(move.value>=L5){
            BeginDrawing();
            drawChessboard(gobang,humNum,comNum,humColor,comColor);
            DrawText("you lose!",INTERVAL,INTERVAL,50,RED);
            EndDrawing();
            WaitTime(3);
            break;
        };

        while (!IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
            BeginDrawing();
            drawChessboard(gobang,humNum,comNum,humColor,comColor);
            EndDrawing();
        }
        cur.pos= convertPosition(gobang);
        gobang[cur.pos.y][cur.pos.x]=humNum;

        key^=humTable[cur.pos.y][cur.pos.x];
        //keyLock^=humTable[cur.pos.y][cur.pos.x];

        spaceCount--;
        cur.value= evaluate(gobang, cur.pos.x, cur.pos.y, humNum,humNum, comNum) + valueMap[cur.pos.y][cur.pos.x] * MAP_VALUE;
        score-=cur.value;

        printf("human:(%d,%d)\n", cur.pos.x-BORDER, cur.pos.y-BORDER);
        printf("human:%d\n",cur.value);
    }while (cur.value<L5);
    if(cur.value>=L5){
        BeginDrawing();
        drawChessboard(gobang,humNum,comNum,humColor,comColor);
        DrawText("you win!",INTERVAL,INTERVAL,50,BLUE);
        EndDrawing();
        WaitTime(3);
    }
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