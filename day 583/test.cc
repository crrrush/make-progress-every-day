

// 79. 单词搜索
// https://leetcode.cn/problems/word-search/description/
// 给定一个 m x n 二维字符网格 board 和一个字符串单词 word 。如果 word 存在于网格中，返回 true ；否则，返回 false 。

// 单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。

 

// 示例 1：


// 输入：board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
// 输出：true
// 示例 2：


// 输入：board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
// 输出：true
// 示例 3：


// 输入：board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
// 输出：false
 

// 提示：

// m == board.length
// n = board[i].length
// 1 <= m, n <= 6
// 1 <= word.length <= 15
// board 和 word 仅由大小写英文字母组成
 

// 进阶：你可以使用搜索剪枝的技术来优化解决方案，使其在 board 更大的情况下可以更快解决问题？


class Solution {
    // string path;
    // vector<vector<bool>> use_map;
    bool use_map[6][6];
    // 也可以修改原始数据来标记 但尽量不要用
    int pos = 0;

    int dx[4] = { 0, 0, 1, -1};
    int dy[4] = { 1, -1, 0, 0};

    bool dfs(vector<vector<char>>& board, const string& word, int i, int j)
    {
        if(pos >= word.size()) return true;

        for(int k = 0;k < 4;++k)
        {
            int x = i + dx[k], y = j + dy[k];
            if(x >= 0 && x < board.size() && y >= 0 && y < board[i].size() && !use_map[x][y] && board[x][y] == word[pos])
            {
                use_map[x][y] = true;
                ++pos;
                if(dfs(board, word, x, y)) return true;
                --pos;
                use_map[x][y] = false;
            }
        }

        return false;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        // use_map.resize(board.size(), vector<bool>(board[0].size(), false));
        for(int i = 0;i < board.size();++i)
        {
            for(int j = 0;j < board[i].size();++j)
            {
                // if(!use_map[i][j])// 不需要
                if(board[i][j] == word.front())
                {
                    // path += board[i][j];
                    use_map[i][j] = true;
                    ++pos;
                    if(dfs(board, word, i, j)) return true;
                    --pos;
                    use_map[i][j] = false;
                    // path.pop_back();
                }
            }
        }
        return false;
    }
};


// class Solution {
//     // string path;
//     // vector<vector<bool>> use_map;
//     bool use_map[6][6];
//     // 也可以修改原始数据来标记 但尽量不要用
//     int pos = 0;

//     bool dfs(vector<vector<char>>& board, const string& word, int i, int j)
//     {
//         if(pos >= word.size()) return true;

//         if(i > 0 && !use_map[i - 1][j] && board[i - 1][j] == word[pos])
//         {
//             ++pos;
//             use_map[i - 1][j] = true;
//             if(dfs(board, word, i - 1, j)) return true;
//             use_map[i - 1][j] = false;
//             --pos;
//         }
//         if(i < board.size() - 1 && !use_map[i + 1][j] && board[i + 1][j] == word[pos])
//         {
//             ++pos;
//             use_map[i + 1][j] = true;
//             if(dfs(board, word, i + 1, j)) return true;
//             use_map[i + 1][j] = false;
//             --pos;
//         }
//         if(j > 0 && !use_map[i][j - 1] && board[i][j - 1] == word[pos])
//         {
//             ++pos;
//             use_map[i][j - 1] = true;
//             if(dfs(board, word, i, j - 1)) return true;
//             use_map[i][j - 1] = false;
//             --pos;
//         }
//         if(j < board[i].size() - 1 && !use_map[i][j + 1] && board[i][j + 1] == word[pos])
//         {
//             ++pos;
//             use_map[i][j + 1] = true;
//             if(dfs(board, word, i, j + 1)) return true;
//             use_map[i][j + 1] = false;
//             --pos;
//         }

//         return false;
//     }

// public:
//     bool exist(vector<vector<char>>& board, string word) {
//         // use_map.resize(board.size(), vector<bool>(board[0].size(), false));
//         for(int i = 0;i < board.size();++i)
//         {
//             for(int j = 0;j < board[i].size();++j)
//             {
//                 // if(!use_map[i][j])// 不需要
//                 if(board[i][j] == word.front())
//                 {
//                     // path += board[i][j];
//                     use_map[i][j] = true;
//                     ++pos;
//                     if(dfs(board, word, i, j)) return true;
//                     --pos;
//                     use_map[i][j] = false;
//                     // path.pop_back();
//                 }
//             }
//         }
//         return false;
//     }
// };

