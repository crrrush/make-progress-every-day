/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2024-05-06 22:05:46
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2024-05-06 22:06:11
 * @FilePath: \every-little-progress\day 525\test.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */


// 137. 只出现一次的数字 II
// https://leetcode.cn/problems/single-number-ii/description/
// 给你一个整数数组 nums ，除某个元素仅出现 一次 外，其余每个元素都恰出现 三次 。请你找出并返回那个只出现了一次的元素。

// 你必须设计并实现线性时间复杂度的算法且使用常数级空间来解决此问题。

 

// 示例 1：

// 输入：nums = [2,2,3,2]
// 输出：3
// 示例 2：

// 输入：nums = [0,1,0,1,0,1,99]
// 输出：99
 

// 提示：

// 1 <= nums.length <= 3 * 104
// -231 <= nums[i] <= 231 - 1
// nums 中，除某个元素仅出现 一次 外，其余每个元素都恰出现 三次


class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ret = 0;
        for(int i = 0;i < 32;++i)
        {
            int sum = 0;
            for(const auto& e : nums) if(e & (1 << i)) ++sum;
            ret |= ((sum % 3) << i); // 出现n次，%n
        }
        return ret;
    }
};

