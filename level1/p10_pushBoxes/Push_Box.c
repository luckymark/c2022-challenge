#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void Print_Map(int (*pMap)[8]);
char Orientation();
int Choose_Map();
void GetMap_fromFile(int Map_Number,int (*(*pMap))[8]);
void Save_Map();
void Move(int (*pMap)[8],char O);
void SaveScore(int MapNumber);


static enum Direct{
    w=8,a=4,d=6,s=2,Character=9,Way=7,Obstacle=5,Box=1,BoxTarget=3
};

static int Row,Cul,Is_BoxT=0,BoxNum=0;
static int step=0;

void main(){

    int Map_Number;
    int Map[8][8]; int (*pMap)[8];
    pMap=Map;

    Save_Map();

    Map_Number=Choose_Map();

    GetMap_fromFile(Map_Number,&pMap);

    Print_Map(pMap);

    while(BoxNum!=0) {
        Move(pMap, Orientation());
    }

    SaveScore(Map_Number);
    printf("本次步数共%d步",step);
}

int Choose_Map(){
    int Map_Num;
    printf("请选择地图,输入 '1','2','3'即可\n");
    fflush(stdout);
    scanf("%d",&Map_Num);

    printf("已选择%d号地图\n",Map_Num);
    return Map_Num;
}

void Save_Map(){
    int Map_1[8][8]={
            {9 , 7 , 5 , 5 , 5 , 5 , 7 , 7},
            {7 , 7 , 5 , 3 , 3 , 5 , 7 , 7},
            {7 , 5 , 5 , 7 , 3 , 5 , 7 , 7},
            {7 , 7 , 1 , 7 , 7 , 3 , 7 , 7},
            {5 , 5 , 7 , 7 , 1 , 7 , 7 , 5},
            {5 , 7 , 7 , 5 , 7 , 7 , 7 , 5},
            {7 , 1 , 7 , 7 , 7 , 7 , 7 , 5},
            {7 , 7 , 7 , 7 , 7 , 7 , 7 , 5}
    };
    int Map_2[8][8]={
            {7 , 7 , 7 , 7 , 5 , 5 , 7 , 7},
            {7 , 7 , 7 , 7 , 3 , 7 , 7 , 7},
            {7 , 5 , 5 , 7 , 3 , 7 , 7 , 7},
            {7 , 5 , 7 , 7 , 7 , 3 , 7 , 7},
            {7 , 5 , 7 , 5 , 1 , 7 , 5 , 5},
            {7 , 7 , 7 , 3 , 7 , 1 , 7 , 5},
            {7 , 9 , 7 , 7 , 7 , 1 , 7 , 5},
            {7 , 5 , 5 , 7 , 7 , 7 , 7 , 5}
    };
    int Map_3[8][8]={
            {7 , 7 , 5 , 5 , 5 , 5 , 7 , 7},
            {7 , 1 , 7 , 3 , 7, 5 , 7 , 7},
            {7 , 7 , 5 , 7 , 7 , 9 , 5 , 7},
            {7 , 7 , 1 , 7 , 7 , 3 , 5 , 7},
            {5 , 7 , 7 , 7 , 1 , 7 , 5 , 5},
            {5 , 7 , 7 , 5 , 7 , 7 , 7 , 5},
            {5 , 1 , 7 , 3, 7 , 7 , 7 , 5},
            {5 , 7 , 7 , 7 , 5 , 5 , 5 , 5}
    };
    for (int J=1;J<4;J++) {
        char str[6];
        sprintf(str, "Map_%d", J);

        FILE *fp = fopen(str, "w+");

        int (*Map)[8];
        switch(J){
            case 1: Map=Map_1;break;
            case 2: Map=Map_2;break;
            case 3: Map=Map_3;break;
            default:break;
        }

        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                fputc(Map[i][j], fp);
            }
        }
        fclose(fp);
    }
}

void SaveScore(int MapNumber){

    FILE *fp = fopen("Score","a+");

    int Round;//未完善功能

    fprintf(fp, "%s%d%s%d%s%d", "第",MapNumber,"关第",Round,"次挑战步数:", step);
    fputc('\n',fp);
    printf("已储存步数\n");

    fclose(fp);

}

void GetMap_fromFile(int Map_Number,int (*(*pMap))[8]){

    char str[6];
    sprintf(str,"Map_%d",Map_Number); //把输入的数字合并成File名字

    FILE *fp = fopen(str,"r+");
    for (int i=0;i<8;i++){
        for(int j=0;j<8;j++){

            (*pMap)[i][j]=fgetc(fp);
                if((*pMap)[i][j]==Character){
                    Row=i,Cul=j;    
                }
            if((*pMap)[i][j]==Box){
                BoxNum+=1;
            }

        }
    }
    fclose(fp);
}

char Orientation(){

    fflush(stdin);
        char Letter;
        scanf("%c",&Letter );

        if (Letter == 'W' || Letter == 'w') {
            return w;
        }
        if (Letter == 'S' || Letter == 's') {
            return s;
        }
        if (Letter == 'A' || Letter == 'a') {
            return a;
        }
        if (Letter == 'D' || Letter == 'd') {
            return d;
        }
    }

