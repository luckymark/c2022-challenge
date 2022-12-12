#include<iostream>
#include<math.h>
#include<time.h>
using namespace std;

bool shu(int n)
{
	if (n % 2 == 0 || n == 1 && n != 2)
		return 0;
	if (n == 2)
		return 1;
	for (int i = 3; i <= sqrt(n); i += 2)
	{
		if (n % i == 0)
			return 0;
	}
	return 1;
}
int main() 
{
	clock_t start, end;
	start = clock();
	for (int i = 2; i <= 100; i += 2)
	{
		for (int j = 1; j <= i/2; j++)
		{
			if (shu(j) && shu(i - j))
				cout << j << '+' << i-j << '=' << i << '\t';
		}
		cout << endl;
	}
	end = clock();
	cout << endl;
	cout << end - start;
	return 0;
}