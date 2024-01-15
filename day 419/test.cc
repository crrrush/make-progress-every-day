/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2024-01-15 10:56:35
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2024-01-15 10:56:39
 * @FilePath: \every-little-progress\day 419\test.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */



// 2405. 子字符串的最优划分
// https://leetcode.cn/problems/optimal-partition-of-string/description/
// 给你一个字符串 s ，请你将该字符串划分成一个或多个 子字符串 ，并满足每个子字符串中的字符都是 唯一 的。也就是说，在单个子字符串中，字母的出现次数都不超过 一次 。

// 满足题目要求的情况下，返回 最少 需要划分多少个子字符串。

// 注意，划分后，原字符串中的每个字符都应该恰好属于一个子字符串。

// 示例 1：

// 输入：s = "abacaba"
// 输出：4
// 解释：
// 两种可行的划分方法分别是 ("a","ba","cab","a") 和 ("ab","a","ca","ba") 。
// 可以证明最少需要划分 4 个子字符串。
// 示例 2：

// 输入：s = "ssssss"
// 输出：6
// 解释：
// 只存在一种可行的划分方法 ("s","s","s","s","s","s") 。
 

// 提示：

// 1 <= s.length <= 105
// s 仅由小写英文字母组成

class Solution {
public:
    int partitionString(string s) {
        vector<int> hash(26, 0);
        int cnt = 1;
        for(const auto& e : s)
        {
            if(hash[e - 'a'] != 0)
            {
                ++cnt;
                for(auto& r : hash) r = 0;
            }

            hash[e - 'a'] = 1;
        }
        return cnt;
    }
};

// class Solution {
// public:
//     int partitionString(string s) {
//         vector<int> hash(26, 0);
//         int cnt = 1;
//         for(const auto& e : s)
//         {
//             if(hash[e - 'a'] != 0)
//             {
//                 ++cnt;
//                 hash.clear();
//                 hash.resize(26,0);
//             }

//             hash[e - 'a'] = 1;
//         }
//         return cnt;
//     }
// };