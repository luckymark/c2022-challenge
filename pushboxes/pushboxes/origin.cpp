#include<graphics.h>
#include<conio.h>	
#include<stdio.h>

#define		MAP1			0
#define		MAP2			100
#define		MAP3			400
#define		MAP4			500
#define		ESC				27
#define		length			10

struct putBox
{
	int direction;		// 储存键盘按的方向：上(1) 下((2) 左(3) 右(4)
	int x;
	int y;				// 玩家当前坐标
	int boxs;			// 玩家需要完成的箱子数：箱子数为0时，游戏结束
}player;

enum list
{
	EMPTY,				// 0 表示空地
	WALL,				// 1 表示墙壁
	PLAYER,				// 2 表示玩家
	BOX,				// 3 表示箱子
	DES,				// 4 表示目的地
	FINISH,				// 5 表示箱子站在目的地上
	DESPLAYER,			// 6 表示人站在目的地上
};

int boxMap[length][length] =
{	// 地图
		{WALL,	WALL,	WALL,	WALL,	WALL,	WALL,	WALL,	WALL,	WALL,	WALL},
		{WALL,	WALL,	WALL,	WALL,	DES,	WALL,	WALL,	WALL,	WALL,	WALL},
		{WALL,	WALL,	EMPTY,	EMPTY,	EMPTY,	EMPTY,	EMPTY,	EMPTY,	WALL,	WALL},
		{WALL,	WALL,	EMPTY,	EMPTY,	BOX,	EMPTY,	BOX,	DES,	WALL,	WALL},
		{WALL,	WALL,	DES,	EMPTY,	BOX,	PLAYER,	EMPTY,	EMPTY,	WALL,	WALL},
		{WALL,	WALL,	EMPTY,	EMPTY,	EMPTY,	EMPTY,	EMPTY,	EMPTY,	WALL,	WALL},
		{WALL,	WALL,	EMPTY,	EMPTY,	EMPTY,	EMPTY,	EMPTY,	EMPTY,	WALL,	WALL},
		{WALL,	WALL,	EMPTY,	EMPTY,	EMPTY,	BOX,	EMPTY,	EMPTY,	WALL,	WALL},
		{WALL,	WALL,	WALL,	WALL,	WALL,	DES,	WALL,	WALL,	WALL,	WALL},
		{WALL,	WALL,	WALL,	WALL,	WALL,	WALL,	WALL,	WALL,	WALL,	WALL}
};

IMAGE img_player;	// 玩家图片
IMAGE img_box;		// 箱子图片

int map[length][length];
int upLeftx = 0, upLefty = 100;
int downRightx = 400, downRighty = 500;

void gameStart();		// 推箱子游戏主函数
void init();		// 初始化地图及数据
void reset();		// 重置本关卡
void drawMap();			// 绘制地图
void move();		// 玩家移动处理

int	main()
{
	gameStart();
	return 0;
}

void gameStart()//开始游戏
{
	int key;
	init();	// 初始化地图、数据
	while (1)
	{
		drawMap();	// 每次按键之后都会更新地图
		if (!player.boxs)
		{	// 完成全部箱子,游戏结束
			settextcolor(LIGHTRED);
			settextstyle(30, 30, 0);
			outtextxy(70, 55, "你赢了");
			break;
		}
		key = _getch();				// 获取用户按键
		player.direction = 0;	// 先清除移动方向
		switch (key)
		{
		case 'w':
			player.direction = 1;
			break;
		case 'a':
			player.direction = 3;
			break;
		case 's':
			player.direction = 2;
			break;
		case 'd':
			player.direction = 4;
			break;
		case ESC:
			return;
		case 'r':
			reset();
			continue;
			break;
		default:
			break;
		}
		move();			// 根据玩家移动方向，进行处理
	}
	_getch();
}

void init()//初始化
{
	initgraph(450, 550);		// 初始化窗口，设置窗口大小
	HWND window = GetHWnd();					// 获取当前窗口
	SetWindowText(window, "推箱子");	// 设置当前窗口的标题
	outtextxy(5, 5, "ESC: 退出");					// 设置提示信息
	outtextxy(80, 5, "R: 重置本关");
	outtextxy(5, 30, "W: 上   A：左   S：下   D：右");
	fillrectangle(0, 100, 400, 500);			// 划分游戏区域
	loadimage(&img_player, "C:\\Users\\谭浩翔\\Desktop\\visual studio\\pushboxes\\player.png", 45, 45);	// 加载玩家图片
	loadimage(&img_box, "C:\\Users\\谭浩翔\\Desktop\\visual studio\\pushboxes\\box.png", 45, 45);		// 加载玩家图片
	reset();
}

void reset()//重置地图
{
	int i, j;
	player.boxs = 0;
	for (i = 0; i < length; i++)
	{
		for (j = 0; j < length; j++)
		{
			map[i][j] = boxMap[i][j];
			if (map[i][j] == BOX)//算出箱子数目
			{	
				player.boxs++;
			}
			if (map[i][j] == PLAYER)// 记录玩家位置
			{	
				player.x = j;
				player.y = i;
			}
		}
	}

}

