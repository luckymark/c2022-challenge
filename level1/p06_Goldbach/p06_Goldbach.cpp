#include<cstdio>
using namespace std;
inline bool is_prime(const int& n)
{
	if (n==1) return 0;
	for (int i=2;i*i<=n;++i)
	{
		if (n%i==0) return 0;
	}
	return 1;
}
int main()
{
	for (int i=4;i<=100;i+=2)
	{
		for (int j=2;j<=i-2;++j)
		{
			if (is_prime(j)&&is_prime(i-j))
			{
				printf("%d = %d + %d\n",i,j,i-j);
			}
		}
	}
	return 0;
}