/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2024-07-19 11:05:02
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2024-07-19 11:05:39
 * @FilePath: \every-little-progress\day 596\test.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */


// 329. 矩阵中的最长递增路径
// https://leetcode.cn/problems/longest-increasing-path-in-a-matrix/description/
// 给定一个 m x n 整数矩阵 matrix ，找出其中 最长递增路径 的长度。

// 对于每个单元格，你可以往上，下，左，右四个方向移动。 你 不能 在 对角线 方向上移动或移动到 边界外（即不允许环绕）。

 

// 示例 1：


// 输入：matrix = [[9,9,4],[6,6,8],[2,1,1]]
// 输出：4 
// 解释：最长递增路径为 [1, 2, 6, 9]。
// 示例 2：


// 输入：matrix = [[3,4,5],[3,2,6],[2,2,1]]
// 输出：4 
// 解释：最长递增路径是 [3, 4, 5, 6]。注意不允许在对角线方向上移动。
// 示例 3：

// 输入：matrix = [[1]]
// 输出：1
 

// 提示：

// m == matrix.length
// n == matrix[i].length
// 1 <= m, n <= 200
// 0 <= matrix[i][j] <= 231 - 1


class Solution {
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    int m = 0, n = 0;
    int memo[201][201];

    int dfs(vector<vector<int>>& matrix, int i, int j)
    {
        if(-1 != memo[i][j]) return memo[i][j];
        int ret = 0;
        for(int k = 0;k < 4;++k)
        {
            int x = dx[k] + i, y = dy[k] + j;
            if(x >= 0 && x < m && y >= 0 && y < n && matrix[x][y] > matrix[i][j]) ret = max(dfs(matrix, x, y), ret);
        }
        memo[i][j] = ret + 1;
        return ret + 1;
    }
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int ret = 0;
        m = matrix.size(), n = matrix[0].size();
        for(int i = 0;i < m;++i) for(int j = 0;j < n;++j) memo[i][j] = -1;
        for(int i = 0;i < m;++i) for(int j = 0;j < n;++j) ret = max(dfs(matrix, i, j), ret);

        return ret;
    }
};
