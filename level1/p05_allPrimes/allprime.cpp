#include<stdio.h>
#include<math.h>
#include<time.h> 
int main()
{
  clock_t t1,t2;
  int x=0,yushu=0;
  int prime; 
  double total;
  t1=clock(); 
   for(x=3;x<=1000;x=x+2){
      prime=1;                                                       
	  double b=sqrt((double)x);
      for(int n=3;n<=b;n=n+2){
      	yushu=x%n;
      	if (yushu ==0){
      	prime=0;
      	break;}	
	  }  
	  if(prime==1){
	  	printf("  %4d  ",x);
	  }    
    }
    t2=clock(); 
    total = (double)(t2 - t1) / CLOCKS_PER_SEC;
    printf("\n%f seconds",total); 
    return 0;
}
