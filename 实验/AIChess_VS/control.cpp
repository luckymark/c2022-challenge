#include "AIChess_VS.h"
using namespace std;

bool line_same(Line x, vector <int> y)
{
	int len1 = x.f.size(), len2 = y.size();
	if (len1 != len2)
		return false;
	for (int i = 0; i < len1; i++)
	{
		if (x.f[i] != y[i])
			return false;
	}
	return true;
}


void AI_put(Chess it)
{
	int x = it.x, y = it.y;
	Map[x][y].color = 1;
	putChess(Map[x][y]);
}

void Person_put(Chess it)
{
	int x = it.x, y = it.y;
	Map[x][y].color = 2;
	putChess(Map[x][y]);
}

Line getline_lay(Chess it,int tmp,int len)//
{
	Line cnt;
	cnt.p = tmp;
	int x = it.x;
	int y = it.y;
	int i = 0;
	for (i = y-tmp+1; i <= y-tmp+len; i++)
	{
		if (Map[x][i].isBoundry == 1)
			break;
		cnt.f.push_back(Map[x][i].color);
	}
	return cnt;
}
Line getline_stand(Chess it, int tmp, int len)//
{
	Line cnt;
	cnt.p = tmp;
	int x = it.x;
	int y = it.y;
	int i = 0;
	for (i = x - tmp + 1; i <= x - tmp + len; i++)
	{
		if (Map[i][y].isBoundry == 1)
			break;
		cnt.f.push_back(Map[i][y].color);
	}
	return cnt;
}
Line getline_main(Chess it, int tmp, int len)//
{
	Line cnt;
	cnt.p = tmp;
	int x = it.x;
	int y = it.y;
	int i = 0,j=0;
	for (i = y - tmp + 1, j = x - tmp + 1; i <= y - tmp + len; i++, j++)
	{
		if (Map[j][i].isBoundry == 1)
			break;
		cnt.f.push_back(Map[j][i].color);
	}
	return cnt;
}
Line getline_vice(Chess it, int tmp, int len)//
{
	Line cnt;
	cnt.p = tmp;
	int x = it.x;
	int y = it.y;
	int i = 0,j=0;
	for (i = y + tmp - 1, j = x - tmp + 1; j <= x - tmp + len; i--, j++)
	{
		if (Map[j][i].isBoundry == 1)
			break;
		cnt.f.push_back(Map[j][i].color);
	}
	return cnt;
}
bool check_win(Chess it)
{
	vector <Line> l(5);
	for (int i = 1; i <= 5; i++)//位置
	{
		if (it.color == 0)
			return false;
		bool flag = 1;
		l[1] = getline_lay(it, i, 5);
		l[2] = getline_stand(it, i, 5);
		l[3] = getline_main(it, i, 5);
		l[4] = getline_vice(it, i, 5);
    	for (int j = 1; j <= 4; j++)//方向
		{
			if (l[j].f.size() != 5)
				continue;
			flag = 1;
			for (int k = 0; k < 5; k++)//链中位置
			{
				if (l[j].f[k] != it.color)
				{
					flag = 0;
					break;
				}
			}
			if (flag)
				return true;
		}
	}
	return false;
}
