

// 1507. 转变日期格式
// https://leetcode.cn/problems/reformat-date/
// 给你一个字符串 date ，它的格式为 Day Month Year ，其中：

// Day 是集合 {"1st", "2nd", "3rd", "4th", ..., "30th", "31st"} 中的一个元素。
// Month 是集合 {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"} 中的一个元素。
// Year 的范围在 ​[1900, 2100] 之间。
// 请你将字符串转变为 YYYY-MM-DD 的格式，其中：

// YYYY 表示 4 位的年份。
// MM 表示 2 位的月份。
// DD 表示 2 位的天数。
 

// 示例 1：

// 输入：date = "20th Oct 2052"
// 输出："2052-10-20"
// 示例 2：

// 输入：date = "6th Jun 1933"
// 输出："1933-06-06"
// 示例 3：

// 输入：date = "26th May 1960"
// 输出："1960-05-26"
 

// 提示：

// 给定日期保证是合法的，所以不需要处理异常输入。

class Solution {
public:
    vector<string> slice(const string& date)
    {
        auto it1 = date.begin();
        auto it2 = date.begin();
        vector<string> vs;
        while(it2 != date.end())
        {
            if(*it2 == ' ')
            {
                vs.push_back(string(it1, it2));
                it1 = it2;
                ++it1;
            }
            ++it2;
        }
        vs.push_back(string(it1, it2));

        return vs;
    }
    string getMon(const string& mon)
    {
        static vector<string> vsm = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
        string M;
        for(int i = 0;i < 12;++i)
        {
            if(vsm[i] == mon)
            {
                if(i < 9) M += '0';
                M += to_string(i + 1);
                break;
            }
        }

        M += '-';
        return M;
    }
    string getDay(const string& day)
    {
        string d;
        if(day.size() < 4) d += '0';
        for(const auto& e : day) if(e >= '0' && e <= '9') d += e;
        return d;
    }
    string reformatDate(string date) {
        vector<string> vs = slice(date);
        string Date = vs[2] + '-';
        Date += getMon(vs[1]);
        Date += getDay(vs[0]);

        return Date;
    }
};