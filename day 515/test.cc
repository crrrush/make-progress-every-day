/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2024-04-26 22:54:24
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2024-04-26 22:54:50
 * @FilePath: \every-little-progress\day 515\test.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */


// 974. 和可被 K 整除的子数组
// https://leetcode.cn/problems/subarray-sums-divisible-by-k/description/
// 给定一个整数数组 nums 和一个整数 k ，返回其中元素之和可被 k 整除的（连续、非空） 子数组 的数目。

// 子数组 是数组的 连续 部分。

 

// 示例 1：

// 输入：nums = [4,5,0,-2,-3,1], k = 5
// 输出：7
// 解释：
// 有 7 个子数组满足其元素之和可被 k = 5 整除：
// [4, 5, 0, -2, -3, 1], [5], [5, 0], [5, 0, -2, -3], [0], [0, -2, -3], [-2, -3]
// 示例 2:

// 输入: nums = [5], k = 9
// 输出: 0
 

// 提示:

// 1 <= nums.length <= 3 * 104
// -104 <= nums[i] <= 104
// 2 <= k <= 104

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> hash;

        // for(int i = -k;i <= k;++i) if(i == 0 || k % i == 0) mnums.push_back(i);
        // for(const auto& r : mnums) cout<<r<<" ";

        int sum = 0;
        int cnt = 0;
        ++hash[sum]; // 自身的余数 k % k
        for(const auto& e : nums)
        {
            sum += e;
            auto it = hash.find((sum % k + k) % k);
            if(hash.end() != it) cnt += it->second;
            ++hash[(sum % k + k) % k];
        }

        return cnt;
    }
};


