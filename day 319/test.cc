/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2023-10-06 13:23:25
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2023-10-06 13:43:03
 * @FilePath: \every-little-progress\day 319\test.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */


// LCR 119. 最长连续序列
// https://leetcode.cn/problems/WhsWhI/description/
// 给定一个未排序的整数数组 nums ，找出数字连续的最长序列（不要求序列元素在原数组中连续）的长度。

 

// 示例 1：

// 输入：nums = [100,4,200,1,3,2]
// 输出：4
// 解释：最长数字连续序列是 [1, 2, 3, 4]。它的长度为 4。
// 示例 2：

// 输入：nums = [0,3,7,2,5,8,4,6,0,1]
// 输出：9
 

// 提示：

// 0 <= nums.length <= 104
// -109 <= nums[i] <= 109
 

// 进阶：可以设计并实现时间复杂度为 O(n) 的解决方案吗？


class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;
        set<int> S;
        for(const auto& e : nums) S.insert(e);

        int cnt = 1;
        int maxlen = 0;
        auto cur = S.begin();
        auto prev = cur++;
        while(cur != S.end())
        {
            if((*prev + 1) == *cur)
                ++cnt;
            else if(*cur != *prev && (*prev + 1) != *cur)
            {
                if(cnt > maxlen) maxlen = cnt;
                cnt = 1;
            }

            ++cur;
            ++prev;
        }

        if(cnt > maxlen) maxlen = cnt;

        return maxlen;
    }
};


// class Solution {
// public:
//     int longestConsecutive(vector<int>& nums) {
//         if(nums.empty()) return 0;

//         sort(nums.begin(), nums.end());
//         int cnt = 1;
//         int maxlen = 0;
//         for(int i = 0;i < nums.size() - 1;++i)
//         {
//             if(nums[i] + 1 == nums[i + 1]) 
//                 ++cnt;
//             else if(nums[i] == nums[i + 1])
//                 continue;
//             else
//             {
//                 if(cnt > maxlen) maxlen = cnt;
//                 cnt = 1;
//             }
//         }
//         if(cnt > maxlen) maxlen = cnt;

//         return maxlen;
//     }
// };