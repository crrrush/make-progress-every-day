/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2024-04-14 22:03:27
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2024-04-14 22:04:08
 * @FilePath: \every-little-progress\day 504\test.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */


// 76. 最小覆盖子串
// https://leetcode.cn/problems/minimum-window-substring/description/
// 给你一个字符串 s 、一个字符串 t 。返回 s 中涵盖 t 所有字符的最小子串。如果 s 中不存在涵盖 t 所有字符的子串，则返回空字符串 "" 。

 

// 注意：

// 对于 t 中重复字符，我们寻找的子字符串中该字符数量必须不少于 t 中该字符数量。
// 如果 s 中存在这样的子串，我们保证它是唯一的答案。
 

// 示例 1：

// 输入：s = "ADOBECODEBANC", t = "ABC"
// 输出："BANC"
// 解释：最小覆盖子串 "BANC" 包含来自字符串 t 的 'A'、'B' 和 'C'。
// 示例 2：

// 输入：s = "a", t = "a"
// 输出："a"
// 解释：整个字符串 s 是最小覆盖子串。
// 示例 3:

// 输入: s = "a", t = "aa"
// 输出: ""
// 解释: t 中两个字符 'a' 均应包含在 s 的子串中，
// 因此没有符合条件的子字符串，返回空字符串。
 

// 提示：

// m == s.length
// n == t.length
// 1 <= m, n <= 105
// s 和 t 由英文字母组成
 

// 进阶：你能设计一个在 o(m+n) 时间内解决此问题的算法吗？

class Solution {
public:
    //
    string minWindow(string s, string t) {
        if(s.size() < t.size()) return "";
        // unordered_map<char, int> hash1;
        int hash1[128] = { 0 };
        for(const auto& e : t) ++hash1[e];
        // string res;
        int begin = -1;// 起始位置

        int left = 0, right = 0, cnt = 0, minL = s.size() + 1;
        // unordered_map<char, int> hash2;
        int hash2[128] = { 0 };
        while(right < s.size())
        {
            // cout<<left<<"~"<<right<<" ";
            // 入窗
            ++hash2[s[right]];
            // if(hash1.count(s[right]) && hash2[s[right]] <= hash1[s[right]]) ++cnt;
            if(hash2[s[right]] <= hash1[s[right]]) ++cnt;

            // 出窗
            // while(left < right && 0 == hash1.count(s[left])) ++left;
            while(left < right && 0 == hash1[s[left]]) ++left;
            // while(left < right && 0 != hash1.count(s[left]) && hash2[s[left]] > hash1[s[left]]) --hash2[s[left++]];
            while(left < right && 0 != hash1[s[left]] && hash2[s[left]] > hash1[s[left]]) --hash2[s[left++]];

            while(cnt == t.size())
            {
                // cout<<tmp<<"\n";
                if(right - left + 1 < minL)
                {
                    minL = right - left + 1;
                    begin = left;
                }

                // 出窗
                if(hash2[s[left]] <= hash1[s[left]]) --cnt;
                --hash2[s[left++]];
                // while(left < right && 0 == hash1.count(s[left])) ++left; // 右移到下一个t中字符
                while(left < right && 0 == hash1[s[left]]) ++left; // 右移到下一个t中字符
            }
            
            ++right;
        }
        if(-1 == begin) return "";

        return s.substr(begin, minL);
    }
};