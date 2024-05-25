/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2024-05-25 14:20:21
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2024-05-25 14:21:25
 * @FilePath: \every-little-progress\day 544\test.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */


// 1. 两数之和
// https://leetcode.cn/problems/two-sum/description/
// 给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 target  的那 两个 整数，并返回它们的数组下标。

// 你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。

// 你可以按任意顺序返回答案。

 

// 示例 1：

// 输入：nums = [2,7,11,15], target = 9
// 输出：[0,1]
// 解释：因为 nums[0] + nums[1] == 9 ，返回 [0, 1] 。
// 示例 2：

// 输入：nums = [3,2,4], target = 6
// 输出：[1,2]
// 示例 3：

// 输入：nums = [3,3], target = 6
// 输出：[0,1]
 

// 提示：

// 2 <= nums.length <= 104
// -109 <= nums[i] <= 109
// -109 <= target <= 109
// 只会存在一个有效答案
 

// 进阶：你可以想出一个时间复杂度小于 O(n2) 的算法吗？


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hash;
        for(int i = 0;i < nums.size();++i)
        {
            if(hash.end() != hash.find(target - nums[i])) return {i, hash[target - nums[i]]};
            
            hash[nums[i]] = i;
        }

        return vector<int>();
    }
};

// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         for(int i = 0;i < nums.size();++i) for(int j = 0;j < i;++j) if(nums[i] + nums[j] == target) return {i, j};

//         return vector<int>();
//     }
// };

// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         unordered_map<int, int> hash;
//         for(int i = 0;i < nums.size();++i) hash[nums[i]] = i;

//         for(int i = 0;i < nums.size();++i) 
//             if(hash.end() != hash.find(target - nums[i]) 
//             && i != hash[target- nums[i]]) 
//                 return {i, hash[target - nums[i]]};

//         return vector<int>();
//     }
// };
