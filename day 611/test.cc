/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2024-08-04 11:43:16
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2024-08-04 11:43:48
 * @FilePath: \every-little-progress\day 611\test.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */


// 1137. 第 N 个泰波那契数
// https://leetcode.cn/problems/n-th-tribonacci-number/description/
// 泰波那契序列 Tn 定义如下： 

// T0 = 0, T1 = 1, T2 = 1, 且在 n >= 0 的条件下 Tn+3 = Tn + Tn+1 + Tn+2

// 给你整数 n，请返回第 n 个泰波那契数 Tn 的值。

 

// 示例 1：

// 输入：n = 4
// 输出：4
// 解释：
// T_3 = 0 + 1 + 1 = 2
// T_4 = 1 + 1 + 2 = 4
// 示例 2：

// 输入：n = 25
// 输出：1389537
 

// 提示：

// 0 <= n <= 37
// 答案保证是一个 32 位整数，即 answer <= 2^31 - 1。


class Solution {
public:
    int tribonacci(int n) {
        if(0 == n) return 0;
        // 空间优化
        int dp[4];
        dp[0] = 0;
        dp[1] = dp[2] = dp[3] = 1;
        for(int i = 2;i < n;++i)
        {
            dp[3] = dp[0] + dp[1] + dp[2];
            dp[0] = dp[1];
            dp[1] = dp[2];
            dp[2] = dp[3];
        }
        return dp[3];
    }
};


// class Solution {
// public:
//     int tribonacci(int n) {
//         int dp[38];
//         dp[0] = 0;
//         dp[1] = dp[2] = 1;
//         for(int i = 2;i < 37;++i) dp[i + 1] = dp[i] + dp[i - 1] + dp[i -2];
//         return dp[n];
//     }
// };

// class Solution {
//     static int dp[38];
//     void init()
//     {
//         if(0 != dp[1]) return;
//         dp[0] = 0;
//         dp[1] = dp[2] = 1;
//         for(int i = 2;i < 37;++i) dp[i + 1] = dp[i] + dp[i - 1] + dp[i -2];
//     }
// public:
//     int tribonacci(int n) {
//         init();
//         return dp[n];
//     }
// };

// int Solution::dp[38] = { 0 };
