/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2024-06-28 20:19:24
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2024-06-28 20:19:52
 * @FilePath: \every-little-progress\day 576\test.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */


// 77. 组合
// https://leetcode.cn/problems/combinations/description/
// 给定两个整数 n 和 k，返回范围 [1, n] 中所有可能的 k 个数的组合。

// 你可以按 任何顺序 返回答案。

 

// 示例 1：

// 输入：n = 4, k = 2
// 输出：
// [
//   [2,4],
//   [3,4],
//   [2,3],
//   [1,2],
//   [1,3],
//   [1,4],
// ]
// 示例 2：

// 输入：n = 1, k = 1
// 输出：[[1]]
 

// 提示：

// 1 <= n <= 20
// 1 <= k <= n



class Solution {
    vector<vector<int>> ret;
    vector<int> path;
    int _n = 0;
    int _k = 0;

    // void dfs(const int& n, const int& k, int pos)
    void dfs(int pos)
    {
        if(_k == path.size()) return ret.push_back(path);

        for(int i = pos;i <= _n;++i)
        {
            path.push_back(i);
            dfs(i + 1);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        _n = n;
        _k = k;
        dfs(1);
        return ret;
    }
};


