
// 牛牛的并联电路
// 链接：https://www.nowcoder.com/questionTerminal/6e13936b6fc54f52ac22efd6c8e7fef3
// 来源：牛客网

// 牛牛有一个阻值是 r1 和一个阻值 r2 的电阻，牛牛想知道这两个电阻并联后等效电阻是多少

// 并联电路的等效电阻公式是：11r1+1r2 r11​+r21​1​ 

// 输入描述:

// 输入 r1 和 r2 两个电阻的阻值



// 输出描述:

// 输出两个电阻并联后的等效电阻zhi

// 示例1
// 输入

// 1 1

// 输出

// 0.5


#include<stdio.h>


int main()
{
    float r1 = 0.0,r2 = 0.0;
    
    scanf("%f%f",&r1,&r2);
    
    printf("%.2f",1.0 / ((1.0 / r1) + (1.0 / r2)));
    
    return 0;
}