#include<bits/stdc++.h>
using namespace std;
int ans;
int main()
{
	int tmp1=0,tmp2=0,tmp3=0;
	for(int i=100;i<=999;i++)
	{
		int sum=0;
		tmp1=i%10;//��λ 
		sum+=pow(tmp1,3);
		tmp2=i/10%10;//ʮλ 
		sum+=pow(tmp2,3);
		tmp3=i/100;//��λ
		sum+=pow(tmp3,3); 
		if(sum==i)
			printf("%d=%d^3+%d^3+%d^3\n",i,tmp3,tmp2,tmp1);
	}
	return 0;
} 
