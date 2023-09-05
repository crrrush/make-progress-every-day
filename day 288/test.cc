/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2023-09-05 17:42:32
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2023-09-05 17:43:20
 * @FilePath: \every-little-progress\day 288\test.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */


// 1812. 判断国际象棋棋盘中一个格子的颜色
// https://leetcode.cn/problems/determine-color-of-a-chessboard-square/
// 给你一个坐标 coordinates ，它是一个字符串，表示国际象棋棋盘中一个格子的坐标。下图是国际象棋棋盘示意图。



// 如果所给格子的颜色是白色，请你返回 true，如果是黑色，请返回 false 。

// 给定坐标一定代表国际象棋棋盘上一个存在的格子。坐标第一个字符是字母，第二个字符是数字。

 

// 示例 1：

// 输入：coordinates = "a1"
// 输出：false
// 解释：如上图棋盘所示，"a1" 坐标的格子是黑色的，所以返回 false 。
// 示例 2：

// 输入：coordinates = "h3"
// 输出：true
// 解释：如上图棋盘所示，"h3" 坐标的格子是白色的，所以返回 true 。
// 示例 3：

// 输入：coordinates = "c7"
// 输出：false
 

// 提示：

// coordinates.length == 2
// 'a' <= coordinates[0] <= 'h'
// '1' <= coordinates[1] <= '8'


class Solution {
public:
    void initBoard(unordered_map<string, bool>& board)
    {
        if(!board.empty()) return;

        for(char ch = 'a';ch <= 'h';++ch)
        {
            bool color = !(ch % 2);
            for(int i = 1;i <= 8;++i)
            {
                string tmp = ch + to_string(i);
                board[tmp] = color;
                color = !color;
            }
        }
    }
    bool squareIsWhite(string coordinates) {
        static unordered_map<string, bool> board;
        initBoard(board);

        return board[coordinates];
    }
};