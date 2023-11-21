/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2023-11-21 12:42:29
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2023-11-21 12:43:55
 * @FilePath: \every-little-progress\day 365\test.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */


// 2133. 检查是否每一行每一列都包含全部整数
// https://leetcode.cn/problems/check-if-every-row-and-column-contains-all-numbers/description/
// 对一个大小为 n x n 的矩阵而言，如果其每一行和每一列都包含从 1 到 n 的 全部 整数（含 1 和 n），则认为该矩阵是一个 有效 矩阵。

// 给你一个大小为 n x n 的整数矩阵 matrix ，请你判断矩阵是否为一个有效矩阵：如果是，返回 true ；否则，返回 false 。

 

// 示例 1：



// 输入：matrix = [[1,2,3],[3,1,2],[2,3,1]]
// 输出：true
// 解释：在此例中，n = 3 ，每一行和每一列都包含数字 1、2、3 。
// 因此，返回 true 。
// 示例 2：



// 输入：matrix = [[1,1,1],[1,2,3],[1,2,3]]
// 输出：false
// 解释：在此例中，n = 3 ，但第一行和第一列不包含数字 2 和 3 。
// 因此，返回 false 。
 

// 提示：

// n == matrix.length == matrix[i].length
// 1 <= n <= 100
// 1 <= matrix[i][j] <= n

class Solution {
    bool is_row_valid(const vector<int>& row)
    {
        vector<bool> table(row.size(), false);
        for(const auto& e : row) table[e - 1] = true;
        for(const auto& e : table) if(e == false) return e;
        return true;
    }
    bool is_col_valid(const vector<vector<int>>& matrix, int col)
    {
        vector<bool> table(matrix.size(), false);
        for(const auto& e : matrix) table[e[col] - 1] = true;
        for(const auto& e : table) if(e == false) return e;
        return true;
    }
public:
    bool checkValid(vector<vector<int>>& matrix) {
        for(int i = 0;i < matrix.size();++i)
        {
            if(is_row_valid(matrix[i]) == false) return false;
            if(is_col_valid(matrix, i) == false) return false;
        }

        return true;
    }
};