/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2024-06-27 19:33:12
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2024-06-27 19:33:39
 * @FilePath: \every-little-progress\day 575\test.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */


// 494. 目标和
// https://leetcode.cn/problems/target-sum/description/
// 给你一个非负整数数组 nums 和一个整数 target 。

// 向数组中的每个整数前添加 '+' 或 '-' ，然后串联起所有整数，可以构造一个 表达式 ：

// 例如，nums = [2, 1] ，可以在 2 之前添加 '+' ，在 1 之前添加 '-' ，然后串联起来得到表达式 "+2-1" 。
// 返回可以通过上述方法构造的、运算结果等于 target 的不同 表达式 的数目。

 

// 示例 1：

// 输入：nums = [1,1,1,1,1], target = 3
// 输出：5
// 解释：一共有 5 种方法让最终目标和为 3 。
// -1 + 1 + 1 + 1 + 1 = 3
// +1 - 1 + 1 + 1 + 1 = 3
// +1 + 1 - 1 + 1 + 1 = 3
// +1 + 1 + 1 - 1 + 1 = 3
// +1 + 1 + 1 + 1 - 1 = 3
// 示例 2：

// 输入：nums = [1], target = 1
// 输出：1
 

// 提示：

// 1 <= nums.length <= 20
// 0 <= nums[i] <= 1000
// 0 <= sum(nums[i]) <= 1000
// -1000 <= target <= 1000


class Solution {
    int sum = 0;

    int dfs(vector<int>& nums, const int& target, int pos)
    {
        // cout<<sum<<":"<<pos<<" ";
        if(pos >= nums.size()) return target == sum ? 1 : 0;
        // cout<<sum<<":"<<pos<<" ";

        int cnt = 0;

        sum += nums[pos];
        cnt += dfs(nums, target, pos + 1);
        sum -= (2 * nums[pos]);
        // sum -= nums[pos];
        // sum -= nums[pos];
        cnt += dfs(nums, target, pos + 1);
        sum += nums[pos];
        

        return cnt;
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        return dfs(nums, target, 0);
    }
};


