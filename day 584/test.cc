/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2024-07-06 16:35:38
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2024-07-06 16:36:06
 * @FilePath: \every-little-progress\day 584\test.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */


// 1219. 黄金矿工
// https://leetcode.cn/problems/path-with-maximum-gold/description/
// 你要开发一座金矿，地质勘测学家已经探明了这座金矿中的资源分布，并用大小为 m * n 的网格 grid 进行了标注。每个单元格中的整数就表示这一单元格中的黄金数量；如果该单元格是空的，那么就是 0。

// 为了使收益最大化，矿工需要按以下规则来开采黄金：

// 每当矿工进入一个单元，就会收集该单元格中的所有黄金。
// 矿工每次可以从当前位置向上下左右四个方向走。
// 每个单元格只能被开采（进入）一次。
// 不得开采（进入）黄金数目为 0 的单元格。
// 矿工可以从网格中 任意一个 有黄金的单元格出发或者是停止。
 

// 示例 1：

// 输入：grid = [[0,6,0],[5,8,7],[0,9,0]]
// 输出：24
// 解释：
// [[0,6,0],
//  [5,8,7],
//  [0,9,0]]
// 一种收集最多黄金的路线是：9 -> 8 -> 7。
// 示例 2：

// 输入：grid = [[1,0,7],[2,0,6],[3,4,5],[0,3,0],[9,0,20]]
// 输出：28
// 解释：
// [[1,0,7],
//  [2,0,6],
//  [3,4,5],
//  [0,3,0],
//  [9,0,20]]
// 一种收集最多黄金的路线是：1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7。
 

// 提示：

// 1 <= grid.length, grid[i].length <= 15
// 0 <= grid[i][j] <= 100
// 最多 25 个单元格中有黄金。



class Solution {
    int max = 0;
    bool check[15][15];
    int sum = 0;
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    void dfs(vector<vector<int>>& grid, int i, int j)
    {
        // bool end = true;
        for(int k = 0;k < 4;++k)
        {
            int x = i + dx[k], y = j + dy[k];
            if(x >= 0 && x < grid.size() && y >= 0 && y < grid[i].size() && !check[x][y] && grid[x][y] != 0)
            {
                // end = false; // 还未终止

                sum += grid[x][y];
                check[x][y] = true;
                dfs(grid, x, y);
                check[x][y] = false;
                sum -= grid[x][y];
            }
        }

        if(sum > max) max = sum;
        // if(end && sum > max) max = sum;
    }
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        for(int i = 0;i < grid.size();++i) 
            for(int j = 0;j < grid[i].size();++j) 
            {
                if(0 != grid[i][j])
                {
                    sum += grid[i][j];
                    check[i][j] = true;
                    dfs(grid, i, j);
                    check[i][j] = false;
                    sum -= grid[i][j];
                }
            }
        // for(int i = 0;i < grid.size();++i) for(int j = 0;j < grid[i].size();++j) dfs(grid, i, j);
        return max;
    }
};
