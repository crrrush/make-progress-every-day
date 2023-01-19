
// 浮点数的个位数字
// 链接：https://www.nowcoder.com/questionTerminal/ffa94d27c6534396aef38813535c279f
// 来源：牛客网

// 给定一个浮点数，要求得到该浮点数的个位数。

// 数据范围： 0<n≤200 0<n≤200 

// 输入描述:

// 一行，包括一个浮点数。



// 输出描述:

// 一行，包含一个整数，为输入浮点数对应的个位数。

// 示例1
// 输入

// 13.141

// 输出

// 3

#include<stdio.h>

int main()//给定一个浮点数，要求得到该浮点数的个位数
{
	float n = 0;
	int j = 0;
	scanf("%f", &n);//输入
	
	for (float i = 0; 10 * i < n; i++)
	{
		if (n - (10 * i) < 10)
		{
			n = n - (10 * i);//清除十位
			for ( j = 0; j < n; j++)
			{
				if (n - j < 1)//得到个位数
					break;
			}
		}	     
	}
	printf("%d", j);
		
	return 0;
}
