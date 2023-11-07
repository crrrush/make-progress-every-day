/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2023-11-07 18:34:53
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2023-11-07 18:35:31
 * @FilePath: \every-little-progress\day 351\test.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */



// 2042. 检查句子中的数字是否递增
// https://leetcode.cn/problems/check-if-numbers-are-ascending-in-a-sentence/description/
// 句子是由若干 token 组成的一个列表，token 间用 单个 空格分隔，句子没有前导或尾随空格。每个 token 要么是一个由数字 0-9 组成的不含前导零的 正整数 ，要么是一个由小写英文字母组成的 单词 。

// 示例，"a puppy has 2 eyes 4 legs" 是一个由 7 个 token 组成的句子："2" 和 "4" 是数字，其他像 "puppy" 这样的 tokens 属于单词。
// 给你一个表示句子的字符串 s ，你需要检查 s 中的 全部 数字是否从左到右严格递增（即，除了最后一个数字，s 中的 每个 数字都严格小于它 右侧 的数字）。

// 如果满足题目要求，返回 true ，否则，返回 false 。

 

// 示例 1：

// example-1

// 输入：s = "1 box has 3 blue 4 red 6 green and 12 yellow marbles"
// 输出：true
// 解释：句子中的数字是：1, 3, 4, 6, 12 。
// 这些数字是按从左到右严格递增的 1 < 3 < 4 < 6 < 12 。
// 示例 2：

// 输入：s = "hello world 5 x 5"
// 输出：false
// 解释：句子中的数字是：5, 5 。这些数字不是严格递增的。
// 示例 3：

// example-3

// 输入：s = "sunset is at 7 51 pm overnight lows will be in the low 50 and 60 s"
// 输出：false
// 解释：s 中的数字是：7, 51, 50, 60 。这些数字不是严格递增的。
// 示例 4：

// 输入：s = "4 5 11 26"
// 输出：true
// 解释：s 中的数字是：4, 5, 11, 26 。
// 这些数字是按从左到右严格递增的：4 < 5 < 11 < 26 。
 

// 提示：

// 3 <= s.length <= 200
// s 由小写英文字母、空格和数字 0 到 9 组成（包含 0 和 9）
// s 中数字 token 的数目在 2 和 100 之间（包含 2 和 100）
// s 中的 token 之间由单个空格分隔
// s 中至少有 两个 数字
// s 中的每个数字都是一个 小于 100 的 正 数，且不含前导零
// s 不含前导或尾随空格

class Solution {
public:
    bool areNumbersAscending(string s) {
        int num = -1;
        for(auto it = s.begin();it != s.end();++it)
        {
            if(*it >= '0' && *it <= '9')
            {
                auto end = it;
                while(end != s.end() && *end >= '0' && *end <= '9') ++end;
                string tmp(it, end);
                int n = stoi(tmp);
                if(n <= num) return false;
                num = n;
                it = end;
                if(it == s.end()) break;
            }
        }

        return true;
    }
};