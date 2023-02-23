#include"chess.h"

void init()//������Ϸ���ڼ����ܡ�
{
	initgraph(700, 800);//������Ϸ���ڡ�
	setbkcolor(RGB(170, 243, 255));
	cleardevice();
	setlinecolor(RGB(0, 0, 0));
	for (int i = 20; i <= 660; i += 40) {
		line(i, 20, i, 660);
	}
	for (int i = 20; i <= 660; i += 40) {
		line(20, i, 660, i);
	}
	settextstyle(50, 30, "����");
	settextcolor(RGB(0, 0, 0));
	outtextxy(400, 700, TEXT("���¿�ʼ"));
	rectangle(400, 700, 650, 750);
	rectangle(240, 695, 375, 750);
	outtextxy(250, 700, TEXT("����"));
	//��ʼ�����̡�
	for (int i = 0; i <= gradeSize; ++i) {
		for (int j = 0; j <= gradeSize; ++j) {
			chessMap[i][j] = 0;
		}
	}
	//��ʼ���ߵĲ���
	for (int i = 0; i < 226; ++i) {
		chessPos[i].x = 0;
		chessPos[i].y = 0;
	}
	playerFlag = true;//��������
	stepNum = 0;
}

//�������ܣ�����Ƿ�Ϊ��Ч����������������
bool clickBoard(int x, int y, ChessPos* pos)
{
	int col = (x - margin_x) / chessSize;//��
	int row = (y - margin_y) / chessSize;//��
	//�����������λ����������Ϸ����λ��
	int leftTopPosX = margin_x + col * chessSize;
	int leftTopPosY = margin_y + row * chessSize;
	int offset = chessSize / 2;
	int len;
	bool ret = false;//bool�����ж��Ƿ�Ϊ��Ч�������Ч���˳�����
	do {
		if (x <= 35 || x >= 640 || y <= 35 || y >= 640) {
			break;
		}
		//���Ͻǵ��ж�
		len = sqrt((x - leftTopPosX) * (x - leftTopPosX) + (y - leftTopPosY) * (y - leftTopPosY));
		if (len <= offset) {
			pos->x = col;
			pos->y = row;
			if (chessMap[pos->y][pos->x] == 0) {
				ret = true;
			}
			break;
		}
		//���Ͻ��ж�
		int x2 = leftTopPosX + chessSize;
		int y2 = leftTopPosY;
		len = sqrt((x - x2) * (x - x2) + (y - y2) * (y - y2));
		if (len <= offset) {
			pos->x = col + 1;
			pos->y = row;
			if (chessMap[pos->y][pos->x] == 0) {
				ret = true;
			}
			break;
		}
		//���½��ж�
		int x3 = leftTopPosX;
		int y3 = leftTopPosY + chessSize;
		len = sqrt((x - x3) * (x - x3) + (y - y3) * (y - y3));
		if (len <= offset) {
			pos->x = col;
			pos->y = row + 1;
			if (chessMap[pos->y][pos->x] == 0) {
				ret = true;
			}
			break;
		}
		//���½��ж�
		int x4 = leftTopPosX + chessSize;
		int y4 = leftTopPosY + chessSize;
		len = sqrt((x - x4) * (x - x4) + (y - y4) * (y - y4));
		if (len <= offset) {
			pos->x = col + 1;
			pos->y = row + 1;
			if (chessMap[pos->y][pos->x] == 0) {
				ret = true;
			}
			break;
		}
	} while (0);
	return ret;
}

//�������ܣ�ʵ������
void chessDown(ChessPos* pos)
{
	int x = margin_x + chessSize * pos->x;
	int y = margin_y + chessSize * pos->y;

	if (playerFlag == true) {
		setfillcolor(BLACK);
	}
	else {
		setfillcolor(WHITE);
	}
	fillcircle(x, y, chessSize / 2);

	//����ͼ
	updateMap(pos);
}

//�������ܣ��������֮����������
bool checkOver()
{
	if (checkWin()) {
		settextstyle(50, 25, _T("����"));
		if (playType == true) {
			if (playerFlag == false) {
				outtextxy(20, 700, TEXT("����Ӯ��"));
			}
			else {
				outtextxy(20, 700, TEXT("����Ӯ��"));
			}
		}
		else {
			if (playerFlag == true) {
				outtextxy(50, 700, TEXT("������"));
			}
			else {
				outtextxy(50, 700, TEXT("��Ӯ��"));
			}
		}
		return true;
	}
	return false;
}

