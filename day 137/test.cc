
// 不用加减乘除做加法


// 链接：https://www.nowcoder.com/questionTerminal/59ac416b4b944300b617d4f7f111b215
// 来源：牛客网

// 写一个函数，求两个整数之和，要求在函数体内不得使用+、-、*、/四则运算符号。

// 数据范围：两个数都满足 −10≤n≤1000−10≤n≤1000
// 进阶：空间复杂度 O(1)O(1)，时间复杂度 O(1)O(1)
// 示例1
// 输入

// 1,2

// 输出

// 3

// 示例2
// 输入

// 0,0

// 输出

// 0

/**
 * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
 *
 * 
 * @param num1 int整型 
 * @param num2 int整型 
 * @return int整型
 *
 * C语言声明定义全局变量请加上static，防止重复定义
 *
 * C语言声明定义全局变量请加上static，防止重复定义
 */

int Add(int num1, int num2 ) {
    num1 = num1 ^ num2;
    num2 = num2 & (num1 ^ num2);
    while(num2)
    {
        num2 <<= 1;
        num1 = num1 ^ num2;
        num2 = num2 & (num1 ^ num2);
    }
    return num1;
}

/*
int Add(int num1, int num2 ) {//failed
    num1 = num1 ^ num2;
    num2 = num2 & (num1 ^ num2);
    int n = 0;
    while((num2 << n) & num1)
    {
        num1 = ~((num2 << n)) & num1;
        n++;
    }
    return num1 | (num2 << n);
}*/