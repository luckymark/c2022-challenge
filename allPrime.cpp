#include<bits/stdc++.h>
using namespace std;
#define MAXN 1000
bool isprime[MAXN];
int prime[MAXN];
int cnt;
void euler()//Å·À­É¸ 
{

	memset(isprime,true,sizeof(isprime));
	isprime[1]=false;
	for(int i=2;i<=MAXN-1;i++)
	{
		if(isprime[i])
			prime[++cnt]=i;
		for(int j=1;j<=cnt&&i*prime[j]<=MAXN-1;j++)
		{
			isprime[i*prime[j]]=false;
			if(i%prime[j]==0)
				break;
		}
	}
}
int main()
{
	clock_t start,finish;
	start=clock();
	euler();
	for(int i=1;i<=1000;i++)
		if(isprime[i])
			cout<<i<<endl;
	finish=clock();
	cout<<endl;
	cout<<(double)(finish-start)<<"ms"<<endl;
	return 0;
}


