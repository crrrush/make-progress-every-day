/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2024-05-09 23:25:13
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2024-05-09 23:25:44
 * @FilePath: \every-little-progress\day 528\test.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */


// 1576. 替换所有的问号
// https://leetcode.cn/problems/replace-all-s-to-avoid-consecutive-repeating-characters/description/
// 给你一个仅包含小写英文字母和 '?' 字符的字符串 s，请你将所有的 '?' 转换为若干小写字母，使最终的字符串不包含任何 连续重复 的字符。

// 注意：你 不能 修改非 '?' 字符。

// 题目测试用例保证 除 '?' 字符 之外，不存在连续重复的字符。

// 在完成所有转换（可能无需转换）后返回最终的字符串。如果有多个解决方案，请返回其中任何一个。可以证明，在给定的约束条件下，答案总是存在的。

 

// 示例 1：

// 输入：s = "?zs"
// 输出："azs"
// 解释：该示例共有 25 种解决方案，从 "azs" 到 "yzs" 都是符合题目要求的。只有 "z" 是无效的修改，因为字符串 "zzs" 中有连续重复的两个 'z' 。
// 示例 2：

// 输入：s = "ubv?w"
// 输出："ubvaw"
// 解释：该示例共有 24 种解决方案，只有替换成 "v" 和 "w" 不符合题目要求。因为 "ubvvw" 和 "ubvww" 都包含连续重复的字符。
 

// 提示：

// 1 <= s.length <= 100

// s 仅包含小写英文字母和 '?' 字符


class Solution {
    char next(const char& ch) { return ((ch - 'a' + 1) % 26) + 'a'; }
    char prev(const char& ch) { return ((ch - 'a' + 25) % 26) + 'a'; }
public:
    string modifyString(string& s) {
        for(int i = 0;i < s.length();++i)
        {
            if(s[i] == '?')
            {
                if(i == 0)
                {
                    if(i + 1 < s.length() && s[i + 1] != '?') s[i] = prev(s[i + 1]);
                    else s[i] = 'a';
                }
                else if(i == s.length() - 1)
                {
                    // if(i != 0) s[i] = next(s[i - 1]);
                    s[i] = next(s[i - 1]);
                }
                else
                {
                    if(s[i + 1] == '?') s[i] = next(s[i - 1]);
                    else if(s[i + 1] == next(s[i - 1])) s[i] = next(s[i + 1]);
                    else s[i] = next(s[i - 1]);
                }
            }
        }
        return s;
    }
};


