

// 200. 岛屿数量
// https://leetcode.cn/problems/number-of-islands/description/
// 给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。

// 岛屿总是被水包围，并且每座岛屿只能由水平方向和/或竖直方向上相邻的陆地连接形成。

// 此外，你可以假设该网格的四条边均被水包围。

 

// 示例 1：

// 输入：grid = [
//   ["1","1","1","1","0"],
//   ["1","1","0","1","0"],
//   ["1","1","0","0","0"],
//   ["0","0","0","0","0"]
// ]
// 输出：1
// 示例 2：

// 输入：grid = [
//   ["1","1","0","0","0"],
//   ["1","1","0","0","0"],
//   ["0","0","1","0","0"],
//   ["0","0","0","1","1"]
// ]
// 输出：3
 

// 提示：

// m == grid.length
// n == grid[i].length
// 1 <= m, n <= 300
// grid[i][j] 的值为 '0' 或 '1'


class Solution {
    // BFS
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int cnt = 0;

        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, 1, -1};

        for(int i = 0;i < m;++i) 
            for(int j = 0;j < n;++j) 
            {
                if('1' != grid[i][j]) continue;

                ++cnt;
                queue<pair<int, int>> q;
                q.push({i, j});
                grid[i][j] = '0';
                while(!q.empty())
                {
                    int sz = q.size();
                    for(int k = 0;k < sz;++k)
                    {
                        int r = q.front().first, c = q.front().second;
                        for(int l = 0;l < 4;++l)
                        {
                            int x = r + dx[l], y = c + dy[l];
                            if(x >= 0 && x < m && y >= 0 && y < n && '1' == grid[x][y])
                            {
                                q.push({x, y});
                                grid[x][y] = '0';
                            }
                        }
                        q.pop();
                    }
                }
            }

        return cnt;
    }
};

// class Solution {
//     bool check[300][300];
//     int m = 0, n = 0;

//     int dx[4] = {1, -1, 0, 0};
//     int dy[4] = {0, 0, 1, -1};

//     bool dfs(vector<vector<char>>& grid, int i, int j)
//     {
//         if(check[i][j]) return false;
//         check[i][j] = true;
//         for(int k = 0;k < 4;++k)
//         {
//             int x = i + dx[k], y = j + dy[k];
//             if(x >= 0 && x < m && y >= 0 && y < n && !check[x][y] && '0' != grid[x][y]) dfs(grid, x, y);
//         }
//         return true;
//     }
// public:
//     int numIslands(vector<vector<char>>& grid) {
//         m = grid.size();
//         n = grid[0].size();
//         int cnt = 0;
//         for(int i = 0;i < m;++i) for(int j = 0;j < n;++j) if('0' != grid[i][j] && dfs(grid, i, j)) ++cnt;
//         return cnt;
//     }
// };

