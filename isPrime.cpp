#include<bits/stdc++.h>
using namespace std;
#define MAXN 0x7fffff
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
bool rule(int num)//³£¹æÅÐ¶Ï 
{
	if(num==1)
		return 0;
	int a=sqrt(num*1.0);
	for(int i=2;i<=a;i++)
		if(!(num%i))
			return 0;
	return 1;
}
int main()
{
	int num;
	cin>>num;
	euler();
	if(isprime[num])
		cout<<"yes";
	else
		cout<<"no"; 
//	if(rule(num))
//		cout<<"yes";
//	else
//		cout<<"no";
	return 0;
}


