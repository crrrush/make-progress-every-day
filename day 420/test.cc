/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2024-01-16 17:03:46
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2024-01-16 17:04:15
 * @FilePath: \every-little-progress\day 420\test.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */



// 674. 最长连续递增序列
// https://leetcode.cn/problems/longest-continuous-increasing-subsequence/description/
// 给定一个未经排序的整数数组，找到最长且 连续递增的子序列，并返回该序列的长度。

// 连续递增的子序列 可以由两个下标 l 和 r（l < r）确定，如果对于每个 l <= i < r，都有 nums[i] < nums[i + 1] ，那么子序列 [nums[l], nums[l + 1], ..., nums[r - 1], nums[r]] 就是连续递增子序列。

 

// 示例 1：

// 输入：nums = [1,3,5,4,7]
// 输出：3
// 解释：最长连续递增序列是 [1,3,5], 长度为3。
// 尽管 [1,3,5,7] 也是升序的子序列, 但它不是连续的，因为 5 和 7 在原数组里被 4 隔开。 
// 示例 2：

// 输入：nums = [2,2,2,2,2]
// 输出：1
// 解释：最长连续递增序列是 [2], 长度为1。
 

// 提示：

// 1 <= nums.length <= 104
// -109 <= nums[i] <= 109


class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int max = 0;
        int cnt = 0;
        for(int i = 0;i < nums.size() - 1;++i)
        {
            ++cnt;
            if(nums[i] >= nums[i + 1])
            {
                if(max < cnt) max = cnt;
                cnt = 0;
            }
        }
        if(max <= cnt) return cnt + 1;

        return max;
    }
};