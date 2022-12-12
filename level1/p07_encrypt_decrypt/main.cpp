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