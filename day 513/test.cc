/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2024-04-24 21:17:56
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2024-04-24 21:18:29
 * @FilePath: \every-little-progress\day 513\test.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */


// 238. 除自身以外数组的乘积
// https://leetcode.cn/problems/product-of-array-except-self/description/
// 给你一个整数数组 nums，返回 数组 answer ，其中 answer[i] 等于 nums 中除 nums[i] 之外其余各元素的乘积 。

// 题目数据 保证 数组 nums之中任意元素的全部前缀元素和后缀的乘积都在  32 位 整数范围内。

// 请 不要使用除法，且在 O(n) 时间复杂度内完成此题。

 

// 示例 1:

// 输入: nums = [1,2,3,4]
// 输出: [24,12,8,6]
// 示例 2:

// 输入: nums = [-1,1,0,-3,3]
// 输出: [0,0,9,0,0]
 

// 提示：

// 2 <= nums.length <= 105
// -30 <= nums[i] <= 30
// 保证 数组 nums之中任意元素的全部前缀元素和后缀的乘积都在  32 位 整数范围内
 

// 进阶：你可以在 O(1) 的额外空间复杂度内完成这个题目吗？（ 出于对空间复杂度分析的目的，输出数组 不被视为 额外空间。）

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> Lpro(n, 1);
        for(int i = 1;i < n;++i) Lpro[i] = Lpro[i - 1] * nums[i - 1];

        vector<int> answer(n, 1);
        int Rpro = 1;
        for(int i = n - 1;i >= 0;--i)
        {
            answer[i] = Lpro[i] * Rpro;
            Rpro *= nums[i];
        }
        return answer;
    }
};


// class Solution {
// public:
//     vector<int> productExceptSelf(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> Lpro(n, 1), Rpro(n, 1);
//         for(int i = 1;i < n;++i) Lpro[i] = Lpro[i - 1] * nums[i - 1];
//         for(int i = n - 2;i >= 0;--i) Rpro[i] = Rpro[i + 1] * nums[i + 1];

//         vector<int> answer(n);
//         for(int i = 0;i < n;++i) answer[i] = Lpro[i] * Rpro[i];
//         return answer;
//     }
// };

