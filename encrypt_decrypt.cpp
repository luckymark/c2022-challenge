#include<bits/stdc++.h>
using namespace std;
#define MAXN 0x7fffff
char bef[MAXN],beh[MAXN];
void encrypt(int len,int key)
{
	for(int i=0;i<len;i++)
		beh[i]=bef[i]+key;
}
void decrypt(int len,int key)
{
	for(int i=0;i<len;i++)
		beh[i]=bef[i]-key;
}
int main()
{
	int key;
	cout<<"'E' to encrypt,'D' to decrypt"<<endl;
	char c;
	cin>>c;
	cout<<"your string"<<endl;
	cin>>bef;
	cout<<"your key"<<endl;
	cin>>key;
	int len=strlen(bef);
	if(c=='E')
		encrypt(len,key);
	else if(c=='D')
		decrypt(len,key);
	cout<<beh;
	return 0;
} 
