/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2024-08-16 11:45:26
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2024-08-16 11:48:00
 * @FilePath: \every-little-progress\day 621\test.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */


// LCR 166. 珠宝的最高价值
// https://leetcode.cn/problems/li-wu-de-zui-da-jie-zhi-lcof/description/
// 现有一个记作二维矩阵 frame 的珠宝架，其中 frame[i][j] 为该位置珠宝的价值。拿取珠宝的规则为：

// 只能从架子的左上角开始拿珠宝
// 每次可以移动到右侧或下侧的相邻位置
// 到达珠宝架子的右下角时，停止拿取
// 注意：珠宝的价值都是大于 0 的。除非这个架子上没有任何珠宝，比如 frame = [[0]]。

 

// 示例 1:

// 输入: frame = [[1,3,1],[1,5,1],[4,2,1]]
// 输出: 12
// 解释: 路径 1→3→5→2→1 可以拿到最高价值的珠宝
 

// 提示：

// 0 < frame.length <= 200
// 0 < frame[0].length <= 200


class Solution {
public:
    int jewelleryValue(vector<vector<int>>& frame) {
        int m = frame.size(), n = frame[0].size();
        int dp[201][201] = { 0 };

        for(int i = 1;i <= m;++i) for(int j = 1;j <= n;++j) dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + frame[i - 1][j - 1];

        return dp[m][n];
    }
};

// class Solution {
// public:
//     int jewelleryValue(vector<vector<int>>& frame) {
//         int m = frame.size(), n = frame[0].size();
//         int dp[200][200];
//         dp[0][0] = frame[0][0];
//         for(int i = 1;i < m;++i) dp[i][0] = dp[i - 1][0] + frame[i][0];
//         for(int j = 1;j < n;++j) dp[0][j] = dp[0][j - 1] + frame[0][j];

//         for(int i = 1;i < m;++i) for(int j = 1;j < n;++j) dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + frame[i][j];

//         return dp[m - 1][n - 1];
//     }
// };
