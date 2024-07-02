

// 51. N 皇后
// https://leetcode.cn/problems/n-queens/description/
// 按照国际象棋的规则，皇后可以攻击与之处在同一行或同一列或同一斜线上的棋子。

// n 皇后问题 研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。

// 给你一个整数 n ，返回所有不同的 n 皇后问题 的解决方案。

// 每一种解法包含一个不同的 n 皇后问题 的棋子放置方案，该方案中 'Q' 和 '.' 分别代表了皇后和空位。

 

// 示例 1：


// 输入：n = 4
// 输出：[[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
// 解释：如上图所示，4 皇后问题存在两个不同的解法。
// 示例 2：

// 输入：n = 1
// 输出：[["Q"]]
 

// 提示：

// 1 <= n <= 9


class Solution {
    vector<vector<string>> ret;
    vector<string> path;
    bool col[9];
    // bool row[9];
    bool line1[17]; // 斜线1
    bool line2[17]; // 斜线2
    // int num = 0;

    // bool dfs(const int& n)
    void dfs(const int& n, int i)
    {
        if(n == i)
        {
            return ret.push_back(path);
        }


        for(int j = 0;j < n;++j)
        {
            // if(false == row[i] && false == col[j] && false == line1[i + j] && false == line2[n - i + j])
            if(false == col[j] && false == line1[i + j] && false == line2[n - i + j])
            {
                // row[i] = true;
                col[j] = true;
                line1[i + j] = true;
                line2[n - i + j] = true;

                // ++num;
                path[i][j] = 'Q';

                // check[i][j] = true;
                // if(dfs(n)) check[i][j] = true;
                // check.push_back({i, j});
                dfs(n, i + 1);
                // check.pop_back();
                // check[i][j] = false;

                path[i][j] = '.';
                // --num;

                // row[i] = false;
                col[j] = false;
                line1[i + j] = false;
                line2[n - i + j] = false;
                // line2[(2 * n - 2) - (i + j)] = false;
            }
        }

    }
public:
    vector<vector<string>> solveNQueens(int n) {
        path.resize(n, string(".........", n));
        // dfs(n);
        dfs(n, 0);
        return ret;
    }
};

// class Solution {
//     vector<vector<string>> ret;
//     vector<string> path;
//     bool hascheck[9][9];
//     vector<pair<int, int>> check;
//     bool col[9];
//     bool row[9];
//     bool line1[17]; // 斜线1
//     bool line2[17]; // 斜线2
//     int num = 0;

//     // bool dfs(const int& n)
//     void dfs(const int& n, int ipos, int jpos)
//     {
//         if(n == num)
//         {
//             // bool flag = false;
//             // for(const auto& [x, y] : check) if(false == hascheck[x][y]) flag = true;
//             // if(flag)
//             {
//                 // for(const auto& [x, y] : check) hascheck[x][y] = true;
//                 ret.push_back(path);
//             }
//             return;
//             // return ret.push_back(path);
//             // ret.push_back(path);
//             // return true;
//         }

//         // for(int i = 0;i < n;++i)
//         for(int i = ipos;i < n;++i)
//         {
//             // for(int j = 0;j < n;++j)
//             for(int j = jpos;j < n;++j)
//             {
//                 if(false == row[i] && false == col[j] && false == line1[i + j] && false == line2[n - i + j])
//                 {
//                     row[i] = true;
//                     col[j] = true;
//                     line1[i + j] = true;
//                     line2[n - i + j] = true;

//                     ++num;
//                     path[i][j] = 'Q';

//                     // check[i][j] = true;
//                     // if(dfs(n)) check[i][j] = true;
//                     // check.push_back({i, j});
//                     dfs(n, i + 1, j);
//                     dfs(n, i, j + 1);
//                     // check.pop_back();
//                     // check[i][j] = false;

//                     path[i][j] = '.';
//                     --num;

//                     row[i] = false;
//                     col[j] = false;
//                     line1[i + j] = false;
//                     line2[n - i + j] = false;
//                     // line2[(2 * n - 2) - (i + j)] = false;
//                 }
//             }
//         }

//         // return false;
//     }
// public:
//     vector<vector<string>> solveNQueens(int n) {
//         path.resize(n, string(".........", n));
//         // dfs(n);
//         dfs(n, 0, 0);
//         return ret;
//     }
// };

