#include<stdio.h>
#include<math.h>
#include<time.h>
void AllPrime();
void IsPrime(int number);
int main()
{
  	clock_t t1,t2;
  	double total;
  	
  	t1=clock();
  	
  	AllPrime();
  	
    t2=clock();
	 
    total = (double)(t2 - t1) / CLOCKS_PER_SEC;
    printf("\n%f seconds",total);
	 
    return 0;
}
void AllPrime(){
	int x=0;
  	
	for(x=3;x<1000;x=x+2){
    	IsPrime(x);     
    }
} 
void IsPrime(int number){
	int prime=1;
	int yushu=0;
	double b=sqrt((double)number);
	
    for(int n=3;n<=b;n=n+2){
    	yushu=number%n;
      	if (yushu ==0){
      	prime=0;
      	break;
		}	
	}
	  
	if(prime==1){
	  	printf("  %4d  ",number);
	}
}
