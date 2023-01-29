#include "head.h"

void testCase(int (*gobang)[SIZE],int humNum,int comNum,Color humColor,Color comColor){
    Coord cases[]={{7,6},{8,5},{10,4},{9,4},{5,9},
                   {10,7},{8,7},{3,7},{6,4},{6,6},{6,11},
                   {3,8},{5,6},{10,1},{3,6},{3,5},{3,4}};

    InitWindow((SIZE-2*BORDER+1)*INTERVAL+ (SIZE-2*BORDER) * LINE_WID, (SIZE-2*BORDER + 1) * INTERVAL + (SIZE-2*BORDER) * LINE_WID, "Gobang Chessboard");
    SetTargetFPS(60);
    Piece cur,move; //cur是玩家，move是AI
    int spaceCount=(SIZE-2*BORDER)*(SIZE-2*BORDER);
    int i=0;
    clock_t start,end;

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
        cur.pos.x= cases[i].x+BORDER;
        cur.pos.y= cases[i].y+BORDER;
        ++i;
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
