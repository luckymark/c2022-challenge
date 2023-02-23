#include"ai.h"

void goAI()
{
	ChessPos pos = think();
	if (playerFlag == true) chessDown(&pos);
	else return;
}

void calculateScore()
{
	for (int i = 0; i <= gradeSize; ++i)
		for (int j = 0; j <= gradeSize; ++j) {
			scoreMap[i][j] = 0;
		}
	attackScore();
	defenseScore();
}

ChessPos think()
{
	calculateScore();
	int maxScore = 1;
	for (int i = 0; i < 20; ++i) {
		maxPoint[i].x = 0;
		maxPoint[i].y = 0;
	}
	int tot = 0;
	for (int row = 1; row <= gradeSize; ++row) {
		for (int col = 1; col <= gradeSize; ++col) {
			if (chessMap[row][col] == 0) {
				if (scoreMap[row][col] > maxScore) {
					maxScore = scoreMap[row][col];
					maxPoint[tot].x = col;
					maxPoint[tot].y = row;
				}
				else if (scoreMap[row][col] == maxScore) {
					maxPoint[++tot].x = col;
					maxPoint[tot].y = row;
				}
			}
		}
	}
	for (int i = 0; i < 16; ++i) {
		for (int j = 0; j < 16; ++j) {
			printf("%d ", scoreMap[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	printf("%d\n", tot);
	printf("%d  %d\n", maxPoint[tot].y, maxPoint[tot].x);
	return maxPoint[tot];
}

void attackScore()
{
	for (int y = 1; y <= 15; ++y) {
		for (int x = 1; x <= 15; ++x) {
			AInum = 1, ManNum = 0, blankNum = 0;
			if (chessMap[y][x] != 0) continue;
			//≈–∂œ◊Û”“	
			for (int i = 1; i <= 4; ++i) {
				if (x - i < 1) {
					break;
				}
				if (chessMap[y][x - i] == 1) AInum++;
				else if (chessMap[y][x - i] == 0) {
					blankNum++;
					break;
				}
				else {
					ManNum++;
					break;
				}
			}
			for (int i = 1; i <= 4; ++i) {
				if (x + i > 15) {
					break;
				}
				if (chessMap[y][x + i] == 1) AInum++;
				else if (chessMap[y][x + i] == 0) {
					blankNum++;
					break;
				}
				else {
					ManNum++;
					break;
				}
			}
			if (ManNum == 0 || blankNum == 2) {
				if (AInum == 2) scoreMap[y][x] += 20;
				if (AInum == 3) scoreMap[y][x] += 120;
				if (AInum == 4) scoreMap[y][x] += 1020;
				if (AInum == 5) scoreMap[y][x] += 50000;
			}
			else if (ManNum == 1 || blankNum == 1) {
				if (AInum == 2) scoreMap[y][x] += 5;
				if (AInum == 3) scoreMap[y][x] += 20;
				if (AInum == 4) scoreMap[y][x] += 120;
				if (AInum == 5) scoreMap[y][x] += 50020;
			}
			else {
				if (AInum == 5) scoreMap[y][x] += 50020;
				else scoreMap[y][x] += 2;
			}
			//≈–∂œ…œœ¬
			AInum = 1, blankNum = 0, ManNum = 0;
			for (int i = 1; i <= 4; ++i) {
				if (y - i < 1) {
					break;
				}
				if (chessMap[y - i][x] == 1) AInum++;
				else if (chessMap[y - i][x] == 0) {
					blankNum++;
					break;
				}
				else {
					ManNum++;
					break;
				}
			}
			for (int i = 1; i <= 4; ++i) {
				if (y + i > 15) {
					break;
				}
				if (chessMap[y + i][x] == 1) AInum++;
				else if (chessMap[y + i][x] == 0) {
					blankNum++;
					break;
				}
				else {
					ManNum++;
					break;
				}
			}
			if (ManNum == 0 || blankNum == 2) {
				if (AInum == 2) scoreMap[y][x] += 20;
				if (AInum == 3) scoreMap[y][x] += 120;
				if (AInum == 4) scoreMap[y][x] += 1020;
				if (AInum == 5) scoreMap[y][x] += 50000;
			}
			else if (ManNum == 1 || blankNum == 1) {
				if (AInum == 2) scoreMap[y][x] += 5;
				if (AInum == 3) scoreMap[y][x] += 20;
				if (AInum == 4) scoreMap[y][x] += 120;
				if (AInum == 5) scoreMap[y][x] += 50000;
			}
			else {
				if (AInum == 5) scoreMap[y][x] += 50000;
			}
			//≈–∂œ◊Ûœ¬£¨”“…œ–±œﬂ
			AInum = 1, blankNum = 0, ManNum = 0;
			for (int i = 1; i <= 4; ++i) {
				if (y + i > 15 || x - i < 1) {
					break;
				}
				if (chessMap[y + i][x - i] == 1) AInum++;
				else if (chessMap[y + i][x - i] == 0) {
					blankNum++;
					break;
				}
				else {
					ManNum++;
					break;
				}
			}
			for (int i = 1; i <= 4; ++i) {
				if (y - i < 1 || x + i > 15) {
					break;
				}
				if (chessMap[y - i][x + i] == 1) AInum++;
				else if (chessMap[y - i][x + i] == 0) {
					blankNum++;
					break;
				}
				else {
					ManNum++;
					break;
				}
			}
			if (ManNum == 0 || blankNum == 2) {
				if (AInum == 2) scoreMap[y][x] += 20;
				if (AInum == 3) scoreMap[y][x] += 120;
				if (AInum == 4) scoreMap[y][x] += 1020;
				if (AInum == 5) scoreMap[y][x] += 50000;
			}
			else if (ManNum == 1 || blankNum == 1) {
				if (AInum == 2) scoreMap[y][x] += 5;
				if (AInum == 3) scoreMap[y][x] += 20;
				if (AInum == 4) scoreMap[y][x] += 120;
				if (AInum == 5) scoreMap[y][x] += 50000;
			}
			else {
				if (AInum == 5) scoreMap[y][x] += 50000;
			}
			//≈–∂œ◊Û…œ-”“œ¬–±œﬂ
			AInum = 1, blankNum = 0, ManNum = 0;
			for (int i = 1; i <= 4; ++i) {
				if (y - i < 1 || x - i < 1) {
					break;
				}
				if (chessMap[y - i][x - i] == 1) AInum++;
				else if (chessMap[y - i][x - i] == 0) {
					blankNum++;
					break;
				}
				else {
					ManNum++;
					break;
				}
			}
			for (int i = 1; i <= 4; ++i) {
				if (y + i > 15 || x + i > 15) {
					break;
				}
				if (chessMap[y + i][x + i] == 1) AInum++;
				else if (chessMap[y + i][x + i] == 0) {
					blankNum++;
					break;
				}
				else {
					ManNum++;
					break;
				}
			}
			if (ManNum == 0 || blankNum == 2) {
				if (AInum == 2) scoreMap[y][x] += 20;
				if (AInum == 3) scoreMap[y][x] += 120;
				if (AInum == 4) scoreMap[y][x] += 1020;
				if (AInum == 5) scoreMap[y][x] += 50000;
			}
			else if (ManNum == 1 || blankNum == 1) {
				if (AInum == 2) scoreMap[y][x] += 5;
				if (AInum == 3) scoreMap[y][x] += 20;
				if (AInum == 4) scoreMap[y][x] += 1020;
				if (AInum == 5) scoreMap[y][x] += 50000;
			}
			else {
				if (AInum == 5) scoreMap[y][x] += 50000;
			}
		}
	}
}

void defenseScore()
{
	for (int y = 1; y <= 15; ++y) {
		for (int x = 1; x <= 15; ++x) {
			if (chessMap[y][x] != 0) continue;
			//≈–∂œ◊Û”“
			AInum = 0, ManNum = 1, blankNum = 0;
			for (int i = 1; i <= 4; ++i) {
				if (x - i < 1) break;
				if (chessMap[y][x - i] == -1) ManNum++;
				else if (chessMap[y][x - i] == 1) {
					AInum++;
					break;
				}
				else {
					blankNum++;
					break;
				}
			}
			for (int i = 1; i <= 4; ++i) {
				if (x + i > 15) break;
				if (chessMap[y][x + i] == -1) ManNum++;
				else if (chessMap[y][x + i] == 1) {
					AInum++;
					break;
				}
				else {
					blankNum++;
					break;
				}
			}
			if (AInum == 0 || blankNum == 2) {
				if (ManNum == 2) scoreMap[y][x] += 10;
				if (ManNum == 3) scoreMap[y][x] += 100;
				if (ManNum == 4) scoreMap[y][x] += 1000;
				if (ManNum == 5) scoreMap[y][x] += 10000;
			}
			else if (AInum == 1 || blankNum == 1) {
				if (ManNum == 2) scoreMap[y][x] += 0;
				if (ManNum == 3) scoreMap[y][x] += 10;
				if (ManNum == 4) scoreMap[y][x] += 100;
				if (ManNum == 5) scoreMap[y][x] += 10000;
			}
			else {
				if (ManNum == 5) scoreMap[y][x] += 10000;
				else scoreMap[y][x] += 2;
			}
			//≈–∂œ…œœ¬
			AInum = 0, ManNum = 1, blankNum = 0;
			for (int i = 1; i <= 4; ++i) {
				if (y - i < 1) break;
				if (chessMap[y - i][x] == -1) ManNum++;
				else if (chessMap[y - i][x] == 1) {
					AInum++;
					break;
				}
				else {
					blankNum++;
					break;
				}
			}
			for (int i = 1; i <= 4; ++i) {
				if (y + i > 15) break;
				if (chessMap[y + i][x] == -1) ManNum++;
				else if (chessMap[y + i][x] == 1) {
					AInum++;
					break;
				}
				else {
					blankNum++;
					break;
				}
			}
			if (AInum == 0 || blankNum == 2) {
				if (ManNum == 2) scoreMap[y][x] += 10;
				if (ManNum == 3) scoreMap[y][x] += 100;
				if (ManNum == 4) scoreMap[y][x] += 1000;
				if (ManNum == 5) scoreMap[y][x] += 10000;
			}
			else if (AInum == 1 || blankNum == 1) {
				if (ManNum == 2) scoreMap[y][x] += 0;
				if (ManNum == 3) scoreMap[y][x] += 10;
				if (ManNum == 4) scoreMap[y][x] += 100;
				if (ManNum == 5) scoreMap[y][x] += 10000;
			}
			else {
				if (ManNum == 5) scoreMap[y][x] += 10000;
				else scoreMap[y][x] += 2;
			}
			//≈–∂œ◊Ûœ¬-”“…œ–±œﬂ
			AInum = 0, ManNum = 1, blankNum = 0;
			for (int i = 1; i <= 4; ++i) {
				if (x - i < 1 || y + i > 15) break;
				if (chessMap[y + i][x - i] == -1) ManNum++;
				else if (chessMap[y + i][x - i] == 1) {
					AInum++;
					break;
				}
				else {
					blankNum++;
					break;
				}
			}
			for (int i = 1; i <= 4; ++i) {
				if (x + i > 15 || y - i < 1) break;
				if (chessMap[y - i][x + i] == -1) ManNum++;
				else if (chessMap[y - i][x + i] == 1) {
					AInum++;
					break;
				}
				else {
					blankNum++;
					break;
				}
			}
			if (AInum == 0 || blankNum == 2) {
				if (ManNum == 2) scoreMap[y][x] += 10;
				if (ManNum == 3) scoreMap[y][x] += 10;
				if (ManNum == 4) scoreMap[y][x] += 1000;
				if (ManNum == 5) scoreMap[y][x] += 10000;
			}
			else if (AInum == 1 || blankNum == 1) {
				if (ManNum == 2) scoreMap[y][x] += 0;
				if (ManNum == 3) scoreMap[y][x] += 10;
				if (ManNum == 4) scoreMap[y][x] += 100;
				if (ManNum == 5) scoreMap[y][x] += 10000;
			}
			else {
				if (ManNum == 5) scoreMap[y][x] += 10000;
				else scoreMap[y][x] += 2;
			}
			//≈–∂œ◊Û…œ-”“œ¬–±œﬂ
			AInum = 0, ManNum = 1, blankNum = 0;
			for (int i = 1; i <= 4; ++i) {
				if (x - i < 1 || y - i < 1) break;
				if (chessMap[y - i][x - i] == -1) ManNum++;
				else if (chessMap[y - i][x - i] == 1) {
					AInum++;
					break;
				}
				else {
					blankNum++;
					break;
				}
			}
			for (int i = 1; i <= 4; ++i) {
				if (x + i > 15 || y + i > 15) break;
				if (chessMap[y + i][x + i] == -1) ManNum++;
				else if (chessMap[y + i][x + i] == 1) {
					AInum++;
					break;
				}
				else {
					blankNum++;
					break;
				}
			}
			if (AInum == 0 || blankNum == 2) {
				if (ManNum == 2) scoreMap[y][x] += 10;
				if (ManNum == 3) scoreMap[y][x] += 100;
				if (ManNum == 4) scoreMap[y][x] += 1000;
				if (ManNum == 5) scoreMap[y][x] += 10000;
			}
			else if (AInum == 1 || blankNum == 1) {
				if (ManNum == 2) scoreMap[y][x] += 0;
				if (ManNum == 3) scoreMap[y][x] += 10;
				if (ManNum == 4) scoreMap[y][x] += 100;
				if (ManNum == 5) scoreMap[y][x] += 10000;
			}
			else {
				if (ManNum == 5) scoreMap[y][x] += 10000;
			}
		}
	}
}