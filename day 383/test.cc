/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2023-12-09 17:30:40
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2023-12-09 17:31:10
 * @FilePath: \every-little-progress\day 383\test.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */



// 2409. 统计共同度过的日子数
// https://leetcode.cn/problems/count-days-spent-together/description/
// Alice 和 Bob 计划分别去罗马开会。

// 给你四个字符串 arriveAlice ，leaveAlice ，arriveBob 和 leaveBob 。Alice 会在日期 arriveAlice 到 leaveAlice 之间在城市里（日期为闭区间），而 Bob 在日期 arriveBob 到 leaveBob 之间在城市里（日期为闭区间）。每个字符串都包含 5 个字符，格式为 "MM-DD" ，对应着一个日期的月和日。

// 请你返回 Alice和 Bob 同时在罗马的天数。

// 你可以假设所有日期都在 同一个 自然年，而且 不是 闰年。每个月份的天数分别为：[31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31] 。

 

// 示例 1：

// 输入：arriveAlice = "08-15", leaveAlice = "08-18", arriveBob = "08-16", leaveBob = "08-19"
// 输出：3
// 解释：Alice 从 8 月 15 号到 8 月 18 号在罗马。Bob 从 8 月 16 号到 8 月 19 号在罗马，他们同时在罗马的日期为 8 月 16、17 和 18 号。所以答案为 3 。
// 示例 2：

// 输入：arriveAlice = "10-01", leaveAlice = "10-31", arriveBob = "11-01", leaveBob = "12-31"
// 输出：0
// 解释：Alice 和 Bob 没有同时在罗马的日子，所以我们返回 0 。
 

// 提示：

// 所有日期的格式均为 "MM-DD" 。
// Alice 和 Bob 的到达日期都 早于或等于 他们的离开日期。
// 题目测试用例所给出的日期均为 非闰年 的有效日期。


class date
{
private:
    static vector<int> months;
    int _month;
    int _day;
public:
    date(const string& d)
    {
        _month = stoi(string(d.begin(), d.begin() + 2));
        _day = stoi(string(d.begin() + 3, d.end()));
        cout<<_month<<":"<<_day<<endl;
    }

    bool operator==(const date& d) const { return _month == d._month && _day == d._day; }

    bool operator<(const date& d) const { return (_month < d._month) || (_month == d._month && _day < d._day); }

    bool operator<=(const date& d) const { return (*this < d) || (*this == d); }

    int operator-(const date& d)
    {
        int D = 0;
        cout<<_month<<":"<<_day<<" - "<<d._month<<":"<<d._day;
        if(_month > d._month)
        {
            D += months[d._month - 1] - d._day;
            for(int i = d._month + 1;i < _month;++i) D += months[i - 1];
            D += _day;
        }
        else
        {
            D += (_day - d._day);
        }
        return D + 1;
    }
};

vector<int> date::months = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        date A_arrive(arriveAlice);
        date A_leave(leaveAlice);
        date B_arrive(arriveBob);
        date B_leave(leaveBob);

        if(A_leave < B_arrive || B_leave < A_arrive) return 0;

        if(A_arrive <= B_arrive)
        {
            if(A_leave <= B_leave) return A_leave - B_arrive;
            else return B_leave - B_arrive;
        }
        else
        {
            if(A_leave <= B_leave) return A_leave - A_arrive;
            else return B_leave - A_arrive;
        }

        return 0;
    }
};