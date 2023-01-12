#include<iostream>
#include<string>
using namespace std;
#define N 100
int sign=1,tot;
int main()
{
	string a;
	cin>>a;
	while(1) {
		tot+=sign;
		for(int i=1;i<=tot;++i) {
			cout<<" ";
		}
		cout<<a;
		system("cls");
		if(tot==N||tot==0) {
			sign=-sign;
		}
	}
	return 0;
}
