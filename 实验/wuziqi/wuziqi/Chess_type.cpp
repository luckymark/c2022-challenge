#include"wuziqi.h"
int Chess_type(int row,int col,int direction) {//ֻʵ�������жϵĹ���
	int num = 1;//���ڼ�¼������������
	int empty = 0;//���ڼ�¼�ո���
	int x, y;//��¼����
	int remote[2] = { 0 };//ʵ�ֿո������ж�
	
	if (direction == 1) {
		// ����1 �зּ�
		x = row; y = col;
		while (true) {//����
			if (x == 0) {
				break;
			}
			if (board[x - 1][y] == board[x][y]) {
				num++;
				x--;
			}
			else if (board[x - 1][y] == 0) {
				empty++;
				remote[0] = Opposite_shore(x - 2, y, 1, board[row][col]);
				break;
			}
			else {
				break;
			}
		}
		x = row; y = col;
		while (true) {//����
			if (x == 14) {
				break;
			}

			if (board[x + 1][y] == board[x][y]){
				num++;
				x++;
			}
			else if (board[x + 1][y] == 0){
				empty++;
				remote[1] = Opposite_shore(x + 2, y, 2, board[row][col]);
				break;
			}
			else{
				break;
			}
		}
	}
	else if (direction == 2) {
		//�зּ�
		x = row; y = col;
		while (true) {//����
			if (y == 0) {
				break;
			}

			if (board[x][y - 1] == board[x][y]) {
				num++;
				y--;
			}
			else if (board[x][y - 1] == 0) {
				empty++;
				remote[0] = Opposite_shore(x, y - 2, 3, board[row][col]);
				break;
			}
			else{
				break;
			}
		}
		x = row; y = col;
		while (true) {//����
			if (y == 14) {
				break;
			}

			if (board[x][y + 1] == board[x][y]) {
				num++;
				y++;
			}
			else if (board[x][y + 1] == 0) {
				empty++;
				remote[1] = Opposite_shore(x, y + 2, 4, board[row][col]);
				break;
			}
			else{
				break;
			}
		}
	}
	else if (direction == 3) {
		//��б�߷ּ�
		x = row; y = col;
		while (true) {//����
			if (x == 0 || y == 0) {
				break;
			}

			if (board[x - 1][y - 1] == board[x][y]) {
				num++;
				x--;
				y--;
			}
			else if (board[x - 1][y - 1] == 0) {
				empty++;
				remote[0] = Opposite_shore(x - 2, y - 2, 5, board[row][col]);
				break;
			}
			else{
				break;
			}
		}

		x = row; y = col;
		while (true) {//����
			if (x == 14 || y == 14) {
				break;
			}

			if (board[x + 1][y + 1] == board[x][y]) {
				num++;
				x++;
				y++;
			}
			else if (board[x + 1][y + 1] == 0) {
				empty++;
				remote[1] = Opposite_shore(x + 2, y + 2, 6, board[row][col]);
				break;
			}
			else{
				break;
			}
		}
	}
	else if (direction == 4) {
		//��б�߷ּ�
		x = row; y = col;
		while (true) {//����
			if (x == 0 || y == 14) {
				break;
			}

			if (board[x - 1][y + 1] == board[x][y]) {
				num++;
				x--;
				y++;
			}
			else if (board[x - 1][y + 1] == 0) {
				empty++;
				remote[0] = Opposite_shore(x - 2, y + 2, 7, board[row][col]);
				break;
			}
			else {
				break;
			}
		}

		x = row; y = col;
		while (true) {//����
			if (x == 14 || y == 0) {
				break;
			}

			if (board[x + 1][y - 1] == board[x][y]) {
				num++;
				x++;
				y--;
			}
			else if (board[x + 1][y - 1] == 0) {
				empty++;
				remote[1] = Opposite_shore(x + 2, y - 2, 8, board[row][col]);
				break;
			}
			else {
				break;
			}
		}

	}
	//���� //remote������ÿ��λ���� 1��ʾͬɫ���� 2��ʾ�ո� 0��ʾ��ɫ����
	if (empty == 0 && num == 1) {//��һ
		return 1;
	}
	if (num == 1 && empty == 1 && (remote[0] == 222 || remote[1] == 222)) {
		return 2;
	}//��һ
	if (num == 1 && empty == 2 && (remote[0] / 10 == 22 || remote[1] / 10 == 22)) {
		return 3;
	}//��һ	

	if (empty == 0 && num == 2) {
		return 4;
	}//����
	if (empty == 1 && num == 2 && (remote[0] == 0 || remote[1] == 0)) {
		return 4;
	}//һ���������� �� �� �� �� ��
	if (empty == 1 && num == 2 && (remote[0] == 20 || remote[1] == 20)) {
		return 4;
	}//������������ �� �� �� �� �� ��
	if (empty == 1 && num == 2 && (remote[0] / 10 == 22 || remote[1] / 10 == 22)) {
		return 5;
	}//�߶� �� �� �� �� �� �� ��ͼ������
	if (empty == 1 && num == 1 && (remote[0] == 122 || remote[1] == 122)) {
		return 5;
	}//һ���߶����� �� �� �� �� �� �� ��ͼ����
	if (empty == 2 && num == 1 && ((remote[0] / 10 == 10 && remote[1] / 100 == 2) || (remote[1] / 10 == 10 && remote[0] / 100 == 2))) {
		return 5;
	}//һ���߶����� �� �� �� �� �� �� ��ͼ����
	if (empty == 1 && num == 1 && ((remote[0] / 100 == 0 && remote[1] / 10 == 212) || (remote[0] / 10 == 10 && remote[1] / 10 == 22))) {
		return 5;
	}//�����߶����� �� �� �� �� �� ��  ��ͼ����
	if (empty == 2 && num == 1 && (remote[0] == 210 || remote[1] == 210)) {
		return 5;
	}//�����߶����� �� �� �� �� �� ��  ��ͼ����
	if (empty != 0 && num == 1 && (remote[0] == 221 || remote[1] == 221)) {
		return 5;
	}//�����߶�����  �� �� �� �� ��   ��ͼ�����ӽԿ�

	if (empty == 2 && num == 2 && (remote[0] / 100 == 2 && remote[1] / 100 == 2)) {
		return 6;
	}//��� �� �� �� �� �� �� ������
	if (empty == 2 && num == 1 && (remote[0] / 10 == 12 && remote[1] / 10 == 12)) {
		return 6;
	}//һ�ͻ������ �� �� �� �� �� ������
	if (empty == 2 && num == 1 && (remote[0] == 212 || remote[1] == 212)) {
		return 6;
	}//���ͻ������ �� �� ��  �� �� �� ������
	
	if (empty == 0 && num == 3 ) {
		return 7;
	}//����
	if (empty == 1 && num == 3 && (remote[0] == 0 || remote[1] == 0)) {
		return 7;
	}//һ����������

	if (empty == 1 && num == 3 && (remote[0] / 100 == 2 || remote[1] / 100 == 2)) {
		return 8;
	}//���� �� �� �� �� �� �� ��ͼ������
	if (empty == 1 && num == 2 && (remote[0] / 10 == 12 || remote[1] / 10== 12)) {
		return 8;
	}//һ���������� �� �� �� �� �� �� ��ͼ������
	if (empty == 2 && num == 1 && (remote[0] == 110 || remote[1] == 110)) {
		return 8;
	}//һ���������� �� �� �� �� �� �� ��ͼ����
	if (empty == 1 && num == 1 && (remote[0] == 110 || remote[1] == 110)) {
		return 8;
	}//������������ �� �� �� �� �� �� ��ͼ����
	if (empty == 2 && num == 2 && (remote[0] / 10 == 10 || remote[1] / 10== 10)) {
		return 8;
	}//������������ �� �� �� �� �� �� ��ͼ������
	if (empty != 0 && num == 2 && (remote[0] / 10 == 21 || remote[1] / 10== 21)) {
		return 8;
	}//������������ �� �� �� �� �� ��ͼ������
	if (empty != 0 && num == 2 && (remote[0] == 211 || remote[1] == 211)) {
		return 8;
	}//������������ �� �� �� �� �� ��ͼ����
	if (empty != 0 && num == 1 && (remote[0] == 121 || remote[1] == 121)) {
		return 8;
	}//������������ �� �� �� �� �� ��ͼ������
	if (empty == 2 && num == 1 && (remote[0] / 100 == 1 || remote[1] / 100== 1)) {
		return 8;
	}//������������ �� �� �� �� �� ��ͼ����
	if (empty == 2 && num == 3 && (remote[0] / 100 == 0 || remote[1] / 100 == 0)) {
		return 8;
	}//������������  �� �� �� �� �� ��  ��ͼ����
	if (empty == 1 && num == 3 && (remote[0] / 10 == 20 || remote[1] / 10== 20)) {
		return 8;
	}//������������  �� �� �� �� �� �� ����ͼ����

	if (empty == 2 && num == 3) {
		return 9;
	}//����
	if (empty == 2 && num == 2 && (remote[0]/10 == 12 || remote[1]/10 == 12)) {
		return 9;
	}//һ��Ƕ�ģ�������˫�Ӵ� �� �� �� �� �� ��
	if (empty == 2 && num == 1 && (remote[0] == 112 || remote[1] == 112)) {
		return 9;
	}//һ��Ƕ�ģ����������Ӵ� 

	if (empty == 0 && num == 4) {
		return 10;
	}//����

	if (empty == 1 &&num == 4 ) {
		return 11;
	}//����
	if (empty != 0 && num == 3 && (remote[0] / 100 == 1 || remote[1] / 100 == 1)) {
		return 11;
	}//һ�ͳ��ı���  �� �� �� �� �� ���Ӵ�
	if (empty != 0 && num == 1 && (remote[0] == 111 || remote[1] == 111)) {
		return 11;
	}//һ�ͳ��ı��� �� �� �� �� �� һ�Ӵ�
	if (empty != 0 && num == 2 && (remote[0]/ 10 == 11 || remote[1] / 10 == 11)) {
		return 11;
	}//���ͳ��ı��� �� ��  �� �� �� ���Ҷ��Ӵ�

	if (empty == 2 && num == 4) {
		return 12;
	}//����
	
	if (num == 5) {
		return 13;
	}//����

	//������ʤ����
	if (empty == 2 && num == 2 && remote[0] / 10 == 11 && remote[1] / 10 == 11) {
		return 13;//�� �� �� �� �� �� �� �� ��
	}
	if (empty == 2 && num == 3 && remote[0] / 100 == 1 && remote[1] / 100 == 1) {
		return 13;//�� �� �� �� �� �� ��  ��
	}
	if (num > 5) {
		return 14;//����
	}
	return 1;
}