void drawMap()//绘制地图
{
	int i, j;
	int uy, ux;
	uy = (downRighty - upLefty) / length;
	ux = (downRightx - upLeftx) / length;
	// 绘制地图
	for (i = 0; i < length; i++)
	{
		for (j = 0; j < length; j++)
		{
			switch (map[i][j])
			{
			case EMPTY:	// 空地
				setfillcolor(CYAN);															// 选择填充颜色
				fillrectangle(upLeftx + j * ux, upLefty + i * uy, upLeftx + (j + 1) * ux, upLefty + (i + 1) * uy);		// 填充相应区域
				break;
			case WALL:	// 墙墙
				setfillcolor(DARKGRAY);
				fillrectangle(upLeftx + j * ux, upLefty + i * uy, upLeftx + (j + 1) * ux, upLefty + (i + 1) * uy);
				break;
			case PLAYER:	// 玩家
				putimage(upLeftx + j * ux, upLefty + i * uy, &img_player);
				break;
			case BOX:	// 箱子
				putimage(upLeftx + j * ux, upLefty + i * uy, &img_box);
				break;
			case DES:	// 目标点
				setfillcolor(GREEN);
				fillrectangle(upLeftx + j * ux, upLefty + i * uy, upLeftx + (j + 1) * ux, upLefty + (i + 1) * uy);
				break;
			case FINISH:	// 箱子站在目标点上
				putimage(upLeftx + j * ux, upLefty + i * uy, &img_box);
				break;
			case DESPLAYER:	// 玩家站在目标点上
				putimage(upLeftx + j * ux, upLefty + i * uy, &img_player);
				break;
			}

		}
	}

}

void move()
{
	int ux, uy, nextX, nextY;

	switch (player.direction)
	{	// 根据移动的方向，计算移动一格的位置，和移动两格的位置
	case 0:
		break;
	case 1:
		ux = player.x;
		uy = player.y - 1;
		nextX = ux;
		nextY = uy - 1;
		break;
	case 3:
		ux = player.x - 1;
		uy = player.y;
		nextX = ux - 1;
		nextY = uy;
		break;
	case 2:
		ux = player.x;
		uy = player.y + 1;
		nextX = ux;
		nextY = uy + 1;
		break;
	case 4:
		ux = player.x + 1;
		uy = player.y;
		nextX = ux + 1;
		nextY = uy;
		break;
	}

	if ((ux < 0 || ux > length)
		|| (uy < 0 || uy > length))
	{	// 如果移动后的x或y坐标超过范围，则无效
		return;
	}

	switch (map[uy][ux])
	{	// 根据下一格的内容，作出相应处理
	case EMPTY:	// 下一格为空地，则移动到空地
		map[uy][ux] = PLAYER;
		if (map[player.y][player.x] == DESPLAYER)
		{	// 如果玩家刚好站在目标点上，则移动后的格子为目标点
			map[player.y][player.x] = DES;
		}
		else
		{	// 如果玩家站在空地上，则移动后的格子为空地
			map[player.y][player.x] = EMPTY;
		}

		player.y = uy;
		player.x = ux;
		break;
	case WALL:	// 下一格为墙或者玩家（玩家：黑人脸问号？），则无效退出
	case PLAYER:
		break;
	case FINISH:	// 下一格为站在目标点上的箱子
	case BOX:	// 下一格为箱子，则根据箱子的下一格内容，作出不同处理
		switch (map[nextY][nextX])
		{	// 根据箱子的下一格内容，作出相应处理
		case EMPTY:	// 箱子的下一格为空，则玩家与箱子都前进一格
			map[nextY][nextX] = BOX;
			if (map[uy][ux] == FINISH)
			{	// 如果箱子刚好站在目标点上，则移动后的格子为人站在目标点上
				map[uy][ux] = DESPLAYER;
				player.boxs++;	// 箱子数++  因为箱子离开了目标点
			}
			else
			{	// 如果箱子站在空地上，则移动后的格子玩家
				map[uy][ux] = PLAYER;
			}

			if (map[player.y][player.x] == DESPLAYER)
			{	// 如果玩家刚好站在目标点上，则移动后的格子为目标点
				map[player.y][player.x] = DES;
			}
			else
			{	// 如果玩家站在空地上，则移动后的格子为空地
				map[player.y][player.x] = EMPTY;
			}
			player.y = uy;
			player.x = ux;
			break;
		case WALL:	// 箱子的下一格为墙、玩家（玩家：再次黑人脸问号？）、箱子，则无效退出
		case PLAYER:
		case BOX:
			break;
		case DES:	// 箱子的下一格为目标点，nice，玩家和箱子都前进一格，完成一个小目标，
			map[nextY][nextX] = FINISH;
			if (map[uy][ux] == FINISH)
			{	// 如果箱子刚好站在目标点上，则移动后的格子为人站在目标点上
				map[uy][ux] = DESPLAYER;
				player.boxs++;	// 箱子数++  因为箱子离开了目标点
			}
			else
			{	// 如果箱子站在空地上，则移动后的格子玩家
				map[uy][ux] = PLAYER;
			}

			if (map[player.y][player.x] == DESPLAYER)
			{	// 如果玩家刚好站在目标点上，则移动后的格子为目标点
				map[player.y][player.x] = DES;
			}
			else
			{	// 如果玩家站在空地上，则移动后的格子为空地
				map[player.y][player.x] = EMPTY;
			}
			player.y = uy;
			player.x = ux;
			player.boxs--;
			break;
		case FINISH:
			break;
		}
		break;
	case DES:
		map[uy][ux] = DESPLAYER;
		map[player.y][player.x] = EMPTY;
		player.y = uy;
		player.x = ux;
		break;

	case DESPLAYER:	// 玩家与目标点重合
		break;
	}
}