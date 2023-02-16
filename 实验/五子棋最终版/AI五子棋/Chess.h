#pragma once
#include <graphics.h>
#include <vector>
using namespace std;
struct ChessPos//棋盘位置 
{
	int row;//行
	int col;//列
	ChessPos(int r = 0,int c=0):row(r),col(c){}
};

typedef enum
{
	CHESS_WHITE = -1,//白棋 
	CHESS_BLACK = 1//黑棋 
}chess_kind_t;

class Chess
{
public:
	Chess(int getChessBoard_Size, int margin_x, int margin_y, float chessSize);
	void init();//棋盘初始化 
	bool clickBoard(int x, int y, ChessPos* pos);//判断点击是否有效 
	void chessDown(ChessPos* pos, chess_kind_t kind);//row-行 col-列 val-黑白棋 
	int getChessBoard_Size();//获取棋盘大小15*15
	int getChessData(ChessPos* pos);
	int getChessData(int row,int col);
	int mode;//单人模式或者双人模式
	bool checkOver();//检查棋局是否结束
private:
	IMAGE chessBlackImg;//黑棋
	IMAGE chessWhiteImg;//白棋
	IMAGE chessBoardImg;//棋盘
	IMAGE backgroundImg;//开始游戏背景
	IMAGE black_winImg;//黑方胜利
	IMAGE white_winImg;//白方胜利
	int chessboard_Size;//棋盘大小
	int margin_x;//棋盘左侧边界
	int margin_y;//棋盘顶部边界
	float chessSize;//棋子的大小
	vector<vector<int>> chessMap;//表示棋盘i行j列落子情况，0：空白，1：黑棋，-1：白棋
	bool playerFlag;//ture:该黑棋走,false:该白棋走
	void updateGameMap(ChessPos* pos);//黑白方交替进行下棋
	bool checkWin();//如果胜负已分，就返回true，否则返回假
	ChessPos lastPos;//最近落子的位置
};
