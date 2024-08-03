/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2024-08-03 11:55:49
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2024-08-03 11:56:13
 * @FilePath: \every-little-progress\day 610\test.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */


// 746. 使用最小花费爬楼梯
// https://leetcode.cn/problems/min-cost-climbing-stairs/description/
// 给你一个整数数组 cost ，其中 cost[i] 是从楼梯第 i 个台阶向上爬需要支付的费用。一旦你支付此费用，即可选择向上爬一个或者两个台阶。

// 你可以选择从下标为 0 或下标为 1 的台阶开始爬楼梯。

// 请你计算并返回达到楼梯顶部的最低花费。

 

// 示例 1：

// 输入：cost = [10,15,20]
// 输出：15
// 解释：你将从下标为 1 的台阶开始。
// - 支付 15 ，向上爬两个台阶，到达楼梯顶部。
// 总花费为 15 。
// 示例 2：

// 输入：cost = [1,100,1,1,1,100,1,1,100,1]
// 输出：6
// 解释：你将从下标为 0 的台阶开始。
// - 支付 1 ，向上爬两个台阶，到达下标为 2 的台阶。
// - 支付 1 ，向上爬两个台阶，到达下标为 4 的台阶。
// - 支付 1 ，向上爬两个台阶，到达下标为 6 的台阶。
// - 支付 1 ，向上爬一个台阶，到达下标为 7 的台阶。
// - 支付 1 ，向上爬两个台阶，到达下标为 9 的台阶。
// - 支付 1 ，向上爬一个台阶，到达楼梯顶部。
// 总花费为 6 。
 

// 提示：

// 2 <= cost.length <= 1000
// 0 <= cost[i] <= 999

class Solution {
public:
    // 动态规划
    int minCostClimbingStairs(vector<int>& cost) {
        // int dp[1001];
        static int dp[1001];
        int len = cost.size();
        dp[0] = cost[0];
        dp[1] = cost[1];
        for(int i = 2;i < len;++i) dp[i] = cost[i] + min(dp[i- 1], dp[i - 2]);
        return min(dp[len - 1], dp[len - 2]);
    }
};

// 记忆化搜索 dfs
// class Solution {
//     int memo[1001];

//     int dfs(vector<int>& cost, int i)
//     {
//         if(i >= 0 && -1 != memo[i]) return memo[i];
//         memo[i] = cost[i] + min(dfs(cost, i - 1), dfs(cost, i - 2));
//         return memo[i];
//     }
// public:
//     int minCostClimbingStairs(vector<int>& cost) {
//         for(int i = 0;i < 1001;++i) memo[i] = -1;
//         memo[0] = cost[0];
//         memo[1] = cost[1];
//         return min(dfs(cost, cost.size() - 1), dfs(cost, cost.size() - 2));
//     }
// };
