//人机对战时的人类玩家
#include"wuziqi.h"
int PlayerMove(int color)
{
	int  f1 = 1;
	int row, col;
	TCHAR stepch[10];
	//玩家移动
	while (f1)
	{
		ExMessage msg = { 0 };
		if (peekmessage(&msg, EM_MOUSE)){//检测鼠标信息
			switch (msg.message){//筛选鼠标信息类型
			case WM_LBUTTONDOWN://左键信息
				if (board[(msg.y + 25) / 50 - 1][(msg.x + 25) / 50 - 1] == 0 && ((msg.y + 25) / 50 - 1 >= 0 && (msg.y + 25) / 50 - 1 <= 14) && ((msg.x + 25) / 50 - 1 >= 0 && (msg.x + 25) / 50 - 1 <= 14)) {
					f1 = 0;
					row = (msg.y + 25) / 50 - 1;//注意x y与row col的关系 y对应row x对应col
					col = (msg.x + 25) / 50 - 1;
					if (color == THEBLACK && fobidden(row, col) == 1) {
						f1 = 1;
					}
					else{
						set(row, col);
					}
					
				}
				else if (msg.x >= 950 && msg.x <= 1050 && msg.y >= 300 && msg.y <= 380) {
					Compete_Chess_Repentance();
					Compete_Chess_Repentance();
				}
				break;
			default:
				break;
			}
		}
	}
	return 0;
}