/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2023-11-29 13:20:28
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2023-11-29 13:20:57
 * @FilePath: \every-little-progress\day 373\test.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */



// 2815. 数组中的最大数对和
// https://leetcode.cn/problems/max-pair-sum-in-an-array/description/
// 给你一个下标从 0 开始的整数数组 nums 。请你从 nums 中找出和 最大 的一对数，且这两个数数位上最大的数字相等。

// 返回最大和，如果不存在满足题意的数字对，返回 -1 。

 

// 示例 1：

// 输入：nums = [51,71,17,24,42]
// 输出：88
// 解释：
// i = 1 和 j = 2 ，nums[i] 和 nums[j] 数位上最大的数字相等，且这一对的总和 71 + 17 = 88 。 
// i = 3 和 j = 4 ，nums[i] 和 nums[j] 数位上最大的数字相等，且这一对的总和 24 + 42 = 66 。
// 可以证明不存在其他数对满足数位上最大的数字相等，所以答案是 88 。
// 示例 2：

// 输入：nums = [1,2,3,4]
// 输出：-1
// 解释：不存在数对满足数位上最大的数字相等。
 

// 提示：

// 2 <= nums.length <= 100
// 1 <= nums[i] <= 104

class Solution {
    int find_max(int n)
    {
        int max = 1;
        while(n > 1)
        {
            if(n % 10 > max) max = n % 10;
            n /= 10;
        }
        return max;
    }
public:
    int maxSum(vector<int>& nums) {
        unordered_map<int, vector<int>> hash;
        for(const auto& e : nums)
        {
            int idx = find_max(e);
            hash[idx].push_back(e);
            if(hash[idx].size() == 3)
            {
                if(hash[idx][0] <= hash[idx][1] && hash[idx][0] < hash[idx][2]) swap(hash[idx][0], hash[idx][2]);
                else if(hash[idx][0] > hash[idx][1] && hash[idx][1] < hash[idx][2]) swap(hash[idx][1], hash[idx][2]);
                hash[idx].pop_back();
            }
        }
        
        int sum = -1;
        for(const auto& [x, y] : hash)
        {
            if(y.size() < 2) continue;
            if(sum < y[0] + y[1]) sum = y[0] + y[1];
        }
        return sum;
    }
};