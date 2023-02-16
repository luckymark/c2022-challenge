#pragma once
#include <graphics.h>
#include <vector>
using namespace std;
struct ChessPos//����λ�� 
{
	int row;//��
	int col;//��
	ChessPos(int r = 0,int c=0):row(r),col(c){}
};

typedef enum
{
	CHESS_WHITE = -1,//���� 
	CHESS_BLACK = 1//���� 
}chess_kind_t;

class Chess
{
public:
	Chess(int getChessBoard_Size, int margin_x, int margin_y, float chessSize);
	void init();//���̳�ʼ�� 
	bool clickBoard(int x, int y, ChessPos* pos);//�жϵ���Ƿ���Ч 
	void chessDown(ChessPos* pos, chess_kind_t kind);//row-�� col-�� val-�ڰ��� 
	int getChessBoard_Size();//��ȡ���̴�С15*15
	int getChessData(ChessPos* pos);
	int getChessData(int row,int col);
	int mode;//����ģʽ����˫��ģʽ
	bool checkOver();//�������Ƿ����
private:
	IMAGE chessBlackImg;//����
	IMAGE chessWhiteImg;//����
	IMAGE chessBoardImg;//����
	IMAGE backgroundImg;//��ʼ��Ϸ����
	IMAGE black_winImg;//�ڷ�ʤ��
	IMAGE white_winImg;//�׷�ʤ��
	int chessboard_Size;//���̴�С
	int margin_x;//�������߽�
	int margin_y;//���̶����߽�
	float chessSize;//���ӵĴ�С
	vector<vector<int>> chessMap;//��ʾ����i��j�����������0���հף�1�����壬-1������
	bool playerFlag;//ture:�ú�����,false:�ð�����
	void updateGameMap(ChessPos* pos);//�ڰ׷������������
	bool checkWin();//���ʤ���ѷ֣��ͷ���true�����򷵻ؼ�
	ChessPos lastPos;//������ӵ�λ��
};
