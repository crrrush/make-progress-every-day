/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2023-11-05 19:47:31
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2023-11-05 19:48:22
 * @FilePath: \every-little-progress\day 349\test.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */



// 2348. 全 0 子数组的数目
// https://leetcode.cn/problems/number-of-zero-filled-subarrays/description/
// 给你一个整数数组 nums ，返回全部为 0 的 子数组 数目。

// 子数组 是一个数组中一段连续非空元素组成的序列。

 

// 示例 1：

// 输入：nums = [1,3,0,0,2,0,0,4]
// 输出：6
// 解释：
// 子数组 [0] 出现了 4 次。
// 子数组 [0,0] 出现了 2 次。
// 不存在长度大于 2 的全 0 子数组，所以我们返回 6 。
// 示例 2：

// 输入：nums = [0,0,0,2,0,0]
// 输出：9
// 解释：
// 子数组 [0] 出现了 5 次。
// 子数组 [0,0] 出现了 3 次。
// 子数组 [0,0,0] 出现了 1 次。
// 不存在长度大于 3 的全 0 子数组，所以我们返回 9 。
// 示例 3：

// 输入：nums = [2,10,2019]
// 输出：0
// 解释：没有全 0 子数组，所以我们返回 0 。
 

// 提示：

// 1 <= nums.length <= 105
// -109 <= nums[i] <= 109

class Solution {
    long long accumulation(long long n)
    {
        long long sum = 0;
        while(n > 0) sum += n--;
        return sum;
    }

public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long cnt = 0;
        vector<int> map;
        bool push = true;
        for(const auto& e : nums)
        {
            if(e == 0)
            {
                if(push)
                {
                    map.push_back(1);
                    push = false;
                }
                else ++(map.back());
            }
            else
                push = true;
        }

        for(const auto& e : map) cnt += accumulation(e);

        return cnt;
    }
};

// class Solution {
//     bool is_all_zero(vector<int>::iterator cur, const vector<int>::iterator& end)
//     {
//         while(cur != end) if(*cur++ != 0) return false;
//         return true;
//     }
// public:
//     long long zeroFilledSubarray(vector<int>& nums) {
//         long long cnt = 0;
//         for(int len = 1;len <= nums.size();++len)
//         {
//             for(auto it = nums.begin();it + len <= nums.end();++it) if(is_all_zero(it, it + len)) ++cnt;
//         }

//         return cnt;
//     }
// };