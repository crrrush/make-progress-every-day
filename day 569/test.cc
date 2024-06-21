/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2024-06-21 19:44:39
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2024-06-21 19:45:07
 * @FilePath: \every-little-progress\day 569\test.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */


// 46. 全排列
// https://leetcode.cn/problems/permutations/description/
// 给定一个不含重复数字的数组 nums ，返回其 所有可能的全排列 。你可以 按任意顺序 返回答案。

 

// 示例 1：

// 输入：nums = [1,2,3]
// 输出：[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
// 示例 2：

// 输入：nums = [0,1]
// 输出：[[0,1],[1,0]]
// 示例 3：

// 输入：nums = [1]
// 输出：[[1]]
 

// 提示：

// 1 <= nums.length <= 6
// -10 <= nums[i] <= 10
// nums 中的所有整数 互不相同


class Solution {
    vector<vector<int>> ret;
    vector<int> path;
    bool check[7];


    void dfs(vector<int>& nums)
    {
        if(path.size() == nums.size()) return ret.push_back(path);
        for(int i = 0;i < nums.size();++i)
        {
            if(false == check[i])
            {
                check[i] = true;
                path.push_back(nums[i]);
                dfs(nums);
                // 回溯 恢复现场
                path.pop_back();
                check[i] = false;
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        dfs(nums);
        return ret;
    }
};


// class Solution {
//     vector<vector<int>> ret;
//     unordered_map<int, bool> hash;
//     int cnt = 0;

//     void dfs(vector<int>& nums, vector<int>& v)
//     {
//         if(cnt == nums.size()) return ret.push_back(v);
//         for(const auto& e : nums)
//         {
//             if(hash[e]) continue;

//             hash[e] = true;
//             ++cnt;
//             v.push_back(e);
//             dfs(nums, v);
//             v.pop_back();
//             --cnt;
//             hash[e] = false;
//         }
//     }
// public:
//     vector<vector<int>> permute(vector<int>& nums) {
//         for(const auto& e : nums) hash[e] = false;
//         vector<int> v;
//         dfs(nums, v);
//         return ret;
//     }
// };

