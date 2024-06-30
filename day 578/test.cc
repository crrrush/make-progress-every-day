/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2024-06-30 18:50:53
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2024-06-30 18:59:58
 * @FilePath: \every-little-progress\day 578\test.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */


// 526. 优美的排列
// https://leetcode.cn/problems/beautiful-arrangement/description/
// 假设有从 1 到 n 的 n 个整数。用这些整数构造一个数组 perm（下标从 1 开始），只要满足下述条件 之一 ，该数组就是一个 优美的排列 ：

// perm[i] 能够被 i 整除
// i 能够被 perm[i] 整除
// 给你一个整数 n ，返回可以构造的 优美排列 的 数量 。

 

// 示例 1：

// 输入：n = 2
// 输出：2
// 解释：
// 第 1 个优美的排列是 [1,2]：
//     - perm[1] = 1 能被 i = 1 整除
//     - perm[2] = 2 能被 i = 2 整除
// 第 2 个优美的排列是 [2,1]:
//     - perm[1] = 2 能被 i = 1 整除
//     - i = 2 能被 perm[2] = 1 整除
// 示例 2：

// 输入：n = 1
// 输出：1
 

// 提示：

// 1 <= n <= 15


class Solution {
    // vector<int> path;
    bool check[16];
    int pos = 1;

    int dfs(const int& n)
    {
        // if(path.size() == n)
        if(pos == n + 1)
        {
            // cout<<" pos:"<<pos<<endl;
            // for(int i = 0;i < path.size();++i) if(path[i] % (i + 1) != 0 && (i + 1) % path[i] != 0) return 0;
            return 1;
        }

        int cnt = 0;
        for(int i = 1;i <= n;++i)
        {
            if(false == check[i] && (i % pos == 0 || pos % i == 0))
            {
                // cout<<i<<" ";
                // path[pos] = i;
                check[i] = true;
                ++pos;
                cnt += dfs(n);
                --pos;
                check[i] = false;
                // path[pos] = 0;
            }
        }

        return cnt;
    }
public:
    int countArrangement(int n) {
        return dfs(n);
    }
};

