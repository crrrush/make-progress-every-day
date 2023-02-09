
// 2的n次方计算
// 链接：https://www.nowcoder.com/questionTerminal/35a1e8b18658411388bc1672439de1d9
// 来源：牛客网

// 不使用累计乘法的基础上，通过移位运算（<<）实现2的n次方的计算。

// 数据范围：0≤n≤31 0≤n≤31 

// 输入描述:

// 一行输入整数n（0 <= n < 31）。



// 输出描述:

// 输出对应的2的n次方的结果。

// 示例1
// 输入

// 2

// 输出

// 4

// 示例2
// 输入

// 10

// 输出

// 1024

#include<stdio.h>

int main()
{
    int n = 0;
    
    scanf("%d",&n);
    
    printf("%d",1 << n);
    
    return 0;
}