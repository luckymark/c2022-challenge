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
	cout<<"w��ʾ�ϣ�s��ʾ�£�d��ʾ�ң�a��ʾ��"<<endl;
	cout<<"#��ʾǽ��O��ʾ��ң�$��ʾ�յ�"<<endl;
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
	cout<<"��Ӯ��";
	Sleep(10000);
	return 0;
}
