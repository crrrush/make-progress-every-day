#define _CRT_SECURE_NO_WARNINGS
//
//125. 验证回文串
//https ://leetcode.cn/problems/valid-palindrome/description/
//
//如果在将所有大写字符转换为小写字符、并移除所有非字母数字字符之后，短语正着读和反着读都一样。则可以认为该短语是一个 回文串 。
//
//字母和数字都属于字母数字字符。
//
//给你一个字符串 s，如果它是 回文串 ，返回 true ；否则，返回 false 。
//
//
//
//示例 1：
//
//输入 : s = "A man, a plan, a canal: Panama"
//输出：true
//解释："amanaplanacanalpanama" 是回文串。
//
//示例 2：
//
//输入：s = "race a car"
//输出：false
//解释："raceacar" 不是回文串。
//
//示例 3：
//
//输入：s = " "
//输出：true
//解释：在移除非字母数字字符之后，s 是一个空字符串 "" 。
//由于空字符串正着反着读都一样，所以是回文串。
//
//
//
//提示：
//
//1 <= s.length <= 2 * 105
//s 仅由可打印的 ASCII 字符组成



class Solution {
    void remove(string& s)
    {
        for (int i = 0; i < s.length(); ++i)
        {
            while ((s[i] < '0' || s[i] > '9') && (s[i] < 'A' || s[i] > 'Z') && (s[i] < 'a' || s[i] > 'z') && i < s.length())
                s.erase(i, 1);
            if (s[i] >= 'A' && s[i] <= 'Z')
                s[i] += 32;
        }
    }
public:
    bool isPalindrome(string s)
    {
        remove(s);
        string rs(s);
        cout << rs << endl;
        reverse(s.begin(), s.end());
        cout << s << endl;
        if (strcmp(s.c_str(), rs.c_str()) == 0)
            return true;
        else
            return false;
    }
};