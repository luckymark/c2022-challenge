#include"ChessBoard.h"
class Node
{
private:
	int num = 60;//ÿ���ڵ���ӽڵ���������Ŀ�ȣ�
	vector<vector<int>> scoreMap;
	vector<vector<int>> chessBoard;
	int min_x=7;
	int min_y=7;
	int max_x=7;
	int max_y=7;
	int bestRow = 0;
	int bestCol = 0;
	//ÿһ���Ȩ��
	vector<vector<int>> p={{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
							{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
							{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
							{1,1,1,2,2,2,2,2,2,2,2,2,1,1,1}, 
							{1,1,1,2,2,2,2,2,2,2,2,2,1,1,1},
							{1,1,1,2,2,2,2,2,2,2,2,2,1,1,1},
							{1,1,1,2,2,2,3,3,3,2,2,2,1,1,1},
							{1,1,1,2,2,2,3,3,3,2,2,2,1,1,1}, 
							{1,1,1,2,2,2,3,3,3,2,2,2,1,1,1}, 
							{1,1,1,2,2,2,2,2,2,2,2,2,1,1,1},
							{1,1,1,2,2,2,2,2,2,2,2,2,1,1,1},
							{1,1,1,2,2,2,2,2,2,2,2,2,1,1,1},
							{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
							{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
							{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}};
public:
	void down(int row, int col, bool type);//false white
	void judgeRange(int i, int j);
	void revokeChess(int row, int col);
	//���캯��
	Node();
	//����node��chessboard����ϵ
	void relate(ChessBoard* board);
	//�����ֵ
	int evaluate(bool black_white);
	//��ÿ�����ֵ
	void calculateScore();

	//ѡȡ���ܵ����ӵ�
	vector<ChessPos> think();
	//Alpha-beta+minimax
	int minimax(int depth, int alpha, int beta, bool black_white);
	int getBestRow();
	int getBestCol();
};