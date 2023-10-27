/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2023-10-27 11:29:19
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2023-10-27 11:29:55
 * @FilePath: \every-little-progress\day 340\test.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */


// 1646. 获取生成数组中的最大值
// https://leetcode.cn/problems/get-maximum-in-generated-array/description/
// 给你一个整数 n 。按下述规则生成一个长度为 n + 1 的数组 nums ：

// nums[0] = 0
// nums[1] = 1
// 当 2 <= 2 * i <= n 时，nums[2 * i] = nums[i]
// 当 2 <= 2 * i + 1 <= n 时，nums[2 * i + 1] = nums[i] + nums[i + 1]
// 返回生成数组 nums 中的 最大 值。

 

// 示例 1：

// 输入：n = 7
// 输出：3
// 解释：根据规则：
//   nums[0] = 0
//   nums[1] = 1
//   nums[(1 * 2) = 2] = nums[1] = 1
//   nums[(1 * 2) + 1 = 3] = nums[1] + nums[2] = 1 + 1 = 2
//   nums[(2 * 2) = 4] = nums[2] = 1
//   nums[(2 * 2) + 1 = 5] = nums[2] + nums[3] = 1 + 2 = 3
//   nums[(3 * 2) = 6] = nums[3] = 2
//   nums[(3 * 2) + 1 = 7] = nums[3] + nums[4] = 2 + 1 = 3
// 因此，nums = [0,1,1,2,1,3,2,3]，最大值 3
// 示例 2：

// 输入：n = 2
// 输出：1
// 解释：根据规则，nums[0]、nums[1] 和 nums[2] 之中的最大值是 1
// 示例 3：

// 输入：n = 3
// 输出：2
// 解释：根据规则，nums[0]、nums[1]、nums[2] 和 nums[3] 之中的最大值是 2
 

// 提示：

// 0 <= n <= 100

class Solution {
public:
    void init(vector<int>& nums)
    {
        nums.resize(101, 0);
        nums[0] = 0;
        nums[1] = 1;
        for(int i = 1;i * 2 <= 100 && 2 * i + 1 <= 100;++i)
        {
            nums[i * 2] = nums[i];
            nums[(i * 2) + 1] = nums[i] + nums[i + 1];
        }
    }
    int getMaximumGenerated(int n) {
        if(n == 0) return 0;
        else if(n == 1) return 1;
        
        static vector<int> nums;
        if(nums.empty()) init(nums);

        int max = -1;
        for(int i = 0;i <= n;++i) if(nums[i] > max) max = nums[i];

        return max;
    }
};

// class Solution {
// public:
//     int getMaximumGenerated(int n) {
//         if(n == 0) return 0;
//         else if(n == 1) return 1;

//         vector<int> nums(n + 1, 0);
//         nums[0] = 0;
//         nums[1] = 1;
//         for(int i = 1;i * 2 <= n && 2 * i + 1 <= n;++i)
//         {
//             nums[i * 2] = nums[i];
//             nums[(i * 2) + 1] = nums[i] + nums[i + 1];
//         }

//         int max = -1;
//         for(const auto& e : nums) if(e > max) max = e;

//         return max;
//     }
// };