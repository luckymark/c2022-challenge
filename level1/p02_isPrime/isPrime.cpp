#include<stdio.h>
#include<math.h>
void IsPrime(int number);
int main(void) 
{
	int x=0,yushu=0;
                                                         
	scanf("%d",&x);
	IsPrime(x);
	
    return 0;
}
void IsPrime(int number){
	int prime=1;
	int yushu;
	 
	if(number%2==0 ||number==1) {
	  	prime=0;
	}
	else {
		double b=sqrt((double)number);
    	for(int n=3;n<=b;n=n+2){
      		yushu=number%n;
      		if (yushu ==0){
      		prime=0;
      		break;
			}
	  	}
	}
      if(prime==1){
	  	printf("yes");
	  	
	  }
	  else{
	  	printf("no");
	  }
	  
} 
