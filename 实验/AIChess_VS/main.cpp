#include "AIChess_VS.h"
using namespace std;

int main()
{
	chessboard();
	int step = 0;
	while (1)
	{
		Chess l1=AI();
		AI_put(l1);
		step++;
		if (check_win(Map[l1.x][l1.y]))
		{
			cout << "AI win" << endl;
			break;
		}
		if (step == 255)
		{
			cout << "棋盘已满" << endl;
			break;
		}
		while (1)
		{
			system("cls");
			cout << "输入X Y，回车下棋" << endl;
			cin >> inx >> iny;
			if (Map[inx][iny].color == 0)
				break;
		}
		Person_put(Map[inx][iny]);
		step++;
		if (check_win(Map[inx][iny]))
		{
			cout << "person win" << endl;
			break;
		}
	}
	system("pause");
	return 0;
}