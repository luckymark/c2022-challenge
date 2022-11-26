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
int n,m,step; char a[MAX_N][MAX_N]; bool tar[MAX_N][MAX_N];
//#-Wall @-current_position T-Target Y-Finished pushing.-Freeway O_Box
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
			if (tar[i][j]) putchar(a[i][j]=='O'?'Y':'T'); else putchar(a[i][j]);
		}
	}
}
inline bool is_finished(void)
{
	for (int i=1;i<=n;++i) for (int j=1;j<=m;++j)
	if (tar[i][j]&&a[i][j]!='O') return 0; return 1;
}
inline bool valid(const int& x,const int& y)
{
	if (x<1||x>n||y<1||y>m) return 0;
	if (a[x][y]=='#'||a[x][y]=='O') return 0;
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
	int nx,ny;
	for (int i=1;i<=n;++i)
	{
		for (int j=1;j<=m;++j)
		{
			if (a[i][j]=='@') nx=i,ny=j;
			if (a[i][j]=='T') tar[i][j]=1,a[i][j]='.';
		}
	}
	print();
	while (!is_finished())
	{
		char ch=getch();
		if (ch==-32)
		{
			ch=getch();
			switch (ch)
			{
				case 72:
					if (a[nx-1][ny]=='O')
					{
						if (valid(nx-2,ny)) a[nx-2][ny]='O',a[nx-1][ny]='@',a[nx][ny]='.',--nx,++step;
					}
					else if (valid(nx-1,ny)) a[nx-1][ny]='@',a[nx][ny]='.',--nx,++step; break;
				case 80:
					if (a[nx+1][ny]=='O')
					{
						if (valid(nx+2,ny)) a[nx+2][ny]='O',a[nx+1][ny]='@',a[nx][ny]='.',++nx,++step;
					}
					else if (valid(nx+1,ny)) a[nx+1][ny]='@',a[nx][ny]='.',++nx,++step; break;
				case 75:
					if (a[nx][ny-1]=='O')
					{
						if (valid(nx,ny-2)) a[nx][ny-2]='O',a[nx][ny-1]='@',a[nx][ny]='.',--ny,++step;
					}
					else if (valid(nx,ny-1)) a[nx][ny-1]='@',a[nx][ny]='.',--ny,++step; break;
				case 77:
					if (a[nx][ny+1]=='O')
					{
						if (valid(nx,ny+2)) a[nx][ny+2]='O',a[nx][ny+1]='@',a[nx][ny]='.',++ny,++step;
					}
					else if (valid(nx,ny+1)) a[nx][ny+1]='@',a[nx][ny]='.',++ny,++step; break;
			}
		}
		print();
	}
	puts("Victory!");
	sleep(3);
	FILE *printer=fopen("score.txt","w");
	fprintf(printer,"Total Steps Cost are: %d steps\n",step);
	fclose(printer);
	return 0;
}