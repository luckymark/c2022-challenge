#include <iostream> 
#include"ChessGame.h"

int main()
{
	People_one people_one;
	People_two people_two;
	AI ai;
	Chess chess(15, 80, 80, 35);
	//getChessBoard_Size���̴�С15��15*15�����̣�
	//margin_x������߽�80
	//margin_y�����ϱ߽�80
	//chessSize���ӵĴ�С��������35*35���ش�С��
	ChessGame game(&people_one, &people_two, &ai, &chess);

	game.play();
	return 0;
}