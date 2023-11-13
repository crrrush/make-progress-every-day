/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2023-11-13 12:52:48
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2023-11-13 12:53:17
 * @FilePath: \every-little-progress\day 357\test.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */



// 2352. 相等行列对
// https://leetcode.cn/problems/equal-row-and-column-pairs/description/
// 给你一个下标从 0 开始、大小为 n x n 的整数矩阵 grid ，返回满足 Ri 行和 Cj 列相等的行列对 (Ri, Cj) 的数目。

// 如果行和列以相同的顺序包含相同的元素（即相等的数组），则认为二者是相等的。

 

// 示例 1：



// 输入：grid = [[3,2,1],[1,7,6],[2,7,7]]
// 输出：1
// 解释：存在一对相等行列对：
// - (第 2 行，第 1 列)：[2,7,7]
// 示例 2：



// 输入：grid = [[3,1,2,2],[1,4,4,5],[2,4,2,2],[2,4,2,2]]
// 输出：3
// 解释：存在三对相等行列对：
// - (第 0 行，第 0 列)：[3,1,2,2]
// - (第 2 行, 第 2 列)：[2,4,2,2]
// - (第 3 行, 第 2 列)：[2,4,2,2]
 

// 提示：

// n == grid.length == grid[i].length
// 1 <= n <= 200
// 1 <= grid[i][j] <= 105

class Solution {
    bool is_same_row(const vector<int> & v1, const vector<int> & v2)
    {
        for(int i = 0;i < v1.size();++i) if(v1[i] != v2[i]) return false;
        return true;
    }
public:
    int equalPairs(vector<vector<int>>& grid) {
        int cnt = 0;
        for(int i = 0;i < grid[0].size();++i)
        {
            vector<int> tmp;
            tmp.resize(grid.size());
            for(int j = 0;j < grid.size();++j) tmp[j] = grid[j][i];
            for(int j = 0;j < grid.size();++j) if(is_same_row(grid[j], tmp)) ++cnt;
        }
        return cnt;
    }
};