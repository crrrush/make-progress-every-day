

// 130. 被围绕的区域
// https://leetcode.cn/problems/surrounded-regions/description/
// 给你一个 m x n 的矩阵 board ，由若干字符 'X' 和 'O' 组成，捕获 所有 被围绕的区域：

// 连接：一个单元格与水平或垂直方向上相邻的单元格连接。
// 区域：连接所有 'O' 的单元格来形成一个区域。
// 围绕：如果您可以用 'X' 单元格 连接这个区域，并且区域中没有任何单元格位于 board 边缘，则该区域被 'X' 单元格围绕。
// 通过将输入矩阵 board 中的所有 'O' 替换为 'X' 来 捕获被围绕的区域。

 

// 示例 1：

// 输入：board = [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]

// 输出：[["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]

// 解释：


// 在上图中，底部的区域没有被捕获，因为它在 board 的边缘并且不能被围绕。

// 示例 2：

// 输入：board = [["X"]]

// 输出：[["X"]]

 

// 提示：

// m == board.length
// n == board[i].length
// 1 <= m, n <= 200
// board[i][j] 为 'X' 或 'O'

class Solution {
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    int m, n;

    void bfs(vector<vector<char>>& board, int i, int j)
    {
        queue<pair<int, int>> q;
        q.push({i, j});
        board[i][j] = '.';
        
        while(!q.empty())
        {
            int sz = q.size();
            for(int k = 0;k < sz;++k)
            {
                int r = q.front().first, c = q.front().second;
                q.pop();
                for(int l = 0;l < 4;++l)
                {
                    int x = dx[l] + r, y = dy[l] + c;
                    if(x >= 0 && x < m && y >= 0 && y < n && 'O' == board[x][y])
                    {
                        board[x][y] = '.';
                        q.push({x, y});
                    }
                }
            }
        }
    }
public:
    // BFS
    void solve(vector<vector<char>>& board) {
        m = board.size();
        n = board[0].size();
        for(int i = 0;i < m;++i)
        {
            if('O' == board[i][0]) bfs(board, i, 0);
            if('O' == board[i][n - 1]) bfs(board, i, n - 1);
        }
        for(int j = 0;j < n;++j)
        {
            if('O' == board[0][j]) bfs(board, 0, j);
            if('O' == board[m - 1][j]) bfs(board, m - 1, j);
        }
        for(int i = 0;i < m;++i) 
            for(int j = 0;j < n;++j)
            {
                if('O' == board[i][j]) board[i][j] = 'X';
                else if('.' == board[i][j]) board[i][j] = 'O';
            }
    }
};



// class Solution {
//     int dx[4] = {1, -1, 0, 0};
//     int dy[4] = {0, 0, 1, -1};

//     bool check[200][200];
//     int m = 0, n = 0;
//     // 正难则反

//     void change(vector<vector<char>>& board, int i, int j)
//     {
//         board[i][j] = '.';
//         for(int k = 0;k < 4;++k)
//         {
//             int x = i + dx[k], y = j + dy[k];
//             if(x >= 0 && x < m && y >= 0 && y < n && 'O' == board[x][y]) change(board, x, y);
//         }
//     }

// public:
//     void solve(vector<vector<char>>& board) {
//         m = board.size();
//         n = board[0].size();
//         for(int i = 0;i < m;++i)
//         {
//             if('O' == board[i][0]) change(board, i, 0);
//             if('O' == board[i][n - 1]) change(board, i, n - 1);
//         }
//         for(int j = 0;j < n;++j)
//         {
//             if('O' == board[0][j]) change(board, 0, j);
//             if('O' == board[m - 1][j]) change(board, m - 1, j);
//         }
//         for(int i = 0;i < m;++i) for(int j = 0;j < n;++j)
//         {
//             if('O' == board[i][j]) board[i][j] = 'X';
//             else if('.' == board[i][j]) board[i][j] = 'O';
//         }
//     }
// };


// class Solution {
//     int dx[4] = {1, -1, 0, 0};
//     int dy[4] = {0, 0, 1, -1};

//     bool check[200][200];
//     int m = 0, n = 0;

//     void change(vector<vector<char>>& board, int i, int j)
//     {
//         board[i][j] = 'X';
//         for(int k = 0;k < 4;++k)
//         {
//             int x = i + dx[k], y = j + dy[k];
//             if(x >= 0 && x < m && y >= 0 && y < n && 'O' == board[x][y]) change(board, x, y);
//         }
//     }

//     bool dfs(vector<vector<char>>& board, int i, int j)
//     {
//         if(check[i][j]) return true;
//         check[i][j] = true;
//         bool ret = false;
//         for(int k = 0;k < 4;++k)
//         {
//             int x = i + dx[k], y = j + dy[k];

//             if(x < 0 || x >= m || y < 0 || y >= n)
//             {
//                 ret = true;
//             }
//             else if(!check[x][y] && 'O' == board[x][y])
//             {
//                 ret |= dfs(board, x, y);
//             }
//         }
//         return ret;
//     }

// public:
//     void solve(vector<vector<char>>& board) {
//         m = board.size();
//         n = board[0].size();
//         for(int i = 0;i < m;++i) for(int j = 0;j < n;++j) if('O' == board[i][j] && !dfs(board, i, j)) change(board, i, j);
//     }
// };
