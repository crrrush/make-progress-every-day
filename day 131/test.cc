
// 等差数列
// 链接：https://www.nowcoder.com/questionTerminal/f792cb014ed0474fb8f53389e7d9c07f
// 来源：牛客网

// 等差数列 2，5，8，11，14。。。。
// （从 2 开始的 3 为公差的等差数列）

// 输出求等差数列前n项和

// 数据范围： 1≤n≤1000 1≤n≤1000 

// 输入描述:

// 输入一个正整数n。



// 输出描述:

// 输出一个相加后的整数。

// 示例1
// 输入

// 2

// 输出

// 7

// 说明

// 2+5=7  

// 示例2
// 输入

// 275

// 输出

// 113575

// 说明

// 2+5+...+821+824=113575

#include<stdio.h>

int main()
{
    int n = 0;
    
    //输入项数
    scanf("%d",&n);
    
    int count = n * (3 * n + 1) / 2;
    
    
    /*
    //首项
    int i = 2;
    //总和
    int count = 0;
    while(n--)
    {
        count += i;
        i += 3;
    }
    */
    printf("%d\n",count);
    
    return 0;
}