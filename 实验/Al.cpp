#include "Al.h"

void Al::init(Chess* chess, ChessBoard* board, Node* node)
{
    this->node = node;
    this->chess = chess;
    this->board = board;

}
//Al落子函数
void Al::go()
{
    ChessPos pos;
    node->relate(board);
    bool flag = true;//true表示棋盘为空
    for (int i = 0; i < chess->getBoardSize(); i++)
    {
        for (int j = 0; j < chess->getBoardSize(); j++)
        {
            if (board->getChessData(i, j) != 0)
            {
                flag = false;
                break;
            }
        }
        if (!flag)
        {
            break;
        }
    }
    if (flag)
    {
        pos.col = 7;
        pos.row = 7;
    }
    else
    {
        node->judgeRange(board->getLastPos().row, board->getLastPos().col);
        node->minimax(0, -99999999, 99999999, black_white);
        pos.row = node->getBestRow();
        pos.col = node->getBestCol();
    }
    board->updateGameMap(&pos, chess->getPlayerFlag());
    chess->chessDown(&pos, chess->getPlayerFlag());
}

void Al::setBlack_White(bool flag)
{
    black_white = flag;
}


