

// 小乐乐走台阶
// 链接：https://www.nowcoder.com/questionTerminal/ebf04de0e02c486099d78b7c3aaec255
// 来源：牛客网

// 小乐乐上课需要走n阶台阶，因为他腿比较长，所以每次可以选择走一阶或者走两阶，那么他一共有多少种走法？

// 输入描述:

// 输入包含一个整数n (1 ≤ n ≤ 30)



// 输出描述:

// 输出一个整数，即小乐乐可以走的方法数。

// 示例1
// 输入

// 2

// 输出

// 2

// 示例2
// 输入

// 10

// 输出

// 89

#include<stdio.h>

int Fibonacci(int num)//递归
{
	if (num > 2)
	{
		return Fibonacci(num - 1) + Fibonacci(num - 2);
	}
	else if (num == 1)
		return 1;
	else if (num == 2)
		return 1;
}

int main()
{
	int n = 0;

	scanf("%d", &n);

	printf("%d\n", Fibonacci(n));

	return 0;
}