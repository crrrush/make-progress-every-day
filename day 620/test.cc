/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2024-08-15 12:38:21
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2024-08-15 12:38:45
 * @FilePath: \every-little-progress\day 620\test.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */


// 63. 不同路径 II
// https://leetcode.cn/problems/unique-paths-ii/description/
// 一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为 “Start” ）。

// 机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为 “Finish”）。

// 现在考虑网格中有障碍物。那么从左上角到右下角将会有多少条不同的路径？

// 网格中的障碍物和空位置分别用 1 和 0 来表示。

 

// 示例 1：


// 输入：obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
// 输出：2
// 解释：3x3 网格的正中间有一个障碍物。
// 从左上角到右下角一共有 2 条不同的路径：
// 1. 向右 -> 向右 -> 向下 -> 向下
// 2. 向下 -> 向下 -> 向右 -> 向右
// 示例 2：


// 输入：obstacleGrid = [[0,1],[0,0]]
// 输出：1
 

// 提示：

// m == obstacleGrid.length
// n == obstacleGrid[i].length
// 1 <= m, n <= 100
// obstacleGrid[i][j] 为 0 或 1


class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        int dp[101][101] = { 0 };
        // 1. 初始化
        dp[0][1] = 1;


        // 2. 状态表示方程和填表
        for(int i = 1;i <= m;++i) for(int j = 1;j <= n;++j) if(0 == obstacleGrid[i - 1][j - 1]) dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        
        return dp[m][n];
    }
};


// class Solution {
// public:
//     int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
//         int m = obstacleGrid.size(), n = obstacleGrid[0].size();
//         int dp[101][101] = { 0 };
//         // 1. 初始化
//         for(int i = 0;i < m && 0 == obstacleGrid[i][0];++i) dp[i][0] = 1;
//         for(int j = 0;j < n && 0 == obstacleGrid[0][j];++j) dp[0][j] = 1;


//         // 2. 状态表示方程和填表
//         for(int i = 1;i < m;++i) for(int j = 1;j < n;++j) if(0 == obstacleGrid[i][j]) dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        
//         return dp[m - 1][n - 1];
//     }
// };
