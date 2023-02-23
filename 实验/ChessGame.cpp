#include "ChessGame.h"

void ChessGame::play()
{
	while (1)
	{
		bool flag = chess->init(board);
		ai->setBlack_White(!flag);
		player->setBlack_White(flag);
		chess->loadChessBoard();
		switch (flag)
		{
			//�������
		case true:
			while (1)
			{
				if (player->go())
				{
					if (chess->checkOver(flag))
					{
						break;
					}
					ai->go();
					if (chess->checkOver(flag))
					{
						break;
					}
				}
				else
				{
					break;
				}
			}
			break;
			//��Һ���
		case false:
			while (1)
			{
				ai->go();
				if (chess->checkOver(flag))
				{
					break;
				}
				if (player->go())
				{
					if (chess->checkOver(flag))
					{
						break;
					}
				}
				else
				{
					break;
				}
			}
		}
	}

}
ChessGame::ChessGame(Player* player, Al* ai, Chess* chess, ChessBoard* board, Node* node)
{
	this->player = player;
	this->ai = ai;
	this->chess = chess;
	this->board = board;

	player->init(chess, board);
	ai->init(chess, board, node);
}


