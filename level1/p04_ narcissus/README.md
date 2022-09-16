### 功能要求：

1. 打印出所有3位水仙花数

水仙花数：n位数的每个数位的n次方之和等于该n位数本身

例如：153=1^3+5^3+3^3
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