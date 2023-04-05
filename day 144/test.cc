

// 打印日期
// 链接：https://www.nowcoder.com/questionTerminal/b1f7a77416194fd3abd63737cdfcf82b
// 来源：牛客网

// 给出年分m和一年中的第n天，算出第n天是几月几号。

// 输入描述:

// 输入包括两个整数y(1<=y<=3000)，n(1<=n<=366)。



// 输出描述:

// 可能有多组测试数据，对于每组数据，
// 按 yyyy-mm-dd的格式将输入中对应的日期打印出来。

// 示例1
// 输入

// 2000 3
// 2000 31
// 2000 40
// 2000 60
// 2000 61
// 2001 60

// 输出

// 2000-01-03
// 2000-01-31
// 2000-02-09
// 2000-02-29
// 2000-03-01
// 2001-03-01


#include <iostream>
using namespace std;

int GetMonth(int year, int day,int& d)
{
    int i = 0;
	int mon[13] = { 0,31,59,90,120,151,181,212,243,273,304,334,400 };

    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
    {
        mon[2]++;
        mon[3]++;
        mon[4]++;
        mon[5]++;
        mon[6]++;
        mon[7]++;
        mon[8]++;
        mon[9]++;
        mon[10]++;
        mon[11]++;
    }
    

    while(mon[i + 1] < day && i < 12)
    {
        i++;
    }
	
    d = day - mon[i];

    return i + 1;
}


int main() {
    int a, b;
    while (cin >> a >> b) 
    { 
        int day  = 0;
        int mon = GetMonth(a, b, day);
        printf("%d-%02d-%02d\n",a, mon, day);
    }
}