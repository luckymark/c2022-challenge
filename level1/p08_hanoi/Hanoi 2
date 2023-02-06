//递归问题 汉诺塔（hanoi）
//第一轮：将a针上的第1-63个盘子移到b针上（问题一）；最后将b针上的63个盘子移到c针上（问题二）；
//第二轮：（问题一）将a针上的第1-62个盘子移到b针上；再将第63个盘子移动到b针上；最后将c针上的62个盘子移动到b针上；
//（问题二）将b针上的第1-62个盘子移到a针上；再将第63个盘子移动到c针上；最后将a针上的62个盘子移动到c针上
//递归问题，n的数量不断在减少，但是move的规律却从未改变

#include<stdio.h>
int move(int n, char x, char y, char z)
{
	if (n == 1)
		printf("%c-->%c\n", x, z);//要注意递归的条件
	else
	{
		move(n - 1, x, z, y);
		printf("%c-->%c\n", x, z);
		move(n - 1, y, x, z);//递归
	}
	return 0;
}
int main(void)
{
	int n;
	scanf_s("%d", &n);
	move(n, 'A', 'B', 'C');
	return 0;
}

/*俸爷的代码：
#include<stdio.h>
int main() {
	if (n == 0)return;
	step++;
}*/

//递归问题的规律：
//从main函数向下调用，遇到同型问题时，hanoi函数自己调用了自己，这就是递归的原理
//自顶向下进行思考，更容易解决问题（复盘代码）
//尾递归：return f（n-1）*n;
//递推简单一般用循环，反推简单一般用递归；
