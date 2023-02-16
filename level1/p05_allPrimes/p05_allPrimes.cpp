#include <stdio.h>
#include <math.h>
#include <time.h>
using namespace std;
int IsPrimeNumber(int num);
int main()
{
	int begin,end;
	begin=clock(); 
	for(int n=2;n<=1000;n++)
	{
		int k=IsPrimeNumber(n);
		if(k==1)
		{
			printf("%d������\n",n);
		}
		else
		{
			printf("%d��������\n",n);
		}
	}
	end=clock();
	printf("����������%d����",end-begin);
};
int IsPrimeNumber(int num)
{
	for(int i=2;i<=sqrt(num);i++)
	{
		if(num%i==0)
		{
			return false;
		}
	}
	return true;
}
