#include<bits/stdc++.h>
using namespace std;
#define MAXN 100
bool isprime[MAXN+1];
int prime[MAXN+1];
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
bool check(int n)
{
	bool flag=0;
	for(int i=1;i<=cnt;i++)
	{
		for(int j=i;j<=cnt;j++)
		{
			for(int k=j;k<=cnt;k++)
				if(n==(prime[i]+prime[j]+prime[k]))
				{
					flag=1;
					break;
				}
			if(flag)
				break;
		}
		if(flag)
			break;
	}
	return flag;
}

int main()
{
	euler();
	for(int i=6;i<=100;i++)
		if(!check(i))
		{
			cout<<"wrong"<<endl;
			return 0;
		}
	cout<<"yes";
	return 0;
}


