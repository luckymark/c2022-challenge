#include<iostream>
#include<math.h>
using namespace std;

int main() 
{
	for (int n = 100; n <= 999; n++)
	{
		int sum = 0;
		int k = n;
		for (int i = 0; i < 3; i++)
		{
			sum += pow(k % 10, 3);
			k /= 10;
		}
		if (sum == n)
			cout << n << endl;
	}
	return 0;
}