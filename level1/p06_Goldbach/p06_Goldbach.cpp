#include <stdio.h>
#include <iostream>
#include <math.h>
using namespace std;
int IsPrimeNumber(int num);
int main()//��һ����2��ż������д����������֮��
{
	for(int n1=2;n1<=100;n1++)
	{
		if(IsPrimeNumber(n1)==1)
		{
			for(int n2=2;n2<=100;n2++)
			{
				if(IsPrimeNumber(n2)==1 && (n1+n2)%2==0)
				{
					cout<<n1+n2<<"�����°ͺղ���"<<endl;
				}
			}
		}
	}
	return 0;
}
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
