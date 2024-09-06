/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2024-09-06 23:22:29
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2024-09-06 23:23:12
 * @FilePath: \every-little-progress\day 639\test.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */


// 1567. 乘积为正数的最长子数组长度
// https://leetcode.cn/problems/maximum-length-of-subarray-with-positive-product/description/
// 给你一个整数数组 nums ，请你求出乘积为正数的最长子数组的长度。

// 一个数组的子数组是由原数组中零个或者更多个连续数字组成的数组。

// 请你返回乘积为正数的最长子数组长度。

 

// 示例  1：

// 输入：nums = [1,-2,-3,4]
// 输出：4
// 解释：数组本身乘积就是正数，值为 24 。
// 示例 2：

// 输入：nums = [0,1,-2,-3,-4]
// 输出：3
// 解释：最长乘积为正数的子数组为 [1,-2,-3] ，乘积为 6 。
// 注意，我们不能把 0 也包括到子数组中，因为这样乘积为 0 ，不是正数。
// 示例 3：

// 输入：nums = [-1,-2,-3,0,1]
// 输出：2
// 解释：乘积为正数的最长子数组是 [-1,-2] 或者 [-2,-3] 。
 

// 提示：

// 1 <= nums.length <= 10^5
// -10^9 <= nums[i] <= 10^9


class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int n = nums.size();
        int f[100001] = { 0 }; // 以i位置结尾乘积为正数的子数组最长长度
        int g[100001] = { 0 }; // 以i位置结尾乘积为负数的子数组最长长度

        int ret = 0;
        for(int i = 1;i <= n;++i)
        {
            if(nums[i - 1] > 0)
            {
                f[i] = (f[i - 1] > 0 ? f[i - 1] + 1 : 1);
                g[i] = (g[i - 1] > 0 ? g[i - 1] + 1 : 0); 
            }
            else if(nums[i - 1] < 0)
            {
                f[i] = (g[i - 1] > 0 ? g[i - 1] + 1 : 0); 
                g[i] = (f[i - 1] > 0 ? f[i - 1] + 1 : 1); 
            }
            else
            {
                f[i] = 0;
                g[i] = 0;
            }
            ret = max(ret, f[i]);
        }

        return ret;
    }
};
