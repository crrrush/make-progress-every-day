

// 542. 01 矩阵
// https://leetcode.cn/problems/01-matrix/description/
// 给定一个由 0 和 1 组成的矩阵 mat ，请输出一个大小相同的矩阵，其中每一个格子是 mat 中对应位置元素到最近的 0 的距离。

// 两个相邻元素间的距离为 1 。

 

// 示例 1：



// 输入：mat = [[0,0,0],[0,1,0],[0,0,0]]
// 输出：[[0,0,0],[0,1,0],[0,0,0]]
// 示例 2：



// 输入：mat = [[0,0,0],[0,1,0],[1,1,1]]
// 输出：[[0,0,0],[0,1,0],[1,2,1]]
 

// 提示：

// m == mat.length
// n == mat[i].length
// 1 <= m, n <= 104
// 1 <= m * n <= 104
// mat[i][j] is either 0 or 1.
// mat 中至少有一个 0 

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, 1, -1};
        vector<vector<int>> ret(m, vector<int>(n));
        queue<pair<int, int>> q;
        for(int i = 0;i < m;++i) for(int j = 0;j < n;++j) if(0 == mat[i][j]) q.push({i, j});
        
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
                    if(x >= 0 && x < m && y >= 0 && y < n && 0 == ret[x][y] && 1 == mat[x][y])
                    {
                        ret[x][y] = ret[r][c] + 1;
                        q.push({x, y});
                    }
                }
            }
        }

        return ret;
    }
};


// class Solution {
// public:
//     vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
//         int m = mat.size(), n = mat[0].size();
//         int dx[4] = {1, -1, 0, 0};
//         int dy[4] = {0, 0, 1, -1};
//         vector<vector<int>> ret(m, vector<int>(n));
//         queue<pair<int, int>> q;
//         for(int i = 0;i < m;++i)
//             for(int j = 0;j < n;++j)
//                 if(1 == mat[i][j])
//                 {
//                     for(int k = 0;k < 4;++k)
//                     {
//                         int x = i + dx[k], y = j + dy[k];
//                         if(x >= 0 && x < m && y >= 0 && y < n && 0 == mat[x][y])
//                         {
//                             q.push({i, j});
//                             ret[i][j] = 1;
//                             break;
//                         }
//                     }
//                 }
        
//         while(!q.empty())
//         {
//             int sz = q.size();
//             while(sz--)
//             {
//                 auto [r, c] = q.front();
//                 q.pop();
//                 for(int i = 0;i < 4;++i)
//                 {
//                     int x = r + dx[i], y = c + dy[i];
//                     if(x >= 0 && x < m && y >= 0 && y < n && 0 == ret[x][y] && 1 == mat[x][y])
//                     {
//                         ret[x][y] = ret[r][c] + 1;
//                         q.push({x, y});
//                     }
//                 }
//             }
//         }

//         return ret;
//     }
// };
