/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2024-04-07 14:12:55
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2024-04-07 14:13:22
 * @FilePath: \every-little-progress\day 497\test.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */



// 209. 长度最小的子数组
// https://leetcode.cn/problems/minimum-size-subarray-sum/
// 给定一个含有 n 个正整数的数组和一个正整数 target 。

// 找出该数组中满足其总和大于等于 target 的长度最小的 连续
// 子数组
//  [numsl, numsl+1, ..., numsr-1, numsr] ，并返回其长度。如果不存在符合条件的子数组，返回 0 。

 

// 示例 1：

// 输入：target = 7, nums = [2,3,1,2,4,3]
// 输出：2
// 解释：子数组 [4,3] 是该条件下的长度最小的子数组。
// 示例 2：

// 输入：target = 4, nums = [1,4,4]
// 输出：1
// 示例 3：

// 输入：target = 11, nums = [1,1,1,1,1,1,1,1]
// 输出：0
 

// 提示：

// 1 <= target <= 109
// 1 <= nums.length <= 105
// 1 <= nums[i] <= 105
 

// 进阶：

// 如果你已经实现 O(n) 时间复杂度的解法, 请尝试设计一个 O(n log(n)) 时间复杂度的解法。

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int min = nums.size() + 1;
        int left = 0, right = 0;
        int sum = 0;
        while(right < nums.size())
        {
            while(right < nums.size() && sum < target) sum += nums[right++];

            // cout<<left<<"~"<<right<<"->";

            while(left < right && sum >= target) sum -= nums[left++];

            // cout<<left<<"~"<<right<<" ";

            if(min > right - left + 1) min = right - left + 1;
            // sum -= nums[left++];
        }

        return min == nums.size() + 1 ? 0 : min;
    }
};