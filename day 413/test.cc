/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2024-01-09 22:03:51
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2024-01-09 22:04:21
 * @FilePath: \every-little-progress\day 413\test.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */


// 2740. 找出分区值
// https://leetcode.cn/problems/find-the-value-of-the-partition/description/
// 给你一个 正 整数数组 nums 。

// 将 nums 分成两个数组：nums1 和 nums2 ，并满足下述条件：

// 数组 nums 中的每个元素都属于数组 nums1 或数组 nums2 。
// 两个数组都 非空 。
// 分区值 最小 。
// 分区值的计算方法是 |max(nums1) - min(nums2)| 。

// 其中，max(nums1) 表示数组 nums1 中的最大元素，min(nums2) 表示数组 nums2 中的最小元素。

// 返回表示分区值的整数。

 

// 示例 1：

// 输入：nums = [1,3,2,4]
// 输出：1
// 解释：可以将数组 nums 分成 nums1 = [1,2] 和 nums2 = [3,4] 。
// - 数组 nums1 的最大值等于 2 。
// - 数组 nums2 的最小值等于 3 。
// 分区值等于 |2 - 3| = 1 。
// 可以证明 1 是所有分区方案的最小值。
// 示例 2：

// 输入：nums = [100,1,10]
// 输出：9
// 解释：可以将数组 nums 分成 nums1 = [10] 和 nums2 = [100,1] 。 
// - 数组 nums1 的最大值等于 10 。 
// - 数组 nums2 的最小值等于 1 。 
// 分区值等于 |10 - 1| = 9 。 
// 可以证明 9 是所有分区方案的最小值。
 

// 提示：

// 2 <= nums.length <= 105
// 1 <= nums[i] <= 109


class Solution {
public:
    int findValueOfPartition(vector<int>& nums) {
       sort(nums.begin(), nums.end());
       size_t d = -1;
       for(int i = 0;i < nums.size() - 1;++i) if(nums[i + 1] - nums[i] < d) d = nums[i + 1] - nums[i];
       return d;
    }
};