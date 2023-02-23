#pragma once
#include <graphics.h>
#include "ChessBoard.h"

class Chess
{
private:
	int boardSize;// 棋盘尺寸（15线）
	float margin_x;//水平边界距离;
	int margin_y;//垂直边界距离;
	float chessSize; //棋子大小（棋盘方格大小）
	int windowWidth = 1400;//窗口宽度
	int windowHigth = 700;//窗口高度

	IMAGE lostImg;
	IMAGE winImg;
	IMAGE chessBlackImg;
	IMAGE chessWhiteImg;

	//标示下棋方, true:黑棋方  false:白棋方
	bool playerFlag;

	//棋盘，用于存储棋局情况
	ChessBoard* board;
public:
	//构造函数
	Chess(int boardSize, int marginX, int marginY, float chessSize);

	//Chess的初始化，创建窗口
	//当棋局开始时会执行一次，且每一局只会执行一次
	bool init(ChessBoard* board);
	//加载棋盘的图片资源，初始化棋盘的相关数据
	void loadChessBoard();
	//判断玩家的先后手选择
	bool chooseHand();

	//判断在指定坐标(x,y)位置，是否是有效点击
	//如果是有效点击，把有效点击的位置(行，列）保存在参数pos中
	bool clickBoard(int x, int y, ChessPos* pos);
	//在棋盘的指定位置落子,true 黑 、false 白
	void chessDown(ChessPos* pos, bool payerFlag/*chess_kind_t kind*/);

	//悔棋函数
	void turnBack(bool black_white);
	//换手函数
	void changeHand(ChessPos* pos);
	// 判断棋局是否结束
	bool checkOver(bool flag);
	bool checkWin();
	bool heqi();

	//用于获取棋盘大小（15线）的接口
	int getBoardSize();
	//用于获取playerFlag的接口
	bool getPlayerFlag();
};
