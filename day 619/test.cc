

// 1162. 地图分析
// https://leetcode.cn/problems/as-far-from-land-as-possible/description/
// 你现在手里有一份大小为 n x n 的 网格 grid，上面的每个 单元格 都用 0 和 1 标记好了。其中 0 代表海洋，1 代表陆地。

// 请你找出一个海洋单元格，这个海洋单元格到离它最近的陆地单元格的距离是最大的，并返回该距离。如果网格上只有陆地或者海洋，请返回 -1。

// 我们这里说的距离是「曼哈顿距离」（ Manhattan Distance）：(x0, y0) 和 (x1, y1) 这两个单元格之间的距离是 |x0 - x1| + |y0 - y1| 。

 

// 示例 1：



// 输入：grid = [[1,0,1],[0,0,0],[1,0,1]]
// 输出：2
// 解释： 
// 海洋单元格 (1, 1) 和所有陆地单元格之间的距离都达到最大，最大距离为 2。
// 示例 2：



// 输入：grid = [[1,0,0],[0,0,0],[0,0,0]]
// 输出：4
// 解释： 
// 海洋单元格 (2, 2) 和所有陆地单元格之间的距离都达到最大，最大距离为 4。
 

// 提示：

// n == grid.length
// n == grid[i].length
// 1 <= n <= 100
// grid[i][j] 不是 0 就是 1


class Solution {
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    bool hash[100][100];
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<pair<int, int>> q;
        bool flag0 = true, flag1 = true;
        for(int i = 0;i < n;++i) 
            for(int j = 0;j < n;++j)
            {
                if(1 == grid[i][j]) 
                {
                    q.push({i, j});
                    flag1 = false;
                }
                else
                    flag0 = false;
            }
        if(flag0 || flag1) return -1;

        int cnt = 0;
        while(!q.empty())
        {
            ++cnt;
            int sz = q.size();
            while(sz--)
            {
                auto [r, c] = q.front();
                q.pop();
                for(int i = 0;i < 4;++i)
                {
                    int x = r + dx[i], y = c + dy[i];
                    if(x >= 0 && x < n && y >= 0 && y < n && !hash[x][y] && 0 == grid[x][y])
                    {
                        hash[x][y] = true;
                        q.push({x, y});
                    }
                }
            }
        }

        return --cnt;
    }
};

// class Solution {
//     int dx[4] = {1, -1, 0, 0};
//     int dy[4] = {0, 0, 1, -1};
//     bool hash[100][100];
// public:
//     int maxDistance(vector<vector<int>>& grid) {
//         int m = grid.size(), n = grid[0].size();
//         queue<pair<int, int>> q;
//         bool flag0 = true, flag1 = true;
//         for(int i = 0;i < m;++i) for(int j = 0;j < n;++j)
//         {
//             if(1 == grid[i][j]) 
//             {
//                 q.push({i, j});
//                 flag1 = false;
//             }
//             else
//                 flag0 = false;
//         }
//         if(flag0 || flag1) return -1;

//         int cnt = 0;
//         while(!q.empty())
//         {
//             ++cnt;
//             int sz = q.size();
//             while(sz--)
//             {
//                 auto [r, c] = q.front();
//                 q.pop();
//                 for(int i = 0;i < 4;++i)
//                 {
//                     int x = r + dx[i], y = c + dy[i];
//                     if(x >= 0 && x < m && y >= 0 && y < n && !hash[x][y] && 0 == grid[x][y])
//                     {
//                         hash[x][y] = true;
//                         q.push({x, y});
//                     }
//                 }
//             }
//         }

//         return --cnt;
//     }
// };

