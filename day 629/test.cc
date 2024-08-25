/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2024-08-25 11:22:40
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2024-08-25 11:23:09
 * @FilePath: \every-little-progress\day 629\test.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */


// 213. 打家劫舍 II
// https://leetcode.cn/problems/house-robber-ii/description/
// 你是一个专业的小偷，计划偷窃沿街的房屋，每间房内都藏有一定的现金。这个地方所有的房屋都 围成一圈 ，这意味着第一个房屋和最后一个房屋是紧挨着的。同时，相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警 。

// 给定一个代表每个房屋存放金额的非负整数数组，计算你 在不触动警报装置的情况下 ，今晚能够偷窃到的最高金额。

 

// 示例 1：

// 输入：nums = [2,3,2]
// 输出：3
// 解释：你不能先偷窃 1 号房屋（金额 = 2），然后偷窃 3 号房屋（金额 = 2）, 因为他们是相邻的。
// 示例 2：

// 输入：nums = [1,2,3,1]
// 输出：4
// 解释：你可以先偷窃 1 号房屋（金额 = 1），然后偷窃 3 号房屋（金额 = 3）。
//      偷窃到的最高金额 = 1 + 3 = 4 。
// 示例 3：

// 输入：nums = [1,2,3]
// 输出：3
 

// 提示：

// 1 <= nums.length <= 100
// 0 <= nums[i] <= 1000

class Solution {
public:
    int f(vector<int>& nums, int l, int r)
    {
        if(l >= r) return 0;
        int dp1[100]; // 该点工作
        int dp2[100]; // 该点休息

        dp1[l] = nums[l];
        dp2[l] = 0;


        for(int i = l + 1;i < r;++i)
        {
            dp1[i] = dp2[i - 1] + nums[i];
            dp2[i] = max(dp1[i - 1], dp2[i - 1]);
        }

        return max(dp1[r - 1], dp2[r - 1]);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        // 分类讨论
        return max(f(nums, 1, n), nums[0] + f(nums, 2, n - 1));
    }
};
