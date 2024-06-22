/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2024-06-22 22:37:44
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2024-06-22 22:38:09
 * @FilePath: \every-little-progress\day 570\test.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */


// 78. 子集
// https://leetcode.cn/problems/subsets/description/
// 给你一个整数数组 nums ，数组中的元素 互不相同 。返回该数组所有可能的
// 子集
// （幂集）。

// 解集 不能 包含重复的子集。你可以按 任意顺序 返回解集。

 

// 示例 1：

// 输入：nums = [1,2,3]
// 输出：[[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
// 示例 2：

// 输入：nums = [0]
// 输出：[[],[0]]
 

// 提示：

// 1 <= nums.length <= 10
// -10 <= nums[i] <= 10
// nums 中的所有元素 互不相同


class Solution {
    vector<vector<int>> ret;
    vector<int> path;

    void dfs(vector<int>& nums, int pos)
    {
        ret.push_back(path);
        for(int i = pos;i < nums.size();++i)
        {
            path.push_back(nums[i]);
            dfs(nums, i + 1);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        dfs(nums, 0);
        return ret;
    }
};


// class Solution {
//     vector<vector<int>> ret;
//     vector<int> path;

//     void dfs(vector<int>& nums, int pos)
//     {
//         if(pos == nums.size()) return ret.push_back(path);

//         dfs(nums, pos + 1);
//         path.push_back(nums[pos]);
//         dfs(nums, pos + 1);
//         path.pop_back();
//     }
// public:
//     vector<vector<int>> subsets(vector<int>& nums) {
//         dfs(nums, 0);
//         return ret;
//     }
// };


// class Solution {
//     vector<vector<int>> ret;

//     void dfs(vector<int>& nums, int pos, vector<int> v)
//     {
//         if(pos == nums.size()) return ret.push_back(v);

//         dfs(nums, pos + 1, v);
//         v.push_back(nums[pos]);
//         dfs(nums, pos + 1, v);
//     }
// public:
//     vector<vector<int>> subsets(vector<int>& nums) {
//         dfs(nums, 0, vector<int>());
//         return ret;
//     }
// };

