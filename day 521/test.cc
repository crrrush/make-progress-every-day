/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2024-05-02 10:40:19
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2024-05-02 10:41:05
 * @FilePath: \every-little-progress\day 521\test.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */


// 136. 只出现一次的数字
// https://leetcode.cn/problems/single-number/description/
// 给你一个 非空 整数数组 nums ，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。

// 你必须设计并实现线性时间复杂度的算法来解决此问题，且该算法只使用常量额外空间。

 

// 示例 1 ：

// 输入：nums = [2,2,1]
// 输出：1
// 示例 2 ：

// 输入：nums = [4,1,2,1,2]
// 输出：4
// 示例 3 ：

// 输入：nums = [1]
// 输出：1
 

// 提示：

// 1 <= nums.length <= 3 * 104
// -3 * 104 <= nums[i] <= 3 * 104
// 除了某个元素只出现一次以外，其余每个元素均出现两次。

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = 0;
        for(const auto& e : nums) n ^= e;
        return n;
    }
};

