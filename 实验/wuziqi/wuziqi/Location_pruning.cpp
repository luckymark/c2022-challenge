#include"wuziqi.h"

void Neighbor_Location(int row, int col,int t) {//t=1�ǲ��룻t=-1��ɾȥ
	for (int i = row - 2; i <= row + 2; i++) {
		for (int j = col - 2; j <= col + 2; j++) {
			if (i >= 0 && i <= 14 && j >= 0 && j <= 14 &&(i != row || j != col)) {
				if (t == -1) {
					vision[i][j]--;
				}
				else {
					vision[i][j]++;
				}
			}
		}
	}
}
