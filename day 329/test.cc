/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2023-10-16 19:48:23
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2023-10-16 19:48:59
 * @FilePath: \every-little-progress\day 329\test.cc
//  * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
//  */


// 1979. 找出数组的最大公约数
// https://leetcode.cn/problems/find-greatest-common-divisor-of-array/description/
// 给你一个整数数组 nums ，返回数组中最大数和最小数的 最大公约数 。

// 两个数的 最大公约数 是能够被两个数整除的最大正整数。

 

// 示例 1：

// 输入：nums = [2,5,6,9,10]
// 输出：2
// 解释：
// nums 中最小的数是 2
// nums 中最大的数是 10
// 2 和 10 的最大公约数是 2
// 示例 2：

// 输入：nums = [7,5,6,8,3]
// 输出：1
// 解释：
// nums 中最小的数是 3
// nums 中最大的数是 8
// 3 和 8 的最大公约数是 1
// 示例 3：

// 输入：nums = [3,3]
// 输出：3
// 解释：
// nums 中最小的数是 3
// nums 中最大的数是 3
// 3 和 3 的最大公约数是 3
 

// 提示：

// 2 <= nums.length <= 1000
// 1 <= nums[i] <= 1000

class Solution {
public:
    int maxCommondivisor(int a, int b)
    {
        while(a % b)
        {
            int mod = a % b;
            a = b;
            b = mod;
        }

        return b;
    }
    int findGCD(vector<int>& nums) {
        int max = nums[0];
        int min = nums[0];
        for(const auto& e : nums)
        {
            if(max < e) max = e;
            if(min > e) min = e;
        }

        return maxCommondivisor(max, min);
    }
};