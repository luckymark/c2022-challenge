#include<iostream>
#include<math.h>
using namespace std;

int main() 
{
	int n = 12;
	while (n)
	{
		if (n % 12 != 0 || n % 6 != 0 || n % 7 != 0)
		{
			n++;
			continue;
		}
		int m = n - n / 6 - n / 12 - n / 7 - 5 - 4;
		if ( m == n / 2)
			break;
		n++;
	}
	cout << n - 4;
	return 0;
}