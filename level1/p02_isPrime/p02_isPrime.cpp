#include<cstdio>
using namespace std;
int n;
inline bool is_prime(const int& n)
{
	if (n==1) return 0;
	for (int i=2;i*i<=n;++i)
	if (n%i==0) return 0;
	return 1;
}
int main()
{
	scanf("%d",&n);
	if (is_prime(n))
	{
		puts("Yes");
	}
	else
	{
		puts("No");
	}
	return 0;
}