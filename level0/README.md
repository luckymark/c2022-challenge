### C0

1. 打印 “Hello world！I'm 某某某！”
```
#include<iostream>
using namespace std;
int main()
{
	cout << "Hello world！I'm 于润东！";
	return 0;
}
```

### C1

1. 判断数的正负、判断是否为偶数
```
#include<iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int a = n < 0 ? 0 : 1;
	if (a == 0)
		cout << n << "是负数,";
	else
		cout << n << "是正数,";
	if (n % 2 == 0)
		cout << "且" << n << "是偶数";
	else
		cout << "且" << n << "是奇数";
	return 0;
}
```
1. 判断一个数是否是13的倍数
```
#include<iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	if (n % 13 == 0)
		cout << "是";
	else
		cout << "不是";
	return 0;
}
```
1. 判断闰年
```
#include<iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	if (n % 4 == 0 && n % 100 != 0 || n % 400 == 0)
		cout << "是闰年";
	else
		cout << "不是闰年";
	return 0;
}
```
1. 从2个整数中，找出最大的那个数
```
#include<iostream>
using namespace std;
int main()
{
	int n, m;
	cin >> n >> m;
	int a= n > m ? n : m;
	cout << a;
	return 0;
}
```
1. 从3个整数中，找出最大的那个数
```
#include<iostream>
using namespace std;

int max(int a, int b)
{
	int c = a > b ? a : b;
	return c;
}
int main()
{
	int n, m, k;
	cin >> n >> m >> k;
	cout << max(n, max(m, k));
	return 0;
}
```
1. 从n个整数中，找出最大的那个数
```
#include<iostream>
using namespace std;

int max(int a, int b)
{
	int c = a > b ? a : b;
	return c;
}
int main()
{
	int n, m, k;
	cin >> n >> m ;
	for (int i = 0; i < n - 1; i++)
	{
		cin >> k;
		m = max(m, k);
	}
	cout << m;
	return 0;
}
```
### C2
1. 说1万遍“你好！”
```
#include<iostream>
using namespace std;

int main()
{
	for (int i = 0; i < 10000; i++)
		cout << "你好！" ;
	return 0;
}
```
2. 尝试以下代码的运行效果(windows环境下)：

```
	system("color 0a");
	while(1){
		printf("0 1");
    }
``` 

3. 尝试以下代码的运行效果：

```
	system("color 0a");
	while(1){
		printf("%d\t",rand()/1000);
    }
```

4. 打印2-100的所有偶数
```
#include<iostream>
using namespace std;

int main()
{
	for (int i = 2; i <= 100; i += 2)
		cout << i << '\t';
	return 0;
}
```
5. 打印所有1-100，能被3整除，但不能被5整除的数
```
#include<iostream>
using namespace std;

int main()
{
	for (int i = 1; i <= 100; i++)
	{
		if (i % 3 == 0 && i % 5 != 0)
			cout << i << '\t';
	}
	return 0;
}
```
6. 打印1-100，是7的倍数，或者尾数为7的所有数，并打印这些数的总和
```
#include<iostream>
using namespace std;

int main()
{
	int sum = 0;
	for (int i = 1; i <= 100; i++)
	{
		if (i % 7 == 0 || i % 10 == 7)
			sum += i;
	}
	cout << sum;
	return 0;
}
```
7. 打印一个九九表
```
#include<iostream>
using namespace std;

int main()
{
	int n = 1;
	for (int i = 1; i <= 9; i++)
	{
		for (int j = 1; j <= n; j++)
			cout << j << '*' << i << '=' << i * j << '\t';
		n++;
		cout << endl;
	}
	return 0;
}
```
8. 输入n个数，并将它们逆序输出
```
#include<iostream>
using namespace std;

int main()
{
	int a[1000], n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int j = 0; j < n-1; j++)
	{
		for (int k = j + 1; k < n; k++)
		{
			if (a[k] < a[j])
			{
				int tmp = a[k];
				a[k] = a[j];
				a[j] = tmp;
			}
		}
	}
	for (int i = 0; i < n; i++)
		cout << a[i] << '\t';
	return 0;	
}
```
9. 输入5个0-9的数，输出0-9中没有出现过的数
```
#include<iostream>
using namespace std;

int main()
{
	int a[10] = { 0,1,2,3,4,5,6,7,8,9 };
	for (int i = 0; i < 5; i++)
	{
		int n;
		cin >> n;
		a[n] = 11;
	}
	for (int i = 0; i < 10; i++)
	{
		if (a[i] != 11)
			cout << a[i] << '\t';
	}
	return 0;
}
```
10. 输入5个0-9的数，输入的数从小到大排序（排序方法不限，但鼓励尝试下“桶排序”，不知道什么是“桶排序”的话，可以google之）
```
#include<iostream>
using namespace std;

void sort(int a[])
{
	for (int i = 1; i < 5 ; i++)
	{
		if (a[i] < a[i - 1])
		{
			int key = a[i], j = i;
			while (a[j - 1] > key)
			{
				a[j] = a[j - 1];
				j--;
			}
			a[j] = key;
		}
	}
}

int main()
{
	int a[10];
	for (int i = 0; i < 5; i++)
		cin >> a[i];
	sort(a);
	for (int i = 0; i < 5; i++)
		cout << a[i];
}
```
### C3
```
1. 编写一个函数，计算数组的和
#include<iostream>
using namespace std;

int main()
{
	int n[10] = { 1,2,3,4,6,7 };
	int sum = 0;
	for (int i = 0; n[i]; i++)
		sum += n[i];
	cout << sum << endl;
	return 0;
}
```
1. 编写一个阶乘函数
```
#include<iostream>
using namespace std;

int main()
{
	int n, mul = 1;
	cin >> n;
	for (int i = n; i >= 1; i--)
		mul *= i;
	cout << mul;
	return 0;
}
```
1. 编写一个斐波那契函数
```
#include<iostream>
using namespace std;

int main()
{
	int a = 1, b = 1, n;
	cin >> n;
	if (n == 1 || n == 2)
	{
		cout << 1;
		return 0;
	}
	for (int i = 0; i < n - 2; i++)
	{
		int c = b;
		b = a + b;
		a = c;
	}
	cout << b;
	return 0;
}
```
1. 编写一个函数，判断三角形是否为直角三角形
```
#include<iostream>
using namespace std;

int main()
{
	int a, b, c;
	cin >> a >> b >> c;
	if (a*a == b * b + c * c || b * b == a * a + c * c || c * c == a * a + b * b)
		cout << "可以";
	return 0;
}
```
1. 编写一个函数，判断2个矩形是否有重叠（即游戏中常用的碰撞检测函数）
```
#include<iostream>
using namespace std;

struct square
{
	int x;
	int y;
	int wide;
	int high;
}r1,r2;

bool overlop(square r1, square r2)
{
	int flag = 0;
	if (r1.y + r1.high > r2.y || r2.y + r2.high > r1.y)
		flag = 1;
	else if (r1.x + r1.wide > r2.x || r2.x + r2.wide > r1.x)
		flag = 1;
	return flag;
}
int main()
{
	r1 = { 1, 2, 3, 4 };
	r2 = { 2,3,4,5 };
	if (overlop(r1, r2))
		cout << "overlop";
	else
		cout << "not overlop";
	return 0;
}
```
1. 编写一个函数，将美元换算为人民币
```
#include<iostream>
using namespace std;

float change(float n)
{
	float money;
	money = n / 6.98;
	return money;
}

int main()
{
	float n;
	cin >> n;
	cout << change(n);
	return 0;
}
```