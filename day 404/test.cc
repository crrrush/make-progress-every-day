/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2023-12-30 12:53:29
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2023-12-30 12:53:55
 * @FilePath: \every-little-progress\day 404\test.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */


// 2206. 将数组划分成相等数对
// https://leetcode.cn/problems/divide-array-into-equal-pairs/description/
// 给你一个整数数组 nums ，它包含 2 * n 个整数。

// 你需要将 nums 划分成 n 个数对，满足：

// 每个元素 只属于一个 数对。
// 同一数对中的元素 相等 。
// 如果可以将 nums 划分成 n 个数对，请你返回 true ，否则返回 false 。

 

// 示例 1：

// 输入：nums = [3,2,3,2,2,2]
// 输出：true
// 解释：
// nums 中总共有 6 个元素，所以它们应该被划分成 6 / 2 = 3 个数对。
// nums 可以划分成 (2, 2) ，(3, 3) 和 (2, 2) ，满足所有要求。
// 示例 2：

// 输入：nums = [1,2,3,4]
// 输出：false
// 解释：
// 无法将 nums 划分成 4 / 2 = 2 个数对且满足所有要求。
 

// 提示：

// nums.length == 2 * n
// 1 <= n <= 500
// 1 <= nums[i] <= 500

class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_map<int, int> hash;
        for(const auto& e : nums) ++hash[e];
        for(const auto& [x, y] : hash) if(y % 2) return false;
        return true;
    }
};

// class Solution {
// public:
//     bool divideArray(vector<int>& nums) {
//         for(int i = 1;i < nums.size();++i) nums[0] ^= nums[i];
//         return nums[0] == 0;
//     }
// };

// class Solution {
// public:
//     bool divideArray(vector<int>& nums) {
//         int n = 0;
//         sort(nums.begin(), nums.end());
//         for(const auto& e : nums) cout<<e<<" ";
//         for(const auto& e : nums) n ^= e;
//         return n == 0;
//     }
// };

// class Solution {
// public:
//     bool divideArray(vector<int>& nums) {
//         int n = 0;
//         for(const auto& e : nums) n ^= e;
//         return n == 0;
//     }
// };