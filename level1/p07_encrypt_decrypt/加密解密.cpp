#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void JiaMi(char *ar,unsigned num);
void JieMi(char *ar,unsigned num);
int main(){
	char ShuRu[1000]={'0'},ShuChu[1000]={'0'};
	scanf("%s",ShuRu);
	JiaMi(ShuRu,strlen(ShuRu));
	printf("%s\n",ShuRu);
	JieMi(ShuRu,strlen(ShuRu));
	printf("%s",ShuRu);
	return 0;	
}

void JiaMi(char *ar,unsigned num){
	int M,m;
	char temp;
	
	for(int i=0;i<num;i++){
		if(*(ar+i)>='a' && *(ar+i)<='z'){
			*(ar+i)=(*(ar+i)-32);
		}
		else if(*(ar+i)>='A' && *(ar+i)<='Z'){
			*(ar+i)=(*(ar+i)+32);
		}
		else if(*(ar+i)>='0' && *(ar+i)<='4'){
			*(ar+i)=*(ar+i)+5;
		}
		else if(*(ar+i)>='5' && *(ar+i)<='9'){
			*(ar+i)=*(ar+i)-5;
		}
	}
	
	M=num/4;
	m=num%4;
	for(int i=0;i<M;i++){
		temp=*(ar+4*i);
		*(ar+4*i)=*(ar+4*i+2);
		*(ar+4*i+2)=*(ar+4*i+1);
		*(ar+4*i+1)=*(ar+4*i+3);
		*(ar+4*i+3)=temp;
	}
	if(m!=0){
		temp=*(ar+4*M);
	for(int i=0;i<m;i++){
		*(ar+4*M+i)=*(ar+4*M+i+1);
	}
	*(ar+4*M+m-1)=temp;
	}
}

void JieMi(char *ar,unsigned num){
	int M,m;
	char temp;
	
	M=num/4;
	m=num%4;
	for(int i=0;i<M;i++){
		temp=*(ar+4*i);
		*(ar+4*i)=*(ar+4*i+3);
		*(ar+4*i+3)=*(ar+4*i+1);
		*(ar+4*i+1)=*(ar+4*i+2);
		*(ar+4*i+2)=temp;
	}
	
	if(m!=0){
		temp=*(ar+4*M+m-1);
	for(int i=0;i<m;i++){
		*(ar+4*M+m-1-i)=*(ar+4*M+m-2-i);
	}
	*(ar+4*M)=temp;
	}
	
	for(int i=0;i<num;i++){
		if(*(ar+i)>='a' && *(ar+i)<='z'){
			*(ar+i)=(*(ar+i)-32);
		}
		else if(*(ar+i)>='A' && *(ar+i)<='Z'){
			*(ar+i)=(*(ar+i)+32);
		}
		else if(*(ar+i)>='0' && *(ar+i)<='4'){
			*(ar+i)=*(ar+i)+5;
		}
		else if(*(ar+i)>='5' && *(ar+i)<='9'){
			*(ar+i)=*(ar+i)-5;
		}
	}
}














