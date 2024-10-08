/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2024-08-17 15:49:13
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2024-08-17 15:49:37
 * @FilePath: \every-little-progress\day 622\test.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */


// 931. 下降路径最小和
// https://leetcode.cn/problems/minimum-falling-path-sum/description/
// 给你一个 n x n 的 方形 整数数组 matrix ，请你找出并返回通过 matrix 的下降路径 的 最小和 。

// 下降路径 可以从第一行中的任何元素开始，并从每一行中选择一个元素。在下一行选择的元素和当前行所选元素最多相隔一列（即位于正下方或者沿对角线向左或者向右的第一个元素）。具体来说，位置 (row, col) 的下一个元素应当是 (row + 1, col - 1)、(row + 1, col) 或者 (row + 1, col + 1) 。

 

// 示例 1：



// 输入：matrix = [[2,1,3],[6,5,4],[7,8,9]]
// 输出：13
// 解释：如图所示，为和最小的两条下降路径
// 示例 2：



// 输入：matrix = [[-19,57],[-40,-5]]
// 输出：-59
// 解释：如图所示，为和最小的下降路径
 

// 提示：

// n == matrix.length == matrix[i].length
// 1 <= n <= 100
// -100 <= matrix[i][j] <= 100

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int dp[102][102] = { 0 };

        // 1. 初始化
        for(int i = 1;i <= n;++i) dp[i][n + 1] = dp[i][0] = INT_MAX;

        // 2. 状态转移方程
        for(int i = 1;i <= n;++i) for(int j = 1;j <= n;++j) dp[i][j] = min(min(dp[i - 1][j - 1], dp[i - 1][j + 1]), dp[i - 1][j]) + matrix[i - 1][j - 1];

        int ret = INT_MAX;
        for(int i = 1;i <= n;++i) ret = min(ret, dp[n][i]);
        return ret;
    }
};

