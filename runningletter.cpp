#include<bits/stdc++.h>
#include<windows.h>
using namespace std;
#define MaxN 50
void print(int tmp)
{
	for(int i=1;i<=tmp;i++)
		cout<<" ";
	cout<<"A";
	Sleep(50);
	system("cls");
}
int main()
{
	int n=1;
	while(1)
	{
		if(n%2==1)
			for(int i=1;i<=MaxN;i++)
				print(i);

		if(n%2==0)
			for(int i=MaxN;i>=1;i--)
				print(i);
		n++;
	}
	return 0;
} 
