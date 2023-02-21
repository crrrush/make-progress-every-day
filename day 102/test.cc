

// 牛牛的圆
// 链接：https://www.nowcoder.com/questionTerminal/75a202e826d048a39824ec694b5ce7e3
// 来源：牛客网

// 牛牛有一个半径为 r 的圆，请你计算这个圆的面积。

// 圆的面积公式是 π×r2 π×r2 ，其中 π π  取 3.14

// 输入描述:

// 输入一个半径 r



// 输出描述:

// 输出圆的面积

// 示例1
// 输入

// 1

// 输出

// 3.14

#include<stdio.h>


int main()
{
    float pi = 3.14,r = 0.0;
    
    scanf("%f",&r);
    
    printf("%.2f",pi * r * r);
    
    return 0;
}