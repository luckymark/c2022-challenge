#include <stdio.h>
int main()
{
	for (float i = 1; i < 120; ++i) {
		if ((i / 6 + i / 12 + i / 7 + 5 + i / 2 + 4) == i)
		{
			printf("%.0f", i - 4);
		}
	}
	return 0;
}