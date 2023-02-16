#include <stdio.h>
#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;
//'*'��ͼ��Χ,'A'���,
//'0'����,'#'�ϰ���,
//'��'Ŀ��ص� 
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
	system("title ���졪��������");
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
		cout<<"���Ѿ�����"<<step<<"��"<<endl;
		cout<<"1�ŵ�ͼ"<<endl;
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
		cout<<"���Ѿ�����"<<step<<"��"<<endl;
		cout<<"2�ŵ�ͼ"<<endl;
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
	printf("                                    ��Ϸ��������                                    \n");
	printf("\n");
	printf("                                 �����ߣ�2022080903022 ����                         \n");
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
	printf("                                    ��Ϸ�������                                    \n");
	printf("\n");
	printf("                                  '*'������ͼ��Χ                        \n");
	printf("                                  'A'������� \n");
	printf("                                  '0'�������� \n");
	printf("                                  '#'�����ϰ��� \n");
	printf("                                  '��'����Ŀ��ص� \n");
	printf("\n");
	printf("\n");
	printf("                         �����Ҫͨ��a��d��w��s���ֱ����A���ҡ��ϡ����ƶ� \n");
	printf("                         �����е������ƶ���Ŀ��ص��ʤ�� \n");
	printf("                         ��Ϸ�����ŵ�ͼ���Ѷ����ε�������һ�ŵ�ͼͨ�����Զ�����ڶ��ŵ�ͼ\n");
	printf("\n");
	printf("\n");
	printf("                         ");
	system("pause");
}
void operate(char map[][50],int &x,int &y,int &k)//k����ڼ�����ͼ 
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
	//����������ǿյأ�����������ƶ� 
	{
		if(map[x][y]!='!')
			map[x][y]=' ';
		y--;
		map[x][y]='A';
	}
	else if(map[x][y-1]=='0' && map[x][y-2]==' ') 
	//��������������ӣ�����������ǿյأ������Ӻ���Ҿ������ƶ� 
	{
		map[x][y-2]='0';
		if(map[x][y]!='!')
			map[x][y]=' ';
		y--;
		map[x][y]='A';
	}
	else if(map[x][y-1]=='0' && map[x][y-2]=='!') 
	//��������������ӣ������������Ŀ�ĵأ������Ӻ���Ҿ������ƶ���Ŀ�ĵر���������ѵ���λ�� 
	{
		map[x][y-2]='$';
		if(map[x][y]!='!')
			map[x][y]=' ';
		y--;
		map[x][y]='A';
	}
	else if(map[x][y-1]=='$' && map[x][y-2]==' ') 
	//������������ѵ���Ŀ�ĵص����ӣ�����������ǿյأ��򵽴�Ŀ�ĵص����Ӻ���Ҿ������ƶ���Ŀ�ĵر���ٴγ��� 
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
	//����������ǿյأ�����������ƶ� 
	{
		if(map[x][y]!='!')
			map[x][y]=' ';
		y++;
		map[x][y]='A';
	}
	else if(map[x][y+1]=='0' && map[x][y+2]==' ')
	//�������ұ������ӣ��������ұ��ǿյأ������Ӻ���Ҿ������ƶ� 
	{
		map[x][y+2]='0';
		if(map[x][y]!='!')
			map[x][y]=' ';
		y++;
		map[x][y]='A';
	}
	else if(map[x][y+1]=='0' && map[x][y+2]=='!')
	//�������ұ������ӣ��������ұ���Ŀ�ĵأ������Ӻ���Ҿ������ƶ���Ŀ�ĵر���������ѵ���λ��
	{
		map[x][y+2]='$';
		if(map[x][y]!='!')
			map[x][y]=' ';
		y++;
		map[x][y]='A';
	}
	else if(map[x][y+1]=='$' && map[x][y+2]==' ')
	//������������ѵ���Ŀ�ĵص����ӣ�����������ǿյأ��򵽴�Ŀ�ĵص����Ӻ���Ҿ������ƶ���Ŀ�ĵر���ٴγ��� 
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
	//����������ǿյأ�����������ƶ� 
	{
		if(map[x][y]!='!')
			map[x][y]=' ';
		x--;
		map[x][y]='A';
	}
	else if(map[x-1][y]=='0' && map[x-2][y]==' ')
	//�������ϱ������ӣ��������ϱ��ǿյأ������Ӻ���Ҿ������ƶ� 
	{
		map[x-2][y]='0';
		if(map[x][y]!='!')
			map[x][y]=' ';
		x--;
		map[x][y]='A';
	}
	else if(map[x-1][y]=='0' && map[x-2][y]=='!')
	//�������ϱ������ӣ��������ϱ���Ŀ�ĵأ������Ӻ���Ҿ������ƶ���Ŀ�ĵر���������ѵ���λ��
	{
		map[x-2][y]='$';
		if(map[x][y]!='!')
			map[x][y]=' ';
		x--;
		map[x][y]='A';
	}
	else if(map[x-1][y]=='$' && map[x-2][y]==' ')
	//�������ϱ����ѵ���Ŀ�ĵص����ӣ��������ϱ��ǿյأ��򵽴�Ŀ�ĵص����Ӻ���Ҿ������ƶ���Ŀ�ĵر���ٴγ��� 
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
	//����������ǿյأ�����������ƶ� 
	{
		if(map[x][y]!='!')
			map[x][y]=' ';
		x++;
		map[x][y]='A';
	}
	else if(map[x+1][y]=='0' && map[x+2][y]==' ')
	//�������±������ӣ��������±��ǿյأ������Ӻ���Ҿ������ƶ� 
	{
		map[x+2][y]='0';
		if(map[x][y]!='!')
			map[x][y]=' ';
		x++;
		map[x][y]='A';
	}
	else if(map[x+1][y]=='0' && map[x+2][y]=='!')
	//�������±������ӣ��������±���Ŀ�ĵأ������Ӻ���Ҿ������ƶ���Ŀ�ĵر���������ѵ���λ��
	{
		map[x+2][y]='$';
		if(map[x][y]!='!')
			map[x][y]=' ';
		x++;
		map[x][y]='A';
	}
	else if(map[x+1][y]=='$' && map[x+2][y]==' ')
	//�������±����ѵ���Ŀ�ĵص����ӣ��������±��ǿյأ��򵽴�Ŀ�ĵص����Ӻ���Ҿ������ƶ���Ŀ�ĵر���ٴγ��� 
	{
		map[x+2][y]='0';
		if(map[x][y]!='!')
			map[x][y]=' ';
		x++;
		map[x][y]='A';
	}
}
void destination1(char map[][50],int &x,int &y)
//1�ŵ�ͼ���������Ŀ�ĵ��غϵ���� 
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
//2�ŵ�ͼ���������Ŀ�ĵ��غϵ���� 
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
//���ȫ�����Ŀ�ĵ��Ѿ�������������Ϸʤ�� 
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
