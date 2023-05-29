
// 119. 杨辉三角 II

// https://leetcode.cn/problems/pascals-triangle-ii/
// 给定一个非负索引 rowIndex，返回「杨辉三角」的第 rowIndex 行。

// 在「杨辉三角」中，每个数是它左上方和右上方的数的和。

 

// 示例 1:

// 输入: rowIndex = 3
// 输出: [1,3,3,1]

// 示例 2:

// 输入: rowIndex = 0
// 输出: [1]

// 示例 3:

// 输入: rowIndex = 1
// 输出: [1,1]

 

// 提示:

//     0 <= rowIndex <= 33


class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> vv;
        vv.resize(rowIndex + 1);
        for(int i = 0;i <= rowIndex;++i)
        {
            vv[i].resize(i + 1);
            vv[i][0] = vv[i][i] = 1;
            for(int j = 1;j < i;++j)
            {
                vv[i][j] = vv[i - 1][j] + vv[i - 1][j - 1];
            }
        }

        return vv[rowIndex];
    }
};
