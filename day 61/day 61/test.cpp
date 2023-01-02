﻿#define _CRT_SECURE_NO_WARNINGS

//
//17. 电话号码的字母组合
//https ://leetcode.cn/problems/letter-combinations-of-a-phone-number/
//
//给定一个仅包含数字 2 - 9 的字符串，返回所有它能表示的字母组合。答案可以按 任意顺序 返回。
//
//给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
//
//
//
//示例 1：
//
//输入：digits = "23"
//输出：["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"]
//
//示例 2：
//
//输入：digits = ""
//输出：[]
//
//示例 3：
//
//输入：digits = "2"
//输出：["a", "b", "c"]
//
//
//
//提示：
//
//0 <= digits.length <= 4
//digits[i] 是范围['2', '9'] 的一个数字。
//




class Solution {
    void pickletter(vector<string>& vs, string in, string& d, int i)
    {
        if (i == d.size())
        {
            vs.push_back(in);
            return;
        }

        static const char* pchar[8] = { "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };

        const char* p = pchar[d[i] - '2'];
        while (*p)
        {
            in.push_back(*p);
            pickletter(vs, in, d, i + 1);
            in.pop_back();
            ++p;
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;//定义答案
        if (digits == "")
            return res;

        string in("");//用于插入
        pickletter(res, in, digits, 0);

        return res;
    }
};