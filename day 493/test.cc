/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2024-04-01 22:07:53
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2024-04-01 22:08:18
 * @FilePath: \every-little-progress\day 493\test.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */



// 611. 有效三角形的个数
// https://leetcode.cn/problems/valid-triangle-number/description/
// 给定一个包含非负整数的数组 nums ，返回其中可以组成三角形三条边的三元组个数。

 

// 示例 1:

// 输入: nums = [2,2,3,4]
// 输出: 3
// 解释:有效的组合是: 
// 2,3,4 (使用第一个 2)
// 2,3,4 (使用第二个 2)
// 2,2,3
// 示例 2:

// 输入: nums = [4,2,3,4]
// 输出: 4
 

// 提示:

// 1 <= nums.length <= 1000
// 0 <= nums[i] <= 1000


class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        if(nums.size() < 3) return 0;
        int cnt = 0;
        sort(nums.begin(), nums.end(), [](const int& x, const int& y){return x > y;}); // O(n*logn)
        for(int i = 0;i < nums.size() - 2;++i)// O(n^2)
        {
            int left = i + 1,right = nums.size() - 1;
            while(left < right)
            {
                while(left < right && nums[right] + nums[left] <= nums[i]) --right; // 找能构成三角形最小的数字

                cnt += (right - left);
                ++left;

                // 如果此时left == right，后面已经没有相加大于最大边的了
            }
        }
        return cnt;
    }
};

// class Solution {
// public:
//     int triangleNumber(vector<int>& nums) {
//         if(nums.size() < 3) return 0;
//         int cnt = 0;
//         sort(nums.begin(), nums.end(), [](const int& x, const int& y){return x > y;}); // O(n*logn)
//         // sort(nums.begin(), nums.end());
//         for(int i = 0;i < nums.size() - 2;++i)// O(n^3)
//         {
//             int l1 = i;
//             for(int j = i + 1;j < nums.size() - 1;++j)
//             {
//                 int l2 = j, l3 = j + 1;
//                 while(l3 < nums.size())
//                 {
//                     // if(nums[l1] + nums[l2] > nums[l3] && nums[l2] + nums[l3] > nums[l1] && nums[l1] + nums[l3] > nums[l2])
//                     if(nums[l2] + nums[l3] > nums[l1])
//                     {
//                         ++cnt;
//                         // if(l1 > 0 && nums[l1] == nums[l1 - 1]) ++cnt;
//                     }
//                     else
//                         break;
                    
//                     ++l3;
//                 }
//             }

//         }
//         return cnt;
//     }
// };