

// 日期差值 
// 链接：https://www.nowcoder.com/questionTerminal/ccb7383c76fc48d2bbc27a2a6319631c
// 来源：牛客网

// 有两个日期，求两个日期之间的天数，如果两个日期是连续的我们规定他们之间的天数为两天

// 输入描述:

// 有多组数据，每组数据有两行，分别表示两个日期，形式为YYYYMMDD



// 输出描述:

// 每组数据输出一行，即日期差值

// 示例1
// 输入

// 20110412
// 20110422

// 输出

// 11

#include <iostream>
using namespace std;


inline int GetDay(int year, int month)
{
	int mon[12] = { 0,31,59,90,120,151,181,212,243,273,304,334 };
	if (((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) && month > 2)
        return mon[month - 1] + 1;
    
	return mon[month - 1];
}

inline int GetYearDay(int year)
{
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
        return 366;
    else
        return 365;
	
}


int main() {
    int y1, m1, d1;
    int y2, m2, d2;
    while (scanf("%4d%2d%2d%4d%2d%2d",&y1, &m1, &d1, &y2, &m2, &d2) != EOF) 
    {
        //cout << y1 << m1 << d1 << endl;
        //cout << y2 << m2 << d2 << endl;

        if(y1 != y2)
        {
            int D1 = GetYearDay(y1) - GetDay(y1, m1);
            int D2 = GetDay(y2, m2);
            ++y1;
            int D3 = 0;
            while(y1 < y2)
            {
                D3 += GetYearDay(y1++);
            }

            cout << D1 + D2 + D3 + 1 << endl;
        }
        else
        {
            cout << GetDay(y2, m2) + d2  - GetDay(y1, m1) - d1 + 1 << endl;
        }

    }
}
// 64 位输出请用 printf("%lld")