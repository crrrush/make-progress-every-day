/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2024-05-03 13:29:13
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2024-05-03 13:29:47
 * @FilePath: \every-little-progress\day 522\test.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */


// 面试题 01.01. 判定字符是否唯一
// https://leetcode.cn/problems/is-unique-lcci/description/
// 实现一个算法，确定一个字符串 s 的所有字符是否全都不同。

// 示例 1：

// 输入: s = "leetcode"
// 输出: false 
// 示例 2：

// 输入: s = "abc"
// 输出: true
// 限制：

// 0 <= len(s) <= 100 
// s[i]仅包含小写字母
// 如果你不使用额外的数据结构，会很加分。


class Solution {
public:
    bool isUnique(string astr) {
        if(astr.length() > 26) return false;
        int bit_set = 0;
        for(const auto& e : astr)
        {
            int tmp = 1 << (e - 'a');
            if(bit_set & tmp) return false;
            bit_set |= tmp;
        }
        return true;
    }
};

// class Solution {
// public:
//     bool isUnique(string astr) {
//         int hash[26] = { 0 };
//         for(const auto& e : astr) if(++hash[e - 'a'] > 1) return false;
//         return true;
//     }
// };

