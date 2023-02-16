#include <iostream> 
#include"ChessGame.h"

int main()
{
	People_one people_one;
	People_two people_two;
	AI ai;
	Chess chess(15, 80, 80, 35);
	//getChessBoard_Size棋盘大小15（15*15的棋盘）
	//margin_x棋盘左边界80
	//margin_y棋盘上边界80
	//chessSize棋子的大小（正方形35*35像素大小）
	ChessGame game(&people_one, &people_two, &ai, &chess);

	game.play();
	return 0;
}