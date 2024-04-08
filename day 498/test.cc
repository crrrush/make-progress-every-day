/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2024-04-08 18:02:23
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2024-04-08 18:02:53
 * @FilePath: \every-little-progress\day 498\test.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */


// 3. 无重复字符的最长子串
// https://leetcode.cn/problems/longest-substring-without-repeating-characters/description/
// 给定一个字符串 s ，请你找出其中不含有重复字符的 最长
// 子串
//  的长度。

 

// 示例 1:

// 输入: s = "abcabcbb"
// 输出: 3 
// 解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
// 示例 2:

// 输入: s = "bbbbb"
// 输出: 1
// 解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
// 示例 3:

// 输入: s = "pwwkew"
// 输出: 3
// 解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
//      请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
 

// 提示：

// 0 <= s.length <= 5 * 104
// s 由英文字母、数字、符号和空格组成

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int hash[128] = { 0 };
        int left = 0, right = 0, maxL = 0;
        while(right < s.size())
        {
            while(right < s.size() && 0 == hash[s[right]]) hash[s[right++]] = 1;

            if(maxL < right - left) maxL = right - left;

            while(left < right && s[left] != s[right]) hash[s[left++]] = 0;
            hash[s[left++]] = 0;
        }

        return maxL;
    }
};

// class Solution {
// public:
//     int lengthOfLongestSubstring(string s) {
//         unordered_set<char> us;
//         int left = 0, right = 0, maxL = 0;
//         while(right < s.size())
//         {
//             while(right < s.size() && us.find(s[right]) == us.end()) us.insert(s[right++]);
//             // cout<<left<<"~"<<right<<" ";

//             if(maxL < right - left) maxL = right - left;

//             while(left < right && s[left] != s[right]) us.erase(s[left++]);
//             us.erase(s[left++]);
//         }

//         return maxL;
//     }
// };