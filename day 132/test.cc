

// 记负均正
// 链接：https://www.nowcoder.com/questionTerminal/6abde6ffcc354ea1a8333836bd6876b8
// 来源：牛客网

// 首先输入要输入的整数个数n，然后输入n个整数。输出为n个整数中负数的个数，和所有正整数的平均值，结果保留一位小数。
// 0即不是正整数，也不是负数，不计入计算。如果没有正数，则平均值为0。

// 数据范围： 1≤n ≤2000 1≤n ≤2000  ，输入的整数都满足 ∣val∣≤1000 ∣val∣≤1000 

// 输入描述:

// 首先输入一个正整数n，
// 然后输入n个整数。



// 输出描述:

// 输出负数的个数，和所有正整数的平均值。

// 示例1
// 输入

// 11 
// 1 2 3 4 5 6 7 8 9 0 -1

// 输出

// 1 5.0

// 示例2
// 输入

// 3
// 0 0 0

// 输出

// 0 0.0


#include<stdio.h>

int main()
{
    int n = 0;
    scanf("%d",&n);//n个数
    
    int i = 0;//负数个数
    float num = 0;//正整数个数
    float count = 0;//正整数之和
    while(n--)
    {
        float j = 0;
        scanf("%f",&j);
        if(j < 0)
        {
            i++;
        }
        if(j > 0)
        {
            num++;
            count += j;
        }
    }
    float average = 0;
    if (num)
        average = count / num;
    printf("%d %.1f\n",i ,average);
    
    return 0;
}