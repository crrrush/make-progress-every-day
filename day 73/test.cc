
// 你能活多少秒 
// 链接：https://www.nowcoder.com/questionTerminal/e1d1bd99fee34b66ae3c777b74d555c8
// 来源：牛客网

// 问题：一年约有 3.156×107 s，要求输入您的年龄，显示该年龄合多少秒。

// 数据范围： 0<age≤200 0<age≤200 



// 输入描述:

// 一行，包括一个整数age。



// 输出描述:

// 一行，包含一个整数，输出年龄对应的秒数。

// 示例1
// 输入

// 20

// 输出

// 631200000


#include<stdio.h>

int main()
{
    long age = 0;
   
    scanf("%ld", &age);

    printf("%ld\n", age * 31560000 );
   


    return 0;
}