//�������ܣ��ж�����Ƿ����
bool checkWin()
{
	//ÿ��һ�����ж�һ�Σ���ֻ�迼�����һ��������˸������Ƿ�����������
	int x = chessPos[stepNum].x;
	int y = chessPos[stepNum].y;

	int chessNum = 1;

	if (chessMap[y][x] == 0) return false;

	//���ж�
	for (int i = 1; i <= 4; ++i) {
		if (x <= 0 || x >= 16 || y <= 0 || y >= 16) {
			break;
		}
		if (chessMap[y][x - i] == chessMap[y][x]) {
			chessNum++;
		}
		else break;
	}
	for (int i = 1; i <= 4; ++i) {
		if (x <= 0 || x >= 16 || y <= 0 || y >= 16) {
			break;
		}
		if (chessMap[y][x + i] == chessMap[y][x]) {
			chessNum++;
		}
		else break;
	}
	if (chessNum >= 5) {
		return true;
	}
	else chessNum = 1;

	//���ж�
	for (int i = 1; i <= 4; ++i) {
		if (x <= 0 || x >= 16 || y <= 0 || y >= 16) {
			break;
		}
		if (chessMap[y - i][x] == chessMap[y][x]) {
			chessNum++;
		}
		else break;
	}
	for (int i = 1; i <= 4; ++i) {
		if (x <= 0 || x >= 16 || y <= 0 || y >= 16) {
			break;
		}
		if (chessMap[y + i][x] == chessMap[y][x]) {
			chessNum++;
		}
		else break;
	}
	if (chessNum >= 5) {
		return true;
	}
	else chessNum = 1;

	//�Խ��ж�
	for (int i = 1; i <= 4; ++i) {
		if (x <= 0 || x >= 16 || y <= 0 || y >= 16) {
			break;
		}
		if (chessMap[y - i][x - i] == chessMap[y][x]) {
			chessNum++;
		}
		else break;
	}
	for (int i = 1; i <= 4; ++i) {
		if (x <= 0 || x >= 16 || y <= 0 || y >= 16) {
			break;
		}
		if (chessMap[y + i][x + i] == chessMap[y][x]) {
			chessNum++;
		}
		else break;
	}
	if (chessNum >= 5) {
		return true;
	}
	else {
		chessNum = 1;
	}
	for (int i = 1; i <= 4; ++i) {
		if (x <= 0 || x >= 16 || y <= 0 || y >= 16) {
			break;
		}
		if (chessMap[y + i][x - i] == chessMap[y][x]) {
			chessNum++;
		}
		else break;
	}
	for (int i = 1; i <= 4; ++i) {
		if (x <= 0 || x >= 16 || y <= 0 || y >= 16) {
			break;
		}
		if (chessMap[y - i][x + i] == chessMap[y][x]) {
			chessNum++;
		}
		else break;
	}
	if (chessNum >= 5) {
		return true;
	}
	else {
		chessNum = 1;
		return false;
	}
}

//�������ܣ��������¿�ʼ�µ���ֹ���
void dispose()
{
	MOUSEMSG msg;
	while (1) {
		msg = GetMouseMsg();
		if (msg.uMsg == WM_LBUTTONDOWN && msg.x >= 400 && msg.x <= 650 && msg.y >= 700 && msg.y <= 750) {
			gameStart();
			break;
		}
		else continue;
	}
}

//�������ܣ����幦��
void regretStep()
{
	//���̱�����˻�����
	chessMap[chessPos[stepNum].y][chessPos[stepNum].x] = 0;
	playerFlag = -playerFlag;

	//�����������ӵ�ɾ��
	deleteStep(&chessPos[stepNum]);
	stepNum--;

	//����˻���ս��ֱ��������
	if (playType == false && stepNum) {
		chessMap[chessPos[stepNum].y][chessPos[stepNum].x] = 0;
		playerFlag = -playerFlag;
		deleteStep(&chessPos[stepNum]);
		stepNum--;
	}
}

//�������ܣ��������幦�ܣ�ɾ�������ϵ����ӣ�
void deleteStep(ChessPos* pos)
{
	int x = margin_x + chessSize * pos->x;
	int y = margin_y + chessSize * pos->y;
	setfillcolor(RGB(170, 243, 255));
	solidrectangle(x - chessSize / 2, y - chessSize / 2, x + chessSize / 2, y + chessSize / 2);
	playerFlag = -playerFlag;
	line(x - chessSize / 2, y, x + chessSize / 2, y);
	line(x, y - chessSize / 2, x, y + chessSize / 2);
	return;
}

//�������ܣ���¼���Ӽ��������巽
void updateMap(ChessPos* pos)
{
	chessMap[pos->y][pos->x] = playerFlag ? 1 : -1;
	playerFlag = !playerFlag;//�������巽
	chessPos[++stepNum] = *pos;
}
