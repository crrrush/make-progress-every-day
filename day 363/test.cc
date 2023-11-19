/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2023-11-19 14:48:40
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2023-11-19 14:49:18
 * @FilePath: \every-little-progress\day 363\test.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */



// 1433. 检查一个字符串是否可以打破另一个字符串
// https://leetcode.cn/problems/check-if-a-string-can-break-another-string/description/
// 给你两个字符串 s1 和 s2 ，它们长度相等，请你检查是否存在一个 s1  的排列可以打破 s2 的一个排列，或者是否存在一个 s2 的排列可以打破 s1 的一个排列。

// 字符串 x 可以打破字符串 y （两者长度都为 n ）需满足对于所有 i（在 0 到 n - 1 之间）都有 x[i] >= y[i]（字典序意义下的顺序）。

 

// 示例 1：

// 输入：s1 = "abc", s2 = "xya"
// 输出：true
// 解释："ayx" 是 s2="xya" 的一个排列，"abc" 是字符串 s1="abc" 的一个排列，且 "ayx" 可以打破 "abc" 。
// 示例 2：

// 输入：s1 = "abe", s2 = "acd"
// 输出：false 
// 解释：s1="abe" 的所有排列包括："abe"，"aeb"，"bae"，"bea"，"eab" 和 "eba" ，s2="acd" 的所有排列包括："acd"，"adc"，"cad"，"cda"，"dac" 和 "dca"。然而没有任何 s1 的排列可以打破 s2 的排列。也没有 s2 的排列能打破 s1 的排列。
// 示例 3：

// 输入：s1 = "leetcodee", s2 = "interview"
// 输出：true
 

// 提示：

// s1.length == n
// s2.length == n
// 1 <= n <= 10^5
// 所有字符串都只包含小写英文字母。

class Solution {
public:
    bool checkIfCanBreak(string s1, string s2) {
        sort(s1.rbegin(), s1.rend());
        sort(s2.rbegin(), s2.rend());

        bool flag1 = true;
        bool flag2 = true;
        auto rit1 = s1.rbegin();
        auto rit2 = s2.rbegin();
        while(rit1 != s1.rend() && rit2 != s2.rend())
        {
            if(*rit1 < *rit2) flag1 = false;
            if(*rit2 < *rit1) flag2 = false;

            ++rit1;
            ++rit2;
        }

        return flag1 || flag2;
    }
};
