### 功能要求：

1. 分别编写“加密”、“解密”函数，输入为任意长度的字符串
#include<iostream>
#include<math.h>
#include<time.h>
using namespace std;

char* jiami(char* a)
{
	char* p = a;
	while (*p)
	{
		*p = *p + 'e' - 'a';
		p++;
	}
	return a;
}

char* jiemi(char* a)
{
	char* p = a;
	while (*p)
	{
		*p = *p - 'e' + 'a';
		p++;
	}
	return a;
}


int main()
{
	clock_t start, end;
	start = clock();
	string a;
	cin >> a;
	char* p = const_cast<char*>(a.c_str());
	p = jiami(p);
	cout << a << endl;
	end = clock();
	cout << end - start;
	return 0;
}