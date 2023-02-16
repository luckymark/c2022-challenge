#include <stdio.h>
#include <conio.h>
#include <windows.h>
using namespace std;
char maps[20][80]=
{
"                                                                 ",
"                                                                 ",
"                                                                 ",
"                                                                 ",
"                                                                 ",
"                 *为障碍                          ***************",
"                 A为玩家                          *A **    ******",
"                 O为出口                          **    ** **   *",
"                 w键控制玩家向上移动              ** ***** ** * *",
"                 s键控制玩家向下移动              **   ***    * *",
"                 a键控制玩家向左移动              **** ******** *",
"                 d键控制玩家向右移动              **   **    *  *",
"                                                  ** **** ** ****",
"         游戏胜利条件：玩家需要移动至出口         **      **   O*",
"                                                  ***************",
};
void print(char maps[][80]);
void welcome();
int main()
{
	system("color b4");
	welcome();
	system("cls");
	system("color 03");
	int x=6,y=51;
	char move;
	print(maps);
	while(1)
	{
		move=getch();
		if(move=='a')
		{
			if(maps[x][y-1]==' ')
			{
				maps[x][y]=' ';
				y--;
				maps[x][y]='A';
			}
		}
		if(move=='d')
		{
			if(maps[x][y+1]==' ')
			{
				maps[x][y]=' ';
				y++;
				maps[x][y]='A';
			}
		}
		if(move=='w')
		{
			if(maps[x-1][y]==' ')
			{
				maps[x][y]=' ';
				x--;
				maps[x][y]='A';
			}
		}
		if(move=='s')
		{
			if(maps[x+1][y]==' ')
			{
				maps[x][y]=' ';
				x++;
				maps[x][y]='A';
			}
		}
		system("cls");
		print(maps);
		if( x==13 && y==62 && move=='d')
		{
			maps[x][y]='A';
			maps[x][y+1]=' ';
			system("cls");
			print(maps);
			break;
		}
	}
	printf("\n\n                                                  YOU WIN!\n\n");
	printf("                                                  ");
	system("pause");
	return 0;	
}
void print(char maps[][80])
{
	int i;
	for(i=0;i<=14;i++)
	{
		puts(maps[i]);
	}
}
void welcome()
{
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("                                    游戏：迷宫（小白难度）                          \n");
	printf("\n");
	printf("                                 制作者：2022080903022 赵庆                         \n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("                                ");
	system("pause");
}
