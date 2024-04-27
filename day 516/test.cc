/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2024-04-27 22:54:41
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2024-04-27 22:55:24
 * @FilePath: \every-little-progress\day 516\test.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */


// 525. 连续数组
// https://leetcode.cn/problems/contiguous-array/description/
// 给定一个二进制数组 nums , 找到含有相同数量的 0 和 1 的最长连续子数组，并返回该子数组的长度。

 

// 示例 1:

// 输入: nums = [0,1]
// 输出: 2
// 说明: [0, 1] 是具有相同数量 0 和 1 的最长连续子数组。
// 示例 2:

// 输入: nums = [0,1,0]
// 输出: 2
// 说明: [0, 1] (或 [1, 0]) 是具有相同数量0和1的最长连续子数组。
 

// 提示：

// 1 <= nums.length <= 105
// nums[i] 不是 0 就是 1


class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> hash;
        int sum = 0;
        // 和一开始位0，0的左边界就是-1
        hash[sum] = -1; // 头开始的子数组的左边界位置即-1
        int maxL = 0;
        for(int i = 0;i < nums.size();++i)
        {
            if(nums[i]) 
                ++sum;
            else 
                --sum;
            
            auto it = hash.find(sum);
            if(hash.end() != it)
            {
                if(i - it->second > maxL) maxL = i - it->second;
            }
            else
                hash[sum] = i;
        }

        return maxL;
    }
};

