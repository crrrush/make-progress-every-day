/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2023-11-04 13:46:37
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2023-11-04 13:50:31
 * @FilePath: \every-little-progress\day 348\test.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */


// 2341. 数组能形成多少数对
// https://leetcode.cn/problems/maximum-number-of-pairs-in-array/description/ 
// 给你一个下标从 0 开始的整数数组 nums 。在一步操作中，你可以执行以下步骤：

// 从 nums 选出 两个 相等的 整数
// 从 nums 中移除这两个整数，形成一个 数对
// 请你在 nums 上多次执行此操作直到无法继续执行。

// 返回一个下标从 0 开始、长度为 2 的整数数组 answer 作为答案，其中 answer[0] 是形成的数对数目，answer[1] 是对 nums 尽可能执行上述操作后剩下的整数数目。

 

// 示例 1：

// 输入：nums = [1,3,2,1,3,2,2]
// 输出：[3,1]
// 解释：
// nums[0] 和 nums[3] 形成一个数对，并从 nums 中移除，nums = [3,2,3,2,2] 。
// nums[0] 和 nums[2] 形成一个数对，并从 nums 中移除，nums = [2,2,2] 。
// nums[0] 和 nums[1] 形成一个数对，并从 nums 中移除，nums = [2] 。
// 无法形成更多数对。总共形成 3 个数对，nums 中剩下 1 个数字。
// 示例 2：

// 输入：nums = [1,1]
// 输出：[1,0]
// 解释：nums[0] 和 nums[1] 形成一个数对，并从 nums 中移除，nums = [] 。
// 无法形成更多数对。总共形成 1 个数对，nums 中剩下 0 个数字。
// 示例 3：

// 输入：nums = [0]
// 输出：[0,1]
// 解释：无法形成数对，nums 中剩下 1 个数字。
 

// 提示：

// 1 <= nums.length <= 100
// 0 <= nums[i] <= 100

class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        vector<int> res(2);
        unordered_map<int, int> hash;
        for(const auto& e : nums) ++hash[e];

        for(const auto& [x, y] : hash)
        {
            // cout<< x<<" : "<<y<<endl;
            res[0] += (y / 2);
            if(y % 2) ++res[1];
        }

        return res;
    }
};