/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2024-04-09 12:31:24
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2024-04-09 12:31:48
 * @FilePath: \every-little-progress\day 499\test.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */



// 1004. 最大连续1的个数 III
// https://leetcode.cn/problems/max-consecutive-ones-iii/description/
// 给定一个二进制数组 nums 和一个整数 k，如果可以翻转最多 k 个 0 ，则返回 数组中连续 1 的最大个数 。

 

// 示例 1：

// 输入：nums = [1,1,1,0,0,0,1,1,1,1,0], K = 2
// 输出：6
// 解释：[1,1,1,0,0,1,1,1,1,1,1]
// 粗体数字从 0 翻转到 1，最长的子数组长度为 6。
// 示例 2：

// 输入：nums = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], K = 3
// 输出：10
// 解释：[0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1]
// 粗体数字从 0 翻转到 1，最长的子数组长度为 10。
 

// 提示：

// 1 <= nums.length <= 105
// nums[i] 不是 0 就是 1
// 0 <= k <= nums.length

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0, right = 0;
        int maxL = 0;
        int cap = k;
        while(right < nums.size())
        {
            // right向右走直到nums[right]不为1且cap消耗完
            while(right < nums.size() && (nums[right] || cap)) if(0 == nums[right++]) --cap;

            // cout<<left<<"~"<<right<<" ";
            if(maxL < right - left) maxL = right - left;

            // left向后走直到回收cap或与right碰撞
            while(left < right && 0 == cap && cap < k) if(0 == nums[left++]) ++cap;

            // cap不足时无法越过0
            if(0 == cap)
            {
                while(right < nums.size() && 0 == nums[right]) ++right;
                left = right;
            }
        }

        return maxL;
    }
};