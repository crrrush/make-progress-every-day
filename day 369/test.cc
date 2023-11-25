/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2023-11-25 14:56:31
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2023-11-25 14:56:43
 * @FilePath: \every-little-progress\day 369\test.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */



// 28. 找出字符串中第一个匹配项的下标
// https://leetcode.cn/problems/find-the-index-of-the-first-occurrence-in-a-string/description/
// 给你两个字符串 haystack 和 needle ，请你在 haystack 字符串中找出 needle 字符串的第一个匹配项的下标（下标从 0 开始）。如果 needle 不是 haystack 的一部分，则返回  -1 。

 

// 示例 1：

// 输入：haystack = "sadbutsad", needle = "sad"
// 输出：0
// 解释："sad" 在下标 0 和 6 处匹配。
// 第一个匹配项的下标是 0 ，所以返回 0 。
// 示例 2：

// 输入：haystack = "leetcode", needle = "leeto"
// 输出：-1
// 解释："leeto" 没有在 "leetcode" 中出现，所以返回 -1 。
 

// 提示：

// 1 <= haystack.length, needle.length <= 104
// haystack 和 needle 仅由小写英文字符组成

class Solution {
public:
    int strStr(string haystack, string needle) {
        for(int i = 0;i + needle.size() <= haystack.size();++i)
        {
            string tmp(&haystack[i], needle.size());
            if(tmp == needle) return i;
        }
        return -1;
    }
};