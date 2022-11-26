#include<cstdio>
#include<ctime>
using namespace std;
const int N=1000;
int prime[N+5],cnt; bool vis[N+5];
int main()
{
	int t1=clock();
	for (int i=2;i<=N;++i)
	{
		if (!vis[i])
		{
			prime[++cnt]=i;
		}
		for (int j=1;j<=cnt&&i*prime[j]<=N;++j)
		{
			vis[i*prime[j]]=1;
			if (i%prime[j]==0) break;
		}
	}
	for (int i=1;i<=cnt;++i) printf("%d%c",prime[i]," \n"[i==cnt]);
	int t2=clock();
	printf("time cost: %d",t2-t1);
	return 0;
}