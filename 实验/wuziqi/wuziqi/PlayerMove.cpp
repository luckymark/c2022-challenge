//�˻���սʱ���������
#include"wuziqi.h"
int PlayerMove(int color)
{
	int  f1 = 1;
	int row, col;
	TCHAR stepch[10];
	//����ƶ�
	while (f1)
	{
		ExMessage msg = { 0 };
		if (peekmessage(&msg, EM_MOUSE)){//��������Ϣ
			switch (msg.message){//ɸѡ�����Ϣ����
			case WM_LBUTTONDOWN://�����Ϣ
				if (board[(msg.y + 25) / 50 - 1][(msg.x + 25) / 50 - 1] == 0 && ((msg.y + 25) / 50 - 1 >= 0 && (msg.y + 25) / 50 - 1 <= 14) && ((msg.x + 25) / 50 - 1 >= 0 && (msg.x + 25) / 50 - 1 <= 14)) {
					f1 = 0;
					row = (msg.y + 25) / 50 - 1;//ע��x y��row col�Ĺ�ϵ y��Ӧrow x��Ӧcol
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