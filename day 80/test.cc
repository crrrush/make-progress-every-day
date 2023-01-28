

// 计算一元二次方程 
// 链接：https://www.nowcoder.com/questionTerminal/7da524bb452441b2af7e64545c38dc26
// 来源：牛客网

// 从键盘输入a, b, c的值，编程计算并输出一元二次方程ax2 + bx + c = 0的根，当a = 0时，输出“Not quadratic equation”，当a ≠ 0时，根据△ = b2 - 4*a*c的三种情况计算并输出方程的根。

// 输入描述:

// 多组输入，一行，包含三个浮点数a, b, c，以一个空格分隔，表示一元二次方程ax2 + bx + c = 0的系数。



// 输出描述:

// 针对每组输入，输出一行，输出一元二次方程ax2 + bx +c = 0的根的情况。

//   如果a = 0，输出“Not quadratic equation”；

//   如果a ≠  0，分三种情况：

// △ = 0，则两个实根相等，输出形式为：x1=x2=...。

// △  > 0，则两个实根不等，输出形式为：x1=...;x2=...，其中x1  <=  x2。

// △  < 0，则有两个虚根，则输出：x1=实部-虚部i;x2=实部+虚部i，即x1的虚部系数小于等于x2的虚部系数，实部为0时不可省略。实部= -b / (2*a),虚部= sqrt(-△ ) / (2*a)

// 所有实数部分要求精确到小数点后2位，数字、符号之间没有空格。

// 示例1
// 输入

// 2.0 7.0 1.0

// 输出

// x1=-3.35;x2=-0.15

// 示例2
// 输入

// 0.0 3.0 3.0

// 输出

// Not quadratic equation

// 示例3
// 输入

// 1 2 1

// 输出

// x1=x2=-1.00

// 示例4
// 输入

// 2 2 5

// 输出

// x1=-0.50-1.50i;x2=-0.50+1.50i

// 示例5
// 输入

// 1 0 1

// 输出

// x1=0.00-1.00i;x2=0.00+1.00i



#include<stdio.h>
#include<math.h>

int main()
{
	float a = 0.0, b = 0.0, c = 0.0;



	while ((scanf("%f %f %f", &a, &b, &c)) != EOF)
	{

		if (a == 0.0)
		{
			printf("Not quadratic equation\n");
			continue;
		}
		if (b * b - 4 * a * c == 0)
		{
			if ((b / -(2 * a)) == 0.0)
			{
				printf("x1=x2=0.00\n");
				continue;
			}
			printf("x1=x2=%.2f\n", (b / -(2 * a)));
		}
		else if (b * b - 4 * a * c > 0)
		{
			if ((b + sqrt(b * b - 4 * a * c)) / -(2 * a) == 0.0)
			{
				printf("x1=0.00;x2=%.2f\n", (b - sqrt(b * b - 4 * a * c)) / -(2 * a));
				continue;
			}
			if ((b - sqrt(b * b - 4 * a * c)) / -(2 * a) == 0.0)
			{
				printf("x1=%.2f;x2=0.00\n", (b + sqrt(b * b - 4 * a * c)) / -(2 * a));
				continue;
			}
			printf("x1=%.2f;x2=%.2f\n", (b + sqrt(b * b - 4 * a * c)) / -(2 * a), (b - sqrt(b * b - 4 * a * c)) / -(2 * a));
		}
		else
		{
			if ((b / -(2 * a)) == 0.0)
			{
				printf("x1=0.00-%.2fi;x2=0.00+%.2fi\n", sqrt(-(b * b - 4 * a * c)) / (2 * a), sqrt(-(b * b - 4 * a * c)) / (2 * a));
				continue;
			}
			printf("x1=%.2f-%.2fi;x2=%.2f+%.2fi\n", b / -(2 * a), sqrt(-(b * b - 4 * a * c)) / (2 * a), b / -(2 * a), sqrt(-(b * b - 4 * a * c)) / (2 * a));
		}
	}


	return 0;
}