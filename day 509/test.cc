/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2024-04-20 12:30:26
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2024-04-20 12:30:41
 * @FilePath: \every-little-progress\day 509\test.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */



// 162. 寻找峰值
// https://leetcode.cn/problems/find-peak-element/description/
// 峰值元素是指其值严格大于左右相邻值的元素。

// 给你一个整数数组 nums，找到峰值元素并返回其索引。数组可能包含多个峰值，在这种情况下，返回 任何一个峰值 所在位置即可。

// 你可以假设 nums[-1] = nums[n] = -∞ 。

// 你必须实现时间复杂度为 O(log n) 的算法来解决此问题。

 

// 示例 1：

// 输入：nums = [1,2,3,1]
// 输出：2
// 解释：3 是峰值元素，你的函数应该返回其索引 2。
// 示例 2：

// 输入：nums = [1,2,1,3,5,6,4]
// 输出：1 或 5 
// 解释：你的函数可以返回索引 1，其峰值元素为 2；
//      或者返回索引 5， 其峰值元素为 6。
 

// 提示：

// 1 <= nums.length <= 1000
// -231 <= nums[i] <= 231 - 1
// 对于所有有效的 i 都有 nums[i] != nums[i + 1]


class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while(left < right)
        {
            int mid = left + (right - left) / 2;

            if(nums[mid] < nums[mid + 1])
                left = mid + 1;
            else
                right = mid;
        }

        return left;
    }
};


// class Solution {
// public:
//     int findPeakElement(vector<int>& nums) {
//         if(nums.size() == 1 || nums[0] > nums[1]) return 0;
//         if(nums[nums.size() - 1] > nums[nums.size() - 2]) return nums.size() - 1;

//         int left = 1, right = nums.size() - 2;
//         while(left <= right)
//         {
//             int mid = left + (right - left) / 2;
//             if(nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1]) 
//                 return mid;
//             else if(nums[mid] > nums[mid - 1])
//                 left = mid + 1;
//             else
//                 right = mid - 1;
//         }

//         return -1;
//     }
// };

// class Solution {
// public:
//     int findPeakElement(vector<int>& nums) {
//         if(nums.size() == 1) return 0;
//         if(nums[0] > nums[1]) return 0;
//         if(nums[nums.size() - 1] > nums[nums.size() - 2]) return nums.size() - 1;

//         for(int i = 1;i < nums.size() - 1;++i)
//         {
//             if(nums[i] > nums[i - 1] && nums[i] > nums[i + 1]) return i;
//         }

//         return -1;
//     }
// };