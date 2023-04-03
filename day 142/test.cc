

// 计算日期到天数转换
// 链接：https://www.nowcoder.com/questionTerminal/769d45d455fe40b385ba32f97e7bcded
// 来源：牛客网

// 根据输入的日期，计算是这一年的第几天。
// 保证年份为4位数且日期合法。
// 进阶：时间复杂度：O(n) O(n) ，空间复杂度：O(1) O(1) 

// 输入描述:

// 输入一行，每行空格分割，分别是年，月，日



// 输出描述:

// 输出是这一年的第几天

// 示例1
// 输入

// 2012 12 31

// 输出

// 366

// 示例2
// 输入

// 1982 3 4

// 输出

// 63

#include <iostream>
using namespace std;


int GetDay(int year, int month)
{
	int mon[12] = { 0,31,59,90,120,151,181,212,243,273,304,334 };
	if (((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) && month > 2)
        return mon[month - 1] + 1;
    
	return mon[month - 1];
}



int main() {
    int a, b, c;
    while (cin >> a >> b >> c) 
    { // 注意 while 处理多个 case
        cout << GetDay(a, b) + c << endl;


    }
}
// 64 位输出请用 printf("%lld")



#include<stdio.h>

int judge_year(int year)
{
    if(year % 4 == 0 && year % 100 != 0)
    {
        return 1;
    }
    else if(year % 400 == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


// int main()
// {
//     int year = 0;
//     int moon = 0;
//     int days = 0;
    
//     int a1[12] = {0 , 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};
//     int a2[12] = {0 , 31, 60, 91, 121, 151, 182, 213, 244, 274, 305, 335};
    
//     scanf("%d%d%d",&year ,&moon, &days);
    
//     if(judge_year(year))
//     {
//       printf("%d\n",a2[moon - 1] + days);
//     }
//     else
//     {
//         printf("%d\n",a1[moon - 1] + days);
//     }
    
//     return 0;
// }