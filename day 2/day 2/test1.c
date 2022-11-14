<<<<<<< HEAD
﻿#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>


//JZ65 不用加减乘除做加法  牛客
// 
//写一个函数，求两个整数之和，要求在函数体内不得使用 + 、 - 、 * 、 / 四则运算符号。
//
//数据范围：两个数都满足 −10≤n≤1000 - 10 \le n \le 1000−10≤n≤1000
//进阶：空间复杂度 O(1)O(1)O(1)，时间复杂度 O(1)O(1)O(1)


//int Add(int num1, int num2) {//failed
//    num1 = num1 ^ num2;
//    num2 = num2 & (num1 ^ num2);
//    int n = 0;
//    while ((num2 << n) & num1)
//    {
//        num1 = ~((num2 << n)) & num1;
//        n++;
//    }
//    return num1 | (num2 << n);
//}


int Add(int num1, int num2) {
    num1 = num1 ^ num2;
    num2 = num2 & (num1 ^ num2);
    while (num2)
    {
        num2 <<= 1;
        num1 = num1 ^ num2;
        num2 = num2 & (num1 ^ num2);
    }
    return num1;
}

//int main()
//{
//    int n1 = 111;
//    int n2 = 899;
//    int sum = Add(n1, n2);
//
//    printf("%d\n", sum);
//
//    return 0;
=======
﻿#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>


//JZ65 不用加减乘除做加法  牛客
// 
//写一个函数，求两个整数之和，要求在函数体内不得使用 + 、 - 、 * 、 / 四则运算符号。
//
//数据范围：两个数都满足 −10≤n≤1000 - 10 \le n \le 1000−10≤n≤1000
//进阶：空间复杂度 O(1)O(1)O(1)，时间复杂度 O(1)O(1)O(1)


//int Add(int num1, int num2) {//failed
//    num1 = num1 ^ num2;
//    num2 = num2 & (num1 ^ num2);
//    int n = 0;
//    while ((num2 << n) & num1)
//    {
//        num1 = ~((num2 << n)) & num1;
//        n++;
//    }
//    return num1 | (num2 << n);
//}


int Add(int num1, int num2) {
    num1 = num1 ^ num2;
    num2 = num2 & (num1 ^ num2);
    while (num2)
    {
        num2 <<= 1;
        num1 = num1 ^ num2;
        num2 = num2 & (num1 ^ num2);
    }
    return num1;
}

//int main()
//{
//    int n1 = 111;
//    int n2 = 899;
//    int sum = Add(n1, n2);
//
//    printf("%d\n", sum);
//
//    return 0;
>>>>>>> 69a39be363279d67410a192d15835bcc43c6cde7
//}