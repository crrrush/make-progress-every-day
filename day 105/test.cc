

// 计算球体的体积
// 链接：https://www.nowcoder.com/questionTerminal/0f5d9bfcd63b47fda2052a583b1fbd1f
// 来源：牛客网

// 给定一个球体的半径，计算其体积。其中球体体积公式为 V = 4/3*πr3，其中 π = 3.1415926。


// 数据范围：输入一个浮点值 0≤n≤15 0≤n≤15 


// 输入描述:

// 一行，用浮点数表示的球体的半径。



// 输出描述:

// 一行，球体的体积，小数点后保留3位。

// 示例1
// 输入

// 3.0

// 输出

// 113.097

#include<stdio.h>

int main()
{
	double r = 0.0;
	double v = 0.0;
	double pi = 3.1415926;
	//输入
	scanf("%lf", &r);
	//计算
	v = (pi * r * r * r)*4 / 3;
	//输出
	printf("%.3lf", v);


	return 0;
}
