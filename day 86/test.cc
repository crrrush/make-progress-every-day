
//平均身高 
// 链接：https://www.nowcoder.com/questionTerminal/b0e489a749f448e2b37f26ef56a76e58
// 来源：牛客网

// 从键盘输入5个人的身高（米），求他们的平均身高（米）。

// 输入描述:

// 一行，连续输入5个身高（范围0.00~2.00），用空格分隔。



// 输出描述:

// 一行，输出平均身高，保留两位小数。

// 示例1
// 输入

// 1.68 1.75 1.82 1.60 1.92

// 输出

// 1.75


#include<stdio.h>

int main()
{
	float arr[5] = { 0 };

	int i = 0;
	float sum = 0;

	float* p = arr;

	for (i = 0; i < 5; i++)
	{
		scanf("%f", &arr[i]);
	}

	for (i = 0; i < 5; i++)
	{
		sum += *(p + i);
	}

	printf("%.2f\n", sum / 5);

	return 0;
}