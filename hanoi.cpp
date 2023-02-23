#include<iostream>
#include<cstdio>
using namespace std;
void hanoi(int x,char y,char z,char mid);
int main()
{
	hanoi(64,'A','B','C');
	return 0;
}
void hanoi(int x,char sta,char mid,char des)
{
	if(x==1) {
		printf("%c->%c\n",sta,des);
	}
	else {
		hanoi(x-1,sta,des,mid);
		printf("%c->%c\n",sta,des);
		hanoi(x-1,mid,sta,des);
	}
	return;
}
