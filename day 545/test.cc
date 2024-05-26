/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2024-05-26 18:21:15
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2024-05-26 18:21:37
 * @FilePath: \every-little-progress\day 545\test.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */


// 面试题 01.02. 判定是否互为字符重排
// https://leetcode.cn/problems/check-permutation-lcci/description/
// 给定两个由小写字母组成的字符串 s1 和 s2，请编写一个程序，确定其中一个字符串的字符重新排列后，能否变成另一个字符串。

// 示例 1：

// 输入: s1 = "abc", s2 = "bca"
// 输出: true 
// 示例 2：

// 输入: s1 = "abc", s2 = "bad"
// 输出: false
// 说明：

// 0 <= len(s1) <= 100 
// 0 <= len(s2) <= 100 


class Solution {
public:
    bool CheckPermutation(string s1, string s2) {
        if(s1.length() != s2.length()) return false;
        int hash[26] = { 0 };
        for(const auto& e : s1) ++hash[e - 'a'];
        for(const auto& e : s2) if(--hash[e - 'a'] < 0) return false;
        for(const auto& e : hash) if(e != 0) return false;
        return true;
    }
};



// class Solution {
// public:
//     bool CheckPermutation(string s1, string s2) {
//         int hash1[26] = { 0 };
//         int hash2[26] = { 0 };
//         for(const auto& e : s1) ++hash1[e - 'a'];
//         for(const auto& e : s2) ++hash2[e - 'a'];
//         for(int i = 0;i < 26;++i) if(hash1[i] != hash2[i]) return false;
//         return true;
//     }
// };

// class Solution {
// public:
//     bool CheckPermutation(string s1, string s2) {
//         int hash1[128] = { 0 };
//         int hash2[128] = { 0 };
//         for(const auto& e : s1) ++hash1[e];
//         for(const auto& e : s2) ++hash2[e];
//         for(int i = 'a';i <= 'z';++i) if(hash1[i] != hash2[i]) return false;
//         return true;
//     }
// };

