#include"wuziqi.h"

//Ϊ��ʵ�����͵��ж� �����м��һ���ĳ��� ����֮�������
//������һ���������ҵ���λ��֮����ֹͣ�������ǽ�һ����ǰ��
//�������������2��
int Opposite_shore(int row,int col,int direction,int color) {
	int go = 0;//�ո����Ĳ���
	int num = 0;//��¼�ո�������� 
	const int Maxgo=3;
	//��1��ʾͬɫ���� 2��ʾ�� 0��ʾ��ɫ���ӻ��������̱�
	switch (direction) {
	case 1://����
		while (row >= 0  && go < Maxgo) {
			if (board[row][col] == color) {
				num = num * 10 + 1;
				row--;
			}
			else if (board[row][col] == 0) {
				num = num * 10 + 2;
				row--;
			}
			else {
				break;
			}
			go++;
		}
		break;
	case 2://����
		while (row <=14 && go < Maxgo) {
			if (board[row][col] == color) {
				num = num * 10 + 1;
				row++;
			}
			else if (board[row][col] == 0) {
				num = num * 10 + 2;
				row++;
			}
			else {
				break;
			}
			go++;
		}
		break;
	case 3://����
		while (col >= 0 && go < Maxgo) {
			if (board[row][col] == color) {
				num = num * 10 + 1;
				col--;
			}
			else if (board[row][col] == 0) {
				num = num * 10 + 2;
				col--;
			}
			else {
				break;
			}
			go++;
		}
		break;
	case 4://����
		while (col <=14 && go < Maxgo) {
			if (board[row][col] == color) {
				num = num * 10 + 1;
				col++;
			}
			else if (board[row][col] == 0) {
				num = num * 10 + 2;
				col++;
			}
			else {
				break;
			}
			go++;
		}
		break;
	case 5://����
		while (row >= 0 && col >= 0 && go < Maxgo) {
			if (board[row][col] == color) {
				num = num * 10 + 1;
				row--;
				col--;
			}
			else if (board[row][col] == 0) {
				num = num * 10 + 2;
				row--;
				col--;
			}
			else {
				break;
			}
			go++;
		}
		break;
	case 6://����
		while (row <= 14 && col <= 14 && go < Maxgo) {
			if (board[row][col] == color) {
				num = num * 10 + 1;
				row++;
				col++;
			}
			else if (board[row][col] == 0) {
				num = num * 10 + 2;
				row++;
				col++;
			}
			else {
				break;
			}
			go++;
		}
		break;
	case 7://����
		while (row >= 0 && col <= 14 && go < Maxgo) {
			if (board[row][col] == color) {
				num = num * 10 + 1;
				row--;
				col++;
			}
			else if (board[row][col] == 0) {
				num = num * 10 + 2;
				row--;
				col++;
			}
			else {
				break;
			}
			go++;
		}
		break;
	case 8://����
		while (row <= 14 && col >= 0 && go < Maxgo) {
			if (board[row][col] == color) {
				num = num * 10 + 1;
				row++;
				col--;
			}
			else if (board[row][col] == 0) {
				num = num * 10 + 2;
				row++;
				col--;
			}
			else {
				break;
			}
			go++;
		}
		break;
	}
	if (num < 100 && num > 0) {
		num = num * 10;
	}
	return num;
}