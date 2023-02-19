#include <stdio.h>
int main()
{
	for (float age = 1; age < 120; ++age) {
		if ((age / 6 + age / 12 + age / 7 + 5 + age / 2 + 4) == age)
		{
			printf("%.0f", age - 4);
		}
	}
	return 0;
}