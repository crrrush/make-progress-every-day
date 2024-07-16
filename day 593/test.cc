/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2024-07-16 20:17:52
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2024-07-16 20:18:18
 * @FilePath: \every-little-progress\day 593\test.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */

// 62. 不同路径
// https://leetcode.cn/problems/unique-paths/description/
// 基因序列可以表示为一条由 8 个字符组成的字符串，其中每个字符都是 'A'、'C'、'G' 和 'T' 之一。

// 假设我们需要调查从基因序列 start 变为 end 所发生的基因变化。一次基因变化就意味着这个基因序列中的一个字符发生了变化。

// 例如，"AACCGGTT" --> "AACCGGTA" 就是一次基因变化。
// 另有一个基因库 bank 记录了所有有效的基因变化，只有基因库中的基因才是有效的基因序列。（变化后的基因必须位于基因库 bank 中）

// 给你两个基因序列 start 和 end ，以及一个基因库 bank ，请你找出并返回能够使 start 变化为 end 所需的最少变化次数。如果无法完成此基因变化，返回 -1 。

// 注意：起始基因序列 start 默认是有效的，但是它并不一定会出现在基因库中。

 

// 示例 1：

// 输入：start = "AACCGGTT", end = "AACCGGTA", bank = ["AACCGGTA"]
// 输出：1
// 示例 2：

// 输入：start = "AACCGGTT", end = "AAACGGTA", bank = ["AACCGGTA","AACCGCTA","AAACGGTA"]
// 输出：2
// 示例 3：

// 输入：start = "AAAAACCC", end = "AACCCCCC", bank = ["AAAACCCC","AAACCCCC","AACCCCCC"]
// 输出：3
 

// 提示：

// start.length == 8
// end.length == 8
// 0 <= bank.length <= 10
// bank[i].length == 8
// start、end 和 bank[i] 仅由字符 ['A', 'C', 'G', 'T'] 组成


class Solution {
    int dp[101][101];

    // 动态规划
public:
    int uniquePaths(int m, int n) {
        dp[1][1] = 1;
        for(int i = 1;i <= m;++i) 
            for(int j = 1;j <= n;++j)
            {
                if(1 == i && 1 == j) continue;
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }

        return dp[m][n];
    }
};


// class Solution {
//     int _m, _n;
//     int hash[101][101];

//     // 记忆化搜索
//     int dfs(int i, int j)
//     {
//         if(-1 != hash[i][j]) return hash[i][j];

//         if(i >= _m || j >= _n) return 0;

//         if(i == _m - 1 && j == _n - 1)
//         {
//             hash[i][j] = 1;
//             return 1;
//         }

//         hash[i][j] = dfs(i + 1, j) + dfs(i, j + 1);
//         return hash[i][j];
//     }
// public:
//     int uniquePaths(int m, int n) {
//         _m = m;
//         _n = n;
//         for(int i = 0;i < 101;++i) for(int j = 0;j < 101;++j) hash[i][j] = -1;
//         return dfs(0, 0);
//     }
// };
