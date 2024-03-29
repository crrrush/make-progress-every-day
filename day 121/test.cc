
// 带空格直角三角形图案
// 链接：https://www.nowcoder.com/questionTerminal/192d1039c3d44155bb868073f5482670
// 来源：牛客网

// KiKi学习了循环，BoBo老师给他出了一系列打印图案的练习，该任务是打印用“*”组成的带空格直角三角形图案。

// 输入描述:

// 多组输入，一个整数（2~20），表示直角三角形直角边的长度，即“*”的数量，也表示输出行数。



// 输出描述:

// 针对每行输入，输出用“*”组成的对应长度的直角三角形，每个“*”后面有一个空格。

// 示例1
// 输入

// 5

// 输出

//         * 
//       * * 
//     * * * 
//   * * * * 
// * * * * *

// 示例2
// 输入

// 4

// 输出

//       * 
//     * * 
//   * * * 
// * * * *

#include<stdio.h>

int main()
{
    int num = 0;
    
    while(~scanf("%d",&num))
    {
        int i = 0,j = 0;
        for(i = 0 ;i < num;i++,printf("\n"))
        {
            for(j = (2*num - i);j + i > num;j--)
            {
                if(j > num + 1)
                    printf("  ");
                else
                    printf("* ");
            }
        }
    }
    
    
    return 0;
}