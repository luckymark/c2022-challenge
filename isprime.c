#include<stdio.h>
int main()
{
	int a,t=0,i;
	scanf("%d",&a);
	for( i=2;i<a;i++)
	{
		if(a%i==0)
		{
			printf("��������");
			t=1;
			break;
		}
	}
	if(t==0){
		printf("������"); 
	}
}
