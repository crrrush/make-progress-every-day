

//正斜线形图案
// 链接：https://www.nowcoder.com/questionTerminal/61ef68d129534dfbb04b232e1244e447
// 来源：牛客网

// KiKi学习了循环，BoBo老师给他出了一系列打印图案的练习，该任务是打印用“*”组成的正斜线形图案。

// 输入描述:

// 多组输入，一个整数（2~20），表示输出的行数，也表示组成正斜线的“*”的数量。



// 输出描述:

// 针对每行输入，输出用“*”组成的正斜线。

// 示例1
// 输入

// 4

// 输出

//    *
//   * 
//  *  
// *   

// 示例2
// 输入

// 5

// 输出

//     *
//    * 
//   *  
//  *   
// * 

#include<stdio.h>


int main()
{
	int n = 0;

	while (~scanf("%d", &n))
	{
		int i = 0, j = 0;
		for (i = n; i > 0; i--,printf("\n"))
		{
			for (j = 1; j <= n; j++)
			{
				if (j == i)
					printf("*");
				else
					printf(" ");
			}
		}
	}



	return 0;
}
