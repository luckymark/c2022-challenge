#include<iostream>
using namespace std;

void move(char sou, char tar)
{
	cout << sou << "->" << tar << endl;
}
void  hanoi(int n, char sou, char tmp, char tar)
{
	if (n == 1)
		move(sou, tar);
	else
	{
		hanoi(n - 1, sou, tar, tmp);
		move(sou, tar);
		hanoi(n - 1, tmp, sou, tar);
	}
}
int main()
{
	int n;
	cin >> n;
	hanoi(n, 'A', 'B', 'C');
	return 0;
}