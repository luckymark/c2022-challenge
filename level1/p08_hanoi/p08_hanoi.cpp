/*
	运用递归算法，考虑找到一个中间柱子用来安置除去最下面一块的盘子
*/
#include<cstdio>
using namespace std;
inline void Hanoi(const int& n,const char& st,const char& rst,const char& end) //n表示这里的盘子数量，从st移动到end，经过rst转移
{
	if (n==1)
	{
		printf("%c -> %c\n",st,end);
		return;
	}
	Hanoi(n-1,st,end,rst);
	printf("%c -> %c\n",st,end);
	Hanoi(n-1,rst,st,end);
}
int main()
{
	Hanoi(64,'A','B','C');
	return 0;
}