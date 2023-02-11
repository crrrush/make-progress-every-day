

// 开学？ 
// 链接：https://www.nowcoder.com/questionTerminal/9cc35bd0754f4feca18e10e57c672467
// 来源：牛客网

// 小S：终于可以开学啦！好开心啊！
// 小Y：你没看新闻吗，开学日期又延后了。
// 小S：NOOOOOOOOOOOOOOOO！
// 小S知道原计划星期X开学，通知开学时间延期N天，请问开学日期是星期几（星期日用7表示）？

// 输入描述:

// 输入包含两个数字X，N（1≤X≤7, 1≤N≤1000）。



// 输出描述:

// 输出一个数字，表示开学日期是星期几。

// 示例1
// 输入

// 1 2

// 输出

// 3

// 示例2
// 输入

// 5 9

// 输出

// 7

#include<stdio.h>


int main()
{
    int X = 0,N = 0;
    
    scanf("%d%d",&X,&N);
    
    printf("%d\n",(N + X - 1) % 7 + 1);
    
    return 0;
}