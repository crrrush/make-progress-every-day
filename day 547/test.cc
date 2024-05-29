/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2024-05-29 22:45:58
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2024-05-29 22:46:22
 * @FilePath: \every-little-progress\day 547\test.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */


// 219. 存在重复元素 II
// https://leetcode.cn/problems/contains-duplicate-ii/description/
// 给你一个整数数组 nums 和一个整数 k ，判断数组中是否存在两个 不同的索引 i 和 j ，满足 nums[i] == nums[j] 且 abs(i - j) <= k 。如果存在，返回 true ；否则，返回 false 。

 

// 示例 1：

// 输入：nums = [1,2,3,1], k = 3
// 输出：true
// 示例 2：

// 输入：nums = [1,0,1,1], k = 1
// 输出：true
// 示例 3：

// 输入：nums = [1,2,3,1,2,3], k = 2
// 输出：false
 

 

// 提示：

// 1 <= nums.length <= 105
// -109 <= nums[i] <= 109
// 0 <= k <= 105

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> hash;
        for(int i = 0;i < nums.size();++i)
        {
            auto it = hash.find(nums[i]);
            if(hash.end() != it)
            {
                if(i - it->second <= k) return true;
                else it->second = i;
            }
            else
            {
                hash.insert(make_pair(nums[i], i));
            }
        }

        return false;
    }
};

