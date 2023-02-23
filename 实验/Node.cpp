#include "Node.h"

void Node::down(int row, int col, bool type)
{
    if (type)
    {
        chessBoard[row][col] = 1;
    }
    else
    {
        chessBoard[row][col] = -1;
    }
    judgeRange(row, col);
}

void Node::judgeRange(int i, int j)
{
    if (i < min_x)
    {
        min_x = i;
    }
    if (i > max_x)
    {
        max_x = i;
    }
    if (j < min_y)
    {
        min_y = j;
    }
    if (j > max_y)
    {
        max_y = j;
    }
}

void Node::revokeChess(int row, int col)
{
    chessBoard[row][col] = 0;
}

Node::Node()
{
    //��ʼ���������ֵ�Ķ�ά����
    for (int i = 0; i < 15; i++)
    {
        vector<int> row;
        for (int j = 0; j < 15; j++)
        {
            row.push_back(0);
        }
        chessBoard.push_back(row);
        scoreMap.push_back(row);
    }
}
void Node::relate(ChessBoard* board)
{
    for (int i = 0; i < 15; i++)
    {
        for (int j = 0; j < 15; j++)
        {
            chessBoard[i][j] = board->getChessData(i, j);
        }
    }
}

//�������ķ���ֵ
int Node::evaluate(bool black_white)
{
    //�������� �� �� ���Խ��� ���Խ���
    int dx[4] = { 0,-1,-1,1 };
    int dy[4] = { -1,0,-1,-1 };

    int value = 0;
    int size = 15;

    int blackChess = 0;
    int whiteChess = 0;
    int emptyChess = 0;

    int row = 0;
    int col = 0;

    switch (black_white)
    {
    case false:
        for (int k = 0; k < 4; k++)
        {
            for (int i = min_x; i <= max_x; i++)
            {
                for (int j = min_y; j <= max_y; j++)
                {
                    if (chessBoard[i][j] == 0)
                    {
                        continue;
                    }
                    int blackChess = 0;
                    int whiteChess = 0;
                    int emptyChess = 0;

                    for (int u = -2; u <= 2; u++)
                    {

                        row = i + dx[k] * u;
                        col = j + dy[k] * u;
                        if (row < 0 || row > 14 || col < 0 || col > 14)
                        {
                            break;
                        }
                        switch (chessBoard[row][col])
                        {
                        case 1:
                            blackChess++;
                            break;
                        case -1:
                            whiteChess++;
                            break;
                        case 0:
                            emptyChess++;
                            break;
                        }
                    }
                    if (k == 0 && emptyChess == 5)
                    {
                        j++;
                        continue;
                    }
                    if (blackChess > 0 && whiteChess > 0)
                    {
                        continue;
                    }
                    else
                    {
                        switch (blackChess)
                        {
                        case 1:
                            value -= 55;
                            break;
                        case 2:
                            value -= 900;
                            break;
                        case 3:
                            value -= 9000;
                            break;
                        case 4:
                            value -= 90000;
                            break;
                        case 5:
                            value -= 9000000;
                            break;
                        }
                        switch (whiteChess)
                        {
                        case 1:
                            value += 50;
                            break;
                        case 2:
                            value += 800;
                            break;
                        case 3:
                            value += 8000;
                            break;
                        case 4:
                            value += 90000;
                            break;
                        case 5:
                            value += 9000000;
                            break;
                        }
                    }
                }
            }
        }
        break;
    case true:
        for (int k = 0; k < 4; k++)
        {
            for (int i = 3; i < 12; i++)
            {
                for (int j = 3; j < 12; j++)
                {
                    if (chessBoard[i][j] == 0)
                    {
                        continue;
                    }
                    int blackChess = 0;
                    int whiteChess = 0;
                    int emptyChess = 0;

                    for (int u = -2; u <= 2; u++)
                    {
                        row = i + dx[k] * u;
                        col = j + dy[k] * u;
                        if (row < 0 || row > 15 || col < 0 || col > 15)
                        {
                            break;
                        }
                        switch (chessBoard[row][col])
                        {
                        case 1:
                            blackChess += 1;
                            break;
                        case -1:
                            whiteChess += 1;
                            break;
                        case 0:
                            emptyChess += 1;
                            break;
                        }
                    }
                    if (blackChess > 0 && whiteChess > 0)
                    {
                        continue;
                    }
                    else
                    {
                        switch (blackChess)
                        {
                        case 1:
                            value += 55;
                            break;
                        case 2:
                            value += 900;
                            break;
                        case 3:
                            value += 9000;
                            break;
                        case 4:
                            value += 90000;
                            break;
                        case 5:
                            value += 9000000;
                            break;
                        }
                        switch (whiteChess)
                        {
                        case 1:
                            value -= 50;
                            break;
                        case 2:
                            value -= 800;
                            break;
                        case 3:
                            value -= 8000;
                            break;
                        case 4:
                            value -= 90000;
                            break;
                        case 5:
                            value -= 9000000;
                            break;
                        }
                    }
                }
            }
        }
        break;
    }
    return value;
}

