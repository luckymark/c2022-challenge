#include<stdio.h>
int main(){
	int x,a; 
	int prime[100];//������� 
	int num=0;
	int he;//�������ĺ� 
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
	}//�����100���ڵ����� 
	
	
	for(int i=6;i<=100;i=i+2){
		for(int num1=1;num1<=num;num1++){
			for(int num2=1;num2<=num;num2++){
				he=prime[num1]+prime[num2];
				if(he==i){
					printf("%d��%d%��%d�ĺ�\n",i,prime[num1],prime[num2]);
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
