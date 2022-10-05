#include<stdio.h>
int tri(int n)
{
	int ans = n;
	for (int i = 0; i < 2; i++)
	{
		ans *= n;
	}
	return ans;
}
int main()
{
	int a[3];
	int n = 0;
	for (int i = 100; i < 1000; i++)
	{
		n = i;
		for (int j = 0; j < 3; j++)
		{
			a[j] = n % 10;
			n /= 10;
		}
		if (i == tri(a[0]) + tri(a[1]) + tri(a[2]))
		{
			printf("%d\n", i);
		}
	}
	return 0;
}