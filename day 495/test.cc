/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2024-04-03 12:46:10
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2024-04-03 12:46:39
 * @FilePath: \every-little-progress\day 495\test.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */



// 15. 三数之和
// https://leetcode.cn/problems/3sum/description/
// 给你一个整数数组 nums ，判断是否存在三元组 [nums[i], nums[j], nums[k]] 满足 i != j、i != k 且 j != k ，同时还满足 nums[i] + nums[j] + nums[k] == 0 。请

// 你返回所有和为 0 且不重复的三元组。

// 注意：答案中不可以包含重复的三元组。

 

 

// 示例 1：

// 输入：nums = [-1,0,1,2,-1,-4]
// 输出：[[-1,-1,2],[-1,0,1]]
// 解释：
// nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0 。
// nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0 。
// nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0 。
// 不同的三元组是 [-1,0,1] 和 [-1,-1,2] 。
// 注意，输出的顺序和三元组的顺序并不重要。
// 示例 2：

// 输入：nums = [0,1,1]
// 输出：[]
// 解释：唯一可能的三元组和不为 0 。
// 示例 3：

// 输入：nums = [0,0,0]
// 输出：[[0,0,0]]
// 解释：唯一可能的三元组和为 0 。
 

// 提示：

// 3 <= nums.length <= 3000
// -105 <= nums[i] <= 105


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> vv;
        int i = 0;
        while(i < nums.size() - 2 && nums[i] <= 0) // 定位一个元素，数据升序储存，定位元素为0时结束
        {
            int left = i + 1, right = nums.size() - 1;
            while(left < right) // 双指针相撞
            {
                if(nums[i] + nums[left] + nums[right] < 0)
                    ++left;
                else if(nums[i] + nums[left] + nums[right] > 0)
                    --right;
                else
                {
                    // 要兼顾去重
                    vv.push_back( vector<int>({nums[i], nums[left], nums[right]}) );

                    int ltmp = nums[left], rtmp = nums[right];
                    while(left < right && nums[left] == ltmp) ++left;
                    while(left < right && nums[right] == rtmp) --right;
                }
            }

            // 兼顾去重
            int itmp = nums[i];
            while(i < nums.size() - 2 && nums[i] == itmp) ++i;
        }

        return vv;
    }
};