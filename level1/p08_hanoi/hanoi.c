#include<stdio.h>

int hanoi(int n,char x,char y,char z);
int move(char,int,char);

int main(){
	int n,count;
	
	printf("ÊäÈë²ãÊý: ");
	scanf("%d",&n);
	putchar('\n');
	
	count=hanoi(n,'A','B','C');
	
	return 0;
}

int hanoi(int n,char x,char y,char z){
	if(n==1){
		move(x,1,z);
	}
	else{
		hanoi(n-1,x,z,y);
		move(x,n,z);
		hanoi(n-1,y,x,z);	
	}
	
	return 0;
}

int move(char getone,int n,char putone){
	
	printf(" %c->%c\n",getone,putone);
	
	return 0;
} 
