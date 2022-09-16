### 题目：奔跑的字母

### 功能要求：

1. 在console上输出一个字母（或单词）
1. 使该字母或单词，按一定速度从左至右运动
1. 当遇到屏幕边界时反向运动
#include<iostream>
#include<windows.h>
using namespace std;

const int L = 0, R = 20;
int main() 
{
	int flag = 1, cur = 0;
	while (true)
	{
		for (int i = 0; i <= cur; i++)
			putchar(' ');
		putchar('%');
		cur += flag;
		if (cur == L || cur == R)
			flag = -flag;
		Sleep(100);
		system("cls");
	}
	return 0;
}


