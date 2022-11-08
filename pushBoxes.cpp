#include<bits/stdc++.h>
#include<conio.h>
using namespace std;
#define MAXN 0x7f
char _map[MAXN][MAXN],tmp1,tmp2;
int n,m,num,x,y,step;
int _box[MAXN][3],_point[MAXN][3];
char person,brick,point,box;
void reset()
{
	for(int i=1;i<=num;i++)
		if(_map[_point[i][1]][_point[i][2]]!=person&&_map[_point[i][1]][_point[i][2]]!=box)
			_map[_point[i][1]][_point[i][2]]=point;
}
void print()
{
	system("cls");
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
			cout<<_map[i][j];
		cout<<endl;
	}
}
bool check()
{
	bool flag=1;
	for(int i=1;i<=num;i++)
		if(_map[_point[i][1]][_point[i][2]]!=box)
		{
			flag=0;
			break;
		}
	if(flag)
	{
		system("cls");
		printf("you win with %d steps",step);
	}
	return flag;
}
void move()
{
	char c=getch();
	_map[x][y]=' ';
	if(c=='w')
		if(_map[x-1][y]!=brick&&_map[x-1][y]!=box)
			x--;
		else if(_map[x-1][y]==box&&_map[x-2][y]!=brick&&_map[x-2][y]!=box)
		{
			x--;
			_map[x-1][y]=box;
		}
	if(c=='s')
		if(_map[x+1][y]!=brick&&_map[x+1][y]!=box)
			x++;
		else if(_map[x+1][y]==box&&_map[x+2][y]!=brick&&_map[x+2][y]!=box)
		{
			x++;
			_map[x+1][y]=box;
		}
	if(c=='a')
		if(_map[x][y-1]!=brick&&_map[x][y-1]!=box)
			y--;
		else if(_map[x][y-1]==box&&_map[x][y-2]!=brick&&_map[x][y-2]!=box)
		{
			y--;
			_map[x][y-1]=box;
		}
	if(c=='d')
		if(_map[x][y+1]!=brick&&_map[x][y+1]!=box)
			y++;
		else if(_map[x][y+1]==box&&_map[x][y+2]!=brick&&_map[x][y+2]!=box)
		{
			y++;
			_map[x][y+1]=box;
		}
	_map[x][y]=person;
	reset();
}
int main()
{
	cout<<"person: brick: point: box:";
	cin>>person>>brick>>point>>box;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			_map[i][j]=getch();
			if(_map[i][j]==person)
				x=i,y=j;
			if(_map[i][j]==point)
			{
				_point[++num][1]=i;
				_point[num][2]=j;
			}
		}
		getch();
	}
	while(!check())
	{
		print();
		move();
		step++;
	}
	return 0;
} 
/*
* # @ 0
5 5
#####
#*  #
# 0 #
# #@#
#####
*/
