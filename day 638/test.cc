/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2024-09-05 21:53:20
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2024-09-05 21:53:45
 * @FilePath: \every-little-progress\day 638\test.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */


// 152. 乘积最大子数组
// https://leetcode.cn/problems/maximum-product-subarray/submissions/561961505/
// 给你一个整数数组 nums ，请你找出数组中乘积最大的非空连续 
// 子数组
// （该子数组中至少包含一个数字），并返回该子数组所对应的乘积。

// 测试用例的答案是一个 32-位 整数。

 

// 示例 1:

// 输入: nums = [2,3,-2,4]
// 输出: 6
// 解释: 子数组 [2,3] 有最大乘积 6。
// 示例 2:

// 输入: nums = [-2,0,-1]
// 输出: 0
// 解释: 结果不能为 2, 因为 [-2,-1] 不是子数组。
 

// 提示:

// 1 <= nums.length <= 2 * 104
// -10 <= nums[i] <= 10
// nums 的任何子数组的乘积都 保证 是一个 32-位 整数


class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int f[20001] = { 0 }; // 以此位置为结尾的子数组最大积
        int g[20001] = { 0 }; // 以此位置为结尾的子数组最小积
        f[0] = g[0] = 1;

        int ret = INT_MIN;
        for(int i = 1;i <= n;++i)
        {
            f[i] = max(max(g[i - 1] * nums[i - 1], f[i - 1] * nums[i - 1]), nums[i - 1]);
            g[i] = min(min(f[i - 1] * nums[i - 1], g[i - 1] * nums[i - 1]), nums[i - 1]);
            ret = max(ret, f[i]);
        }

        return ret;
    }
};
