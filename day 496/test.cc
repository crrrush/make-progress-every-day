/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2024-04-04 13:48:33
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2024-04-04 13:48:59
 * @FilePath: \every-little-progress\day 496\test.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */


// 18. 四数之和
// https://leetcode.cn/problems/4sum/description/
// 给你一个由 n 个整数组成的数组 nums ，和一个目标值 target 。请你找出并返回满足下述全部条件且不重复的四元组 [nums[a], nums[b], nums[c], nums[d]] （若两个四元组元素一一对应，则认为两个四元组重复）：

// 0 <= a, b, c, d < n
// a、b、c 和 d 互不相同
// nums[a] + nums[b] + nums[c] + nums[d] == target
// 你可以按 任意顺序 返回答案 。

 

// 示例 1：

// 输入：nums = [1,0,-1,0,-2,2], target = 0
// 输出：[[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
// 示例 2：

// 输入：nums = [2,2,2,2,2], target = 8
// 输出：[[2,2,2,2]]
 

// 提示：

// 1 <= nums.length <= 200
// -109 <= nums[i] <= 109
// -109 <= target <= 109


class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> vv;
        int n = nums.size();
        for(int i = 0;i < n - 3;) // 第一个定位指针
        {
            long long int t0 = target - nums[i]; // 分离第一个数
            for(int p = i + 1;p < n - 2;) // 第二个定位指针 
            {
                int left = p + 1, right = n - 1;
                long long int t1 = t0 - nums[p]; // 分离第二个数
                while(left < right)
                {
                    long long int sum = nums[left] + nums[right];
                    if(sum < t1)
                        ++left;
                    else if(sum > t1)
                        --right;
                    else
                    {
                        vv.push_back({nums[i], nums[p], nums[left], nums[right]});

                        // 去重 + 迭代
                        ++left;
                        --right;
                        while(left < right && nums[left] == nums[left - 1]) ++left;
                        while(left < right && nums[right] == nums[right + 1]) --right;
                    }
                }

                // 去重 + 迭代
                ++p;
                while(p < n - 2 && nums[p] == nums[p - 1]) ++p;
            }

            // 去重 + 迭代
            ++i;
            while(i < n - 3 && nums[i] == nums[i - 1]) ++i;
        }

        return vv;
    }
};