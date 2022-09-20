#include<bits/stdc++.h>
using namespace std;

void move(int n,char A,char B,char C)
{
	if(n==1)
		printf("%c -> %c\n",A,C);
	else
	{
		move(n-1,A,C,B);
		printf("%c -> %c\n",A,C);
		move(n-1,B,A,C);
	}
}

int main()
{
	int n;
	cout<<"×ÜÊý"<<endl;
	cin>>n;
	move(n,'A','B','C');
	return 0;
}
