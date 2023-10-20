/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2023-10-20 15:45:34
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2023-10-20 15:45:46
 * @FilePath: \every-little-progress\day 333\test.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */


// 1848. 到目标元素的最小距离
// https://leetcode.cn/problems/minimum-distance-to-the-target-element/description/
// 给你一个整数数组 nums （下标 从 0 开始 计数）以及两个整数 target 和 start ，请你找出一个下标 i ，满足 nums[i] == target 且 abs(i - start) 最小化 。注意：abs(x) 表示 x 的绝对值。

// 返回 abs(i - start) 。

// 题目数据保证 target 存在于 nums 中。

 

// 示例 1：

// 输入：nums = [1,2,3,4,5], target = 5, start = 3
// 输出：1
// 解释：nums[4] = 5 是唯一一个等于 target 的值，所以答案是 abs(4 - 3) = 1 。
// 示例 2：

// 输入：nums = [1], target = 1, start = 0
// 输出：0
// 解释：nums[0] = 1 是唯一一个等于 target 的值，所以答案是 abs(0 - 0) = 0 。
// 示例 3：

// 输入：nums = [1,1,1,1,1,1,1,1,1,1], target = 1, start = 0
// 输出：0
// 解释：nums 中的每个值都是 1 ，但 nums[0] 使 abs(i - start) 的结果得以最小化，所以答案是 abs(0 - 0) = 0 。
 

// 提示：

// 1 <= nums.length <= 1000
// 1 <= nums[i] <= 104
// 0 <= start < nums.length
// target 存在于 nums 中

class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int left = start, right = start;
        while(left >= 0 && right < nums.size())
        {
            if(nums[left] == target && nums[right] == target) return (start -left) < (right - start) ? (start -left) : (right - start);
            else if(nums[left] == target) return start -left;
            else if(nums[right] == target) return right - start;

            --left;
            ++right;
        }
        while(left >= 0)
        {
            if(nums[left] == target) return start -left;
            --left;
        }
        while(right < nums.size())
        {
            if(nums[right] == target) return right - start;
            ++right;
        }

        return 0;
    }
};
