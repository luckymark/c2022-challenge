#include<stdio.h>
int main(){
	int x,a; 
	int prime[100];//存放素数 
	int num=0;
	int he;//两素数的和 
	for(int i=3;i<=99;i=i+2){
		for(a=3;a<i;a++){
			x=i%a;
			if(x==0){
				break;
			}
		}
		if(a==i){
			num++;
			prime[num]=i;
		}
	}//先求出100以内的素数 
	
	
	for(int i=6;i<=100;i=i+2){
		for(int num1=1;num1<=num;num1++){
			for(int num2=1;num2<=num;num2++){
				he=prime[num1]+prime[num2];
				if(he==i){
					printf("%d是%d%与%d的和\n",i,prime[num1],prime[num2]);
					break;
				} 
			}
			if(he==i){
				break;
			}
		}
		if(he!=i){
				break;
		}
	}
	
	return 0;
} 
