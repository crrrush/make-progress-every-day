/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2023-11-06 13:06:19
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2023-11-06 13:06:48
 * @FilePath: \every-little-progress\day 350\test.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */



// 1185. 一周中的第几天
// https://leetcode.cn/problems/day-of-the-week/
// 给你一个日期，请你设计一个算法来判断它是对应一周中的哪一天。

// 输入为三个整数：day、month 和 year，分别表示日、月、年。

// 您返回的结果必须是这几个值中的一个 {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"}。

 

// 示例 1：

// 输入：day = 31, month = 8, year = 2019
// 输出："Saturday"
// 示例 2：

// 输入：day = 18, month = 7, year = 1999
// 输出："Sunday"
// 示例 3：

// 输入：day = 15, month = 8, year = 1993
// 输出："Sunday"
 

// 提示：

// 给出的日期一定是在 1971 到 2100 年之间的有效日期。

class Solution {
public:
    string dayOfTheWeek(int day, int month, int year) {
        static vector<string> vs = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
        int c = year / 100; // year高两位
        int y = 0, m = 0, d = 0;
        if(month <= 2)
        {
            if(year % 100 == 0)// year低两位
            {
                y = 99;
                --c;
            }
            else
                y = year % 100 - 1;
             
            m = 12 + month;//[3,14]
        }
        else
        {
            y = year % 100; // year低两位
            m = month;//[3,14]
        }

        d = day;

        // cout<<"c:"<<c<<" y:"<<y<<" m:"<<m<<" d:"<<d<<endl;

        int D = (c / 4) - 2 * c + y + (y / 4) + (13 * (m + 1) / 5) + d - 1;
        // cout<<"D:"<<D;
        while(D < 0) D += 7;
        return vs[D % 7];
    }
};