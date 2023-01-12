#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
#define N 100
int check[N],prime[N],tot,sum,select[4],mat=6,temp[N];
void pr(int n)
{
	for(int i=2;i<=n;++i) {
		if(!check[i]) prime[++tot]=i;
		for(int j=1;j<=tot;++j) {
			if(i*prime[j]>n) break;
			check[i*prime[j]]=1;
			if(i%prime[j]==0) break; 
		}
	}
}
void judge(int num)
{
	for(int i=6;i<=num;++i) {
		for(int x=1;x<=tot;++x)
			for(int y=1;y<=tot;++y)
				for(int z=1;z<=tot;++z) {
					if(prime[x]+prime[y]+prime[z]==i) {
						++temp[i];
						if(temp[i]==1) {
							printf("%d+%d+%d=%d\n",prime[x],prime[y],prime[z],i);
						}
						
					}
				}
	}
}
int main()
{
	pr(100);
	judge(100);
	return 0;
}
