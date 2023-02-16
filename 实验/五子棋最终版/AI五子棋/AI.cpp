#include "AI.h"

void AI::init(Chess* chess)
{
	this->chess = chess;
	int size = chess->getChessBoard_Size();
	for (int i = 0; i < size; i++)
	{
		vector<int>row;
		for (int j = 0; j < size; j++)
		{
			row.push_back(0);
		}
		scoreMap.push_back(row);
	}
}
void AI::go()
{
	ChessPos pos = think();
	Sleep(800);//��װ˼��
	chess->chessDown(&pos, CHESS_WHITE);
}

void AI::calculateScore()
{
	int personNum = 0;//���ַ������壩�����ж��ٵ�����
	int aiNum = 0;//AI�������壩�����ж��ٸ�����������
	int emptyNum = 0;//�÷����Ͽհ�λ�ĸ���
	//����������������
	for (int i = 0; i < scoreMap.size(); i++)
	{
		for (int j = 0; j < scoreMap[i].size(); j++)
		{
			scoreMap[i][j] = 0;
		}
	}

	int size = chess->getChessBoard_Size();//��ȡ���̴�С��15*15��
	for (int row = 0; row < size; row++)
	{
		for (int col = 0; col < size; col++)
		{

			//��ÿ������м���
			if (chess->getChessData(row, col)!=NULL) continue;
			//y���ƴ�ֱ����x����ˮƽ����
			for (int y = -1; y <= 1; y++)//-1�����£�0����ǰλ�ã�1������
			{
				for (int x = -1; x <= 1; x++)//-1������0����ǰλ�ã�1������
				{
					if (y == 0 && x == 0) continue;//��ǰλ�ò��ж�
					personNum = 0;
					aiNum = 0;
					emptyNum = 0;

					//��������ڸ�λ�����ӣ��ṹ��ʲô����
					for (int i = 1; i <= 4; i++)
					{
						int curRow = row + i * y;
						int curCol = col + i * x;

						if (curRow >= 0 && curRow < size &&
							curCol >= 0 && curCol < size &&
							chess->getChessData(curRow, curCol) == 1)
						{
							personNum++;
						}
						else if (curRow >= 0 && curRow < size &&
							     curCol >= 0 && curCol < size &&
							     chess->getChessData(curRow, curCol) == 0)
						{
							emptyNum++;
							if (curRow + y >= 0 && curRow+y < size &&
								curCol + x >= 0 && curCol+x < size &&
								chess->getChessData(curRow + y, curCol + x) == 1 && personNum == 2)
							{
								scoreMap[curRow][curCol] += 160;
							}
							else if (curRow + y >= 0 && curRow + y < size &&
									 curCol + x >= 0 && curCol + x < size && 
									 chess->getChessData(curRow + y, curCol + x) == 1 && personNum == 3)
							{
								scoreMap[curRow][curCol] += 460;
							}
							break;
						}
						else
						{
							break;
						}
					}
					//�����������
					for (int i = 1; i <= 4; i++)
					{
						int curRow = row - i * y;
						int curCol = col - i * x;

						if (curRow >= 0 && curRow < size &&
							curCol >= 0 && curCol < size &&
							chess->getChessData(curRow, curCol) == 1)
						{
							personNum++;
						}
						else if (curRow >= 0 && curRow < size &&
							     curCol >= 0 && curCol < size &&
							     chess->getChessData(curRow, curCol) == 0)
						{
							emptyNum++;
							if (curRow - y >= 0 && curRow - y < size &&
								curCol - x >= 0 && curCol - x < size &&
								chess->getChessData(curRow - y, curCol - x) == 1 && personNum == 2)
							{
								scoreMap[curRow][curCol] += 160;
							}
							else if (curRow - y >= 0 && curRow - y < size &&
									 curCol - x >= 0 && curCol - x < size &&
									 chess->getChessData(curRow - y, curCol - x) == 1 && personNum == 3)
							{
								scoreMap[curRow][curCol] += 460;
							}
							break;
						}
						else
						{
							break;
						}
					}
					if (personNum == 1)//��2
					{
						scoreMap[row][col] += 100;
					}
					else if (personNum == 2)
					{
						if (emptyNum == 1)//����
						{
							scoreMap[row][col] += 300;
						}
						else if(emptyNum == 2)//����
						{
							scoreMap[row][col] += 400;
						}
					}
					else if (personNum == 3)
					{
						if (emptyNum == 1)//����
						{
							scoreMap[row][col] += 6000;
						}
						if (emptyNum == 2)//����
						{
							scoreMap[row][col] += 10000;
						}
					}
					else if (personNum == 4)//��������
					{
						scoreMap[row][col] += 100000;
					}
					//��������ڸ�λ�����ӣ��ṹ��ʲô����
					emptyNum = 0;
					for (int i = 1; i <= 4; i++)
					{
						int curRow = row + i * y;
						int curCol = col + i * x;

						if (curRow >= 0 && curRow < size &&
							curCol >= 0 && curCol < size &&
							chess->getChessData(curRow, curCol) == -1)
						{
							aiNum++;
						}
						else if (curRow >= 0 && curRow < size &&
							curCol >= 0 && curCol < size &&
							chess->getChessData(curRow, curCol) == 0)
						{
							emptyNum++;
							if (curRow - y >= 0 && curRow - y < size &&
								curCol - x >= 0 && curCol - x < size &&
								chess->getChessData(curRow - y, curCol - x) == -1 && emptyNum == 2)
							{
								scoreMap[curRow][curCol] += 250;
							}
							else if (curRow - y >= 0 && curRow - y < size &&
								curCol - x >= 0 && curCol - x < size &&
								chess->getChessData(curRow - y, curCol - x) == -1 && emptyNum == 3)
							{
								scoreMap[curRow][curCol] += 550;
							}
							break;
						}
						else
						{
							break;
						}
					}
					//����
					for (int i = 1; i <= 4; i++)
					{
						int curRow = row - i * y;
						int curCol = col - i * x;

						if (curRow >= 0 && curRow < size &&
							curCol >= 0 && curCol < size &&
							chess->getChessData(curRow, curCol) == -1)
						{
							aiNum++;
						}
						else if (curRow >= 0 && curRow < size &&
							curCol >= 0 && curCol < size &&
							chess->getChessData(curRow, curCol) == 0)
						{
							emptyNum++;
							if (curRow - y >= 0 && curRow - y < size &&
								curCol - x >= 0 && curCol - x < size &&
								chess->getChessData(curRow - y, curCol - x) == -1 && emptyNum == 2)
							{
								scoreMap[curRow][curCol] += 250;
							}
							else if (curRow - y >= 0 && curRow - y < size &&
								curCol - x >= 0 && curCol - x < size &&
								chess->getChessData(curRow - y, curCol - x) == -1 && emptyNum == 3)
							{
								scoreMap[curRow][curCol] += 550;
							}
							break;
						}
						else
						{
							break;
						}
					}
					if (aiNum == 1)//����
					{
						scoreMap[row][col] += 150;
					}
					else if (aiNum == 2)
					{
						if (emptyNum == 1)//����
						{
							scoreMap[row][col] += 350;
						}
						else if (emptyNum == 2)//����
						{
							scoreMap[row][col] += 450;
						}
					}
					else if (aiNum == 3)
					{
						if (emptyNum == 1)//����
						{
							scoreMap[row][col] += 6500;
						}
						else if (emptyNum == 2)//����
						{
							scoreMap[row][col] += 20000;
						}
					}
					else if (aiNum >= 4)//��������
					{
						scoreMap[row][col] += 200000;
					}
				}
			}
		}
	}
}

ChessPos AI::think()
{
	calculateScore();
	vector<ChessPos>maxPoints;
	int maxScore = 0;
	int size = chess->getChessBoard_Size();
	for (int row = 0; row < size; row++)
	{
		for (int col = 0; col < size; col++)
		{
			if (chess->getChessData(row, col) == 0)
			{
				if (scoreMap[row][col] > maxScore)
				{
					maxScore = scoreMap[row][col];
					maxPoints.clear();
					maxPoints.push_back(ChessPos(row, col));
				}
				else if (scoreMap[row][col] == maxScore)
				{
					maxPoints.push_back(ChessPos(row,col));

				}
			}
		}
	}
	int index = rand() % maxPoints.size();
	return maxPoints[index];
}
