/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2024-08-29 23:48:47
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2024-08-29 23:49:15
 * @FilePath: \every-little-progress\day 632\test.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */

// 309. 买卖股票的最佳时机含冷冻期
// https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-with-cooldown/description/
// 给定一个整数数组prices，其中第  prices[i] 表示第 i 天的股票价格 。​

// 设计一个算法计算出最大利润。在满足以下约束条件下，你可以尽可能地完成更多的交易（多次买卖一支股票）:

// 卖出股票后，你无法在第二天买入股票 (即冷冻期为 1 天)。
// 注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。

 

// 示例 1:

// 输入: prices = [1,2,3,0,2]
// 输出: 3 
// 解释: 对应的交易状态为: [买入, 卖出, 冷冻期, 买入, 卖出]
// 示例 2:

// 输入: prices = [1]
// 输出: 0
 

// 提示：

// 1 <= prices.length <= 5000
// 0 <= prices[i] <= 1000


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        const int n = prices.size();
        if(1 == n) return 0;
        
        int dp[50002][3] = { 0 };
        // 0 买入
        // 1 可交易状态 已买入未卖出
        // 2 冻结
        dp[0][0] = -prices[0];
        // dp[0][1] = dp[0][2] = 0;

        for(int i = 1;i <= n;++i)
        {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - prices[i - 1]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][2]);
            dp[i][2] = dp[i - 1][0] + prices[i - 1];
        }

        return max(dp[n][1], dp[n][2]);
    }
};

// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         const int n = prices.size();
//         if(1 == n) return 0;
        
//         int dp[50002][5] = { 0 };
//         // 0 买入
//         // 1 卖出 卖出需初始化
//         dp[0][0] = dp[0][3] = -prices[0];
//         // 2 冻结
//         // 3 不做买卖且已买入
//         // 4 不做买卖且未买入
//         for(int i = 1;i <= n;++i)
//         {
//             // 买入
//             dp[i][0] = max(dp[i - 1][4], dp[i - 1][2]) - prices[i - 1];
//             // 卖出
//             dp[i][1] = max(dp[i - 1][0], dp[i - 1][3]) + prices[i - 1];
//             // 冻结
//             // dp[i][2] = dp[i - 1][1];
//             dp[i][2] = max(dp[i - 1][1], dp[i - 1][4]);
//             // 不做买卖且已买入
//             dp[i][3] = max(dp[i - 1][0], dp[i - 1][3]);
//             // 不做买卖且未买入
//             // dp[i][4] = max(dp[i - 1][2], dp[i - 1][4]);
//             dp[i][4] = max(max(dp[i - 1][2], dp[i - 1][4]),  dp[i - 1][1]);
//         }

//         return max(
//             max(dp[n][0], dp[n][1]),
//             max(dp[n][2], dp[n][3])
//             );
//     }
// };

