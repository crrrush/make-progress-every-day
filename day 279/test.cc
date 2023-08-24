/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2023-08-24 10:55:27
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2023-08-24 10:58:15
 * @FilePath: \every-little-progress\day 279\test.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */


// 1365. 有多少小于当前数字的数字
// https://leetcode.cn/problems/how-many-numbers-are-smaller-than-the-current-number/
// 给你一个数组 nums，对于其中每个元素 nums[i]，请你统计数组中比它小的所有数字的数目。

// 换而言之，对于每个 nums[i] 你必须计算出有效的 j 的数量，其中 j 满足 j != i 且 nums[j] < nums[i] 。

// 以数组形式返回答案。

 

// 示例 1：

// 输入：nums = [8,1,2,2,3]
// 输出：[4,0,1,1,3]
// 解释： 
// 对于 nums[0]=8 存在四个比它小的数字：（1，2，2 和 3）。 
// 对于 nums[1]=1 不存在比它小的数字。
// 对于 nums[2]=2 存在一个比它小的数字：（1）。 
// 对于 nums[3]=2 存在一个比它小的数字：（1）。 
// 对于 nums[4]=3 存在三个比它小的数字：（1，2 和 2）。
// 示例 2：

// 输入：nums = [6,5,4,8]
// 输出：[2,1,0,3]
// 示例 3：

// 输入：nums = [7,7,7,7]
// 输出：[0,0,0,0]
 

// 提示：

// 2 <= nums.length <= 500
// 0 <= nums[i] <= 100


class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        unordered_map<int, int> hash;
        priority_queue<int> q;
        for(int i = 0;i < nums.size();++i) q.push(nums[i]);

        while(!q.empty())
        {
            hash[q.top()] = q.size() - 1;
            q.pop();
        }

        for(int i = 0;i < nums.size();++i) nums[i] = hash[nums[i]];

        return nums;
    }
};