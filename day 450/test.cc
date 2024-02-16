/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2024-02-16 14:53:10
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2024-02-16 14:53:36
 * @FilePath: \every-little-progress\day 450\test.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */



// 961. 在长度 2N 的数组中找出重复 N 次的元素
// https://leetcode.cn/problems/n-repeated-element-in-size-2n-array/description/
// 给你一个整数数组 nums ，该数组具有以下属性：

// nums.length == 2 * n.
// nums 包含 n + 1 个 不同的 元素
// nums 中恰有一个元素重复 n 次
// 找出并返回重复了 n 次的那个元素。

 

// 示例 1：

// 输入：nums = [1,2,3,3]
// 输出：3
// 示例 2：

// 输入：nums = [2,1,2,5,3,2]
// 输出：2
// 示例 3：

// 输入：nums = [5,1,5,2,5,3,5,4]
// 输出：5
 

// 提示：

// 2 <= n <= 5000
// nums.length == 2 * n
// 0 <= nums[i] <= 104
// nums 由 n + 1 个 不同的 元素组成，且其中一个元素恰好重复 n 次


class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_map<int, int> hash;
        int N = nums.size() / 2;
        for(const auto& e : nums)
        {
            ++hash[e];
            if(hash[e] >= N) return e;
        }

        return 0;
    }
};