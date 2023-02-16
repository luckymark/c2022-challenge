#include<stdio.h>
#include<math.h>
int AllPrime(int *ar);
int IsPrime(int number);
void Goldbach(int number,int *ar);

int main(){
	int prime[100];
	int geshu; 

	geshu=AllPrime(prime);
	
	Goldbach(geshu,prime);
	
	return 0;
}

int AllPrime(int *ar){
	int x=0;
	int num=0;
  	
   for(x=3;x<100;x=x+2){
		if(IsPrime(x)==1){
			*(ar+num)=x;
			num++;     
    	}    
	}
	
	return num;
}

int IsPrime(int number){
	int yushu=0;
	int panduan=1;
	                                                     
	double b=sqrt((double)number);
    for(int n=3;n<=b;n=n+2){
    	yushu=number%n;
      	if (yushu == 0){
      		panduan=0;
      		break;
		}	
	}
	  
	return panduan;
}

void Goldbach(int number,int *ar){
	int he;
	for(int i=6;i<=100;i=i+2){
		for(int num1=0;num1<=number;num1++){
			for(int num2=0;*(ar+num1)+*(ar+num2)<=i;num2++){
				he=*(ar+num1)+*(ar+num2);
				if(he==i){
					printf("%d是%d%与%d的和\n",i,*(ar+num1),*(ar+num2));
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
}
