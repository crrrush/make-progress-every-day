#define _CRT_SECURE_NO_WARNINGS


//43. 字符串相乘
//https ://leetcode.cn/problems/multiply-strings/
//给定两个以字符串形式表示的非负整数 num1 和 num2，返回 num1 和 num2 的乘积，它们的乘积也表示为字符串形式。
//注意：不能使用任何内置的 BigInteger 库或直接将输入转换为整数。
//
//
//
//示例 1:
//
//输入: num1 = "2", num2 = "3"
//输出 : "6"
//
//示例 2 :
//
//    输入 : num1 = "123", num2 = "456"
//    输出 : "56088"
//
//
//
//    提示：
//
//    1 <= num1.length, num2.length <= 200
//    num1 和 num2 只能由数字组成。
//    num1 和 num2 都不包含任何前导零，除了数字0本身。


class Solution {
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
public:
    string multiply(string num1, string num2) {
        if (num1[0] == '0' || num2[0] == '0')
            return string("0");

        string res("0");
        auto it1 = num1.rbegin();
        auto it2 = num2.rbegin();
        while (it2 != num2.rend())
        {
            it1 = num1.rbegin();
            string tmp;
            int carry = 0;
            //按位相乘
            while (it1 != num1.rend())
            {
                int n1 = *it1 - '0';
                int n2 = *it2 - '0';
                if (n1 * n2 + carry >= 10)
                {
                    tmp.push_back((n1 * n2 + carry) % 10 + '0');
                    carry = (n1 * n2 + carry) / 10;
                }
                else
                {
                    tmp.push_back(n1 * n2 + carry + '0');
                    carry = 0;
                }
                ++it1;
            }
            //处理进位
            if (carry > 0)
                tmp.push_back(carry + '0');

            //翻转
            reverse(tmp.begin(), tmp.end());

            //补倍数
            auto mul = it2;
            while (mul-- != num2.rbegin())
                tmp.push_back('0');

            //累加加得结果
            res = addStrings(res, tmp);

            //迭代
            ++it2;
        }
        return res;
    }
};