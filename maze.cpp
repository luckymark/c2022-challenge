#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<windows.h>
#include<conio.h>
using namespace std;
char a[20][20]={"O     ####",
				"##### ####",
				"##### ####",
				"####  ####",
				"     #####",
				" #########",
				" ##     ##",
				" ## ### ##",
				" ## ### ##",
				"    ###  $"};
int main()
{
	CONSOLE_CURSOR_INFO cursor_info={1,0};
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),&cursor_info);
	cout<<"w表示上，s表示下，d表示右，a表示左"<<endl;
	cout<<"#表示墙，O表示玩家，$表示终点"<<endl;
	Sleep(1000);
	system("cls");
	int x=0,y=0;
	char ch;
	for(int i=0;i<=9;++i)
		puts(a[i]);
	while(1) {
		ch=getch();
		if(ch=='w') {
			if(a[x-1][y]==' '||a[x-1][y]=='$') {
				a[x][y]=' ';
				x--;
				a[x][y]='O';
			}
		}
		if(ch=='s') {
			if(a[x+1][y]==' '||a[x+1][y]=='$') {
				a[x][y]=' ';
				x++;
				a[x][y]='O';
			}
		}
		if(ch=='a') {
			if(a[x][y-1]==' '||a[x][y-1]=='$') {
				a[x][y]=' ';
				y--;
				a[x][y]='O';
			}
		}
		if(ch=='d') {
			if(a[x][y+1]==' '||a[x][y+1]=='$') {
				a[x][y]=' ';
				y++;
				a[x][y]='O';
			}
		}
		system("cls");
		for(int i=0;i<=9;++i) 
			puts(a[i]);
		if(x==9&&y==9) 
			break;
	}
	cout<<"你赢了";
	Sleep(10000);
	return 0;
}
