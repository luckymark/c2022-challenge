#include <stdio.h>
#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	int n,k=1;
	cin>>n;
	for(int i=2;i<=sqrt(n);i++)
	{
		if(n%i==0)
		{
			k=0;
		}
	}
	if(k==1)
	{
		cout<<n<<"是素数"; 
	}
	else
	{
		cout<<n<<"不是素数";
	}
	return 0;
}
