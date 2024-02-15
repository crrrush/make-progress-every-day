/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2024-02-15 14:59:40
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2024-02-15 15:00:04
 * @FilePath: \every-little-progress\day 449\test.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */


// 2165. 重排数字的最小值
// https://leetcode.cn/problems/smallest-value-of-the-rearranged-number/description/
// 给你一个整数 num 。重排 num 中的各位数字，使其值 最小化 且不含 任何 前导零。

// 返回不含前导零且值最小的重排数字。

// 注意，重排各位数字后，num 的符号不会改变。

 

// 示例 1：

// 输入：num = 310
// 输出：103
// 解释：310 中各位数字的可行排列有：013、031、103、130、301、310 。
// 不含任何前导零且值最小的重排数字是 103 。
// 示例 2：

// 输入：num = -7605
// 输出：-7650
// 解释：-7605 中各位数字的部分可行排列为：-7650、-6705、-5076、-0567。
// 不含任何前导零且值最小的重排数字是 -7650 。
 

// 提示：

// -1015 <= num <= 1015


class Solution {
public:
    long long smallestNumber(long long num) {
        multiset<char> s;
        bool neg = false;
        if(num < 0)
        {
            num = -num;
            neg = true;
        }

        string n = to_string(num);
        for(const auto& e : n) s.insert(e);
        string res;
        if(!neg)
        {
            for(const auto& e : s) res += e;
            if(res.front() == '0') for(int i = 1;i < res.size() && res[0] == '0';++i) if(res[i] != '0') swap(res[0], res[i]);
            return stol(res);
        }
        else
        {
            auto rit = s.rbegin();
            while(rit != s.rend())
            {
                res += *rit;
                ++rit;
            }
            return -stol(res);
        }

        return 0;
    }
};