/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2024-04-28 21:31:56
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2024-04-28 21:32:29
 * @FilePath: \every-little-progress\day 517\test.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */


// 1314. 矩阵区域和
// https://leetcode.cn/problems/matrix-block-sum/description/
// 给你一个 m x n 的矩阵 mat 和一个整数 k ，请你返回一个矩阵 answer ，其中每个 answer[i][j] 是所有满足下述条件的元素 mat[r][c] 的和： 

// i - k <= r <= i + k, 
// j - k <= c <= j + k 且
// (r, c) 在矩阵内。
 

// 示例 1：

// 输入：mat = [[1,2,3],[4,5,6],[7,8,9]], k = 1
// 输出：[[12,21,16],[27,45,33],[24,39,28]]
// 示例 2：

// 输入：mat = [[1,2,3],[4,5,6],[7,8,9]], k = 2
// 输出：[[45,45,45],[45,45,45],[45,45,45]]
 

// 提示：

// m == mat.length
// n == mat[i].length
// 1 <= m, n, k <= 100
// 1 <= mat[i][j] <= 100

class Solution {
public:
    // 边长为k的正方形的和 优化空间复杂度
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        for(int i = 1;i < m + 1;++i) for(int j = 1;j < n + 1;++j) dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + mat[i - 1][j - 1];

        for(int i = 0;i < m;++i) 
            for(int j = 0;j < n;++j)
            {
                int x1 = max(0, i - k) + 1, y1 = max(0, j - k) + 1;
                int x2 = min(m - 1, i + k) + 1, y2 = min(n - 1, j + k) + 1;
                mat[i][j] = dp[x2][y2] - dp[x1 - 1][y2] - dp[x2][y1 - 1] + dp[x1 - 1][y1 - 1];
            }

        return mat;
    }
};


// class Solution {
// public:
//     // 边长为k的正方形的和
//     vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
//         int m = mat.size(), n = mat[0].size();
//         vector<vector<int>> dp(m + k * 2, vector<int>(n + k * 2));
//         for(int i = k;i < k + m;++i) for(int j = k;j < k + n;++j) dp[i][j] = mat[i - k][j - k];
//         for(int i = k;i < dp.size();++i) for(int j = k;j < dp[0].size();++j) dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + dp[i][j];

//         // for(const auto& e : dp)
//         // {
//         //     for(const auto& r : e) cout<<r<<" ";
//         //     cout<<endl;
//         // }

//         for(int i = k;i < k + m;++i)
//         {
//             for(int j = k;j < k + n;++j)
//             {
//                 if(i == k && j == k)
//                     mat[i - k][j - k] = dp[i + k][j + k];
//                 else if(i == k)
//                     mat[i - k][j - k] = dp[i + k][j + k] - dp[i + k][j - k - 1];
//                 else if(j == k)
//                     mat[i - k][j - k] = dp[i + k][j + k] - dp[i - k - 1][j + k];
//                 else
//                     mat[i - k][j - k] = dp[i + k][j + k] - dp[i - k - 1][j + k] - dp[i + k][j - k - 1] + dp[i - k - 1][j - k - 1];
//             }
//         }

//         return mat;
//     }
// };

