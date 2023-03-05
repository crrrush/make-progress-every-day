


// 获得月份天数
// 链接：https://www.nowcoder.com/questionTerminal/13aeae34f8ed4697960f7cfc80f9f7f6
// 来源：牛客网

// KiKi想获得某年某月有多少天，请帮他编程实现。输入年份和月份，计算这一年这个月有多少天。

// 输入描述:

// 多组输入，一行有两个整数，分别表示年份和月份，用空格分隔。



// 输出描述:

// 针对每组输入，输出为一行，一个整数，表示这一年这个月有多少天。

// 示例1
// 输入

// 2008 2

// 输出

// 29

#include<stdio.h>

int main()
{
    int year = 0,moon = 0;
    
    while(~scanf("%d %d",&year,&moon))
    {
        if((year % 4 == 0 && year % 100 != 0 ) || year % 400 == 0)
        {
            if(moon == 2)
                printf("29\n");
            else if(moon == 4 || moon == 6 || moon == 9 || moon == 11)
                printf("30\n");
            else
                printf("31\n");
        }
        else
        {
            if(moon == 2)
                printf("28\n");
            else if(moon == 4 || moon == 6 || moon == 9 || moon == 11)
                printf("30\n");
            else
                printf("31\n");
        }
    }
    
    return 0;
}