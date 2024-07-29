

// 695. 岛屿的最大面积
// https://leetcode.cn/problems/max-area-of-island/description/
// 给你一个大小为 m x n 的二进制矩阵 grid 。

// 岛屿 是由一些相邻的 1 (代表土地) 构成的组合，这里的「相邻」要求两个 1 必须在 水平或者竖直的四个方向上 相邻。你可以假设 grid 的四个边缘都被 0（代表水）包围着。

// 岛屿的面积是岛上值为 1 的单元格的数目。

// 计算并返回 grid 中最大的岛屿面积。如果没有岛屿，则返回面积为 0 。

 

// 示例 1：


// 输入：grid = [[0,0,1,0,0,0,0,1,0,0,0,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,1,1,0,1,0,0,0,0,0,0,0,0],[0,1,0,0,1,1,0,0,1,0,1,0,0],[0,1,0,0,1,1,0,0,1,1,1,0,0],[0,0,0,0,0,0,0,0,0,0,1,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,0,0,0,0,0,0,1,1,0,0,0,0]]
// 输出：6
// 解释：答案不应该是 11 ，因为岛屿只能包含水平或垂直这四个方向上的 1 。
// 示例 2：

// 输入：grid = [[0,0,0,0,0,0,0,0]]
// 输出：0
 

// 提示：

// m == grid.length
// n == grid[i].length
// 1 <= m, n <= 50
// grid[i][j] 为 0 或 1


class Solution {
public:
    // BFS
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, 1, -1};
        int ret = 0;
        for(int i = 0;i < m;++i) 
            for(int j = 0;j < n;++j) 
                if(0 != grid[i][j])
                {
                    int cnt = 0;
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    grid[i][j] = 0;

                    while(!q.empty())
                    {
                        int sz = q.size();
                        for(int k = 0;k < sz;++k)
                        {
                            int r = q.front().first, c = q.front().second;
                            q.pop();
                            ++cnt;
                            for(int l = 0;l < 4;++l)
                            {
                                int x = r + dx[l], y = c + dy[l];
                                if(x >= 0 && x < m && y >= 0 && y < n && 0 != grid[x][y])
                                {
                                    q.push({x, y});
                                    grid[x][y] = 0;
                                }
                            }
                        }
                    }

                    ret = max(ret, cnt);                    
                }
        return ret;
    }
};

// class Solution {
//     int max = 0, m = 0, n = 0;
//     int cnt = 0;
//     bool check[50][50];

//     int dx[4] = {1, -1, 0, 0};
//     int dy[4] = {0, 0, 1, -1};

//     void dfs(vector<vector<int>>& grid, int i, int j)
//     {
//         if(check[i][j]) return;
//         ++cnt;
//         if(cnt > max) max = cnt;
//         check[i][j] = true;
//         for(int k = 0;k < 4;++k)
//         {
//             int x = i + dx[k], y = j + dy[k];
//             if(x >= 0 && x < m && y >= 0 && y < n && !check[x][y] && 0 != grid[x][y]) dfs(grid, x, y);
//         }
//     }
// public:
//     int maxAreaOfIsland(vector<vector<int>>& grid) {
//         m = grid.size();
//         n = grid[0].size();
//         for(int i = 0;i < m;++i) 
//             for(int j = 0;j < n;++j) 
//                 if(0 != grid[i][j])
//                 {
//                     cnt = 0;
//                     dfs(grid, i, j);
//                 }
//         return max;
//     }
// };

