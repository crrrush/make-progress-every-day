/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2024-09-04 23:47:49
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2024-09-04 23:48:15
 * @FilePath: \every-little-progress\day 637\test.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */


// 918. 环形子数组的最大和
// https://leetcode.cn/problems/maximum-sum-circular-subarray/description/
// 给定一个长度为 n 的环形整数数组 nums ，返回 nums 的非空 子数组 的最大可能和 。

// 环形数组 意味着数组的末端将会与开头相连呈环状。形式上， nums[i] 的下一个元素是 nums[(i + 1) % n] ， nums[i] 的前一个元素是 nums[(i - 1 + n) % n] 。

// 子数组 最多只能包含固定缓冲区 nums 中的每个元素一次。形式上，对于子数组 nums[i], nums[i + 1], ..., nums[j] ，不存在 i <= k1, k2 <= j 其中 k1 % n == k2 % n 。

 

// 示例 1：

// 输入：nums = [1,-2,3,-2]
// 输出：3
// 解释：从子数组 [3] 得到最大和 3
// 示例 2：

// 输入：nums = [5,-3,5]
// 输出：10
// 解释：从子数组 [5,5] 得到最大和 5 + 5 = 10
// 示例 3：

// 输入：nums = [3,-2,2,-3]
// 输出：3
// 解释：从子数组 [3] 和 [3,-2,2] 都可以得到最大和 3
 

// 提示：

// n == nums.length
// 1 <= n <= 3 * 104
// -3 * 104 <= nums[i] <= 3 * 104​​​​​​​

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        // int dp1[30001] = { 0 };
        vector<int> dp1(n + 1);
        // int dp2[30001] = { 0 };
        vector<int> dp2(n + 1);

        int maxret = INT_MIN, minret = INT_MAX, sum = 0;
        for(int i = 1;i <= n;++i)
        {
            sum += nums[i - 1];
            dp1[i] = max(nums[i - 1], dp1[i - 1] + nums[i - 1]);
            dp2[i] = min(nums[i - 1], dp2[i - 1] + nums[i - 1]);
            maxret = max(maxret, dp1[i]);
            minret = min(minret, dp2[i]);
        }
        if(sum == minret) return maxret;
        
        return max(sum - minret, maxret);
    }
};
