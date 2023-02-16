//玩家对下
#include"wuziqi.h"
int Move(void){
	int row, col;
	TCHAR stepch[10];
	while (true){
		ExMessage msg = { 0 };
		if (peekmessage(&msg, EM_MOUSE)){//检测鼠标信息
			switch (msg.message){//筛选鼠标信息类型
			case WM_LBUTTONDOWN://左键信息 落黑子
				if ( board[(msg.y + 25) / 50 - 1][(msg.x + 25) / 50 - 1] == 0 && ((msg.y + 25) / 50 - 1 >= 0 && (msg.y + 25) / 50 - 1 <= 14) && ((msg.x + 25) / 50 - 1 >= 0 && (msg.x + 25) / 50 - 1 <= 14)) {
					//注意x y与row col的关系 y对应row x对应col 
					row = (msg.y + 25) / 50 - 1;
					col = (msg.x + 25) / 50 - 1;
					if (step % 2==0 && fobidden(row, col) == 1) {
						break;
					}
					else {
						set(row, col);
					}
				}
				else if (msg.x >= 950 && msg.x <= 1050 && msg.y >= 300 && msg.y <= 380) {
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

