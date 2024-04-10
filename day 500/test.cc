/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2024-04-10 14:57:34
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2024-04-10 14:57:58
 * @FilePath: \every-little-progress\day 500\test.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */


// 1658. 将 x 减到 0 的最小操作数
// https://leetcode.cn/problems/minimum-operations-to-reduce-x-to-zero/description/
// 给你一个整数数组 nums 和一个整数 x 。每一次操作时，你应当移除数组 nums 最左边或最右边的元素，然后从 x 中减去该元素的值。请注意，需要 修改 数组以供接下来的操作使用。

// 如果可以将 x 恰好 减到 0 ，返回 最小操作数 ；否则，返回 -1 。

 

// 示例 1：

// 输入：nums = [1,1,4,2,3], x = 5
// 输出：2
// 解释：最佳解决方案是移除后两个元素，将 x 减到 0 。
// 示例 2：

// 输入：nums = [5,6,7,8,9], x = 4
// 输出：-1
// 示例 3：

// 输入：nums = [3,2,20,1,1,3], x = 10
// 输出：5
// 解释：最佳解决方案是移除后三个元素和前两个元素（总共 5 次操作），将 x 减到 0 。
 

// 提示：

// 1 <= nums.length <= 105
// 1 <= nums[i] <= 104
// 1 <= x <= 109

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int target = -x;
        for(const auto& e : nums) target += e;
        if(target < 0) return -1;

        int left = 0, right = 0, sum = 0, maxL = -1;
        while(right < nums.size())
        {
            while(right < nums.size() && sum < target) sum += nums[right++];

            while(left < right && sum > target) sum -= nums[left++];

            if(target == sum) maxL = max(right - left + 1, maxL);

            sum += nums[right++];
        }
        if(maxL == -1) return -1;

        return nums.size() - maxL + 1;
    }
};