

// 67. 二进制求和
// https://leetcode.cn/problems/add-binary/
// 给你两个二进制字符串 a 和 b ，以二进制字符串的形式返回它们的和。

 

// 示例 1：

// 输入:a = "11", b = "1"
// 输出："100"

// 示例 2：

// 输入：a = "1010", b = "1011"
// 输出："10101"

 

// 提示：

//     1 <= a.length, b.length <= 104
//     a 和 b 仅由字符 '0' 或 '1' 组成
//     字符串如果不是 "0" ，就不含前导零



class Solution {
    int addBinary_(const int& a, const int& b,int& carry)
    {
        switch(a + b + carry)
        {
        case 3:
        {
            carry = 1;
            return 1;
        }
            break;
        case 2:
        {
            carry = 1;
            return 0;
        }
            break;
        case 1:
        {
            carry = 0;
            return 1;
        }
            break;
        case 0:
        {
            carry = 0;
            return 0;
        }
            break;
        default:
            break;
        }

        return 0;
    }
public:
    string addBinary(string a, string b) {
        list<int> bnum;
        int carry = 0;
        auto rita = a.rbegin();
        auto ritb = b.rbegin();

        while(rita != a.rend() && ritb != b.rend())
        {
            bnum.push_front(addBinary_(*rita - '0', *ritb - '0', carry));

            ++rita;
            ++ritb;
        }
        while(rita != a.rend())
        {
            bnum.push_front(addBinary_(*rita - '0', 0, carry));

            ++rita;
        }
        while(ritb != b.rend())
        {
            bnum.push_front(addBinary_(*ritb - '0', 0, carry));

            ++ritb;
        }
        if(carry) bnum.push_front(1);

        string res;
        for(const auto& e : bnum) res += (e + '0');

        return res;
    }
};