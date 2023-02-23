

// 牛牛的水杯
// 链接：https://www.nowcoder.com/questionTerminal/c196c47c23394bf3bdd4f82a838df6bf
// 来源：牛客网

// 牛牛口渴了，要喝10升水才能解渴，但现在只有一个深 h 厘米，底面半径是 r 厘米的水杯，牛牛最少要喝多少杯水才能解渴。

// 水杯的体积公式是 π×h×r2 π×h×r2 ，其中 π π  取 3.14 ，h h  和 r r  是整数。

// 输入描述:

// 输入杯子的高度 h ，底面半径 r 。



// 输出描述:

// 输出牛牛最少要喝多少杯水

// 示例1
// 输入

// 2 6

// 输出

// 45

#include<stdio.h>

#define pi  3.14

int main()
{
    float h = 0, r = 0;
    //输入数据
    scanf("%f%f", &h, &r);

    //输出
    int a = (int)(10000 / (pi * h * r * r)) + 1;
    printf("%d", a);


    return 0;
}