/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2024-09-10 23:55:13
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2024-09-10 23:55:37
 * @FilePath: \every-little-progress\day 643\test.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */


// 467. 环绕字符串中唯一的子字符串
// https://leetcode.cn/problems/unique-substrings-in-wraparound-string/submissions/563536838/
// 定义字符串 base 为一个 "abcdefghijklmnopqrstuvwxyz" 无限环绕的字符串，所以 base 看起来是这样的：

// "...zabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcd....".
// 给你一个字符串 s ，请你统计并返回 s 中有多少 不同非空子串 也在 base 中出现。

 

// 示例 1：

// 输入：s = "a"
// 输出：1
// 解释：字符串 s 的子字符串 "a" 在 base 中出现。
// 示例 2：

// 输入：s = "cac"
// 输出：2
// 解释：字符串 s 有两个子字符串 ("a", "c") 在 base 中出现。
// 示例 3：

// 输入：s = "zab"
// 输出：6
// 解释：字符串 s 有六个子字符串 ("z", "a", "b", "za", "ab", and "zab") 在 base 中出现。
 

// 提示：

// 1 <= s.length <= 105
// s 由小写英文字母组成

class Solution {
    bool is_connect(const char& ch1, const char& ch2)
    {
        int a = ch2 - ch1;
        if(a != 1 && a != -25) return false;
        return true;
    }
public:
    int findSubstringInWraproundString(string s) {
        int hash[26] = { 0 };
        const int n = s.size();
        s = ' ' + s;
        vector<int> dp(n + 1, 1);

        int ret = 0;
        for(int i = 1;i <= n;++i)
        {
            if(is_connect(s[i - 1], s[i])) 
                dp[i] = 1 + dp[i - 1];
            else
                dp[i] = 1;

            hash[s[i] - 'a'] = max(dp[i], hash[s[i] - 'a']);
        }

        for(auto e : hash) ret += e;

        return ret;
    }
};

