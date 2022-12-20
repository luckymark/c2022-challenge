### 题目：冒泡排序

### 功能要求：

1. 采用冒泡算法实现一个排序算法
1. 构造一个正整数数组，测试该冒泡算法
1. 测试不同情况下的执行时间

### 参考：
```
[冒泡排序－百度百科](http://baike.baidu.com/link?url=mk5B_WaNbOLIbgx-pjQ45OkfTe14BCxcz1C6ZS86AsAduhwNKFM_Q3kqIK-6a6VDh6XKpd-VW8PR1IvaU1FhYTUqqnh5n4ovRUALgFvGox3nEmhkpALdhpvYxfbTkLGpDL90SiatgfuWCWujleIA8E3FUL3qJmC0TnEQN7kD1fHxmhq6uZeVXeTNfxlURvAd)
#include<iostream>
using namespace std;

void swap(int* a, int* b)
{
	int c = *a;
	*a = *b;
	*b = c;
}
void maopao(int m[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - 1; j++)
		{
			if (m[j] > m[j + 1])
				swap(&m[j], &m[j + 1]);
		}
	}
}
int main()
{
	clock_t start, end;
	start = clock();
	int m[10] = { 8,9,2,4,6,7 };
	int n = 6;
	maopao(m, n);
	for (int i = 0; i < n; i++)
		cout << m[i] << '\t';
	end = clock();
	cout << endl << end - start;
	return 0;
}
```