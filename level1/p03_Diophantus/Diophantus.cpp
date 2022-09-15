#include<stdio.h>
#define MAX 200
int main(void)
{
  float year;
  float a,b,c,d,e,f,g;
  for(year=1;year<MAX;year++){
  	a=year/6;
  	b=year/12;
  	c=year/7;
  	d=5;
  	e=a+b+c+d;
  	f=year/2;
  	g=e+f;
  	if(g==year-4){
  		printf("%f\n",year-4);
	  }
  }
  return 0;
} 
