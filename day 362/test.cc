/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2023-11-18 13:38:43
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2023-11-18 13:40:20
 * @FilePath: \every-little-progress\day 362\test.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */



// 2574. 左右元素和的差值
// https://leetcode.cn/problems/left-and-right-sum-differences/description/
// 给你一个下标从 0 开始的整数数组 nums ，请你找出一个下标从 0 开始的整数数组 answer ，其中：

// answer.length == nums.length
// answer[i] = |leftSum[i] - rightSum[i]|
// 其中：

// leftSum[i] 是数组 nums 中下标 i 左侧元素之和。如果不存在对应的元素，leftSum[i] = 0 。
// rightSum[i] 是数组 nums 中下标 i 右侧元素之和。如果不存在对应的元素，rightSum[i] = 0 。
// 返回数组 answer 。

 

// 示例 1：

// 输入：nums = [10,4,8,3]
// 输出：[15,1,11,22]
// 解释：数组 leftSum 为 [0,10,14,22] 且数组 rightSum 为 [15,11,3,0] 。
// 数组 answer 为 [|0 - 15|,|10 - 11|,|14 - 3|,|22 - 0|] = [15,1,11,22] 。
// 示例 2：

// 输入：nums = [1]
// 输出：[0]
// 解释：数组 leftSum 为 [0] 且数组 rightSum 为 [0] 。
// 数组 answer 为 [|0 - 0|] = [0] 。
 

// 提示：

// 1 <= nums.length <= 1000
// 1 <= nums[i] <= 105

class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        vector<int> differ;
        int lsum = 0, rsum = 0;
        for(const auto& e : nums) rsum += e;

        for(const auto& e : nums)
        {
            rsum -= e;
            differ.push_back(abs(lsum - rsum));
            lsum += e;
        }

        return differ;
    }
};