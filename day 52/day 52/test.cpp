#define _CRT_SECURE_NO_WARNINGS

//
//415. 字符串相加
//https ://leetcode.cn/problems/add-strings/
//
//给定两个字符串形式的非负整数 num1 和num2 ，计算它们的和并同样以字符串形式返回。
//
//你不能使用任何內建的用于处理大整数的库（比如 BigInteger）， 也不能直接将输入的字符串转换为整数形式。
//
//
//
//示例 1：
//
//输入：num1 = "11", num2 = "123"
//输出："134"
//
//示例 2：
//
//输入：num1 = "456", num2 = "77"
//输出："533"
//
//示例 3：
//
//输入：num1 = "0", num2 = "0"
//输出："0"
//


class Solution {
public:
    string addStrings(string num1, string num2) {
        string res;
        int carry = 0;
        auto it1 = num1.rbegin();
        auto it2 = num2.rbegin();
        while (it1 != num1.rend() && it2 != num2.rend())
        {
            int n1 = *it1 - '0';
            int n2 = *it2 - '0';
            if (n1 + n2 + carry >= 10)
            {
                res.push_back(n1 + n2 + carry - 10 + '0');
                carry = 1;
            }
            else
            {
                res.push_back(n1 + n2 + carry + '0');
                carry = 0;
            }
            ++it1;
            ++it2;
        }
        while (it1 != num1.rend())
        {
            if (*it1 - '0' + carry == 10)
            {
                res.push_back(*it1 + carry - 10);
                carry = 1;
            }
            else
            {
                res.push_back(*it1 + carry);
                carry = 0;
            }
            ++it1;
        }
        while (it2 != num2.rend())
        {
            if (*it2 - '0' + carry == 10)
            {
                res.push_back(*it2 + carry - 10);
                carry = 1;
            }
            else
            {
                res.push_back(*it2 + carry);
                carry = 0;
            }
            ++it2;
        }
        if (carry)
            res.push_back('1');
        reverse(res.begin(), res.end());
        return res;
    }
};