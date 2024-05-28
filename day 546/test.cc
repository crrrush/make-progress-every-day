/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2024-05-28 23:24:51
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2024-05-28 23:25:18
 * @FilePath: \every-little-progress\day 546\test.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */


// 217. 存在重复元素
// https://leetcode.cn/problems/contains-duplicate/description/
// 给你一个整数数组 nums 。如果任一值在数组中出现 至少两次 ，返回 true ；如果数组中每个元素互不相同，返回 false 。
 

// 示例 1：

// 输入：nums = [1,2,3,1]
// 输出：true
// 示例 2：

// 输入：nums = [1,2,3,4]
// 输出：false
// 示例 3：

// 输入：nums = [1,1,1,3,3,4,3,2,4,2]
// 输出：true
 

// 提示：

// 1 <= nums.length <= 105
// -109 <= nums[i] <= 109

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> hash;
        for(const auto& e : nums)
            if(hash.end() == hash.find(e))
                hash.insert(e);
            else
                return true;
        
        return false;
    }
};

