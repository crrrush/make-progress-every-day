/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2024-02-28 14:26:18
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2024-02-28 14:26:52
 * @FilePath: \every-little-progress\day 461\test.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */



// 2869. 收集元素的最少操作次数
// https://leetcode.cn/problems/minimum-operations-to-collect-elements/description/
// 给你一个正整数数组 nums 和一个整数 k 。

// 一次操作中，你可以将数组的最后一个元素删除，将该元素添加到一个集合中。

// 请你返回收集元素 1, 2, ..., k 需要的 最少操作次数 。

 

// 示例 1：

// 输入：nums = [3,1,5,4,2], k = 2
// 输出：4
// 解释：4 次操作后，集合中的元素依次添加了 2 ，4 ，5 和 1 。此时集合中包含元素 1 和 2 ，所以答案为 4 。
// 示例 2：

// 输入：nums = [3,1,5,4,2], k = 5
// 输出：5
// 解释：5 次操作后，集合中的元素依次添加了 2 ，4 ，5 ，1 和 3 。此时集合中包含元素 1 到 5 ，所以答案为 5 。
// 示例 3：

// 输入：nums = [3,2,5,3,1], k = 3
// 输出：4
// 解释：4 次操作后，集合中的元素依次添加了 1 ，3 ，5 和 2 。此时集合中包含元素 1 到 3  ，所以答案为 4 。
 

// 提示：

// 1 <= nums.length <= 50
// 1 <= nums[i] <= nums.length
// 1 <= k <= nums.length
// 输入保证你可以收集到元素 1, 2, ..., k 。


class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        bitset<51> bs;
        int cnt = 0;

        for(int i = nums.size() - 1;i >= 0;--i)
        {
            if(nums[i] <= k) 
            {
                if(!bs.test(nums[i]))
                {
                    bs.set(nums[i]);
                    ++cnt;

                    if(cnt == k) return nums.size() - i;
                }
            }
        }
        return -1;
    }
};