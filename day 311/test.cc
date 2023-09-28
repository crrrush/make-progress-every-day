/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2023-09-28 11:57:35
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2023-09-28 11:58:05
 * @FilePath: \every-little-progress\day 311\test.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */



// 2089. 找出数组排序后的目标下标
// https://leetcode.cn/problems/find-target-indices-after-sorting-array/
// 给你一个下标从 0 开始的整数数组 nums 以及一个目标元素 target 。

// 目标下标 是一个满足 nums[i] == target 的下标 i 。

// 将 nums 按 非递减 顺序排序后，返回由 nums 中目标下标组成的列表。如果不存在目标下标，返回一个 空 列表。返回的列表必须按 递增 顺序排列。

 

// 示例 1：

// 输入：nums = [1,2,5,2,3], target = 2
// 输出：[1,2]
// 解释：排序后，nums 变为 [1,2,2,3,5] 。
// 满足 nums[i] == 2 的下标是 1 和 2 。
// 示例 2：

// 输入：nums = [1,2,5,2,3], target = 3
// 输出：[3]
// 解释：排序后，nums 变为 [1,2,2,3,5] 。
// 满足 nums[i] == 3 的下标是 3 。
// 示例 3：

// 输入：nums = [1,2,5,2,3], target = 5
// 输出：[4]
// 解释：排序后，nums 变为 [1,2,2,3,5] 。
// 满足 nums[i] == 5 的下标是 4 。
// 示例 4：

// 输入：nums = [1,2,5,2,3], target = 4
// 输出：[]
// 解释：nums 中不含值为 4 的元素。
 

// 提示：

// 1 <= nums.length <= 100
// 1 <= nums[i], target <= 100

class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<int> v;
        for(int i = 0;i < nums.size();++i) if(nums[i] == target) v.push_back(i);

        return v;
    }
};