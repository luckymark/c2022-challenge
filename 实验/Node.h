#include"ChessBoard.h"
class Node
{
private:
	int num = 60;//每个节点的子节点个数（树的宽度）
	vector<vector<int>> scoreMap;
	vector<vector<int>> chessBoard;
	int min_x=7;
	int min_y=7;
	int max_x=7;
	int max_y=7;
	int bestRow = 0;
	int bestCol = 0;
	//每一点的权重
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
	//构造函数
	Node();
	//建立node与chessboard的联系
	void relate(ChessBoard* board);
	//局面估值
	int evaluate(bool black_white);
	//对每个点估值
	void calculateScore();

	//选取可能的落子点
	vector<ChessPos> think();
	//Alpha-beta+minimax
	int minimax(int depth, int alpha, int beta, bool black_white);
	int getBestRow();
	int getBestCol();
};