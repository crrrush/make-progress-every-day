/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2023-10-07 10:27:55
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2023-10-07 10:28:27
 * @FilePath: \every-little-progress\day 320\test.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */


// 1822. 数组元素积的符号
// https://leetcode.cn/problems/sign-of-the-product-of-an-array/description/
// 已知函数 signFunc(x) 将会根据 x 的正负返回特定值：

// 如果 x 是正数，返回 1 。
// 如果 x 是负数，返回 -1 。
// 如果 x 是等于 0 ，返回 0 。
// 给你一个整数数组 nums 。令 product 为数组 nums 中所有元素值的乘积。

// 返回 signFunc(product) 。

 

// 示例 1：

// 输入：nums = [-1,-2,-3,-4,3,2,1]
// 输出：1
// 解释：数组中所有值的乘积是 144 ，且 signFunc(144) = 1
// 示例 2：

// 输入：nums = [1,5,0,2,-3]
// 输出：0
// 解释：数组中所有值的乘积是 0 ，且 signFunc(0) = 0
// 示例 3：

// 输入：nums = [-1,1,-1,1,-1]
// 输出：-1
// 解释：数组中所有值的乘积是 -1 ，且 signFunc(-1) = -1
 

// 提示：

// 1 <= nums.length <= 1000
// -100 <= nums[i] <= 100

class Solution {
public:
    int arraySign(vector<int>& nums) {
        int cnt = 0;
        bool zero = false;
        for(const auto& e : nums)
        {
            if(e < 0) ++cnt;
            else if(e == 0)
            {
                zero = true;
                break;
            }
        }

        if(zero) return 0;

        if(cnt % 2) return -1;

        return 1;
    }
};