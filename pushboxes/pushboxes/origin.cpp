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
	int direction;		// ������̰��ķ�����(1) ��((2) ��(3) ��(4)
	int x;
	int y;				// ��ҵ�ǰ����
	int boxs;			// �����Ҫ��ɵ���������������Ϊ0ʱ����Ϸ����
}player;

enum list
{
	EMPTY,				// 0 ��ʾ�յ�
	WALL,				// 1 ��ʾǽ��
	PLAYER,				// 2 ��ʾ���
	BOX,				// 3 ��ʾ����
	DES,				// 4 ��ʾĿ�ĵ�
	FINISH,				// 5 ��ʾ����վ��Ŀ�ĵ���
	DESPLAYER,			// 6 ��ʾ��վ��Ŀ�ĵ���
};

int boxMap[length][length] =
{	// ��ͼ
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

IMAGE img_player;	// ���ͼƬ
IMAGE img_box;		// ����ͼƬ

int map[length][length];
int upLeftx = 0, upLefty = 100;
int downRightx = 400, downRighty = 500;

void gameStart();		// ��������Ϸ������
void init();		// ��ʼ����ͼ������
void reset();		// ���ñ��ؿ�
void drawMap();			// ���Ƶ�ͼ
void move();		// ����ƶ�����

int	main()
{
	gameStart();
	return 0;
}

void gameStart()//��ʼ��Ϸ
{
	int key;
	init();	// ��ʼ����ͼ������
	while (1)
	{
		drawMap();	// ÿ�ΰ���֮�󶼻���µ�ͼ
		if (!player.boxs)
		{	// ���ȫ������,��Ϸ����
			settextcolor(LIGHTRED);
			settextstyle(30, 30, 0);
			outtextxy(70, 55, "��Ӯ��");
			break;
		}
		key = _getch();				// ��ȡ�û�����
		player.direction = 0;	// ������ƶ�����
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
		move();			// ��������ƶ����򣬽��д���
	}
	_getch();
}

void init()//��ʼ��
{
	initgraph(450, 550);		// ��ʼ�����ڣ����ô��ڴ�С
	HWND window = GetHWnd();					// ��ȡ��ǰ����
	SetWindowText(window, "������");	// ���õ�ǰ���ڵı���
	outtextxy(5, 5, "ESC: �˳�");					// ������ʾ��Ϣ
	outtextxy(80, 5, "R: ���ñ���");
	outtextxy(5, 30, "W: ��   A����   S����   D����");
	fillrectangle(0, 100, 400, 500);			// ������Ϸ����
	loadimage(&img_player, "C:\\Users\\̷����\\Desktop\\visual studio\\pushboxes\\player.png", 45, 45);	// �������ͼƬ
	loadimage(&img_box, "C:\\Users\\̷����\\Desktop\\visual studio\\pushboxes\\box.png", 45, 45);		// �������ͼƬ
	reset();
}

void reset()//���õ�ͼ
{
	int i, j;
	player.boxs = 0;
	for (i = 0; i < length; i++)
	{
		for (j = 0; j < length; j++)
		{
			map[i][j] = boxMap[i][j];
			if (map[i][j] == BOX)//���������Ŀ
			{	
				player.boxs++;
			}
			if (map[i][j] == PLAYER)// ��¼���λ��
			{	
				player.x = j;
				player.y = i;
			}
		}
	}

}

void drawMap()//���Ƶ�ͼ
{
	int i, j;
	int uy, ux;
	uy = (downRighty - upLefty) / length;
	ux = (downRightx - upLeftx) / length;
	// ���Ƶ�ͼ
	for (i = 0; i < length; i++)
	{
		for (j = 0; j < length; j++)
		{
			switch (map[i][j])
			{
			case EMPTY:	// �յ�
				setfillcolor(CYAN);															// ѡ�������ɫ
				fillrectangle(upLeftx + j * ux, upLefty + i * uy, upLeftx + (j + 1) * ux, upLefty + (i + 1) * uy);		// �����Ӧ����
				break;
			case WALL:	// ǽǽ
				setfillcolor(DARKGRAY);
				fillrectangle(upLeftx + j * ux, upLefty + i * uy, upLeftx + (j + 1) * ux, upLefty + (i + 1) * uy);
				break;
			case PLAYER:	// ���
				putimage(upLeftx + j * ux, upLefty + i * uy, &img_player);
				break;
			case BOX:	// ����
				putimage(upLeftx + j * ux, upLefty + i * uy, &img_box);
				break;
			case DES:	// Ŀ���
				setfillcolor(GREEN);
				fillrectangle(upLeftx + j * ux, upLefty + i * uy, upLeftx + (j + 1) * ux, upLefty + (i + 1) * uy);
				break;
			case FINISH:	// ����վ��Ŀ�����
				putimage(upLeftx + j * ux, upLefty + i * uy, &img_box);
				break;
			case DESPLAYER:	// ���վ��Ŀ�����
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
	{	// �����ƶ��ķ��򣬼����ƶ�һ���λ�ã����ƶ������λ��
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
	{	// ����ƶ����x��y���곬����Χ������Ч
		return;
	}

	switch (map[uy][ux])
	{	// ������һ������ݣ�������Ӧ����
	case EMPTY:	// ��һ��Ϊ�յأ����ƶ����յ�
		map[uy][ux] = PLAYER;
		if (map[player.y][player.x] == DESPLAYER)
		{	// �����Ҹպ�վ��Ŀ����ϣ����ƶ���ĸ���ΪĿ���
			map[player.y][player.x] = DES;
		}
		else
		{	// ������վ�ڿյ��ϣ����ƶ���ĸ���Ϊ�յ�
			map[player.y][player.x] = EMPTY;
		}

		player.y = uy;
		player.x = ux;
		break;
	case WALL:	// ��һ��Ϊǽ������ң���ң��������ʺţ���������Ч�˳�
	case PLAYER:
		break;
	case FINISH:	// ��һ��Ϊվ��Ŀ����ϵ�����
	case BOX:	// ��һ��Ϊ���ӣ���������ӵ���һ�����ݣ�������ͬ����
		switch (map[nextY][nextX])
		{	// �������ӵ���һ�����ݣ�������Ӧ����
		case EMPTY:	// ���ӵ���һ��Ϊ�գ�����������Ӷ�ǰ��һ��
			map[nextY][nextX] = BOX;
			if (map[uy][ux] == FINISH)
			{	// ������Ӹպ�վ��Ŀ����ϣ����ƶ���ĸ���Ϊ��վ��Ŀ�����
				map[uy][ux] = DESPLAYER;
				player.boxs++;	// ������++  ��Ϊ�����뿪��Ŀ���
			}
			else
			{	// �������վ�ڿյ��ϣ����ƶ���ĸ������
				map[uy][ux] = PLAYER;
			}

			if (map[player.y][player.x] == DESPLAYER)
			{	// �����Ҹպ�վ��Ŀ����ϣ����ƶ���ĸ���ΪĿ���
				map[player.y][player.x] = DES;
			}
			else
			{	// ������վ�ڿյ��ϣ����ƶ���ĸ���Ϊ�յ�
				map[player.y][player.x] = EMPTY;
			}
			player.y = uy;
			player.x = ux;
			break;
		case WALL:	// ���ӵ���һ��Ϊǽ����ң���ң��ٴκ������ʺţ��������ӣ�����Ч�˳�
		case PLAYER:
		case BOX:
			break;
		case DES:	// ���ӵ���һ��ΪĿ��㣬nice����Һ����Ӷ�ǰ��һ�����һ��СĿ�꣬
			map[nextY][nextX] = FINISH;
			if (map[uy][ux] == FINISH)
			{	// ������Ӹպ�վ��Ŀ����ϣ����ƶ���ĸ���Ϊ��վ��Ŀ�����
				map[uy][ux] = DESPLAYER;
				player.boxs++;	// ������++  ��Ϊ�����뿪��Ŀ���
			}
			else
			{	// �������վ�ڿյ��ϣ����ƶ���ĸ������
				map[uy][ux] = PLAYER;
			}

			if (map[player.y][player.x] == DESPLAYER)
			{	// �����Ҹպ�վ��Ŀ����ϣ����ƶ���ĸ���ΪĿ���
				map[player.y][player.x] = DES;
			}
			else
			{	// ������վ�ڿյ��ϣ����ƶ���ĸ���Ϊ�յ�
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

	case DESPLAYER:	// �����Ŀ����غ�
		break;
	}
}