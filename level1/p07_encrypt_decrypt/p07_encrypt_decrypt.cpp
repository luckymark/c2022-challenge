#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;
void lock(string &s,int len);
void unlock(string &s,int len);
int main()
{
	string s;
	cin>>s;
	int len=s.size();
	lock(s,len);//º”√‹ 
	cout<<s<<endl;
	unlock(s,len);//Ω‚√‹ 
	cout<<s;
	return 0;
}
void lock(string &s,int len)
{
	for(int i=0;i<len;i++)
	{
		s[i]=s[i]+11;
	}
}
void unlock(string &s,int len)
{
	for(int i=0;i<len;i++)
	{
		s[i]=s[i]-11;
	}
}
