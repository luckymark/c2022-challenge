/*
	从map.txt中读取地图信息，通关后在score.txt中输出时间
*/
#include<cstdio>
#include<fstream>
#include<ctime>
#include<windows.h>
#include<conio.h>
using namespace std;
const int MAX_N=105;
int n,m; char a[MAX_N][MAX_N];
//#-Wall @-current_position E-exit .-Freeway
inline void print(void)
{	
	#ifdef _WIN32
		system("cls");
	#else
		system("clear");
	#endif
	for (int i=1;i<=n;++i,putchar('\n'))
	{
		for (int j=1;j<=m;++j)
		{
			putchar(a[i][j]);
		}
	}
}
inline bool valid(const int& x,const int& y)
{
	if (x<1||x>n||y<1||y>m) return 0;
	if (a[x][y]=='#') return 0;
	return 1;
}
int main()
{
	FILE *reader=fopen("map.txt","r");
	while (fscanf(reader,"%s",a[n+1]+1)!=EOF)
	{
		++n;
		m=strlen(a[n]+1);
	}
	fclose(reader);
	int nx,ny,tx,ty;
	for (int i=1;i<=n;++i)
	{
		for (int j=1;j<=m;++j)
		{
			if (a[i][j]=='@') nx=i,ny=j;
			if (a[i][j]=='E') tx=i,ty=j;
		}
	}
	int t1=time(0);
	print();
	while (nx!=tx||ny!=ty)
	{
		char ch=getch();
		if (ch==-32)
		{
			ch=getch();
			switch (ch)
			{
				case 72:
					if (valid(nx-1,ny)) a[nx-1][ny]='@',a[nx][ny]='.',--nx; break;
				case 80:
					if (valid(nx+1,ny)) a[nx+1][ny]='@',a[nx][ny]='.',++nx; break;
				case 75:
					if (valid(nx,ny-1)) a[nx][ny-1]='@',a[nx][ny]='.',--ny; break;
				case 77:
					if (valid(nx,ny+1)) a[nx][ny+1]='@',a[nx][ny]='.',++ny; break;
			}
		}
		print();
	}
	int t2=time(0);
	FILE *printer=fopen("score.txt","w");
	fprintf(printer,"Find the exit successfully!\nYour time cost is %d s\n",t2-t1);
	fclose(printer);
	return 0;
}