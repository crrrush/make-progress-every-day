/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2024-08-23 21:26:02
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2024-08-23 21:26:46
 * @FilePath: \every-little-progress\day 628\test.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */


// 面试题 17.16. 按摩师
// https://leetcode.cn/problems/the-masseuse-lcci/description/
// 一个有名的按摩师会收到源源不断的预约请求，每个预约都可以选择接或不接。在每次预约服务之间要有休息时间，因此她不能接受相邻的预约。给定一个预约请求序列，替按摩师找到最优的预约集合（总预约时间最长），返回总的分钟数。

// 注意：本题相对原题稍作改动

 

// 示例 1：

// 输入： [1,2,3,1]
// 输出： 4
// 解释： 选择 1 号预约和 3 号预约，总时长 = 1 + 3 = 4。
// 示例 2：

// 输入： [2,7,9,3,1]
// 输出： 12
// 解释： 选择 1 号预约、 3 号预约和 5 号预约，总时长 = 2 + 9 + 1 = 12。
// 示例 3：

// 输入： [2,1,4,5,3,1,1,3]
// 输出： 12
// 解释： 选择 1 号预约、 3 号预约、 5 号预约和 8 号预约，总时长 = 2 + 4 + 3 + 3 = 12。

class Solution {
public:
    int massage(vector<int>& nums) {
        int n = nums.size();
        if(0 == n) return n;
        int dp1[100]; // 该点工作
        int dp2[100]; // 该点休息

        dp1[0] = nums[0];
        dp2[0] = 0;


        for(int i = 1;i < n;++i)
        {
            dp1[i] = dp2[i - 1] + nums[i];
            dp2[i] = max(dp1[i - 1], dp2[i - 1]);
        }

        return max(dp1[n - 1], dp2[n - 1]);
    }
};




// class Solution {
// public:
//     int massage(vector<int>& nums) {
//         int n = nums.size();
//         if(0 == n) return n;
//         else if(1 == n) return nums[0];
//         int dp1[1000]; // 该点工作
//         int dp2[1000]; // 该点休息

//         dp1[0] = nums[0];
//         dp2[0] = 0;

//         dp1[1] = nums[1];
//         dp2[1] = dp1[0];

//         for(int i = 2;i < n;++i)
//         {
//             dp1[i] = max(dp2[i - 1], dp2[i - 2]) + nums[i];
//             dp2[i] = dp1[i - 1];
//         }

//         return max(dp1[n - 1], dp2[n - 1]);
//     }
// };


