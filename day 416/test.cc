/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2024-01-12 16:05:58
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2024-01-12 16:06:37
 * @FilePath: \every-little-progress\day 416\test.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */


// LCR 019. 验证回文串 II
// https://leetcode.cn/problems/RQku0D/description/

// 给定一个非空字符串 s，请判断如果 最多 从字符串中删除一个字符能否得到一个回文字符串。

 

// 示例 1:

// 输入: s = "aba"
// 输出: true
// 示例 2:

// 输入: s = "abca"
// 输出: true
// 解释: 可以删除 "c" 字符 或者 "b" 字符
// 示例 3:

// 输入: s = "abc"
// 输出: false
 

// 提示:

// 1 <= s.length <= 105
// s 由小写英文字母组成
 

// 注意：本题与主站 680 题相同： https://leetcode-cn.com/problems/valid-palindrome-ii/

class Solution {
    bool is_reverse(const string& s, bool left, bool right)
    {
        int l = 0, r = s.size() - 1;
        while(l < r)
        {
            if(s[l] != s[r])
            {
                if(left)
                {
                    left = false;
                    ++l;
                }
                else if(right)
                {
                    right = false;
                    --r;
                }
                else
                    return false;
            }
            else
            {
                ++l;
                --r;
            }
        }
        return true;
    }
public:
    bool validPalindrome(string s) {
        return is_reverse(s, true, false) || is_reverse(s, false, true);
    }
};