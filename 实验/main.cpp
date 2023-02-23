#pragma GCC optimize(3,"Ofast","inline")
#include "ChessGame.h"

int main()
{

	ChessBoard board(15);
	Node node;
	Chess chess(15, 290, 64, 41);
	Player player;
	Al ai;
	ChessGame game(&player, &ai, &chess, &board, &node);
	game.play();
	return 0;
}