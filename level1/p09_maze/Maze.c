#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void PrintMap(char Map[10][10]);
void Control(char Map[10][10]);

const char RMap1[10][10] = {{'|', '*', ' ', ' ', '|', '|', '|', '|', '|', '#'},
                     {'|', '|', ' ', '|', ' ', '|', '|', ' ', ' ', ' '},
                     {'|', ' ', ' ', ' ', ' ', '|', '|', ' ', ' ', '|'},
                     {'|', ' ', '|', '|', ' ', ' ', ' ', ' ', '|', '|'},
                     {'|', '|', '|', '|', '|', '|', '|', '|', '|', '|'}};

//char RMap2[10][10] = {{'|', '|', '|', '|', ' ', '◎', '|', '|', '|', '|'},
//                      {'◎', ' ', ' ',' ', ' ', '■', '|', '|', ' ', '|'},
//                      {' ', '|', ' ', '|', ' ', ' ', '|', ' ', ' ', '|'},
//                      {' ', '■', ' ', '|', ' ', ' ', ' ', '■', ' ', '|'},
//                      {'*', ' ', ' ', '|', '|', '|', '|', ' ', ' ', '◎'},
//                      {'|', '|', '|', '|','|', '|', '|', '|', '|', '|'}};

void main(){
    PrintMap(RMap1);

    printf("'|'是墙壁     '*'是玩家     '#'是出口");
    fflush(stdout);
    Control(RMap1);

}

void Control(char Map[10][10]){

    int Row=0,Cul=1;

    while(Map[0][9]!='*') {
        char Letter;
        Letter = getch();


        if (Letter == 'W' || Letter == 'w') {
            if (Map[Row - 1][Cul] != '|') {
                Map[Row][Cul] = ' ';
                Row--;
                Map[Row][Cul] = '*';
            }
        }
        if (Letter == 'S' || Letter == 's') {
            if (Map[Row + 1][Cul] != '|') {
                Map[Row][Cul] = ' ';
                Row++;
                Map[Row][Cul] = '*';
            }
        }
        if (Letter == 'A' || Letter == 'a') {
            if (Map[Row][Cul - 1] != '|') {
                Map[Row][Cul] = ' ';
                Cul--;
                Map[Row][Cul] = '*';
            }
        }
        if (Letter == 'D' || Letter == 'd') {
            if (Map[Row][Cul + 1] != '|') {
                Map[Row][Cul] = ' ';
                Cul++;
                Map[Row][Cul] = '*';
            }
        }
        PrintMap(Map);
    }
    printf("You Win HH!");
    system("pause");
}


void PrintMap(char Map[10][10]){

    system("cls");

     for (char i=0;i<6;i++){
         for (char j=0;j<10;j++) {
             printf("%c", Map[i][j]);
             fflush(stdout);
         }
         printf("\n");
     }
}
