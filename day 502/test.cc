/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2024-04-12 14:18:24
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2024-04-12 14:18:46
 * @FilePath: \every-little-progress\day 502\test.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */


// 438. 找到字符串中所有字母异位词
// https://leetcode.cn/problems/find-all-anagrams-in-a-string/description/
// 给定两个字符串 s 和 p，找到 s 中所有 p 的 异位词 的子串，返回这些子串的起始索引。不考虑答案输出的顺序。

// 异位词 指由相同字母重排列形成的字符串（包括相同的字符串）。

 

// 示例 1:

// 输入: s = "cbaebabacd", p = "abc"
// 输出: [0,6]
// 解释:
// 起始索引等于 0 的子串是 "cba", 它是 "abc" 的异位词。
// 起始索引等于 6 的子串是 "bac", 它是 "abc" 的异位词。
//  示例 2:

// 输入: s = "abab", p = "ab"
// 输出: [0,1,2]
// 解释:
// 起始索引等于 0 的子串是 "ab", 它是 "ab" 的异位词。
// 起始索引等于 1 的子串是 "ba", 它是 "ab" 的异位词。
// 起始索引等于 2 的子串是 "ab", 它是 "ab" 的异位词。
 

// 提示:

// 1 <= s.length, p.length <= 3 * 104
// s 和 p 仅包含小写字母


class Solution {
public:
    // 在s中找能组成p的子串
    vector<int> findAnagrams(string s, string p) {
        // vector<int> hash(26, 0);
        int hash[26] = { 0 };
        for(const auto& e : p) ++hash[e - 'a']; // p字符表

        vector<int> res;
        int left = 0, right = 0, len = 0; 
        while(right < s.size())// 滑动窗口
        {
            // 入窗口
            if(0 != hash[s[right] - 'a'])
            {
                // cout<<s[right];
                ++len;
                --hash[s[right++] - 'a'];
            }
            else
            {
                // cout<<" ";
                if(len == p.size()) res.push_back(left);
                // 出窗口
                // 不断回收字符直至回收完或者hash[s[right] - 'a']回收到字符
                while(left < right && 0 == hash[s[right] - 'a']) ++hash[s[left++] - 'a']; 

                len = right - left; // 更新长度
                if(0 == hash[s[right] - 'a']) left = ++right; // 碰到不在p中的字符则越过
            }
        }
        if(len == p.size()) res.push_back(left);

        return res;
    }
};