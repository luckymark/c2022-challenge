#include<cstdio>
using namespace std;
const int age_limit=100;
int main()
{
	for (int i=1;i<=age_limit;++i)
	{
		int j=2*i;
		if (j%12==0&&j%7==0)
		{
			if (j/6+j/12+j/7+5+i+4==j)
			{
				printf("Diophantus's age when his son died is %d",j-4);
				break;
			}
		}
	}
	return 0;
}