/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2024-07-04 21:19:29
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2024-07-04 21:20:03
 * @FilePath: \every-little-progress\day 582\test.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */


// 37. 解数独
// https://leetcode.cn/problems/sudoku-solver/description/
// 编写一个程序，通过填充空格来解决数独问题。

// 数独的解法需 遵循如下规则：

// 数字 1-9 在每一行只能出现一次。
// 数字 1-9 在每一列只能出现一次。
// 数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。（请参考示例图）
// 数独部分空格内已填入了数字，空白格用 '.' 表示。

 

// 示例 1：


// 输入：board = [["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]
// 输出：[["5","3","4","6","7","8","9","1","2"],["6","7","2","1","9","5","3","4","8"],["1","9","8","3","4","2","5","6","7"],["8","5","9","7","6","1","4","2","3"],["4","2","6","8","5","3","7","9","1"],["7","1","3","9","2","4","8","5","6"],["9","6","1","5","3","7","2","8","4"],["2","8","7","4","1","9","6","3","5"],["3","4","5","2","8","6","1","7","9"]]
// 解释：输入的数独如上图所示，唯一有效的解决方案如下所示：


 

// 提示：

// board.length == 9
// board[i].length == 9
// board[i][j] 是一位数字或者 '.'
// 题目数据 保证 输入数独仅有一个解



class Solution {
    bool row[9][10];
    bool col[9][10];
    bool grid[3][3][10];
    
    // 剪枝递归
    bool dfs(vector<vector<char>>& board)
    {
        for(int i = 0;i < 9;++i) 
        {
            for(int j = 0;j < 9;++j) 
            {
                if('.' == board[i][j])
                {
                    for(int key = 1;key <= 9;++key)
                    {
                        if(!row[i][key] && !col[j][key] && !grid[i / 3][j / 3][key])
                        {
                            board[i][j] = '0' + key;
                            row[i][key] = col[j][key] = grid[i / 3][j / 3][key] = true;
                            if(dfs(board)) return true; // !!!
                            board[i][j] = '.';
                            row[i][key] = col[j][key] = grid[i / 3][j / 3][key] = false;
                        }
                    }
                    return false; // !!!
                }
            }
        }

        return true; // !!!
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        for(int i = 0;i < 9;++i) 
        {
            for(int j = 0;j < 9;++j) 
            {
                if('.' != board[i][j])
                {
                    int key = board[i][j] - '0';
                    row[i][key] = col[j][key] = grid[i / 3][j / 3][key] = true;
                }
            }
        }

        dfs(board);
    }
};



