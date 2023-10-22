/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2023-10-22 12:25:42
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2023-10-22 12:26:09
 * @FilePath: \every-little-progress\day 335\test.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */


// 1876. 长度为三且各字符不同的子字符串
// https://leetcode.cn/problems/substrings-of-size-three-with-distinct-characters/description/
// 如果一个字符串不含有任何重复字符，我们称这个字符串为 好 字符串。

// 给你一个字符串 s ，请你返回 s 中长度为 3 的 好子字符串 的数量。

// 注意，如果相同的好子字符串出现多次，每一次都应该被记入答案之中。

// 子字符串 是一个字符串中连续的字符序列。

 

// 示例 1：

// 输入：s = "xyzzaz"
// 输出：1
// 解释：总共有 4 个长度为 3 的子字符串："xyz"，"yzz"，"zza" 和 "zaz" 。
// 唯一的长度为 3 的好子字符串是 "xyz" 。
// 示例 2：

// 输入：s = "aababcabc"
// 输出：4
// 解释：总共有 7 个长度为 3 的子字符串："aab"，"aba"，"bab"，"abc"，"bca"，"cab" 和 "abc" 。
// 好子字符串包括 "abc"，"bca"，"cab" 和 "abc" 。
 

// 提示：

// 1 <= s.length <= 100
// s​​​​​​ 只包含小写英文字母。

class Solution {
public:
    bool is_good(const string& s) { return s[0] != s[1] && s[1] != s[2] && s[0] != s[2]; }
    void move(string& s, char c)
    {
        s[0] = s[1];
        s[1] = s[2];
        s[2] = c;
    }

    int countGoodSubstrings(string s) {
        if(s.length() < 3) return 0;

        string gs(s.begin(), s.begin() + 3);
        int cnt = 0;
        if(is_good(gs)) ++cnt;
        for(int i = 1;i < s.length();++i)
        {
            move(gs, s[i]);
            if(is_good(gs)) ++cnt;
        }

        return cnt;
    }
};