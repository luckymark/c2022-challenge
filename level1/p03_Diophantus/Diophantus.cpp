//### 编程解决下面的问题：
//
//取自《希腊诗选》（Greek Anthology）：
//
//丢番图的童年经过了他一生的六分之一，
//
//青年经过了十二分之一，
//
//又有七分之一的时间是单身汉。
//
//结婚五年后得了个儿子，
//
//儿子比父亲先死四年，
//
//年级是他的一半。
//
//问儿子死时丢番图多大？
#include<stdio.h>
#include<stdlib.h>
int main()
{
	for (float age = 0; age < 100; age++)
	{
		if (age == age / 6.0 + age / 12.0 + age / 7.0 + 5.0 + age/2.0 + 4.0)
		{
			printf("%d\n", int(age - 4));
		}
	}
	system("pause");
	return 0;
}