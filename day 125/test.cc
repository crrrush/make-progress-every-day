

// 空心正方形图案
// 链接：https://www.nowcoder.com/questionTerminal/72347ee949dc47399186ee183632f303
// 来源：牛客网

// KiKi学习了循环，BoBo老师给他出了一系列打印图案的练习，该任务是打印用“*”组成的“空心”正方形图案。

// 输入描述:

// 多组输入，一个整数（3~20），表示输出的行数，也表示组成正方形边的“*”的数量。



// 输出描述:

// 针对每行输入，输出用“*”组成的“空心”正方形，每个“*”后面有一个空格。

// 示例1
// 输入

// 4

// 输出

// * * * * 
// *     * 
// *     * 
// * * * * 

// 示例2
// 输入

// 5

// 输出

// * * * * * 
// *       * 
// *       * 
// *       * 
// * * * * * 

#include<stdio.h>


int main()
{
	int n = 0;

	while (~scanf("%d", &n))
	{
		int i = 0, j = 0;
		for (i = 0; i < n; i++)
		{
			printf("* ");
		}
		printf("\n");
		for (i = 0; i < n - 2; i++, printf("\n"))
		{
			for (j = 0; j < n; j++)
			{
				if (j == 0)
					printf("* ");
				else if (j == n - 1)
					printf("* ");
				else
					printf("  ");
			}
		}
		for (i = 0; i < n; i++)
		{
			printf("* ");
		}
		printf("\n");
	}



	return 0;
}