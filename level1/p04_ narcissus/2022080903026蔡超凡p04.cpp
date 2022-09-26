#include<stdio.h>
void main( )
{
	for (int i = 100; i < 1000; i++)
	{
		int gewei = i % 10;
		int shiwei = ((i - gewei) % 100) / 10;
		int baiwei = (i - shiwei * 10 - gewei) / 100;
		if (i == gewei * gewei * gewei + shiwei * shiwei * shiwei + baiwei * baiwei * baiwei)
		{
			printf("%d  ", i);
		}
	}
}