//����ÿһ��ķ���ֵ
void Node::calculateScore()
{
    //�������� �� �� ���Խ��� ���Խ���
    int dx[4] = { 0,-1,-1,1 };
    int dy[4] = { -1,0,-1,-1 };

    int blackNum = 0; //�����ж��ٸ�����������
    int whiteNum = 0; //�����ж��ٸ�����������
    int emptyNum = 0; //�÷����Ͽհ�λ�ĸ���

    int size = 15;

    // ����������������
    for (int i = 0; i < scoreMap.size(); i++)
    {
        for (int j = 0; j < scoreMap[i].size(); j++)
        {
            scoreMap[i][j] = 0;
        }
    }
    for (int row = 0; row < size; row++)
    {
        for (int col = 0; col < size; col++)
        {
            //��ֵ�㷨֮�󻹿����Ż�
            //��ÿ������м���
            if (this->chessBoard[row][col])
            {
                continue;
            }
            for (int u = 0; u < 4; u++)
            {
                blackNum = 0;
                whiteNum = 0;
                emptyNum = 0;

                // ��������ڸ�λ�����ӣ��ṹ��ʲô����
                for (int i = 1; i <= 4; i++)
                {
                    int curRow = row + i * dx[u];
                    int curCol = col + i * dy[u];

                    if (curRow >= 0 && curRow < size && curCol >= 0 && curCol < size && chessBoard[curRow][curCol] == 1)
                    {
                        blackNum++;
                    }
                    else if (curRow >= 0 && curRow < size && curCol >= 0 && curCol < size && chessBoard[curRow][curCol] == 0)
                    {
                        emptyNum++;
                        break;
                    }
                    else
                    {
                        break;
                    }
                }
                // �����������
                for (int i = 1; i <= 4; i++)
                {
                    int curRow = row - i * dx[u];
                    int curCol = col - i * dy[u];

                    if (curRow >= 0 && curRow < size && curCol >= 0 && curCol < size && chessBoard[curRow][curCol] == 1)
                    {
                        blackNum++;
                    }
                    else if (curRow >= 0 && curRow < size && curCol >= 0 && curCol < size && chessBoard[curRow][curCol] == 0)
                    {
                        emptyNum++;
                        break;
                    }
                    else
                    {
                        break;
                    }
                }
                if (blackNum == 0)
                {
                    scoreMap[row][col] += 1*p[row][col];
                }
                else if (blackNum == 1)
                {
                    //��2
                    scoreMap[row][col] += 10 * p[row][col];
                }
                else if (blackNum == 2)
                {
                    if (emptyNum == 1)
                    {
                        //����
                        scoreMap[row][col] += 100 * p[row][col];
                    }
                    else if (emptyNum == 2)
                    {
                        //����
                        scoreMap[row][col] += 1000 * p[row][col];
                    }
                }
                else if (blackNum == 3)
                {
                    if (emptyNum == 1)
                    {
                        //����
                        scoreMap[row][col] += 1000 * p[row][col];
                    }
                    else if (emptyNum == 2)
                    {
                        //����
                        scoreMap[row][col] += 10000 * p[row][col];
                    }
                }
                else if (blackNum == 4)
                {
                    //����
                    scoreMap[row][col] += 100000 * p[row][col];
                }

                // ��������ڸ�λ�����ӣ��ṹ��ʲô����
                emptyNum = 0;
                for (int i = 1; i <= 4; i++)
                {
                    int curRow = row + i * dx[u];
                    int curCol = col + i * dy[u];

                    if (curRow >= 0 && curRow < size && curCol >= 0 && curCol < size && chessBoard[curRow][curCol] == -1)
                    {
                        whiteNum++;
                    }
                    else if (curRow >= 0 && curRow < size && curCol >= 0 && curCol < size && chessBoard[curRow][curCol] == 0)
                    {
                        emptyNum++;
                        break;
                    }
                    else
                    {
                        break;
                    }
                }
                for (int i = 1; i <= 4; i++)
                {
                    int curRow = row - i * dx[u];
                    int curCol = col - i * dy[u];

                    if (curRow >= 0 && curRow < size && curCol >= 0 && curCol < size && chessBoard[curRow][curCol] == -1)
                    {
                        whiteNum++;
                    }
                    else if (curRow >= 0 && curRow < size && curCol >= 0 && curCol < size && chessBoard[curRow][curCol] == 0)
                    {
                        emptyNum++;
                        break;
                    }
                    else
                    {
                        break;
                    }
                }
                if (whiteNum == 0)
                {
                    scoreMap[row][col] += 1 * p[row][col];
                }
                else if (whiteNum == 1)
                {
                    //����
                    scoreMap[row][col] += 10 * p[row][col];
                }
                else if (whiteNum == 2)
                {
                    if (emptyNum == 1)
                    {
                        //����
                        scoreMap[row][col] += 100 * p[row][col];
                    }
                    else if (emptyNum == 2)
                    {
                        //����
                        scoreMap[row][col] += 1000 * p[row][col];
                    }
                }
                else if (whiteNum == 3)
                {
                    //����
                    if (emptyNum == 1)
                    {
                        scoreMap[row][col] += 1000 * p[row][col];
                    }
                    else if (emptyNum == 2)
                    {
                        //����
                        scoreMap[row][col] += 10000 * p[row][col];
                    }
                }
                else if (whiteNum >= 4)
                {
                    //����
                    scoreMap[row][col] += 100000 * p[row][col];
                }
            }
        }
    }
}
//ѡȡ���ܵ����ӵ�
vector<ChessPos> Node::think()
{
    calculateScore();
    //���ڴ���������ֵ�����ڱȽ�
    vector<int> maxScore(num, 0);
    //���ڴ���������ֵ������
    vector<ChessPos> maxPoints;
    int size = 15;
    int lastMax = 9999999;

    for (int i = 0; i < num; i++)
    {
        maxPoints.push_back(ChessPos(0, 0));
        for (int row = 0; row < size; row++)
        {
            for (int col = 0; col < size; col++)
            {
                //�жϸõ��Ƿ�Ϊ��
                if (this->chessBoard[row][col] == 0)
                {
                    if (scoreMap[row][col] > maxScore[i] && scoreMap[row][col] <= lastMax) //�����յ���һ�Ƚϣ���������ֵ������
                    {

                        if (i == 0)
                        {
                            maxScore[i] = scoreMap[row][col];
                            maxPoints.clear();
                            maxPoints.push_back(ChessPos(row, col));
                        }
                        else if (i != 0 && maxPoints[i - 1].col != col && maxPoints[i - 1].row != row)
                        {
                            maxScore[i] = scoreMap[row][col];
                            maxPoints.pop_back();
                            maxPoints.push_back(ChessPos(row, col));
                        }
                    }
                }
            }
        }
        lastMax = maxScore[i];
    }
    return maxPoints;
}

