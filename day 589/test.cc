

// 417. 太平洋大西洋水流问题
// https://leetcode.cn/problems/pacific-atlantic-water-flow/description/
// 有一个 m × n 的矩形岛屿，与 太平洋 和 大西洋 相邻。 “太平洋” 处于大陆的左边界和上边界，而 “大西洋” 处于大陆的右边界和下边界。

// 这个岛被分割成一个由若干方形单元格组成的网格。给定一个 m x n 的整数矩阵 heights ， heights[r][c] 表示坐标 (r, c) 上单元格 高于海平面的高度 。

// 岛上雨水较多，如果相邻单元格的高度 小于或等于 当前单元格的高度，雨水可以直接向北、南、东、西流向相邻单元格。水可以从海洋附近的任何单元格流入海洋。

// 返回网格坐标 result 的 2D 列表 ，其中 result[i] = [ri, ci] 表示雨水从单元格 (ri, ci) 流动 既可流向太平洋也可流向大西洋 。

 

// 示例 1：



// 输入: heights = [[1,2,2,3,5],[3,2,3,4,4],[2,4,5,3,1],[6,7,1,4,5],[5,1,1,2,4]]
// 输出: [[0,4],[1,3],[1,4],[2,2],[3,0],[3,1],[4,0]]
// 示例 2：

// 输入: heights = [[2,1],[1,2]]
// 输出: [[0,0],[0,1],[1,0],[1,1]]
 

// 提示：

// m == heights.length
// n == heights[r].length
// 1 <= m, n <= 200
// 0 <= heights[r][c] <= 105


class Solution {
    // bool P = false, A = false;
    int m = 0, n = 0;
    // 正难则反
    bool check[200][200];
    bool done[200][200][2];

    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    void dfs(vector<vector<int>>& heights, const int& ocean, int i, int j)
    {
        done[i][j][ocean] = true;
        for(int k = 0;k < 4;++k)
        {
            int x = i + dx[k], y = j + dy[k];
            if(x >= 0 && x < m && y >= 0 && y < n && !done[x][y][ocean] && !check[x][y] && heights[x][y] >= heights[i][j])
            {
                check[x][y] = true;
                dfs(heights, ocean, x, y);
                check[x][y] = false;
            }
        }
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m = heights.size();
        n = heights[0].size();
        vector<vector<int>> ret;
        for(int i = 0;i < m;++i)
        {
            dfs(heights, 0, i, 0);
            dfs(heights, 1, i, n - 1);
        }
        for(int j = 0;j < n;++j)
        {
            dfs(heights, 0, 0, j);
            dfs(heights, 1, m - 1, j);
        }

        for(int i = 0;i < m;++i) 
            for(int j = 0;j < n;++j)
            {
                if(done[i][j][0] && done[i][j][1])
                {
                    ret.push_back({i, j});
                }
            }

        return ret;
    }
};


// class Solution {
//     bool P = false, A = false;
//     int m = 0, n = 0;
//     bool check[200][200];
//     bool done[200][200][3];

//     int dx[4] = {1, -1, 0, 0};
//     int dy[4] = {0, 0, 1, -1};

//     void dfs(vector<vector<int>>& heights, int i, int j)
//     {
//         for(int k = 0;k < 4;++k)
//         {
//             int x = i + dx[k], y = j + dy[k];
//             if(x <0 || y < 0) P = true;
//             else if(x >= m || y >= n) A = true;
//             else if(!check[x][y] && heights[x][y] <= heights[i][j])
//             {
//                 if(done[x][y][0])
//                 {
//                     if(done[x][y][1]) P = true;
//                     if(done[x][y][2]) A = true;
//                     continue;
//                 }
//                 done[x][y][0] = true;
//                 check[x][y] = true;
//                 dfs(heights, x, y);
//                 check[x][y] = false;
//                 if(P) done[x][y][1] = true;
//                 if(A) done[x][y][2] = true;
//             }
//         }
//     }
// public:
//     vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
//         m = heights.size();
//         n = heights[0].size();
//         vector<vector<int>> ret;
//         for(int i = 0;i < m;++i) 
//             for(int j = 0;j < n;++j)
//             {
//                 P = A = false;
//                 done[i][j][0] = true;
//                 dfs(heights, i, j);
//                 if(P) done[i][j][1] = true;
//                 if(A) done[i][j][2] = true;
//                 if(P && A)
//                 {
//                     ret.push_back({i, j});
//                 }
//             }

//         return ret;
//     }
// };


// class Solution {
//     bool P = false, A = false;
//     int m = 0, n = 0;
//     bool check[200][200];
//     bool done[200][200];

//     int dx[4] = {1, -1, 0, 0};
//     int dy[4] = {0, 0, 1, -1};

//     void dfs(vector<vector<int>>& heights, int i, int j)
//     {
//         for(int k = 0;k < 4;++k)
//         {
//             int x = i + dx[k], y = j + dy[k];
//             if(x <0 || y < 0) P = true;
//             else if(x >= m || y >= n) A = true;
//             else if(!check[x][y] && heights[x][y] <= heights[i][j])
//             {
//                 if(done[x][y])
//                 {
//                     P = A = true;
//                     return;
//                 }
//                 check[x][y] = true;
//                 dfs(heights, x, y);
//                 check[x][y] = false;
//             }
//         }
//     }
// public:
//     vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
//         m = heights.size();
//         n = heights[0].size();
//         vector<vector<int>> ret;
//         for(int i = 0;i < m;++i) 
//             for(int j = 0;j < n;++j)
//             {
//                 P = A = false;
//                 dfs(heights, i, j);
//                 if(P && A)
//                 {
//                     ret.push_back({i, j});
//                     done[i][j] = true;
//                 }
//             }

//         return ret;
//     }
// };
