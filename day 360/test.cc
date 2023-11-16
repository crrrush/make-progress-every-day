/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2023-11-16 12:12:39
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2023-11-16 12:13:19
 * @FilePath: \every-little-progress\day 360\test.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */



// 917. 仅仅反转字母
// https://leetcode.cn/problems/reverse-only-letters/description/
// 给你一个字符串 s ，根据下述规则反转字符串：

// 所有非英文字母保留在原有位置。
// 所有英文字母（小写或大写）位置反转。
// 返回反转后的 s 。

 

// 示例 1：

// 输入：s = "ab-cd"
// 输出："dc-ba"
// 示例 2：

// 输入：s = "a-bC-dEf-ghIj"
// 输出："j-Ih-gfE-dCba"
// 示例 3：

// 输入：s = "Test1ng-Leet=code-Q!"
// 输出："Qedo1ct-eeLg=ntse-T!"
 

// 提示

// 1 <= s.length <= 100
// s 仅由 ASCII 值在范围 [33, 122] 的字符组成
// s 不含 '\"' 或 '\\'


class Solution {
public:
    string reverseOnlyLetters(string s) {
        auto left = s.begin();
        auto right = s.end() - 1;
        while(left < right)
        {
            if(isalpha(*right) && isalpha(*left))
            {
                swap(*left++, *right--);
            }
            else if(!isalpha(*right))
                --right;
            else if(!isalpha(*left))
                ++left;
            
        }
        return s;
    }
};