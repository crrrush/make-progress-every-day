/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2024-04-25 20:07:13
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2024-04-25 20:08:18
 * @FilePath: \every-little-progress\day 514\test.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */


// 560. 和为 K 的子数组
// https://xiaozhao.leihuo.netease.com/neitui/#/?introduceId=43uqbja1pcd68zy6
// 给你一个整数数组 nums 和一个整数 k ，请你统计并返回 该数组中和为 k 的子数组的个数 。

// 子数组是数组中元素的连续非空序列。

 

// 示例 1：

// 输入：nums = [1,1,1], k = 2
// 输出：2
// 示例 2：

// 输入：nums = [1,2,3], k = 3
// 输出：2
 

// 提示：

// 1 <= nums.length <= 2 * 104
// -1000 <= nums[i] <= 1000
// -107 <= k <= 107

class Solution {
public:// wrong
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> hash;
        int sum = 0;
        int cnt = 0;
        ++hash[sum];
        for(const auto& e : nums)
        {
            sum += e;
            auto it = hash.find(sum - k);
            if(it != hash.end()) cnt += it->second;
            ++hash[sum];
        }

        return cnt;
    }
};

// class Solution {
// public:// wrong
//     int subarraySum(vector<int>& nums, int k) {
//         int n = nums.size();
//         vector<int> dpL(nums);
//         for(int i = 1;i < n;++i) dpL[i] = dpL[i - 1] + nums[i];
//         // for(int i = n - 2;i >= 0;--i) dpR[i] = dpR[i + 1] + nums[i];
//         int cnt = 0;
//         for(int i = 0;i < n;++i) for(int j = i;j < n;++j) if(dpL[j] - dpL[i] + nums[i] == k) ++cnt;
//         return cnt;
//     }
// };

