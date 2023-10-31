

// 面试题 16.04. 井字游戏
// https://leetcode.cn/problems/tic-tac-toe-lcci/description/
// 设计一个算法，判断玩家是否赢了井字游戏。输入是一个 N x N 的数组棋盘，由字符" "，"X"和"O"组成，其中字符" "代表一个空位。

// 以下是井字游戏的规则：

// 玩家轮流将字符放入空位（" "）中。
// 第一个玩家总是放字符"O"，且第二个玩家总是放字符"X"。
// "X"和"O"只允许放置在空位中，不允许对已放有字符的位置进行填充。
// 当有N个相同（且非空）的字符填充任何行、列或对角线时，游戏结束，对应该字符的玩家获胜。
// 当所有位置非空时，也算为游戏结束。
// 如果游戏结束，玩家不允许再放置字符。
// 如果游戏存在获胜者，就返回该游戏的获胜者使用的字符（"X"或"O"）；如果游戏以平局结束，则返回 "Draw"；如果仍会有行动（游戏未结束），则返回 "Pending"。

// 示例 1：

// 输入： board = ["O X"," XO","X O"]
// 输出： "X"
// 示例 2：

// 输入： board = ["OOX","XXO","OXO"]
// 输出： "Draw"
// 解释： 没有玩家获胜且不存在空位
// 示例 3：

// 输入： board = ["OOX","XXO","OX "]
// 输出： "Pending"
// 解释： 没有玩家获胜且仍存在空位
// 提示：

// 1 <= board.length == board[i].length <= 100
// 输入一定遵循井字棋规则


class Solution {
    bool win_in_row(string& res, const string& row, bool& space)
    {
        if(row.front() == ' ')
        {
            space = true;
            return false;
        }

        for(const auto& e : row)
        {
            if(e != row.front()) return false;
            if(e == ' ') space = true;
        }

        res = row[0];
        return true;
    }

    bool win_in_col(string& res, const vector<string>& board, int i, bool& space)
    {
        if(board[0][i] == ' ')
        {
            space = true;
            return false;
        }

        for(const auto& e : board)
        {
            if(e[i] != board[0][i]) return false;
            if(e[i] == ' ') space = true;
        }

        res = board[0][i];
        return true;
    }

    bool win_in_cater(string& res, const vector<string>& board, int pos, int off, bool& space)
    {
        if(board[0][pos] == ' ')
        {
            space = true;
            return false;
        }
        
        int offset = pos;
        for(const auto& e : board) 
        {
            if(e[offset] != board[0][pos]) return false;
            if(e[offset] == ' ') space = true;
            offset += off;
        }

        res = board[0][pos];
        return true;
    }
public:
    string tictactoe(vector<string>& board) {
        bool space = false;
        string res;

        for(const auto& e : board) if(win_in_row(res, e, space)) return res;

        for(int i = 0;i < board[0].size();++i) if(win_in_col(res, board, i, space)) return res;

        if(win_in_cater(res, board, 0, 1, space)) return res;
        if(win_in_cater(res, board, board[0].size() - 1, -1, space)) return res;

        if(space) 
            return "Pending";
        else 
            return "Draw";
    }
};