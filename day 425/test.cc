/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2024-01-22 16:24:57
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2024-01-22 16:25:23
 * @FilePath: \every-little-progress\day 425\test.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */


// 566. 重塑矩阵
// https://leetcode.cn/problems/reshape-the-matrix/description/
// 在 MATLAB 中，有一个非常有用的函数 reshape ，它可以将一个 m x n 矩阵重塑为另一个大小不同（r x c）的新矩阵，但保留其原始数据。

// 给你一个由二维数组 mat 表示的 m x n 矩阵，以及两个正整数 r 和 c ，分别表示想要的重构的矩阵的行数和列数。

// 重构后的矩阵需要将原始矩阵的所有元素以相同的 行遍历顺序 填充。

// 如果具有给定参数的 reshape 操作是可行且合理的，则输出新的重塑矩阵；否则，输出原始矩阵。

 

// 示例 1：


// 输入：mat = [[1,2],[3,4]], r = 1, c = 4
// 输出：[[1,2,3,4]]
// 示例 2：


// 输入：mat = [[1,2],[3,4]], r = 2, c = 4
// 输出：[[1,2],[3,4]]
 

// 提示：

// m == mat.length
// n == mat[i].length
// 1 <= m, n <= 100
// -1000 <= mat[i][j] <= 1000
// 1 <= r, c <= 300


class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int mrow = mat.size();
        int mcol =  mat[0].size();
        if(mrow * mcol != r * c || (mrow == r && mcol == c)) return mat; // 不合理，返回原矩阵

        vector<vector<int>> res(r, vector<int>(c, 0));
        int pos = 0;
        int line = 0;
        for(int i = 0;i < r;++i)
        {
            for(int j = 0;j < c;++j)
            {
                if(pos == mcol)
                {
                    pos = 0;
                    ++line;
                }
                res[i][j] = mat[line][pos++];
            }
        }

        return res;
    }
};