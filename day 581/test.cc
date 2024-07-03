

// 36. 有效的数独
// 请你判断一个 9 x 9 的数独是否有效。只需要 根据以下规则 ，验证已经填入的数字是否有效即可。

// 数字 1-9 在每一行只能出现一次。
// 数字 1-9 在每一列只能出现一次。
// 数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。（请参考示例图）
 

// 注意：

// 一个有效的数独（部分已被填充）不一定是可解的。
// 只需要根据以上规则，验证已经填入的数字是否有效即可。
// 空白格用 '.' 表示。
 

// 示例 1：


// 输入：board = 
// [["5","3",".",".","7",".",".",".","."]
// ,["6",".",".","1","9","5",".",".","."]
// ,[".","9","8",".",".",".",".","6","."]
// ,["8",".",".",".","6",".",".",".","3"]
// ,["4",".",".","8",".","3",".",".","1"]
// ,["7",".",".",".","2",".",".",".","6"]
// ,[".","6",".",".",".",".","2","8","."]
// ,[".",".",".","4","1","9",".",".","5"]
// ,[".",".",".",".","8",".",".","7","9"]]
// 输出：true
// 示例 2：

// 输入：board = 
// [["8","3",".",".","7",".",".",".","."]
// ,["6",".",".","1","9","5",".",".","."]
// ,[".","9","8",".",".",".",".","6","."]
// ,["8",".",".",".","6",".",".",".","3"]
// ,["4",".",".","8",".","3",".",".","1"]
// ,["7",".",".",".","2",".",".",".","6"]
// ,[".","6",".",".",".",".","2","8","."]
// ,[".",".",".","4","1","9",".",".","5"]
// ,[".",".",".",".","8",".",".","7","9"]]
// 输出：false
// 解释：除了第一行的第一个数字从 5 改为 8 以外，空格内其他数字均与 示例1 相同。 但由于位于左上角的 3x3 宫内有两个 8 存在, 因此这个数独是无效的。
 

// 提示：

// board.length == 9
// board[i].length == 9
// board[i][j] 是一位数字（1-9）或者 '.'



class Solution {
    // bool row[9][10];
    // bool col[9][10];
    // bool grid[3][3][10];
    
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool row[9][10];
        bool col[9][10];
        bool grid[3][3][10];

        for(int i = 0;i < 9;++i) 
        {
            for(int j = 0;j < 9;++j) 
            {
                if('.' != board[i][j])
                {
                    int key = board[i][j] - '0';
                    if(row[i][key] || col[j][key] || grid[i / 3][j / 3][key]) return false;
                    row[i][key] = col[j][key] = grid[i / 3][j / 3][key] = true;
                }
            }
        }

        return true;
    }
};

// 解数独
// class Solution {
//     bool row[9][10];
//     bool col[9][10];
//     bool grid[3][3][10];
    
//     // 剪枝递归
//     bool dfs(vector<vector<char>>& board)
//     {
//         for(int i = 0;i < 9;++i) 
//         {
//             for(int j = 0;j < 9;++j) 
//             {
//                 if('.' == board[i][j])
//                 {
//                     for(int key = 1;key <= 9;++key)
//                     {
//                         if(!row[i][key] && !col[j][key] && !grid[i / 3][j / 3][key])
//                         {
//                             board[i][j] = '0' + key;
//                             row[i][key] = col[j][key] = grid[i / 3][j / 3][key] = true;
//                             if(dfs(board)) return true; // !!!
//                             board[i][j] = '.';
//                             row[i][key] = col[j][key] = grid[i / 3][j / 3][key] = false;
//                         }
//                     }
//                     return false; // !!!
//                 }
//             }
//         }

//         return true; // !!!
//     }
// public:
//     bool isValidSudoku(vector<vector<char>>& board) {
//         for(int i = 0;i < 9;++i) 
//         {
//             for(int j = 0;j < 9;++j) 
//             {
//                 if('.' != board[i][j])
//                 {
//                     int key = board[i][j] - '0';
//                     row[i][key] = col[j][key] = grid[i / 3][j / 3][key] = true;
//                 }
//             }
//         }

//         return dfs(board);
//     }
// };


// class Solution {
//     // bool row[9];
//     // bool col[9];
//     // bool sq[9];
    
// public:
//     bool isValidSudoku(vector<vector<char>>& board) {
//         bool row[9];
//         for(int n = 0;n < 9;++n) row[n] = false;
//         for(int i = 0;i < 9;++i)
//         {
//             // cout<<i<<"   ";
//             for(int j = 0;j < 9;++j)
//             {
//                 if(board[i][j] != '.')
//                 {
//                     // cout<<board[i][j] <<" "<<row[board[i][j] - '1']<<">";
//                     if(row[board[i][j] - '1']) return false;
//                     row[board[i][j] - '1'] = true;
//                 }
//             }
//             for(int n = 0;n < 9;++n) row[n] = false;
//             // cout<<endl;
//         }

//         bool col[9];
//         for(int n = 0;n < 9;++n) col[n] = false;
//         for(int i = 0;i < 9;++i)
//         {
//             // cout<<i<<" ";
//             for(int j = 0;j < 9;++j)
//             {
//                 if(board[j][i] != '.')
//                 {
//                     // cout<<board[j][i] <<" "<<row[board[j][i] - '1']<<">";
//                     if(col[board[j][i] - '1']) return false;
//                     col[board[j][i] - '1'] = true;
//                 }
//             }
//             for(int n = 0;n < 9;++n) col[n] = false;
//             // cout<<endl;
//         }

//         bool square[9];
//         for(int n = 0;n < 9;++n) square[n] = false;
//         for(int i = 0;i < 9;++i)
//         {
//             int r = (i / 3) * 3, c = (i % 3) * 3;
//             // cout<<r<<":"<<c<<"  ";
//             for(int x = 0;x < 3;++x)
//             {
//                 for(int y = 0;y < 3;++y)
//                 {
//                     if(board[r + x][c + y] != '.')
//                     {
//                         // cout<<square[board[r + x][c + y] - '1']<<">";
//                         if(true == square[board[r + x][c + y] - '1'])
//                         {
//                             return false;
//                         }

//                         square[board[r + x][c + y] - '1'] = true;
//                     }
//                 }
//             }
//             for(int n = 0;n < 9;++n) square[n] = false;
//             // cout<<endl;
//         }

//         return true;
//     }
// };

