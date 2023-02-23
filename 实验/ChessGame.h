#pragma once
#include "Player.h"
#include "Al.h"
#include "Chess.h"
#include "ChessBoard.h"


class ChessGame
{
private:
	Player* player;
	Al* ai;
	Chess* chess;
	ChessBoard* board;
public:
	ChessGame(Player*, Al*, Chess*, ChessBoard*, Node*);
	void play();
};


