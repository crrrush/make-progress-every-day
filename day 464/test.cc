/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2024-03-02 12:31:07
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2024-03-02 12:31:33
 * @FilePath: \every-little-progress\day 464\test.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */


// 2414. 最长的字母序连续子字符串的长度
// https://leetcode.cn/problems/length-of-the-longest-alphabetical-continuous-substring/description/
// 字母序连续字符串 是由字母表中连续字母组成的字符串。换句话说，字符串 "abcdefghijklmnopqrstuvwxyz" 的任意子字符串都是 字母序连续字符串 。

// 例如，"abc" 是一个字母序连续字符串，而 "acb" 和 "za" 不是。
// 给你一个仅由小写英文字母组成的字符串 s ，返回其 最长 的 字母序连续子字符串 的长度。

 

// 示例 1：

// 输入：s = "abacaba"
// 输出：2
// 解释：共有 4 个不同的字母序连续子字符串 "a"、"b"、"c" 和 "ab" 。
// "ab" 是最长的字母序连续子字符串。
// 示例 2：

// 输入：s = "abcde"
// 输出：5
// 解释："abcde" 是最长的字母序连续子字符串。
 

// 提示：

// 1 <= s.length <= 105
// s 由小写英文字母组成


class Solution {
public:
    int longestContinuousSubstring(string s) {
        char lastc = 0;
        int cnt = -1;
        int max = -1;
        for(const auto& e : s)
        {
            if(e != lastc + 1)
            {
                if(cnt > max) max = cnt;
                lastc = e;
                cnt = 1;
            }
            else
            {
                ++cnt;
                lastc = e;
            }
        }
        if(cnt > max) max = cnt;
        return max;
    }
};