int Node::minimax(int depth, int alpha, int beta, bool black_white)
{
    if (depth == 4)
    {
        return evaluate(black_white);
    }
    else if (depth % 2)//min��
    {
        int i;
        int j;
        int value;
        vector<ChessPos> v = think();
        for (int k = 0; k < num; k++)
        {
            i = v[k].row;
            j = v[k].col;
            if (chessBoard[i][j] != 0)
            {
                continue;
            }
            down(i, j, depth % 2);
            value = minimax(depth + 1, alpha, beta, black_white);
            //pvs Ч����������û��
            /*value = minimax(depth + 1, alpha, alpha+1);
            if (value > alpha)
            {
                value = minimax(depth + 1, alpha, beta);

            }*/
            if (beta > value)
            {
                beta = value;
            }
            revokeChess(i, j);
            if (alpha >= beta)
            {
                return beta;
            }
        }
        return beta;
    }
    else//max��
    {
        int i;
        int j;
        int value;
        vector<ChessPos> v = think();
        for (int k = 0; k < num; k++)
        {
            i = v[k].row;
            j = v[k].col;

            if (chessBoard[i][j] != 0)
            {
                continue;
            }
            down(i, j, depth % 2);
            value = minimax(depth + 1, alpha, beta, black_white);
            //pvs Ч����������û��
            /*value = minimax(depth + 1, alpha, alpha + 1);
            if (value > alpha)
            {
                value = minimax(depth + 1, alpha, beta);

            }*/
            if (alpha < value)
            {
                alpha = value;
                if (depth == 0)
                {
                    bestRow = i;
                    bestCol = j;
                }
            }
            revokeChess(i, j);
            if (alpha >= beta)
            {
                return alpha;
            }
        }
    }
    return alpha;
}

int Node::getBestRow()
{
    return bestRow;
}
int Node::getBestCol()
{
    return bestCol;
}
