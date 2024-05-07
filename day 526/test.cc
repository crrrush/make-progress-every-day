/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2024-05-07 21:37:43
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2024-05-07 21:38:10
 * @FilePath: \every-little-progress\day 526\test.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */

// 260. 只出现一次的数字 III
// https://leetcode.cn/problems/single-number-iii/description/
// 给你一个整数数组 nums，其中恰好有两个元素只出现一次，其余所有元素均出现两次。 找出只出现一次的那两个元素。你可以按 任意顺序 返回答案。

// 你必须设计并实现线性时间复杂度的算法且仅使用常量额外空间来解决此问题。

 

// 示例 1：

// 输入：nums = [1,2,1,3,2,5]
// 输出：[3,5]
// 解释：[5, 3] 也是有效的答案。
// 示例 2：

// 输入：nums = [-1,0]
// 输出：[-1,0]
// 示例 3：

// 输入：nums = [0,1]
// 输出：[1,0]
 

// 提示：

// 2 <= nums.length <= 3 * 104
// -231 <= nums[i] <= 231 - 1
// 除两个只出现一次的整数外，nums 中的其他数字都出现两次


class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xsum = 0;
        for(const auto& e : nums) xsum ^= e;

        int flag = (xsum == INT_MIN ? 1 : xsum & -xsum); // 取xsum最右侧的1 不重复的两个数的该位一定是不同的

        int n1 = 0, n2 = 0;
        for(const auto& e : nums)
        {
            if(e & flag)
                n1 ^= e;
            else
                n2 ^= e;
        }


        return {n1, n2};
    }
};

// class Solution {
// public:
//     vector<int> singleNumber(vector<int>& nums) {
//         vector<pair<int, int>> mods(2, make_pair(0, 0));
//         vector<int> ans;
//         int num = 0;
//         for(const auto& e : nums) num ^= e;

//         // mod数分出子序列
//         while(ans.empty())
//         {
//             int n = mods.size();
//             for(const auto& e : nums)
//             {
//                 mods[(e % n + n) % n].first ^= e;
//                 mods[(e % n + n) % n].second++;
//             }
//             for(auto& e : mods)
//             {
//                 if(e.second % 2) ans.push_back(e.first);
//                 e.first = e.second = 0;
//             }

//             if(ans.size() != 2) ans.clear();
//             mods.push_back(make_pair(0, 0));
//         }

//         return ans;
//     }
// };

// class Solution {
// public:
//     vector<int> singleNumber(vector<int>& nums) {
//         unordered_map<int, int> hash;
//         vector<int> ans;
//         for(const auto& e : nums) ++hash[e];
//         for(const auto& [x, y] : hash) if(y == 1) ans.push_back(x);
//         return ans;
//     }
// };


