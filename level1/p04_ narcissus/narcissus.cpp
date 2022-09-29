#include<stdio.h>
#define MAX 999
void ShuiXianHua();
int main(void)
{
	ShuiXianHua();
	
	return 0;
 }
void ShuiXianHua(){
 	int a,b,c=0;
	int i,j;
	for(i=100;i<MAX;i++){
		b=i;
		for(j=1;j<4;j++){
			a=b%10;
			b=b/10;
			c+=a*a*a;
		 	if(c==i && j==3){
				printf("%6d",i);
		 	}
		 	if(j==3){
		 		c=0;
		 	}   
		}		
	}
 } 
