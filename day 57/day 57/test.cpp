#define _CRT_SECURE_NO_WARNINGS

//
//118. 杨辉三角
//https ://leetcode.cn/problems/pascals-triangle/
//给定一个非负整数 numRows，生成「杨辉三角」的前 numRows 行。
//
//在「杨辉三角」中，每个数是它左上方和右上方的数的和。
//
//
//
//示例 1:
//
//输入: numRows = 5
//输出 : [[1], [1, 1], [1, 2, 1], [1, 3, 3, 1], [1, 4, 6, 4, 1]]
//
//示例 2 :
//
//    输入 : numRows = 1
//    输出 : [[1]]
//
//
//
//提示:
//
//    1 <= numRows <= 30



class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> vv;
        vv.resize(numRows);
        for (int i = 0; i < numRows; ++i)
        {
            vv[i].resize(i + 1);
            vv[i][0] = vv[i][i] = 1;
            for (int j = 1; j < i; ++j)
            {
                vv[i][j] = vv[i - 1][j] + vv[i - 1][j - 1];
            }
        }

        return vv;
    }
};