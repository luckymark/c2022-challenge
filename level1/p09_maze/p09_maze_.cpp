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
"                 *Ϊ�ϰ�                          ***************",
"                 AΪ���                          *A **    ******",
"                 OΪ����                          **    ** **   *",
"                 w��������������ƶ�              ** ***** ** * *",
"                 s��������������ƶ�              **   ***    * *",
"                 a��������������ƶ�              **** ******** *",
"                 d��������������ƶ�              **   **    *  *",
"                                                  ** **** ** ****",
"         ��Ϸʤ�������������Ҫ�ƶ�������         **      **   O*",
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
	printf("                                    ��Ϸ���Թ���С���Ѷȣ�                          \n");
	printf("\n");
	printf("                                 �����ߣ�2022080903022 ����                         \n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("                                ");
	system("pause");
}
