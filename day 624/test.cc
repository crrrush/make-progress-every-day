/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2024-08-19 13:29:55
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2024-08-19 13:30:23
 * @FilePath: \every-little-progress\day 624\test.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */


// 174. 地下城游戏
// https://leetcode.cn/problems/dungeon-game/description/
// 恶魔们抓住了公主并将她关在了地下城 dungeon 的 右下角 。地下城是由 m x n 个房间组成的二维网格。我们英勇的骑士最初被安置在 左上角 的房间里，他必须穿过地下城并通过对抗恶魔来拯救公主。

// 骑士的初始健康点数为一个正整数。如果他的健康点数在某一时刻降至 0 或以下，他会立即死亡。

// 有些房间由恶魔守卫，因此骑士在进入这些房间时会失去健康点数（若房间里的值为负整数，则表示骑士将损失健康点数）；其他房间要么是空的（房间里的值为 0），要么包含增加骑士健康点数的魔法球（若房间里的值为正整数，则表示骑士将增加健康点数）。

// 为了尽快解救公主，骑士决定每次只 向右 或 向下 移动一步。

// 返回确保骑士能够拯救到公主所需的最低初始健康点数。

// 注意：任何房间都可能对骑士的健康点数造成威胁，也可能增加骑士的健康点数，包括骑士进入的左上角房间以及公主被监禁的右下角房间。

 

// 示例 1：


// 输入：dungeon = [[-2,-3,3],[-5,-10,1],[10,30,-5]]
// 输出：7
// 解释：如果骑士遵循最佳路径：右 -> 右 -> 下 -> 下 ，则骑士的初始健康点数至少为 7 。
// 示例 2：

// 输入：dungeon = [[0]]
// 输出：1
 

// 提示：

// m == dungeon.length
// n == dungeon[i].length
// 1 <= m, n <= 200
// -1000 <= dungeon[i][j] <= 1000

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size(), n = dungeon[0].size();
        // int dp[201][201] = { 0 };
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, INT_MAX));
        // 1.初始化
        dp[m - 1][n] = dp[m][n - 1] = 1; 

        // 2. 状态转移方程和填表
        for(int i = m - 1;i >= 0;--i) for(int j = n - 1;j >= 0;--j)
        {
            dp[i][j] = min(dp[i + 1][j], dp[i][j + 1]) - dungeon[i][j];
            dp[i][j] = max(1, dp[i][j]);
        }

        return dp[0][0];
    }
};

