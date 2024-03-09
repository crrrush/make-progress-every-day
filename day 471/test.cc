


// 73. 矩阵置零
// https://leetcode.cn/problems/set-matrix-zeroes/description/
// 给定一个 m x n 的矩阵，如果一个元素为 0 ，则将其所在行和列的所有元素都设为 0 。请使用 原地 算法。

 

// 示例 1：


// 输入：matrix = [[1,1,1],[1,0,1],[1,1,1]]
// 输出：[[1,0,1],[0,0,0],[1,0,1]]
// 示例 2：


// 输入：matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
// 输出：[[0,0,0,0],[0,4,5,0],[0,3,1,0]]
 

// 提示：

// m == matrix.length
// n == matrix[0].length
// 1 <= m, n <= 200
// -231 <= matrix[i][j] <= 231 - 1
 

// 进阶：

// 一个直观的解决方案是使用  O(mn) 的额外空间，但这并不是一个好的解决方案。
// 一个简单的改进方案是使用 O(m + n) 的额外空间，但这仍然不是最好的解决方案。
// 你能想出一个仅使用常量空间的解决方案吗？



class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<int> rows(matrix.size());
        vector<int> cols(matrix[0].size());
        for(int i = 0;i < matrix.size();++i)
        {
            for(int j = 0;j < matrix[0].size();++j)
            {
                if(0 == matrix[i][j])
                {
                    rows[i] = 1;
                    cols[j] = 1;
                }
            }
        }

        for(int i = 0;i < rows.size();++i) if(rows[i]) for(int j = 0;j < matrix[i].size();++j) matrix[i][j] = 0;
        for(int i = 0;i < cols.size();++i) if(cols[i]) for(int j = 0;j < matrix.size();++j) matrix[j][i] = 0;
    }
};

// class Solution {
// public:
//     void setZeroes(vector<vector<int>>& matrix) {
//         vector<pair<int, int>> zeros;
//         for(int i = 0;i < matrix.size();++i)
//         {
//             for(int j = 0;j < matrix[0].size();++j)
//             {
//                 if(0 == matrix[i][j]) zeros.push_back(make_pair(i, j));
//             }
//         }

//         for(const auto& [x, y] : zeros)
//         {
//             for(int i = 0;i < matrix[x].size();++i) matrix[x][i] = 0;
//             for(int i = 0;i < matrix.size();++i) matrix[i][y] = 0;
//         }
//     }
// };


// class Solution {
//     void set_zero(vector<vector<int>>& matrix, int x, int y)
//     {
//         if(x < 0 || x >= matrix.size() || y < 0 || y >= matrix[0].size()) return;

//         matrix[x][y] = 0;
//         set_zero(matrix, x - 1, y);
//         set_zero(matrix, x + 1, y);
//         set_zero(matrix, x, y - 1);
//         set_zero(matrix, x, y + 1);
//     }
// public:
//     void setZeroes(vector<vector<int>>& matrix) {
//         for(int i = 0;i < matrix.size();++i)
//         {
//             for(int j = 0;j < matrix[0].size();++j)
//             {
//                 if(0 == matrix[i][j]) set_zero(matrix, i, j);
//             }
//         }
//     }
// };