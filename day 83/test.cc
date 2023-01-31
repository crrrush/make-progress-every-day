

//菱形图案
// 链接：https://www.nowcoder.com/questionTerminal/8b935f8ffe99445dbd42494febd13e45
// 来源：牛客网

// KiKi学习了循环，BoBo老师给他出了一系列打印图案的练习，该任务是打印用“*”组成的菱形图案。

// 输入描述:

// 多组输入，一个整数（2~20）。



// 输出描述:

// 针对每行输入，输出用“*”组成的菱形，每个“*”后面有一个空格。

// 示例1
// 输入

// 2

// 输出

//   * 
//  * * 
// * * * 
//  * * 
//   * 

// 示例2
// 输入

// 3

// 输出

//    * 
//   * * 
//  * * * 
// * * * * 
//  * * * 
//   * * 
//    * 

// 示例3
// 输入

// 4

// 输出

//     * 
//    * * 
//   * * * 
//  * * * * 
// * * * * * 
//  * * * * 
//   * * * 
//    * * 
//     * 

#include<stdio.h>


int main()
{
    int num = 0;

    while (~scanf("%d", &num))
    {
        int i = 0, j = 0;
        for (i = 0; i < num + 1; i++, printf("\n"))
        {
            for (j = 0; j < num + 1; j++)
            {
                if (j < num - i)
                    printf(" ");
                else
                    printf("* ");
            }
        }
        for (i = 0; i < num; i++, printf("\n"))
        {
            for (j = num + 1; j > 0; j--)
            {
                if (j > num - i)
                    printf(" ");
                else
                    printf("* ");
            }
        }
    }

    return 0;
}