void Move(int (*pMap)[8],char O){

    switch(O){
        case a: {
            if(pMap[Row][Cul - 1] ==Obstacle){break;}

            if (pMap[Row][Cul - 1] == Way || pMap[Row][Cul - 1] == BoxTarget) {

                if(Is_BoxT){ //如果上一步是BoxTarget,还原BoxTarget
                    pMap[Row][Cul] = BoxTarget;
                    Is_BoxT=0;
                }
                else{pMap[Row][Cul] =Way;}

                if(pMap[Row][Cul - 1] == BoxTarget){//判断下一个是BoxTarget 就记录
                    Is_BoxT=1;
                }

                Cul--;
                pMap[Row][Cul] = Character;
                step+=1;
                break;
            }
            if (pMap[Row][Cul - 1] == Box) {
                if (pMap[Row][Cul - 2] == Obstacle||pMap[Row][Cul - 2] ==Box) {
                    break;
                }
                if (pMap[Row][Cul - 2] == BoxTarget) {
                    pMap[Row][Cul] =Way;
                    Cul--;
                    pMap[Row][Cul] = Character;

                    BoxNum-=1;
                    step+=1;
                    break;
                }
                if (pMap[Row][Cul - 2] == Way) {
                    pMap[Row][Cul] =Way;
                    Cul--;
                    pMap[Row][Cul] = Character;
                    pMap[Row][Cul - 1] = Box;

                    step+=1;
                    break;
                }
            }
            
        }
        case d: {
            if(pMap[Row][Cul + 1] ==Obstacle){break;}
            if (pMap[Row][Cul + 1] == Way || pMap[Row][Cul + 1] == BoxTarget) {

                if(Is_BoxT){ //如果上一步是BoxTarget,还原BoxTarget
                    pMap[Row][Cul] = BoxTarget;
                    Is_BoxT=0;
                }
                else{pMap[Row][Cul] =Way;}

                if(pMap[Row][Cul + 1] == BoxTarget){//判断下一个是BoxTarget 就记录
                    Is_BoxT=1;
                }

                Cul++;
                pMap[Row][Cul] = Character;
                step+=1;
                break;
            }
            if (pMap[Row][Cul + 1] == Box) {
                if (pMap[Row][Cul + 2] == Obstacle||pMap[Row][Cul - 2] ==Box) {
                    break;
                }
                if (pMap[Row][Cul + 2] == BoxTarget) {
                    pMap[Row][Cul] =Way;
                    Cul++;
                    pMap[Row][Cul] = Character;

                    BoxNum-=1;
                    step+=1;
                    break;
                }
                if (pMap[Row][Cul + 2] == Way) {
                    pMap[Row][Cul] =Way;
                    Cul++;
                    pMap[Row][Cul] = Character;
                    pMap[Row][Cul + 1] = Box;
                    step+=1;
                    break;
                }
            }
            default:break;
        }
        case w: {
            if(pMap[Row-1][Cul] ==Obstacle){break;}
            if (pMap[Row-1][Cul] == Way || pMap[Row-1][Cul] == BoxTarget) {

                if(Is_BoxT){ //如果上一步是BoxTarget,还原BoxTarget
                    pMap[Row][Cul] = BoxTarget;
                    Is_BoxT=0;
                }
                else{pMap[Row][Cul] =Way;}

                if(pMap[Row-1][Cul] == BoxTarget){//判断下一个是BoxTarget 就记录
                    Is_BoxT=1;
                }

                Row--;
                pMap[Row][Cul] = Character;
                step+=1;
                break;
            }
            if (pMap[Row-1][Cul] == Box) {
                if (pMap[Row-2][Cul] == Obstacle||pMap[Row][Cul - 2] ==Box) {
                    break;
                }
                if (pMap[Row-2][Cul] == BoxTarget) {
                    pMap[Row][Cul] =Way;
                    Row--;
                    pMap[Row][Cul] = Character;

                    step+=1;
                    BoxNum-=1;
                    break;
                }
                if (pMap[Row-2][Cul] == Way) {
                    pMap[Row][Cul] =Way;
                    Row--;
                    pMap[Row][Cul] = Character;
                    pMap[Row-1][Cul] = Box;
                    step+=1;
                    break;
                }
            }

        }
        case s: {
            if(pMap[Row+1][Cul] ==Obstacle){break;}
            if (pMap[Row+1][Cul] == Way || pMap[Row+1][Cul] == BoxTarget) {

                if(Is_BoxT){ //如果上一步是BoxTarget,还原BoxTarget
                    pMap[Row][Cul] = BoxTarget;
                    Is_BoxT=0;
                }
                else{pMap[Row][Cul] =Way;}

                if(pMap[Row+1][Cul] == BoxTarget){//判断下一个是BoxTarget 就记录
                    Is_BoxT=1;
                }

                Row++;
                pMap[Row][Cul] = Character;
                step+=1;
                break;
            }
            if (pMap[Row+1][Cul] == Box) {
                if (pMap[Row+2][Cul] == Obstacle||pMap[Row][Cul - 2] ==Box) {
                    break;
                }
                if (pMap[Row+2][Cul] == BoxTarget) {
                    pMap[Row][Cul] =Way;
                    Row++;
                    pMap[Row][Cul] = Character;

                    step+=1;
                    BoxNum-=1;
                    break;
                }
                if (pMap[Row+2][Cul] == Way) {
                    pMap[Row][Cul] =Way;
                    Row++;
                    pMap[Row][Cul] = Character;
                    pMap[Row+1][Cul] = Box;
                    step+=1;
                    break;
                }
            }

        }
    
    }
        Print_Map(pMap);
}

void Print_Map(int (*pMap)[8]){

//    system("cls");

    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            switch(*(*(pMap+i)+j)) {
                case 1:
                    printf(" □ ");//Box
                    break;
                case 9:
                    printf(" ♀ ");//主角
                    break;
                case 3:
                    printf(" ◎ ");//BoxTarget
                    break;
                case 7:
                    printf("   ");
                    break;
                case 5:
                    printf(" ■ ");//Obstacle
                    break;
                case 6:
                    printf("¤");
                    break;
                default:
                    break;
            }
        }
        putchar('\n');
    } fflush(stdout);
}