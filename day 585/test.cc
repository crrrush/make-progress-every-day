/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2024-07-07 15:22:57
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2024-07-07 15:24:08
 * @FilePath: \every-little-progress\day 585\test.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */

// 980. 不同路径 III
// https://leetcode.cn/problems/unique-paths-iii/description/
// 在二维网格 grid 上，有 4 种类型的方格：

// 1 表示起始方格。且只有一个起始方格。
// 2 表示结束方格，且只有一个结束方格。
// 0 表示我们可以走过的空方格。
// -1 表示我们无法跨越的障碍。
// 返回在四个方向（上、下、左、右）上行走时，从起始方格到结束方格的不同路径的数目。

// 每一个无障碍方格都要通过一次，但是一条路径中不能重复通过同一个方格。

 

// 示例 1：

// 输入：[[1,0,0,0],[0,0,0,0],[0,0,2,-1]]
// 输出：2
// 解释：我们有以下两条路径：
// 1. (0,0),(0,1),(0,2),(0,3),(1,3),(1,2),(1,1),(1,0),(2,0),(2,1),(2,2)
// 2. (0,0),(1,0),(2,0),(2,1),(1,1),(0,1),(0,2),(0,3),(1,3),(1,2),(2,2)
// 示例 2：

// 输入：[[1,0,0,0],[0,0,0,0],[0,0,0,2]]
// 输出：4
// 解释：我们有以下四条路径： 
// 1. (0,0),(0,1),(0,2),(0,3),(1,3),(1,2),(1,1),(1,0),(2,0),(2,1),(2,2),(2,3)
// 2. (0,0),(0,1),(1,1),(1,0),(2,0),(2,1),(2,2),(1,2),(0,2),(0,3),(1,3),(2,3)
// 3. (0,0),(1,0),(2,0),(2,1),(2,2),(1,2),(1,1),(0,1),(0,2),(0,3),(1,3),(2,3)
// 4. (0,0),(1,0),(2,0),(2,1),(1,1),(0,1),(0,2),(0,3),(1,3),(1,2),(2,2),(2,3)
// 示例 3：

// 输入：[[0,1],[2,0]]
// 输出：0
// 解释：
// 没有一条路能完全穿过每一个空的方格一次。
// 请注意，起始和结束方格可以位于网格中的任意位置。
 

// 提示：

// 1 <= grid.length * grid[0].length <= 20

class Solution {
    // bool check[20][20]; // 改原表代替
    int cnt = 0;
    int sum = 0;
    int pnum = 0;

    int dx[4] = { 1, -1, 0, 0};
    int dy[4] = { 0, 0, 1, -1};

    void dfs(vector<vector<int>>& grid, int i , int j)
    {
        for(int k = 0;k < 4;++k)
        {
            int x = i + dx[k], y = j + dy[k];
            if(x >= 0 && x < grid.size() && y >= 0 && y < grid[i].size() && grid[x][y] != -1 && grid[x][y] != 3)
            {
                if(2 == grid[x][y])
                {
                    if(pnum == sum) ++cnt;
                    continue;
                }

                grid[x][y] = 3;
                ++pnum;
                dfs(grid, x, y);
                --pnum;
                grid[x][y] = 0;
            }
        }
    }
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        sum = grid.size() * grid[0].size();
        for(const auto& e : grid) for(const auto& r : e) if(0 != r) --sum;
        for(int i = 0;i < grid.size();++i) 
            for(int j = 0;j < grid[i].size();++j) 
                if(1 == grid[i][j])
                {
                    grid[i][j] = -1;
                    dfs(grid, i, j);
                    return cnt;
                }

        return cnt;
    }
};