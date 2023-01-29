

// 简单计算器 
// 链接：https://www.nowcoder.com/questionTerminal/b8f770674ba7468bb0a0efcc2aa3a239
// 来源：牛客网

// KiKi实现一个简单计算器，实现两个数的“加减乘除”运算，用户从键盘输入算式“操作数1运算符操作数2”，计算并输出表达式的值，如果输入的运算符号不包括在（+、-、*、/）范围内，输出“Invalid operation!”。当运算符为除法运算，即“/”时。如果操作数2等于0.0，则输出“Wrong!Division by zero!”

// 数据范围：字符串长度满足 3≤n≤50 3≤n≤50  ，保证运算符是一个char类型字符。

// 输入描述:

// 输入一行字符串，操作数1+运算符+操作数2 （其中合法的运算符包括：+、-、*、/）。



// 输出描述:

// 输出为一行。

// 如果操作数和运算符号均合法，则输出一个表达式，操作数1运算符操作数2=运算结果，各数小数点后均保留4位，数和符号之间没有空格。

// 如果输入的运算符号不包括在（+、-、*、/）范围内，输出“Invalid operation!”。当运算符为除法运算，即“/”时。

// 如果操作数2等于0.0，则输出“Wrong!Division by zero!”。

// 示例1
// 输入

// 1.0+3.0

// 输出

// 1.0000+3.0000=4.0000

// 示例2
// 输入

// 1.0;4.0

// 输出

// Invalid operation!

// 示例3
// 输入

// 44.0/0.0

// 输出

// Wrong!Division by zero!


#include<stdio.h>

int main()
{
	//调用内存存储数据
	char n[] = "+-*/";
	char syb = 0;
	char* p = n;

	double a = 0.0, b = 0.0;
	double cos = 0.0;

	//输入
	scanf("%lf", &a);
	syb = getchar();
	scanf("%lf", &b);

	//判断合法性
	char* q = p;//建立第二个指针判断符号
	while (q)
	{
		if (syb == *q)
			break;
		q++;
		if (q - p > 3)
		{
			printf("Invalid operation!\n");
			return 0;
		}
	}

	//输出
	if (syb == *(p + 3))
	{
		if (b == 0)//判断
		{
			printf("Wrong!Division by zero!\n");
			return 0;
		}
		else
			printf("%.4lf%c%.4lf=%.4lf\n", a, syb, b, a / b);
	}
	else if(syb == *p)
		printf("%.4lf%c%.4lf=%.4lf\n", a, syb, b, a + b);
	else if (syb == *(p + 1))
		printf("%.4lf%c%.4lf=%.4lf\n", a, syb, b, a - b);
	else
		printf("%.4lf%c%.4lf=%.4lf\n", a, syb, b, a * b);


	return 0;
}