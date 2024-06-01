/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2024-06-01 23:05:12
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2024-06-01 23:05:44
 * @FilePath: \every-little-progress\day 550\test.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */


// 5. 最长回文子串
// https://leetcode.cn/problems/longest-palindromic-substring/description/
// 给你一个字符串 s，找到 s 中最长的 
// 回文
 
// 子串
// 。

 

// 示例 1：

// 输入：s = "babad"
// 输出："bab"
// 解释："aba" 同样是符合题意的答案。
// 示例 2：

// 输入：s = "cbbd"
// 输出："bb"
 

// 提示：

// 1 <= s.length <= 1000
// s 仅由数字和英文字母组成


class Solution {
public:
    // 中心扩展算法
    string longestPalindrome(string s) {
        // 1.固定一个中心点 
        // 2.从中心点开始，向两边扩展 注意奇数和偶数长度子串都要考虑

        int begin = 0, maxL = -1, sz = s.size();
        for(int i = 0;i < sz;++i)
        {
            int l = i, r = i;
            while(l >= 0 && s[l] == s[i]) --l;
            while(r < sz && s[r] == s[i]) ++r;
            while(l >= 0 && r < sz)
            {
                if(s[l] != s[r]) break;
                --l;
                ++r;
            }
            if(maxL < r - l - 1)
            {
                begin = l + 1;
                maxL = r - l - 1;
            }
        }

        return s.substr(begin, maxL);
    }
};

