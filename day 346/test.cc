/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2023-11-02 16:28:55
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2023-11-02 16:37:02
 * @FilePath: \every-little-progress\day 346\test.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */


// 2221. 数组的三角和
// https://leetcode.cn/problems/find-triangular-sum-of-an-array/description/
// 给你一个下标从 0 开始的整数数组 nums ，其中 nums[i] 是 0 到 9 之间（两者都包含）的一个数字。

// nums 的 三角和 是执行以下操作以后最后剩下元素的值：

// nums 初始包含 n 个元素。如果 n == 1 ，终止 操作。否则，创建 一个新的下标从 0 开始的长度为 n - 1 的整数数组 newNums 。
// 对于满足 0 <= i < n - 1 的下标 i ，newNums[i] 赋值 为 (nums[i] + nums[i+1]) % 10 ，% 表示取余运算。
// 将 newNums 替换 数组 nums 。
// 从步骤 1 开始 重复 整个过程。
// 请你返回 nums 的三角和。

 

// 示例 1：



// 输入：nums = [1,2,3,4,5]
// 输出：8
// 解释：
// 上图展示了得到数组三角和的过程。
// 示例 2：

// 输入：nums = [5]
// 输出：5
// 解释：
// 由于 nums 中只有一个元素，数组的三角和为这个元素自己。
 

// 提示：

// 1 <= nums.length <= 1000
// 0 <= nums[i] <= 9

class Solution {
public:
    int triangularSum(vector<int>& nums) {
        for(int sz = nums.size() - 1;sz > 0;--sz) for(int i = 0;i < sz;++i) nums[i] = (nums[i] + nums[i + 1]) % 10;

        return nums[0];
    }
};

// class Solution {
//     unsigned long long factorial(unsigned long long n)
//     {
//         unsigned long long fac = 1;
//         while(n != 0) fac *= n--;
//         return fac;
//     }
//     unsigned long long combinatorial_number(unsigned long long m, unsigned long long n) { return factorial(n) / (factorial(m) * factorial(n -m));}
// public:
//     int triangularSum(vector<int>& nums) {
//         int sum = 0;
//         int sz = nums.size();
//         int left = 0, right = sz - 1;
//         while(left < right)
//         {
//             cout<<combinatorial_number(left, sz - 1)<<" ";
//             sum += (combinatorial_number(left, sz - 1) * (nums[left] + nums[right]));
//             ++left;
//             --right;
//         }
//         if(left == right) sum += (combinatorial_number(left, sz - 1) * nums[left]);

//         return sum % 10;
//     }
// };