#include<stdio.h>
#include<math.h>
int main()
{
  int x=0,yushu=0;
  int prime=1;                                                          
      scanf("%d",&x);
	  if(x%2==0 ||x==1) {
	  printf("no");
	  return 0;
	  }
	  double b=sqrt((double)x);
      for(int n=3;n<=b;n=n+2){
      	yushu=x%n;
      	if (yushu ==0){
      	prime=0;
      	break;}
	  	
	  }
      if(prime==1){
	  	printf("yes");
	  	
	  }
	  else printf("no");
	  
    return 0;
}
