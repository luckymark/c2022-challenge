#include<iostream>
using namespace std;
int judge(int n)
{
	int a,b,c;
	a=n/100;
	b=n/10%10;
	c=n%10;
	if(a*a*a+b*b*b+c*c*c==n) return 1;
	return 0;
}
int main()
{
	for(int i=100;i<=999;++i) {
		if(judge(i)) {
			cout<<i<<" ";
		}
	}
	return 0;
}
