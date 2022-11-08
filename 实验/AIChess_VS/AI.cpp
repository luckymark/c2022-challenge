#include "AIChess_VS.h"
#include "manual.h"
using namespace std;
typedef long long ll;
ll getatkV(Chess it)
{
	vector <Line> t(5);
	ll v = 0;
	for (int i = 4; i <= 7; i++)//长度
	{
		for (int j = 1; j <= i; j++)//位置
		{
			t[1] = getline_lay(it, j, i);
			t[2] = getline_stand(it, j, i);
			t[3] = getline_main(it, j, i);
			t[4] = getline_vice(it, j, i);
			for (int k = 1; k <= 4; k++)//方向
			{
				if (t[k].f.size() != i)
					continue;
				t[k].f[t[k].p - 1] = 1;
				if (i == 4)
				{
					if (line_same(t[k], ah32))
						v += 4;
					if (line_same(t[k], ah33))
						v += 4;
					if (line_same(t[k], ah23))
						v += 2;
				}
				else if (i == 5)
				{
					if (line_same(t[k], al51))
						return 10000000;
					if (line_same(t[k], ac41))
						v += 12;
					if (line_same(t[k], ac42))
						v += 12;
					if (line_same(t[k], ac45))
						v += 12;
					if (line_same(t[k], ah31))
						v += 8;
					if (line_same(t[k], am37))
						v += 4;
					if (line_same(t[k], am38))
						v += 4;
					if (line_same(t[k], am39))
						v += 4;
					if (line_same(t[k], ah22))
						v += 2;
				}
				else if (i == 6)
				{
					if (line_same(t[k], ah41))
						return 1000000;
					if (line_same(t[k], ac43))
						v += 12;
					if (line_same(t[k], ac44))
						v += 12;
					if (line_same(t[k], am31))
						v += 4;
					if (line_same(t[k], am32))
						v += 4;
					if (line_same(t[k], am33))
						v += 4;
					if (line_same(t[k], am34))
						v += 4;
					if (line_same(t[k], am35))
						v += 4;
					if (line_same(t[k], am36))
						v += 4;
					if (line_same(t[k], ah21))
						v += 2;
				}
				else if (i == 7)
				{
					if (line_same(t[k], am310))
						v += 4;
				}
			}
		}
	}
	return v;
}
ll getdefV(Chess it)
{
	vector <Line> t(5);
	ll v = 0;
	for (int i = 4; i <= 7; i++)//长度
	{
		for (int j = 1; j <= i; j++)//位置
		{
			t[1] = getline_lay(it, j, i);
			t[2] = getline_stand(it, j, i);
			t[3] = getline_main(it, j, i);
			t[4] = getline_vice(it, j, i);
			for (int k = 1; k <= 4; k++)//方向
			{
				if (t[k].f.size() != i)
					continue;
				t[k].f[t[k].p - 1] = 2;
				if (i == 4)
				{
					if (line_same(t[k], dh32))
						v += 4;
					if (line_same(t[k], dh33))
						v += 4;
					if (line_same(t[k], dh23))
						v += 2;
				}
				else if (i == 5)
				{
					if (line_same(t[k], dl51))
						return 10000000;
					if (line_same(t[k], dc41))
						v += 12;
					if (line_same(t[k], dc42))
						v += 12;
					if (line_same(t[k], dc45))
						v += 12;
					if (line_same(t[k], dh31))
						v += 8;
					if (line_same(t[k], dm37))
						v += 4;
					if (line_same(t[k], dm38))
						v += 4;
					if (line_same(t[k], dm39))
						v += 4;
					if (line_same(t[k], dh22))
						v += 2;
				}
				else if (i == 6)
				{
					if (line_same(t[k], dh41))
						return 100000;
					if (line_same(t[k], dc43))
						v += 12;
					if (line_same(t[k], dc44))
						v += 12;
					if (line_same(t[k], dm31))
						v += 4;
					if (line_same(t[k], dm32))
						v += 4;
					if (line_same(t[k], dm33))
						v += 4;
					if (line_same(t[k], dm34))
						v += 4;
					if (line_same(t[k], dm35))
						v += 4;
					if (line_same(t[k], dm36))
						v += 4;
					if (line_same(t[k], dh21))
						v += 2;
				}
				else if (i == 7)
				{
					if (line_same(t[k], dm310))
						v += 4;
				}
			}
		}
	}
	return v;
}
void giveAllValue()//遍历
{
	for(int i=1;i<=15;i++)
	{
		for (int j = 1; j <= 15; j++)
		{
			if (Map[i][j].color != 0)
			{
				Map[i][j].atkV = Map[i][j].defV = -1;
				continue;
			}
			Map[i][j].atkV = getatkV(Map[i][j]);
			Map[i][j].defV = getdefV(Map[i][j]);
		}
	}
	
}
Chess getBestdef(vector <pair<int, int> > f)
{
	vector <pair<int, int> > tmp;
	int Max = 0;
	for (int i = 0; i < f.size(); i++)
	{
		int x = f[i].first, y = f[i].second;
		if (Max == Map[x][y].defV)
		{
			tmp.push_back(f[i]);
		}
		else if (Max < Map[x][y].defV)
		{
			tmp.clear();
			tmp.push_back(f[i]);
			Max = Map[x][y].defV;
		}
	}
	if (tmp.size() == 1)
		return Map[tmp[0].first][tmp[0].second];
	srand((unsigned)time(NULL));
	int n = rand() % tmp.size();
	return Map[tmp[n].first][tmp[n].second];
}
Chess getBestatk(vector <pair<int, int> > f)
{
	vector <pair<int, int> > tmp;
	int Max = 0;
	for (int i = 0; i < f.size(); i++)
	{
		int x = f[i].first, y = f[i].second;
		if (Max == Map[x][y].atkV)
		{
			tmp.push_back(f[i]);
		}
		else if (Max < Map[x][y].atkV)
		{
			tmp.clear();
			tmp.push_back(f[i]);
			Max = Map[x][y].atkV;
		}
	}
	if (tmp.size() == 1)
		return Map[tmp[0].first][tmp[0].second];
	srand((unsigned)time(NULL));
	int n = rand() % tmp.size();
	return Map[tmp[n].first][tmp[n].second];
}
Chess getBestChess()
{
	vector <pair<int, int> > atktmp, deftmp;
	int atkMax=0, defMax=0;
	for (int i = 1; i <= 15; i++)
	{
		for (int j = 1; j <= 15; j++)
		{
			if (atkMax == Map[i][j].atkV)
				atktmp.push_back({ i,j });
			else if (atkMax < Map[i][j].atkV)
			{
				atktmp.clear();
				atkMax = Map[i][j].atkV;
				atktmp.push_back({ i,j });
			}

			if (defMax == Map[i][j].defV)
				deftmp.push_back({ i,j });
			else if (defMax < Map[i][j].defV)
			{
				defMax = Map[i][j].defV;
				deftmp.clear();
				deftmp.push_back({ i,j });
			}
		}
	}
	if (atkMax >= defMax)
	{
		return getBestdef(atktmp);
	}
	else
	{
		return getBestatk(deftmp);
	}
}
Chess AI()
{
	if (Map_num() == 0)
	{
		AI_put(Map[8][8]);
		return Map[8][8];
	}
	giveAllValue();
	Chess best = getBestChess();
	return best;
}