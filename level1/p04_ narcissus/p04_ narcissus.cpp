#include <stdio.h>
#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	int a,b,c;
	for(int n=100;n<=999;n++)
	{
		a=n/100;//百位 
		b=(n/10)%10;//十位 
		c=n%10;//个位 
		if(n==pow(a,3)+pow(b,3)+pow(c,3))
		{
			cout<<n<<'='<<a<<"^3+"<<b<<"^3+"<<c<<"^3"<<endl;
		}
	}
	return 0;
}
