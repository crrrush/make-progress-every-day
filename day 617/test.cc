/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2024-08-11 13:12:42
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2024-08-11 13:15:04
 * @FilePath: \every-little-progress\day 617\test.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */


// 1020. 飞地的数量
// https://leetcode.cn/problems/number-of-enclaves/description/
// 给你一个大小为 m x n 的二进制矩阵 grid ，其中 0 表示一个海洋单元格、1 表示一个陆地单元格。

// 一次 移动 是指从一个陆地单元格走到另一个相邻（上、下、左、右）的陆地单元格或跨过 grid 的边界。

// 返回网格中 无法 在任意次数的移动中离开网格边界的陆地单元格的数量。

 

// 示例 1：


// 输入：grid = [[0,0,0,0],[1,0,1,0],[0,1,1,0],[0,0,0,0]]
// 输出：3
// 解释：有三个 1 被 0 包围。一个 1 没有被包围，因为它在边界上。
// 示例 2：


// 输入：grid = [[0,1,1,0],[0,0,1,0],[0,0,1,0],[0,0,0,0]]
// 输出：0
// 解释：所有 1 都在边界上或可以到达边界。
 

// 提示：

// m == grid.length
// n == grid[i].length
// 1 <= m, n <= 500
// grid[i][j] 的值为 0 或 1


class Solution {
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        queue<pair<int, int>> q;
        for(int i = 0;i < m;++i)
        {
            if(1 == grid[i][0]) q.push({i, 0});
            if(1 == grid[i][n -1]) q.push({i, n - 1});
            grid[i][0] = grid[i][n -1] = 0;
        }
        for(int i = 0;i < n;++i)
        {
            if(1 == grid[0][i]) q.push({0, i});
            if(1 == grid[m - 1][i]) q.push({m - 1, i});
            grid[0][i] = grid[m - 1][i] = 0;
        }

        while(!q.empty())
        {
            int sz = q.size();
            while(sz--)
            {
                auto [r, c] = q.front();
                q.pop();
                for(int i = 0;i < 4;++i)
                {
                    int x = r + dx[i], y = c + dy[i];
                    if(x >= 0 && x < m && y >= 0 && y < n && 1 == grid[x][y])
                    {
                        grid[x][y] = 0;
                        q.push({x, y});
                    }
                }
            }
        }

        int cnt = 0;
        for(const auto& e : grid) for(const auto& r : e) if(1 == r) ++cnt;
        return cnt;
    }
};
