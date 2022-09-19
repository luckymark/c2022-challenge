### 编程解决下面的问题：

取自《希腊诗选》（Greek Anthology）：

丢番图的童年经过了他一生的六分之一，

青年经过了十二分之一，

又有七分之一的时间是单身汉。

结婚五年后得了个儿子，

儿子比父亲先死四年，

年级是他的一半。

问儿子死时丢番图多大？
```
#include<iostream>
#include<math.h>
using namespace std;

int main() 
{
	int n = 12;
	while (n)
	{
		if (n % 12 != 0 || n % 6 != 0 || n % 7 != 0)
		{
			n++;
			continue;
		}
		int m = n - n / 6 - n / 12 - n / 7 - 5 - 4;
		if ( m == n / 2)
			break;
		n++;
	}
	cout << n - 4;
	return 0;
}
```