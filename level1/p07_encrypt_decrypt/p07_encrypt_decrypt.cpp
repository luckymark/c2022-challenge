/*
	运用hash算法，将字符串映射为一个unsigned long long整值
	为避免冲突，采用多组seed，最后将结果转化为十六进制串
*/
#include<cstdio>
#include<string>
#include<iostream>
#include<map>
using namespace std;
string opt,s;
map <string,string> mp;
const unsigned long long seed[4]={114514,1919810,19260817,998244353};
const string rep[16]={"0","1","2","3","4","5","6","7","8","9","A","B","C","D","E","F"};
//opt=encrypt加密 opt=decrypt解密
inline string D_to_H(unsigned long long x)
{
	string tmp;
	for (int i=1;i<=16;++i,x>>=4)
	{
		tmp=rep[x%16]+tmp;
	}
	return tmp;
}
inline string encrypt(const string& s)
{
	unsigned long long val[4];
	for (int i=0;i<s.size();++i)
	{
		for (int j=0;j<4;++j)
		{
			val[j]=val[j]*seed[j]+s[i];
		}
	}
	string tar;
	for (int j=0;j<4;++j)
	{
		tar+=D_to_H(val[j]);
	}
	mp[tar]=s;
	return tar;
}
inline string decrypt(const string& s)
{
	if (mp.count(s)) return mp[s];
	else return "Can't find aboriginal codes";
}
int main()
{
	while (cin>>opt>>s)
	{
		if (opt[0]=='e')
		{
			cout<<encrypt(s)<<endl;
		} else
		{
			cout<<decrypt(s)<<endl;
		}
	}
	return 0;
}