/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2024-09-07 20:28:46
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2024-09-07 20:29:12
 * @FilePath: \every-little-progress\day 640\test.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */


// 413. 等差数列划分
// https://leetcode.cn/problems/arithmetic-slices/description/
// 如果一个数列 至少有三个元素 ，并且任意两个相邻元素之差相同，则称该数列为等差数列。

// 例如，[1,3,5,7,9]、[7,7,7,7] 和 [3,-1,-5,-9] 都是等差数列。
// 给你一个整数数组 nums ，返回数组 nums 中所有为等差数组的 子数组 个数。

// 子数组 是数组中的一个连续序列。

 

// 示例 1：

// 输入：nums = [1,2,3,4]
// 输出：3
// 解释：nums 中有三个子等差数组：[1, 2, 3]、[2, 3, 4] 和 [1,2,3,4] 自身。
// 示例 2：

// 输入：nums = [1]
// 输出：0
 

// 提示：

// 1 <= nums.length <= 5000
// -1000 <= nums[i] <= 1000


class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        const int n = nums.size();
        int dnum[5001] = { 0 };
        int dlen[5001] = { 0 };
        dnum[0] = dnum[1] = 0;
        dlen[0] = 1;
        dlen[1] = 2;

        for(int i = 2;i < n;++i)
        {
            if(nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2])
            {
                dnum[i] = dnum[i - 1] + dlen[i - 1] - 1;
                dlen[i] = dlen[i - 1] + 1;
            }
            else
            {
                dnum[i] = dnum[i - 1];
                dlen[i] = 2;
            }
        }

        return dnum[n - 1];
    }
};
