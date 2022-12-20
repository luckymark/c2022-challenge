#include<iostream>
#include<math.h>
using namespace std;


int main() 
{
	int n;
	cin >> n;
	if (n % 2 == 0 || n == 1 && n != 2)
	{
		cout << "false";
		return 0;
	}
	else if (n == 2)
	{
		cout << "true";
		return 0;
	}
	for (int i = 3; i <= sqrt(n); i += 2)
	{
		if (n % i == 0)
		{
			cout << "false";
			return 0;
		}
	}
	cout << "true";
	return 0;
}