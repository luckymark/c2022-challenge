#include<bits/stdc++.h>
#include<conio.h>
using namespace std;
#define MAXN 0x7f
char Map[MAXN][MAXN];
int n,m;
int x,y,x_1,y_1;
char person,brick,point;
void print()
{
	system("cls");
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
			cout<<Map[i][j];
		cout<<endl;
	}
}
void move()
{
	char c=getch();
	Map[x][y]=' ';
	if(c=='w'&&Map[x-1][y]!=brick)
		x--;
	else if(c=='s'&&Map[x+1][y]!=brick)
		x++;
	else if(c=='a'&&Map[x][y-1]!=brick)
		y--;
	else if(c=='d'&&Map[x][y+1]!=brick)
		y++;
	Map[x][y]=person;
}
bool check()
{
	if(x==x_1&&y==y_1)
	{
		system("cls");
		cout<<"you win"<<endl;
		return 1;
	}
	return 0;
}
int main()
{
	cout<<"person: brick: point: "<<endl;
	cin>>person>>brick>>point;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		
		for(int j=1;j<=m;j++)
		{
			Map[i][j]=getch();
			if(Map[i][j]==person)
				x=i,y=j;
			else if(Map[i][j]==point)
				x_1=i,y_1=j;
		}
		getch();
	}
	//38 40 37 39 ÉÏÏÂ×óÓÒ
	while(!check())
	{
		print();
		move();
	}
	return 0;
}
/*
* # @
5 5
#####
#*  #
# # #
#  @#
#####

*/
