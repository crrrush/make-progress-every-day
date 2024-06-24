/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2024-06-24 23:29:24
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2024-06-24 23:30:14
 * @FilePath: \every-little-progress\day 572\test.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */


// 47. 全排列 II
// https://leetcode.cn/problems/permutations-ii/description/
// 给定一个可包含重复数字的序列 nums ，按任意顺序 返回所有不重复的全排列。

 

// 示例 1：

// 输入：nums = [1,1,2]
// 输出：
// [[1,1,2],
//  [1,2,1],
//  [2,1,1]]
// 示例 2：

// 输入：nums = [1,2,3]
// 输出：[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
 

// 提示：

// 1 <= nums.length <= 8
// -10 <= nums[i] <= 10


class Solution {
    vector<vector<int>> ret;
    vector<int> path;
    bool check[8];

    void dfs(vector<int>& nums)
    {
        if(path.size() == nums.size()) return ret.push_back(path);
        for(int i = 0;i < nums.size();++i)
        {
            // 剪枝
            if(check[i]) continue;
            if(i > 0 && check[i - 1] == false && nums[i] == nums[i - 1]) continue;

            path.push_back(nums[i]);
            check[i] = true;
            dfs(nums);
            check[i] = false;
            path.pop_back();

        }

    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        dfs(nums);
        return ret;
    }
};

// class Solution {
//     vector<vector<int>> ret;
//     vector<int> path;
//     bool check[8];

//     void dfs(vector<int>& nums)
//     {
//         if(path.size() == nums.size()) return ret.push_back(path);
//         unordered_set<int> hash;
//         for(int i = 0;i < nums.size();++i)
//         {
//             if(check[i] || hash.end() != hash.find(nums[i])) continue;
//             hash.insert(nums[i]);
//             path.push_back(nums[i]);
//             check[i] = true;
//             dfs(nums);
//             check[i] = false;
//             path.pop_back();

//         }

//     }
// public:
//     vector<vector<int>> permuteUnique(vector<int>& nums) {
//         for(int i = 0;i < 8;++i) check[i] = false;
//         dfs(nums);
//         return ret;
//     }
// };
