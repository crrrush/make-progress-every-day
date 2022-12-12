﻿#define _CRT_SECURE_NO_WARNINGS

//
//387. 字符串中的第一个唯一字符
//https ://leetcode.cn/problems/first-unique-character-in-a-string/
//
//给定一个字符串 s ，找到 它的第一个不重复的字符，并返回它的索引 。如果不存在，则返回 - 1 。
//
//
//
//示例 1：
//
//输入 : s = "leetcode"
//输出 : 0
//
//示例 2 :
//
//    输入 : s = "loveleetcode"
//    输出 : 2
//
//    示例 3 :
//
//    输入 : s = "aabb"
//    输出 : -1
//
//
//
//提示:
//
//1 <= s.length <= 105
//s 只包含小写字母
//


class Solution {
public:
    int firstUniqChar(string s) {
        int count[26] = { 0 };
        for (int i = 0; i < s.length(); ++i)
        {
            count[s[i] - 'a']++;
        }
        for (int i = 0; i < s.length(); ++i)
        {
            if (count[s[i] - 'a'] == 1)
            {
                return s.find(s[i]);
            }
        }
        return -1;
    }
};