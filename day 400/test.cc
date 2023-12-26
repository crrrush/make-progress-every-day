/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2023-12-26 15:33:10
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2023-12-26 15:33:38
 * @FilePath: \every-little-progress\day 400\test.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */


// 1380. 矩阵中的幸运数
// https://leetcode.cn/problems/lucky-numbers-in-a-matrix/description/
// 给你一个 m * n 的矩阵，矩阵中的数字 各不相同 。请你按 任意 顺序返回矩阵中的所有幸运数。

// 幸运数 是指矩阵中满足同时下列两个条件的元素：

// 在同一行的所有元素中最小
// 在同一列的所有元素中最大
 

// 示例 1：

// 输入：matrix = [[3,7,8],[9,11,13],[15,16,17]]
// 输出：[15]
// 解释：15 是唯一的幸运数，因为它是其所在行中的最小值，也是所在列中的最大值。
// 示例 2：

// 输入：matrix = [[1,10,4,2],[9,3,8,7],[15,16,17,12]]
// 输出：[12]
// 解释：12 是唯一的幸运数，因为它是其所在行中的最小值，也是所在列中的最大值。
// 示例 3：

// 输入：matrix = [[7,8],[1,2]]
// 输出：[7]
// 解释：7是唯一的幸运数字，因为它是行中的最小值，列中的最大值。
 

// 提示：

// m == mat.length
// n == mat[i].length
// 1 <= n, m <= 50
// 1 <= matrix[i][j] <= 10^5
// 矩阵中的所有元素都是不同的


class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<pair<int, int>> mins(matrix.size());
        vector<int> nums;
        for(int i = 0;i < matrix.size();++i)
        {
            int min_pos = 0;
            for(int j = 0;j < matrix[i].size();++j) if(matrix[i][j] < matrix[i][min_pos]) min_pos = j;
            mins.push_back(make_pair(matrix[i][min_pos], min_pos));
        }
        for(const auto& [x, y] : mins)
        {
            bool flag = true;
            for(int i = 0;i < matrix.size() && flag;++i) if(matrix[i][y] > x) flag = false;
            if(flag) nums.push_back(x);
        }
        return nums;
    }
};