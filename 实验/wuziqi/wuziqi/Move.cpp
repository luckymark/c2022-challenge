//��Ҷ���
#include"wuziqi.h"
int Move(void){
	int row, col;
	TCHAR stepch[10];
	while (true){
		ExMessage msg = { 0 };
		if (peekmessage(&msg, EM_MOUSE)){//��������Ϣ
			switch (msg.message){//ɸѡ�����Ϣ����
			case WM_LBUTTONDOWN://�����Ϣ �����
				if ( board[(msg.y + 25) / 50 - 1][(msg.x + 25) / 50 - 1] == 0 && ((msg.y + 25) / 50 - 1 >= 0 && (msg.y + 25) / 50 - 1 <= 14) && ((msg.x + 25) / 50 - 1 >= 0 && (msg.x + 25) / 50 - 1 <= 14)) {
					//ע��x y��row col�Ĺ�ϵ y��Ӧrow x��Ӧcol 
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

