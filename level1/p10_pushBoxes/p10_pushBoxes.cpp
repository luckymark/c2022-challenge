#include <stdio.h>
#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;
//'*'地图范围,'A'玩家,
//'0'箱子,'#'障碍物,
//'！'目标地点 
char map1[50][50]=
{
"***************************",
"***************************",
"*!        !   ! ! *********",
"** 0    #   # 0 0 *********",
"***  # #  !    #  *********",
"***   0  #  0     *********",
"***A              *********",
"***************************",
"***************************",
};
char map2[50][50]=
{
"***************************",
"******  !*** ***!**********",
"*!   # 0   !   ! ! ********",
"** 0    #   # 0 0   **!****",
"***  #    !    #  #  *  ***",
"***  0 0  #  0     0    ***",
"***A              0 0   ***",
"******************!  !*****",
"***************************",
};
char map[50][50]=
{
"***************************",
"***************************",
"***************************",
"***************************",
"***************************",
"***************************",
"***************************",
"***************************",
"***************************",
};
void init(char [][50],char [][50]);
void print(char [][50]);
void welcome();
void rule(); 
void operate(char [][50],int &x,int &y,int &k);
void left(char [][50],int &x,int &y);
void right(char [][50],int &x,int &y);
void up(char [][50],int &x,int &y);
void down(char [][50],int &x,int &y);
void destination1(char map[][50],int &x,int &y);
void destination2(char map[][50],int &x,int &y);
int win(char map[][50]);
int main()
{
	system("title 赵庆——推箱子");
	system("color b4");
	welcome();
	system("cls");
	rule();
	system("cls");
	system("color 03");
	int x=6,y=3;
	int step=0,k=1;
	init(map1,map);
	print(map);
	while(1)
	{
		operate(map,x,y,k);
		step++;
		cout<<"您已经走了"<<step<<"步"<<endl;
		cout<<"1号地图"<<endl;
		if(win(map)==1)
			break;
	}
	cout<<"You Win!"<<endl;
	system("cls");
	x=6,y=3;
	step=0,k=2;
	system("color 05");
	init(map2,map);
	print(map);
	while(1)
	{
		operate(map,x,y,k);
		step++;
		cout<<"您已经走了"<<step<<"步"<<endl;
		cout<<"2号地图"<<endl;
		if(win(map)==1)
			break;
	}
	cout<<"You Win!"<<endl;
	return 0;
}
void init(char maps[][50],char map[][50])
{
	for(int i=0;i<=8;i++)
	{
		for(int j=0;j<=26;j++)
		{
			map[i][j]=maps[i][j];
		}
	}
}
void print(char map[][50])
{
	int i;
	for(i=0;i<=8;i++)
	{
		puts(map[i]);
	}
}
void welcome()
{
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("                                    游戏：推箱子                                    \n");
	printf("\n");
	printf("                                 制作者：2022080903022 赵庆                         \n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("                                ");
	system("pause");
}
void rule()
{
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("                                    游戏规则介绍                                    \n");
	printf("\n");
	printf("                                  '*'——地图范围                        \n");
	printf("                                  'A'——玩家 \n");
	printf("                                  '0'——箱子 \n");
	printf("                                  '#'——障碍物 \n");
	printf("                                  '！'——目标地点 \n");
	printf("\n");
	printf("\n");
	printf("                         玩家需要通过a、d、w、s键分别控制A左、右、上、下移动 \n");
	printf("                         将所有的箱子移动至目标地点后胜利 \n");
	printf("                         游戏有两张地图，难度依次递增，第一张地图通过后自动进入第二张地图\n");
	printf("\n");
	printf("\n");
	printf("                         ");
	system("pause");
}
void operate(char map[][50],int &x,int &y,int &k)//k代表第几个地图 
{
	char move;
	move=getch();
	switch(move)
	{
		case 'a':	left(map,x,y);
			break;
		case 'd':	right(map,x,y);
			break;
		case 'w':	up(map,x,y);
			break;
		case 's':	down(map,x,y);
			break;		
	}
	system("cls");
	print(map);
	if(k==1)
		destination1(map,x,y);
	if(k==2)
		destination2(map,x,y);
}
void left(char [][50],int &x,int &y)
{
	if(map[x][y-1]==' ')
	//如果向左走是空地，则玩家向左移动 
	{
		if(map[x][y]!='!')
			map[x][y]=' ';
		y--;
		map[x][y]='A';
	}
	else if(map[x][y-1]=='0' && map[x][y-2]==' ') 
	//如果玩家左边是箱子，且箱子左边是空地，则箱子和玩家均向左移动 
	{
		map[x][y-2]='0';
		if(map[x][y]!='!')
			map[x][y]=' ';
		y--;
		map[x][y]='A';
	}
	else if(map[x][y-1]=='0' && map[x][y-2]=='!') 
	//如果玩家左边是箱子，且箱子左边是目的地，则箱子和玩家均向左移动，目的地标记上箱子已到达位置 
	{
		map[x][y-2]='$';
		if(map[x][y]!='!')
			map[x][y]=' ';
		y--;
		map[x][y]='A';
	}
	else if(map[x][y-1]=='$' && map[x][y-2]==' ') 
	//如果玩家左边是已到达目的地的箱子，且箱子左边是空地，则到达目的地的箱子和玩家均向左移动，目的地标记再次出现 
	{
		map[x][y-2]='0';
		if(map[x][y]!='!')
			map[x][y]=' ';
		y--;
		map[x][y]='A';
	}
}
void right(char [][50],int &x,int &y)
{
	if(map[x][y+1]==' ')
	//如果向右走是空地，则玩家向右移动 
	{
		if(map[x][y]!='!')
			map[x][y]=' ';
		y++;
		map[x][y]='A';
	}
	else if(map[x][y+1]=='0' && map[x][y+2]==' ')
	//如果玩家右边是箱子，且箱子右边是空地，则箱子和玩家均向右移动 
	{
		map[x][y+2]='0';
		if(map[x][y]!='!')
			map[x][y]=' ';
		y++;
		map[x][y]='A';
	}
	else if(map[x][y+1]=='0' && map[x][y+2]=='!')
	//如果玩家右边是箱子，且箱子右边是目的地，则箱子和玩家均向右移动，目的地标记上箱子已到达位置
	{
		map[x][y+2]='$';
		if(map[x][y]!='!')
			map[x][y]=' ';
		y++;
		map[x][y]='A';
	}
	else if(map[x][y+1]=='$' && map[x][y+2]==' ')
	//如果玩家左边是已到达目的地的箱子，且箱子左边是空地，则到达目的地的箱子和玩家均向左移动，目的地标记再次出现 
	{
		map[x][y+2]='0';
		if(map[x][y]!='!')
			map[x][y]=' ';
		y++;
		map[x][y]='A';
	}
}
void up(char [][50],int &x,int &y)
{
	if(map[x-1][y]==' ')
	//如果向上走是空地，则玩家向上移动 
	{
		if(map[x][y]!='!')
			map[x][y]=' ';
		x--;
		map[x][y]='A';
	}
	else if(map[x-1][y]=='0' && map[x-2][y]==' ')
	//如果玩家上边是箱子，且箱子上边是空地，则箱子和玩家均向上移动 
	{
		map[x-2][y]='0';
		if(map[x][y]!='!')
			map[x][y]=' ';
		x--;
		map[x][y]='A';
	}
	else if(map[x-1][y]=='0' && map[x-2][y]=='!')
	//如果玩家上边是箱子，且箱子上边是目的地，则箱子和玩家均向上移动，目的地标记上箱子已到达位置
	{
		map[x-2][y]='$';
		if(map[x][y]!='!')
			map[x][y]=' ';
		x--;
		map[x][y]='A';
	}
	else if(map[x-1][y]=='$' && map[x-2][y]==' ')
	//如果玩家上边是已到达目的地的箱子，且箱子上边是空地，则到达目的地的箱子和玩家均向上移动，目的地标记再次出现 
	{
		map[x-2][y]='0';
		if(map[x][y]!='!')
			map[x][y]=' ';
		x--;
		map[x][y]='A';
	}
}
void down(char [][50],int &x,int &y)
{
	if(map[x+1][y]==' ')
	//如果向下走是空地，则玩家向下移动 
	{
		if(map[x][y]!='!')
			map[x][y]=' ';
		x++;
		map[x][y]='A';
	}
	else if(map[x+1][y]=='0' && map[x+2][y]==' ')
	//如果玩家下边是箱子，且箱子下边是空地，则箱子和玩家均向下移动 
	{
		map[x+2][y]='0';
		if(map[x][y]!='!')
			map[x][y]=' ';
		x++;
		map[x][y]='A';
	}
	else if(map[x+1][y]=='0' && map[x+2][y]=='!')
	//如果玩家下边是箱子，且箱子下边是目的地，则箱子和玩家均向下移动，目的地标记上箱子已到达位置
	{
		map[x+2][y]='$';
		if(map[x][y]!='!')
			map[x][y]=' ';
		x++;
		map[x][y]='A';
	}
	else if(map[x+1][y]=='$' && map[x+2][y]==' ')
	//如果玩家下边是已到达目的地的箱子，且箱子下边是空地，则到达目的地的箱子和玩家均向下移动，目的地标记再次出现 
	{
		map[x+2][y]='0';
		if(map[x][y]!='!')
			map[x][y]=' ';
		x++;
		map[x][y]='A';
	}
}
void destination1(char map[][50],int &x,int &y)
//1号地图处理玩家与目的地重合的情况 
{
	if(x==2 && y==1)
	{
		map[2][1]='!';
	}
	if(x==2 && y==10)
	{
		map[2][10]='!';
	}
	if(x==4 && y==10)
	{
		map[4][10]='!';
	}
	if(x==2 && y==14)
	{
		map[2][14]='!';
	}
	if(x==2 && y==16)
	{
		map[2][16]='!';
	}
}
void destination2(char map[][50],int &x,int &y)
//2号地图处理玩家与目的地重合的情况 
{
	if(x==2 && y==1)
	{
		map[2][1]='!';
	}
	if(x==1 && y==8)
	{
		map[1][8]='!';
	}
	if(x==2 && y==11)
	{
		map[2][11]='!';
	}
	if(x==2 && y==15)
	{
		map[2][15]='!';
	}
	if(x==2 && y==17)
	{
		map[2][17]='!';
	}
	if(x==3 && y==22)
	{
		map[3][22]='!';
	}
	if(x==4 && y==10)
	{
		map[4][10]='!';
	}
	if(x==7 && y==18)
	{
		map[7][18]='!';
	}
	if(x==7 && y==21)
	{
		map[7][21]='!';
	}
}
int win(char map[][50])
//如果全部标记目的地已经被消除，则游戏胜利 
{
	for(int i=0;i<=8;i++)
	{
		for(int j=0;j<=26;j++)
		{
			if(map[i][j]=='!')
			{
				return 0;
				break;
			}
		}
	}
	return 1;
}
