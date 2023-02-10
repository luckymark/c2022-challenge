#include<stdio.h>
#include<math.h>
void special(int a, int r);
int main()
{
	int a, b, r;
	float c;
	r=scanf_s("%d", &a);
	special(a, r);
	return 0;
}
void special(int a,int r) {
	int b, c;
	c = sqrt(a);
	if (r == 1)
	{
		for (b = 2; b < c + 1; ++b)
		{
			if (a % b == 0)break;
		}
		if (b > c) printf("yes");

		else printf("no");
	}
	else printf("error");
}
