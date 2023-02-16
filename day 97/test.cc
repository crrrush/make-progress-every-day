
// 计算y的值
// 链接：https://www.nowcoder.com/questionTerminal/61a0f16117484d219b59c62224b33b1c
// 来源：牛客网

// 已知一个函数y=f(x)，当x < 0时，y = 1；当x = 0时，y = 0；当x > 0时，y = -1。   

// 输入描述:

// 一行，输入一个整数x。（-10000<x<10000）



// 输出描述:

// 一行，输出y的值。

// 示例1
// 输入

// 10

// 输出

// -1

// 示例2
// 输入

// -10

// 输出

// 1

#include<stdio.h>


int main()
{
    int x = 0, y = 0;
    
    scanf("%d",&x);
    
    if(x == 0)
    {
        y = 0;
    }
    else if(x > 0)
    {
        y = -1;
    }
    else
    {
        y = 1;
    }
    
    printf("%d\n",y);
    
    return 0;
}