/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2024-01-23 14:59:11
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2024-01-23 15:00:08
 * @FilePath: \every-little-progress\day 426\test.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */


// 896. 单调数列
// https://leetcode.cn/problems/monotonic-array/description/
// 如果数组是单调递增或单调递减的，那么它是 单调 的。

// 如果对于所有 i <= j，nums[i] <= nums[j]，那么数组 nums 是单调递增的。 如果对于所有 i <= j，nums[i]> = nums[j]，那么数组 nums 是单调递减的。

// 当给定的数组 nums 是单调数组时返回 true，否则返回 false。

 

// 示例 1：

// 输入：nums = [1,2,2,3]
// 输出：true
// 示例 2：

// 输入：nums = [6,5,4,4]
// 输出：true
// 示例 3：

// 输入：nums = [1,3,2]
// 输出：false
 

// 提示：

// 1 <= nums.length <= 105
// -105 <= nums[i] <= 105

class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        // if(nums.size() == 1) return true;
        bool bigger = true;
        for(int i = 0;i < nums.size() - 1;++i)
        {
            if(nums[i] > nums[i + 1])
            {
                bigger = true;
                break; 
            }
            else if(nums[i] < nums[i + 1])
            {
                bigger = false;
                break;
            }
        }

        if(bigger)
        {
            for(int i = 0;i < nums.size() - 1;++i) if(nums[i] < nums[i + 1]) return false;
        }
        else
        {
            for(int i = 0;i < nums.size() - 1;++i) if(nums[i] > nums[i + 1]) return false;
        }
        
        return true;
    }
};