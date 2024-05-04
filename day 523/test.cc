/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2024-05-04 20:51:58
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2024-05-04 20:53:36
 * @FilePath: \every-little-progress\day 523\test.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */


// 268. 丢失的数字
// https://leetcode.cn/problems/missing-number/description/
// 给定一个包含 [0, n] 中 n 个数的数组 nums ，找出 [0, n] 这个范围内没有出现在数组中的那个数。

 

// 示例 1：

// 输入：nums = [3,0,1]
// 输出：2
// 解释：n = 3，因为有 3 个数字，所以所有的数字都在范围 [0,3] 内。2 是丢失的数字，因为它没有出现在 nums 中。
// 示例 2：

// 输入：nums = [0,1]
// 输出：2
// 解释：n = 2，因为有 2 个数字，所以所有的数字都在范围 [0,2] 内。2 是丢失的数字，因为它没有出现在 nums 中。
// 示例 3：

// 输入：nums = [9,6,4,2,3,5,7,0,1]
// 输出：8
// 解释：n = 9，因为有 9 个数字，所以所有的数字都在范围 [0,9] 内。8 是丢失的数字，因为它没有出现在 nums 中。
// 示例 4：

// 输入：nums = [0]
// 输出：1
// 解释：n = 1，因为有 1 个数字，所以所有的数字都在范围 [0,1] 内。1 是丢失的数字，因为它没有出现在 nums 中。
 

// 提示：

// n == nums.length
// 1 <= n <= 104
// 0 <= nums[i] <= n
// nums 中的所有数字都 独一无二
 

// 进阶：你能否实现线性时间复杂度、仅使用额外常数空间的算法解决此问题?


class Solution {
public:
    // 位运算
    // 高斯求和 数列的前n项和
    int missingNumber(vector<int>& nums) {
        int ans = 0;
        for(int i = 0;i < nums.size();++i)
        {
            ans ^= (i + 1);
            ans ^= nums[i];
        }
        return ans;
    }
};

// class Solution {
// public:
//     // 哈希 记录后遍历0到n并查询是否出现
//     // 红黑树 记录后遍历，查看是否是上一个数+1
//     int missingNumber(vector<int>& nums) {
//         unordered_set<int> hash;
//         for(const auto& e : nums) hash.insert(e);
//         for(int i = 0;i <= nums.size();++i) if(hash.find(i) == hash.end()) return i;
//         return -1;
//     }
// };


