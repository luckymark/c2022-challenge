#include<cstdio>
using namespace std;
int main()
{
	for (int i=100;i<=999;++i)
	{
		int a=i/100,b=i/10%10,c=i%10;
		if (a*a*a+b*b*b+c*c*c==i)
		{
			printf("%d \n",i);
		}
	}
	return 0;
}